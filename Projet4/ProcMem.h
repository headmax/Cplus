#ifndef MEM_H
#define MEM_H

#include <Windows.h>
#include <vector>
#include <TlHelp32.h>

typedef DWORD64 MemAddress;

//PTR CHECK
#ifdef _AMD64_
#define _PTR_MAX_VALUE ((MemAddress)0x000F000000000000)
#else
#define _PTR_MAX_VALUE ((MemAddress)0xFFE00000)
#endif

bool IsValid(MemAddress Ptr);

class MemProcess
{
public:
	MemProcess();

	bool attach(const char* exeName, bool waitForProcess = true);
	bool attachWindow(LPCSTR windowName);
	void detach();

	bool isFocused();
	DWORD getProcessId();
	HANDLE getProcessHandle();
	HWND getHwnd();

	bool bDataCompare(BYTE* pData, BYTE* bMask, char * szMask);
	MemAddress dwFindPattern(BYTE* pData, DWORD dwSize, BYTE* bMask, char* szMask);
	MemAddress ResolveRelativePtr(MemAddress Address, MemAddress ofs);
	MemAddress FindPatternEx(BYTE *bMask, char *szMask, MemAddress dwAddress, MemAddress dwLength);

	bool read(MemAddress address, LPVOID buffer, SIZE_T size);
	bool readBool(MemAddress address);
	BYTE readByte(MemAddress address);
	WORD readWord(MemAddress address);
	DWORD readDword(MemAddress address);
	float readFloat(MemAddress address);
	double readDouble(MemAddress address);

	bool write(MemAddress address, LPCVOID buffer, SIZE_T size);
	BYTE writeByte(MemAddress address, byte db);
	WORD writeWord(MemAddress address, WORD dw);
	DWORD writeDword(MemAddress address, DWORD dd);
	float writeFloat(MemAddress address, float flt);
	double writeDouble(MemAddress address, double dbl);

	HMODULE getModuleHandle(const char* moduleName);
	MemAddress getModuleAddress(const char* moduleName);

	bool MemPatch(DWORD_PTR addressToWrite, byte* valueToWrite, int byteNum);
private:
	//process
	DWORD pid;
	HANDLE pHandle;
	HWND hWnd;
};


#endif