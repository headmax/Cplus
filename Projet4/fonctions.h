#ifndef BF4FONC_H
#define BF4FONC_H


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PBYTE WINAPI HookVTableFunction(PDWORD64* ppVTable, PBYTE pHook, SIZE_T iIndex) 
{
	DWORD dwOld = 0; PBYTE pOrig = 0; bool vpReturn = false;
	if (VirtualProtect((void*)((*ppVTable) + iIndex), sizeof(PDWORD64), PAGE_EXECUTE_READWRITE, &dwOld))
	{
		vpReturn = true;
		pOrig = ((PBYTE)(*ppVTable)[iIndex]);
		(*ppVTable)[iIndex] = (DWORD64)pHook;

		VirtualProtect((void*)((*ppVTable) + iIndex), sizeof(PDWORD64), dwOld, &dwOld);
	}
	return pOrig;
}


#ifdef _AMD64_
#define _MAX_VALUE ((PVOID)0x000F000000000000)
#define _VALUE ULONG_PTR
#define _Allign 0x7 // soit 0x...0 ou 0x...8
#else
#define _MAX_VALUE ((PVOID)0xFFF00000)
#define _VALUE ULONG
#define _Allign 0x3
#endif

__forceinline bool IsValidPtr(PVOID p) { return (p >= (PVOID)0x10000) && (p < _MAX_VALUE) && !((_VALUE)p & _Allign); }
__forceinline bool IsValidDataPtr(PVOID p) { return (p >= (PVOID)0x10000) && (p < _MAX_VALUE); }

/****************************************************/
// 48 8B 01      mov   rax, [rcx]
// C3            retn
#include <tchar.h>
#include <fstream>



#pragma code_seg(push, ".text")
__declspec(allocate(".text"))
UCHAR __shit_bytenz[4] = { 0x48, 0x8B, 0x01, 0xC3 };
#pragma code_seg()

typedef PVOID(*tShitFUnc)(PVOID);
static const tShitFUnc AvoidShit = (tShitFUnc)&__shit_bytenz;

#define SHIT_HAPPEND ((PVOID)0x1338cafebabef00d)

LONG NTAPI EH(_EXCEPTION_POINTERS *ExceptionInfo)
{
	if (ExceptionInfo->ContextRecord->Rip != (ULONG_PTR)__shit_bytenz)
		return EXCEPTION_CONTINUE_SEARCH;

	ExceptionInfo->ContextRecord->Rip += 3;
	ExceptionInfo->ContextRecord->Rax = (ULONG_PTR)SHIT_HAPPEND;

	return EXCEPTION_CONTINUE_EXECUTION;
}

#ifdef _AMD64_
#define _PTR_MAX_VALUE ((PVOID)0x000F000000000000)
#else
#define _PTR_MAX_VALUE ((PVOID)0xFFE00000)
#endif

inline bool IsValidPtrEh(PVOID Ptr)
{
	return (Ptr >= (PVOID)0x10000) && (Ptr < _PTR_MAX_VALUE) &&
		AvoidShit(Ptr) != SHIT_HAPPEND;
}


/*******************************************************************/


bool IsValidPtrdebug(PVOID p) 
{ 
	bool valid = true;
	if (p <= (PVOID)0x10000) valid = false;
	if (p > _MAX_VALUE) valid = false;
	_VALUE test = ((_VALUE)p & _Allign);
	if (((_VALUE)p & _Allign)!=0) valid = false;
	return valid;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define CVMTHOOK(vtable, name, index) \
	name##Hook = new CVMTHookManager64((DWORD64**)vtable);  \
	o##name = (name##_t)##name##Hook->dwGetMethodAddress(index); \
	name##Hook->dwHookMethod((DWORD64)hk##name, index);

class CVMTHookManager64
{

public:
	CVMTHookManager64(void)
	{
		memset(this, 0, sizeof(CVMTHookManager64));
	}

	CVMTHookManager64(PDWORD64* ppdwClassBase)
	{
		bInitialize(ppdwClassBase);
	}

	~CVMTHookManager64(void)
	{
		UnHook();
	}

	bool bInitialize(PDWORD64* ppdwClassBase)
	{
		m_ppdwClassBase = ppdwClassBase;
		m_pdwOldVMT = *ppdwClassBase;
		m_dwVMTSize = dwGetVMTCount(*ppdwClassBase);
		m_pdwNewVMT = new DWORD64[m_dwVMTSize];
		memcpy(m_pdwNewVMT, m_pdwOldVMT, sizeof(DWORD64)*m_dwVMTSize);
		*ppdwClassBase = m_pdwNewVMT;
		return true;
	}

	bool bInitialize(PDWORD64** pppdwClassBase)
	{
		return bInitialize(*pppdwClassBase);
	}

	void UnHook(void)
	{
		dwHookMethod(oFunction, unhookindex);
	}

	void ReHook(void)
	{
		if (m_ppdwClassBase)
		{
			*m_ppdwClassBase = m_pdwNewVMT;
		}
	}

	void ReplaceOldVTable(void) //En fait quand tu unhook, ca remplace juste la fonction, si tu veux restoré la vraie vtable ca peut être utile. Surtout si tu hook plusieurs fonctions dans la même vtable.
	{
		if (m_ppdwClassBase)
		{
			*m_ppdwClassBase = m_pdwOldVMT;
		}
	}

	int iGetFuncCount(void)
	{
		return(int)m_dwVMTSize;
	}

	DWORD64 dwGetMethodAddress(int Index)
	{
		if (Index >= 0 && Index <= (int)m_dwVMTSize && m_pdwOldVMT != 0)
		{
			oFunction = m_pdwOldVMT[Index];
			unhookindex = Index;
			return m_pdwOldVMT[Index];
		}
		return 0;
	}

	PDWORD64 pdwGetOldVMT(void)
	{
		return m_pdwOldVMT;
	}

	DWORD64 dwHookMethod(DWORD64 dwNewFunc, unsigned int iIndex)
	{
		if (m_pdwNewVMT && m_pdwOldVMT &&iIndex <= m_dwVMTSize&&iIndex >= 0)
		{
			m_pdwNewVMT[iIndex] = dwNewFunc;
			return m_pdwOldVMT[iIndex];
		}
		return 0;
	}
private:

	DWORD64 dwGetVMTCount(PDWORD64 pdwVMT)
	{
		DWORD dwIndex = 0;
		for (dwIndex = 0; pdwVMT[dwIndex]; dwIndex++)
		{
			if (!IsValidDataPtr((PVOID)pdwVMT[dwIndex]))
			{
				break;
			}
		}
		return dwIndex;
	}

	PDWORD64* m_ppdwClassBase;
	PDWORD64 m_pdwNewVMT, m_pdwOldVMT;
	DWORD64 m_dwVMTSize, oFunction;
	int unhookindex;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


DWORD64 ResolveRelativePtr(DWORD64 Address, DWORD64 ofs = 0)
{
	if (Address)
	{
		Address += ofs;
		DWORD tRead = *(DWORD*)Address;
		if (tRead)
			return (DWORD64)(Address + tRead + sizeof(DWORD));
	}
	return NULL;
}



/////////////////////////////////////////////////////////////////
// USAGE:
// DWORD address=FindPattern(Base,Base+Size,GetSig(pPBTable->GetScanSignature(i)).c_str());
// addresse = FindPattern(dwBase, dwBase + dwSize, "48 8B 0D ? ? ? ? 48 85 C9 75 03 33 C0 C3 E9 ? ? ? ?");
// FILE_LOG(logINFO) << "Addresse: 0x" << std::hex << addresse;
/////////////////////////////////////////////////////////////////
#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))

DWORD64 FindPattern(DWORD64 rangeStart, DWORD64 rangeEnd, const char* pattern)
{
	const char* pat = pattern;
	DWORD64 firstMatch = 0;
	for (DWORD64 pCur = rangeStart; pCur < rangeEnd; pCur++)
	{
		if (!*pat) return firstMatch;
		if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte(pat)) {
			if (!firstMatch) firstMatch = pCur;
			if (!pat[2]) return firstMatch;
			if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?') pat += 3;
			else pat += 2;    //one ?
		}
		else {
			pat = pattern;
			firstMatch = 0;
		}
	}
	return NULL;
}



/////////////////////////////////////////////////////////////////////////////
//DWORD Base = (DWORD)GetModuleHandleA("CShell.dll");
//DWORD BasicPlayerInfo = FindCodePattern(Base, 0xffffffff, (PBYTE)"\xA3\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x8B\x54\x24\x30\x3B\xD3\x75\x04\x33\xC9\xEB\x09\x8B\x4C\x24\x34\x2B\xCA\xC1\xF9\x02\x69\xC9\x00\x00\x00\x00\x51\x53\x50\xE8\x00\x00\x00\x00\x8B\x2D\x00\x00\x00\x00", "x????xx????xxxxxxxxxxxxxxxxxxxxxxx????xxxx????xx????");
//addresse = FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x75\x03\x33\xC0\xC3\xE9\x00\x00\x00\x00", "xxx????xxxxxxxxx????");
//FILE_LOG(logINFO) << "Addresse: 0x" << std::hex << addresse;
//BasicPlayerInfo += 0x1;
//BasicPlayerInfo = *(DWORD*)BasicPlayerInfo;
/////////////////////////////////////////////////////////////////////////////
bool bDataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	return (*szMask) == NULL;
}
DWORD64 FindCodePattern(DWORD64 dwAddress, DWORD64 dwLen, BYTE *bMask, char* szMask) // neoIII http://www.unknowncheats.me/forum/633940-post20.html
{
	for (DWORD64 i = 0; i < dwLen; i++)
		if (bDataCompare((BYTE*)(dwAddress + i), bMask, szMask))
			return (DWORD64)(dwAddress + i);
	return NULL;
}

#include <Psapi.h>
///////////////////////////////////////////////////////////////
//Usage:
//
//DWORD dwBase, dwSize;
//
//To get DLL base and size
//GetModuleAddressAndSize("CShell.dll", &dwBase, &dwSize);
//To get exe base and size
//GetModuleAddressAndSize(NULL, &dwBase, &dwSize)
class ModuleAppz{
	const char* dllName; 
	DWORD64* base;
	DWORD64* size; 
	HMODULE ModuleHandle = NULL;
	MODULEINFO module;

public : ModuleAppz(const char* dllName, DWORD64* base, DWORD64* size, HMODULE ModuleHandle = NULL){
		this->dllName = dllName;
		this->base = base;
		this->size = size;
		this->ModuleHandle = ModuleHandle;
		if (IsValidPtr(base) && IsValidPtr(size))
			this->GetModuleAddressAndSize();
	}
	/////////////////////////////////////////////////////////////////
	void GetModuleAddressAndSize()
	{
		
		ZeroMemory(&this->module, sizeof(this->module));
		*this->base = 0;
		*this->size = 0;
		if (!this->ModuleHandle)
		{
			this->ModuleHandle = GetModuleHandleA(this->dllName);
		}
		if (GetModuleInformation(GetCurrentProcess(), this->ModuleHandle, &this->module, sizeof(this->module)))
		{
			*this->base = (DWORD64)this->module.lpBaseOfDll;
			*this->size = (DWORD64)this->module.SizeOfImage;
		}
	}

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define cMaxConsoleLines 500

void ReadyConsole() {

	short int hConHandle;
	long lStdHandle;

	CONSOLE_SCREEN_BUFFER_INFO coninfo;

	FILE *fp;

	// Allocate a console for the program
	AllocConsole();

	// set the screen buffer to be big enough to let us scroll text
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);

	coninfo.dwSize.Y = cMaxConsoleLines; // The max number of lines for the console!
	coninfo.dwSize.X = coninfo.dwSize.X * 2; // double X

	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coninfo.dwSize);
	// set color
	WORD wAttributes = coninfo.wAttributes | BACKGROUND_GREEN;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);

	// Redirect STDOUT to the console
	lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);

	fp = _fdopen(hConHandle, "w");  // Writing to the console

	*stdout = *fp;

	setvbuf(stdout, NULL, _IONBF, 0);
	// -------------------------------


	// Redirect STDIN to the console
	lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);

	fp = _fdopen(hConHandle, "r");  // Reading from the console

	*stdin = *fp;

	setvbuf(stdin, NULL, _IONBF, 0);
	// ------------------------------


	// Redirect STDERR to the console
	lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);

	fp = _fdopen(hConHandle, "w");  // STDERR writing to the console!

	*stderr = *fp;

	setvbuf(stderr, NULL, _IONBF, 0);
	// ------------------------------


	// Point the console to STDIO
	std::ios::sync_with_stdio();

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dumpsig()
{
	
	FILE_LOG(logINFO) << "\n<Sig Dump Start>";
	DWORD64 dwBase, dwSize;
	ModuleAppz* mApp = new ModuleAppz(NULL, &dwBase, &dwSize);

	FILE_LOG(logINFO) << "BF4 Base: 0x" << std::hex << dwBase;
	FILE_LOG(logINFO) << "BF4 Size: 0x" << std::hex << dwSize;

	FILE_LOG(logINFO) << "DebugRenderSettings= 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x29\x00", "xxx????xxxxxxxx????xxx????x????xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "EnlightenRuntimeSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x6C\x00\x0F\x84\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00","xxx????xxxxxxxx????xxx????x????xxx????xxxxxx????xxx????"), 3);
	FILE_LOG(logINFO) << "TextureStreamingSettings = 0x" << std::hex << 1+ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x83\x3D\x00\x00\x00\x00\x00\x75\x21","xxx?????xx"), 3);
	FILE_LOG(logINFO) << "SyncedBFSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x1D\x00\x00\x00\x00\x48\x85\xDB\x75\x26\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x89\x05\x00\x00\x00\x00\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x0F\xB6\x4B\x54\x88\x4D\xD7\x0F\xB6\x4B\x55\x88\x4D\xD9","xxx????xxxxxxxx????xxx????x????xxxxxx????xxxxx????xxxxxxxxxxxxxx"), 3);
	FILE_LOG(logINFO) << "MeshStreamingSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x83\x3D\x00\x00\x00\x00\x00","xxx????xxxxxxxx????xxx????x????xxx????xxx?????"), 3);
	FILE_LOG(logINFO) << "VisualTerrainSettings = 0x" << std::hex << 1+ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x83\x3D\x00\x00\x00\x00\x00\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x49\x8B\x3E","xxx?????xxxxx????xxx????x????xxx????xxx"), 3);
	FILE_LOG(logINFO) << "EffectSystemSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x40\x84\xED","xxx????xxxxxxxx????xxx????x????xxx????xxx"), 3);
	FILE_LOG(logINFO) << "EmitterSystemSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x8B\x40\x28\x85\xC0","xxx????xxxxxxxx????xxx????x????xxx????xxxxx"), 3);
	FILE_LOG(logINFO) << "GameRenderSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\xB8\x00\x00\x00\x00\x00\x40\x0F\x94\xC7","xxx????xxxxxxxx????xxx????x????xxx????xx?????xxxx"), 3);
	FILE_LOG(logINFO) << "DynamicTextureAtlasSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x0D\x00\x00\x00\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x48\x85\xC9","xxx????xxxx?xxxx?xxx"), 3);
	FILE_LOG(logINFO) << "GameContext = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x89\x44\x24\x00\x4C\x8D\xB6\x00\x00\x00\x00","xxx????x????xxxxxxx?xxx????"), 3);
	FILE_LOG(logINFO) << "GameRenderer = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x74\x06\x48\x8B\x01\xFF\x50\x50","xxx????xxxxxxxxxxx"), 3);
	FILE_LOG(logINFO) << "DxRenderer = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\x01\xFF\x50\x08\x85\xC0\x75\x2D","xxx????xxxxxxxxxx"), 3);

	FILE_LOG(logINFO) << "DebugRenderer = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 8B 0D ? ? ? ? 48 85 C9 75 03 33 C0 C3 E9");

	FILE_LOG(logINFO) << "WorldRenderSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x8B\xDA\xFF\xCA", "xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "SSModule = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x74\x24", "xxx????xxxxx"), 3);
	FILE_LOG(logINFO) << "RecieveSS = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x89\x1D\x00\x00\x00\x00\xE9\x00\x00\x00\x00", "xxx????x????"), 3);
	FILE_LOG(logINFO) << "SSWidth = 0x" << std::hex << 4+ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xEB\x25", "xx????????xx"), 2);
	FILE_LOG(logINFO) << "SSHeight = 0x" << std::hex << 4+ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\xC7\x05\x00\x00\x00\x00\x00\x00\x00\x00\xEB\x03", "xx????????xx"), 2);
	FILE_LOG(logINFO) << "BorderInput = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x4C\x8B\x05\x00\x00\x00\x00\x4C\x8B\x74\x24\x00", "xxx????xxxx?"), 3);
	FILE_LOG(logINFO) << "VirtualFileSystem = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x1D\x00\x00\x00\x00\x48\x85\xDB\x74\x1B\x8B\x4B\x08\xE8\x00\x00\x00\x00\xF0\xFF\x4B\x08\x75\x0D\x48\x8B\x03\xBA\x00\x00\x00\x00\x48\x8B\xCB\xFF\x10\x48\x8B\x3D\x00\x00\x00\x00", "xxx????xxxxxxxxx????xxxxxxxxxx????xxxxxxxx????"), 3);
	FILE_LOG(logINFO) << "Weapon = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x89\x3D\x00\x00\x00\x00\xF3\x0F\x10\x35\x00\x00\x00\x00", "xxx????xxxx????"), 3);
	FILE_LOG(logINFO) << "ViewAngles = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x89\x05\x00\x00\x00\x00\xEB\x07\x48\x89\x35\x00\x00\x00\x00\x48\x8B\xCB", "xxx????xxxxx????xxx"), 3);
	FILE_LOG(logINFO) << "ServerMetricsSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x33\xF6\x40\x38\x70\x20", "xxx????xxxxxxxx????xxx????x????xxx????xxxxxx"), 3);
	FILE_LOG(logINFO) << "ClientMetricsSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x10\x00", "xxx????xxxxxxxx????xxx????x????xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "EmblemSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x4C\x89\x35\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x49\x8B\x45\x10\x48\x89\x7C\x24\x00\x8B\x48\xFC\x85\xC9\x0F\x84\x00\x00\x00\x00\x48\x89\x5C\x24\x00\x4C\x89\x64\x24\x00\x4C\x89\x7C\x24\x00\x48\x89\x6C\x24\x00\x4D\x8B\xFE\x44\x8B\xE1\x48\x89\x74\x24\x00\x0F\x1F\x84\x00\x00\x00\x00\x00", "xxx????x????xxxxxxxx?xxxxxxx????xxxx?xxxx?xxxx?xxxx?xxxxxxxxxx?xxxx????"), 3);
	FILE_LOG(logINFO) << "ThreadSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x33\xC9\xC7\x40\x00\x00\x00\x00\x00", "xxx????xxxx?????"), 3);
	FILE_LOG(logINFO) << "GameAnimationSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x5E\x00", "xxx????xxxxxxxx????xxx????x????xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "ChatSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x35\x00\x00\x00\x00\x48\x85\xF6\x75\x22\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xF0\x48\x89\x05\x00\x00\x00\x00\x48\x85\xC0\x74\x4B", "xxx????xxxxxxxx????xxx????x????xxxxxx????xxxxx"), 3);
	FILE_LOG(logINFO) << "ClientSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x38\x98\x00\x00\x00\x00", "xxx????xxxxxxxx????xxx????x????xxx????xx????"), 3);
	FILE_LOG(logINFO) << "PersistenceSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8B\x48\x48\x48\x85\xC9", "xxx????xxxxxxxx????xxx????x????xxx????xxxxxxx"), 3);
	FILE_LOG(logINFO) << "OriginSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8B\x68\x30", "xxx????xxxxxxxx????xxx????x????xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "VeniceOnlineSettings = 0x" << std::hex << 1+ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x83\x3D\x00\x00\x00\x00\x00\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0", "xxx?????xxxxx????xxx????x????xxx????xxx????xxx"), 3);
	FILE_LOG(logINFO) << "UISettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x49\x8B\xCE", "xxx????xxxxxxxx????xxx????x????xxx????xxx"), 3);
	FILE_LOG(logINFO) << "SoldierSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x20", "xxx????xxxxx"), 3);
	FILE_LOG(logINFO) << "WindowSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\xB9\x00\x00\x00\x00\x44\x8B\x78\x28", "xxx????x????xxxx"), 3);
	FILE_LOG(logINFO) << "VeniceUISettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x33\xC9\x45\x33\xC9\x4C\x8D\x05\x00\x00\x00\x00\x48\x8B\x50\x30\xE8\x00\x00\x00\x00\x48\x8B\xF0", "xxx????xxxxxxxx????xxx????x????xxx????xxxxxxxx????xxxxx????xxx"), 3);
	FILE_LOG(logINFO) << "GameSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x8B\x48\x18", "xxx????xxxxxxxx????xxx????x????xxx????xxx"), 3);
	FILE_LOG(logINFO) << "GameTimeSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\xB9\x00\x00\x00\x00", "xxx????xxxxxxxx????xxx????x????xxx????x????"), 3);
	FILE_LOG(logINFO) << "SyncedGameSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x15\x00\x00\x00\x00\x48\x85\xD2\x75\x22\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xD0\x48\x89\x05\x00\x00\x00\x00\x48\x85\xC0", "xxx????xxxxxxxx????xxx????x????xxxxxx????xxx"), 3);
	FILE_LOG(logINFO) << "SoundSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x58\x00\x0F\x84\x00\x00\x00\x00", "xxx????xxxxxxxx????xxx????x????xxx????xxxxxx????"), 3);
	FILE_LOG(logINFO) << "GameModeSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9", "xxx????xxxxxxxx????xxx????x????xxx????xxx????xxx"), 3);
	FILE_LOG(logINFO) << "DecalSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x33\x00\x74\x67", "xxx????xxxxxxxx????xxx????x????xxx????xxxxxx"), 3);
	FILE_LOG(logINFO) << "BFDedicatedServerSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8B\x58\x20\x48\x85\xDB\x74\x06\x48\x8B\x5B\x28", "xxx????xxxxxxxx????xxx????x????xxx????xxxxxxxxxxxxx"), 3);
	FILE_LOG(logINFO) << "NetworkSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x8B\x68\x30", "xxx????xxxxxxxx????xxx????x????xxx????xxx"), 3);
	FILE_LOG(logINFO) << "DemoSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8D\x15\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8D\x58\x20", "xxx????xxxxxxxx????xxx????x????xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "PhysicsSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x3E\x00\x74\x34", "xxx????xxxxxxxx????xxx????x????xxx????xxxxxx"), 3);
	FILE_LOG(logINFO) << "AntSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x40\x38\x68\x54", "xxx????xxxxxxxx????xxx????x????xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "EntitySettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x80\x78\x28\x00", "xxx????xxxxxxxx????xxx????x????xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "MeshSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x75\x1A\x48\x8B\x0D\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\xF3\x0F\x10\x40\x00\xF3\x0F\x59\x83\x00\x00\x00\x00\x41\x0F\x2F\xC0\x76\x09\x0F\x2F\xF8\x76\x04\x32\xC0", "xxx????xxxxxxxx????xxx????x????xxx????xxxx?xxxx????xxxxxxxxxxxxx"), 3);
	FILE_LOG(logINFO) << "DxDisplaySettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x74\x0D\x89\x58\x2C", "xxx????xxxxxxxx"), 3);
	FILE_LOG(logINFO) << "AudioSettings = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x05\x00\x00\x00\x00\x8B\x48\x6C", "xxx????xxx"), 3);
	FILE_LOG(logINFO) << "Main = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x89\x1D\x00\x00\x00\x00\x48\x8B\x77\x70", "xxx????xxxx"), 3);
	FILE_LOG(logINFO) << "nearSpawnEntityList = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8B\x1D\x00\x00\x00\x00\x48\x85\xDB\x74\x0C\x48\x8B\x03\x48\x89\x05\x00\x00\x00\x00\xEB\x3F", "xxx????xxxxxxxxxxx????xx"), 3);
	FILE_LOG(logINFO) << "PbSdk = 0x" << std::hex << 1+ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x83\x3D\x00\x00\x00\x00\x00\x48\x8B\xFA\x48\x8B\xF1", "xxx?????xxxxxx"), 3);
	FILE_LOG(logINFO) << "EntitySize = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x89\x15\x00\x00\x00\x00\x48\x89\x15\x00\x00\x00\x00\x48\x8D\x05\x00\x00\x00\x00","xx????xxx????xxx????"), 2);
														  
	
	FILE_LOG(logINFO) << "DebugRenderer::DrawText = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 49 8B F9 41 8B F0");
	FILE_LOG(logINFO) << "DebugRenderer::DrawLine = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 89 5C 24 ? 44 89 4C 24 ? 57");
	FILE_LOG(logINFO) << "DebugRenderer::DrawLineRect2D = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 89 5C 24 ? 48 89 74 24 ? 44 89 4C 24 ? 57 48 83 EC 50");
	FILE_LOG(logINFO) << "DebugRenderer::DrawRect2D = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 8B C4 48 89 58 08 48 89 70 10 44 89 48 20");
	FILE_LOG(logINFO) << "DebugRenderer::CreateCommand = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 41 68 41 8D 78 0F");
	FILE_LOG(logINFO) << "DxDebugRenderer::DxDebugRenderer = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 89 4C 24 ? 53 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 8B D9 E8 ? ? ? ? 90 48 8D 05 ? ? ? ? 48 89 03 48 8B 05"); 
	FILE_LOG(logINFO) << "BaseDebugRenderer::BaseDebugRenderer = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "48 89 4C 24 ? 53 55 56 57 41 54 41 56 41 57 48 83 EC 50 48 C7 44 24 ? ? ? ? ? 48 8B F1"); 
	FILE_LOG(logINFO) << "DebugRenderSettings::DebugRenderSettings = 0x" << std::hex << FindPattern(dwBase, dwBase + dwSize, "40 53 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 03 C7 43 ? ? ? ? ? C7 43 ? ? ? ? ? 48 8B C3 C7 43 ? ? ? ? ? C7 43 ? ? ? ? ? C7 43 ? ? ? ? ? C7 43");

	FILE_LOG(logINFO) << "JUMPA = 0x" << std::hex << FindCodePattern(dwBase, dwSize, (PBYTE)"\x89\x73\x48\xE9\x3E\x01\x00\x00\xC7\x43\x48\x02\x00\x00", "xxxxxx??xxxx??");
	FILE_LOG(logINFO) << "JUMPA = 0x" << std::hex << FindCodePattern(dwBase, dwSize, (PBYTE)"\x89\x73\x48\x89\xB3\x94\x00\x00\x00\xC6\x43\x54", "xxxxxx???xxx");

	//FILE_LOG(logINFO) << "VTABLE_VENICECLIENTMISSILEENTITY = 0x" << std::hex << ResolveRelativePtr(FindCodePattern(dwBase, dwSize, (PBYTE)"\x48\x8D\x05\x00\x00\x00\x00\x8B\xDA\x48\x8B\xF9\x48\x89\x01\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x41\x60\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x81\x00\x00\x00\x00\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x81\x00\x00\x00\x00\xE8\x00\x00\x00\x00\xF6\xC3\x01\x74\x08\x48\x8B\xCF\xE8\x00\x00\x00\x00\x48\x8B\xC7\x48\x8B\x5C\x24\x00\x48\x83\xC4\x20\x5F\xC3\x48\x8D\x0D\x00\x00\x00\x00\xE9\x00\x00\x00\x00", "xxx????xxxxxxxxxxx????xxxxxxx????xxx????xxx????xxx????x????xxxxxxxxx????xxxxxxx?xxxxxxxxx????x????"), 3);
	//FILE_LOG(logINFO) << "VTABLE_VENICECLIENTBULLETENTITY = 0x" << std::hex << FindCodePattern(dwBase, dwSize, (PBYTE)"\x60\x9B\x28\x40\x01\x00\x00\x00\x90\x6B\x37\x40\x01\x00\x00\x00\xF0\xBD\x78\x40\x01\x00\x00\x00\x00\x0B\x14\x40\x01\x00\x00\x00\xD0\xBE\x93\x40\x01\x00\x00\x00", "xxxxx???xxxxx???xxxxx????xxxx???xxxxx???");

	FILE_LOG(logINFO) << "<Sig Dump End>\n";
	
	
}





#endif