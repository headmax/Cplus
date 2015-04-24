#include <minwinbase.h>
#include <conio.h>
#include <dwmapi.h>
#include <stdio.h>
#pragma comment(lib, "dwmapi.lib")

namespace std{
	BOOL MemPatchSafe(DWORD_PTR addressToWrite, byte* valueToWrite, int byteNum){
		DWORD oldProt;
		VirtualProtect((LPVOID)(addressToWrite), byteNum, PAGE_EXECUTE_READWRITE, &oldProt);
		for (int i = 0; i < byteNum; i++)
		{
			*(BYTE*)(addressToWrite + i) = valueToWrite[i];
		}
		VirtualProtect((LPVOID)(addressToWrite), byteNum, oldProt, NULL);
		return TRUE;
	}

	PBYTE WINAPI HookaVTableFunction(PDWORD64 ppVTable, PBYTE pHook, SIZE_T iIndex)
	{
		DWORD dwOld = 0; PBYTE pOrig = 0; bool vpReturn = false;
		if (VirtualProtect((void*)((ppVTable)+iIndex), sizeof(PDWORD64), PAGE_EXECUTE_READWRITE, &dwOld))
		{
			vpReturn = true;
			pOrig = ((PBYTE)(ppVTable)[iIndex]);
			(ppVTable)[iIndex] = (DWORD64)pHook;

			VirtualProtect((void*)((ppVTable)+iIndex), sizeof(PDWORD64), dwOld, &dwOld);
		}
		return pOrig;
	}
}

