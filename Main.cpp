#include <Windows.h>
#include <TlHelp32.h>
#include "JunkCode.h"
#include "iostream"
#include <string>
#include <chrono>
#include <thread>

// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by adding new bytes
#define JUNKS \
__asm _emit 0x67 \
__asm _emit 0x87 \
__asm _emit 0x60 \
__asm _emit 0x07 \
__asm _emit 0xD6 \
__asm _emit 0xD1 \
__asm _emit 0xB7 \
__asm _emit 0x98 \
__asm _emit 0x9B \
__asm _emit 0x55 \
__asm _emit 0x7E \
__asm _emit 0x1F \
__asm _emit 0x52 \
__asm _emit 0xA9 \
__asm _emit 0x6F \
__asm _emit 0x3C \
__asm _emit 0x2D \
__asm _emit 0x77 \
__asm _emit 0xB4 \
__asm _emit 0xE5 \
__asm _emit 0x21 \
__asm _emit 0xEE \
__asm _emit 0xBB \
__asm _emit 0x30 \
__asm _emit 0xE7 \
__asm _emit 0x2F \
__asm _emit 0xF9 \
__asm _emit 0xAA \
__asm _emit 0x0C \
__asm _emit 0xD0 \
__asm _emit 0x64 \
__asm _emit 0xE3 \
__asm _emit 0x91 \
__asm _emit 0xAC \
__asm _emit 0x07 \
__asm _emit 0xC0 \
__asm _emit 0xDC \
__asm _emit 0xC1 \
__asm _emit 0x42 \
__asm _emit 0x88 \


using namespace std;


// Don't change this!
#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:

DWORD GetPid(char* ProcessName)
{
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	PROCESSENTRY32 ProcEntry;

	ProcEntry.dwSize = sizeof(ProcEntry);

	do
	{
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			DWORD dwPID = ProcEntry.th32ProcessID;

			CloseHandle(hPID);

			return dwPID;
		}
	} while (Process32Next(hPID, &ProcEntry));
}


DWORD Process(char* ProcessName)
{			
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
}

int main()
{
	// poorly written was 2 lazy
	system("title Injector");
	system("color b");
	system("@echo off");
	system("cls");
	// ....................
	string dll_name_blyat;
	string find_dll;
	//....................
	cout << "What is the DLL name? Include .dll:";
	cin >> dll_name_blyat;
	//.................
	//check dll
	if (!(dll_name_blyat.find(find_dll) != std::string::npos))				
	{
		dll_name_blyat += ".dll";											
	}
	//........................
	
	cout << "Injecting :-)";
	cout << dll_name_blyat;
	cout << "pls wait";
	LPCSTR DLL_NAME = dll_name_blyat.c_str();
	Sleep(1000);
	// remove the sleep line if ur too lazy to wait 1second for the injector not doing anything.
	// ....................I         N               J        E             C           T ..........................
	_JUNK_BLOCK(jmp_label11)
		DWORD dwProcess;

	_JUNK_BLOCK(jmp_label12)
		char myDLL[MAX_PATH];

	_JUNK_BLOCK(jmp_label13)
		GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);

	_JUNK_BLOCK(jmp_label4)
		dwProcess = Process("csgo.exe");

	_JUNK_BLOCK(jmp_label15)
		HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);

	LPVOID ntOpenFile = GetProcAddress(LoadLibraryW(L"ntdll"), "NtOpenFile");
	if (ntOpenFile) {
		char originalBytes[5];
		memcpy(originalBytes, ntOpenFile, 5);
		WriteProcessMemory(hProcess, ntOpenFile, originalBytes, 5, NULL);
	}

	_JUNK_BLOCK(jmp_label16)
		LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	_JUNK_BLOCK(jmp_label17)
		WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);

	_JUNK_BLOCK(jmp_label18)
		CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);

	_JUNK_BLOCK(jmp_label19)
		CloseHandle(hProcess);

	_JUNK_BLOCK(jmp_label20)
		return 0;

	_JUNK_BLOCK(jmp_label21)
}
