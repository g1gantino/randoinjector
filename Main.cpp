#include <Windows.h>
#include <TlHelp32.h>
#include "JunkCode.h"
#include "iostream"
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "Set.h"
#include <ctime>



// And you need:
// 1. change all bytes(0x00, 0x01, 0x03....) in define "JUNKS" to random bytes
// 2. change size this block by adding new bytes
#define JUNKS \
__asm _emit 0x86 \
__asm _emit 0xD2 \
__asm _emit 0x40 \
__asm _emit 0x34 \
__asm _emit 0x59 \
__asm _emit 0x65 \
__asm _emit 0xA1 \
__asm _emit 0x3A \
__asm _emit 0x12 \
__asm _emit 0xF6 \
__asm _emit 0x81 \
__asm _emit 0xC6 \
__asm _emit 0x22 \
__asm _emit 0x9C \
__asm _emit 0xC1 \
__asm _emit 0x8F \
__asm _emit 0x0E \
__asm _emit 0x51 \
__asm _emit 0xA8 \
__asm _emit 0x30 \
__asm _emit 0x9D \
__asm _emit 0x81 \
__asm _emit 0x80 \
__asm _emit 0xCA \
__asm _emit 0xED \
__asm _emit 0xEE \
__asm _emit 0x2A \
__asm _emit 0x8F \
__asm _emit 0x3E \
__asm _emit 0x4F \
__asm _emit 0x86 \
__asm _emit 0xF7 \
__asm _emit 0x35 \
__asm _emit 0xDC \
__asm _emit 0xBC \
__asm _emit 0xDE \
__asm _emit 0xAA \
__asm _emit 0xE3 \
__asm _emit 0x46 \
__asm _emit 0x24 \
__asm _emit 0x9B \
__asm _emit 0x26 \
__asm _emit 0xD3 \
__asm _emit 0x3C \
__asm _emit 0x67 \
__asm _emit 0x7B \
__asm _emit 0x56 \
__asm _emit 0x7E \
__asm _emit 0x94 \
__asm _emit 0xFB \

// you can move theese into a header file and include the header file, but for the majority i left it here....
string dll_name;
string find_dll;
string title;
string color;
string echo_off;
string cls;
int x;
int y;
int z;
int _x;
int _y;
int _z;
int yeet;
int yah;
int yeah_motherfucking_yeet;


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
		} while (Process32Next(hPID, &ProcEntry));

			_JUNK_BLOCK(jmp_label10)
}

int main()
{
	system("@echo off");
	system("title Injector made by giga");
	system("color b");
	//....................
	cout << "DLL:" << endl;
	cin >> dll_name;
	//.................
	if (!(dll_name.find(find_dll) != std::string::npos))
	{
		dll_name += ".dll";
	}
	// junkcode
	system("cls");
	cout << "Random Numbers / ignore" << endl;
	srand(time(NULL));
	x = rand() % 10000;
	y = rand() % 10000;
	z = rand() % 10000;
	_x = x * y;
	_y = y * z;
	_z = z * y;
	//
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	//
	cout << _x << endl;
	cout << _y << endl;
	cout << _z << endl;
	Sleep(420);
	cout << "Done...";
	LPCSTR DLL_NAME = dll_name.c_str();
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

void retarded_big_coder_moments() {
	yeet = 10;
		yah = 20;
		yeah_motherfucking_yeet = yeet + yah;

}


