#include <Windows.h>
#include <TlHelp32.h>
#include "iostream"
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//could have made a header file, but works. you can make a header file and copy all of theese into it and add using namespace std;  / and then you #include "header_name.h" in the main.cpp
string dll_name;
string find_dll;
string title;
string color;
string echo_off;
string cls;
string holy_thousand;
int x;
int y;
int z;
int _x;
int _y;
int _z;
int jc1;
int jc2;
int jc123;
// _________________________READ_________________________
/*
Injector is made by the creator of randoinjector, then fixed by martinjanas to fix with trustlaunch, then I added some misc stuff here.
It is nothing special but it works, is UD and is free.
Feel free to use it in your videos etc.
==\
Colors:
(for you if you want to change colors)
#define FOREGROUND_BLUE      0x0001 // text color contains blue.
#define FOREGROUND_GREEN     0x0002 // text color contains green.
#define FOREGROUND_RED       0x0004 // text color contains red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.
*/



//READ: CHANGE theese __asm _emit 0x86 \ with a generator. This is what makes the injector ud.
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
	//FIXME: dont use system
	system("@echo off");
	system("title Future Injector");
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << " ______     _                    _____       _           _             " << endl;
	cout << "|  ____|   | |                  |_   _|     (_)         | |            " << endl;
	cout << "| |__ _   _| |_ _   _ _ __ ___    | |  _ __  _  ___  ___| |_ ___  _ __ " << endl;
	cout << "|  __| | | | __| | | | '__/ _ |   | | | '_ || |/ _ |/ __| __/ _ || '__|" << endl;
	cout << "| |  | |_| | |_| |_| | | |  __/  _| |_| | | | |  __/ (__| || (_) | |   " << endl;
	cout << "|_|   |__,_||__||__,_|_|  |___| |_____|_| |_| ||___||___||__|___/|_|   " << endl;
	cout << "                                           |__/                         " << endl;
	cout << endl;
	cout << endl;
	//....................
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "DLL NAME:" << endl;
	cin >> dll_name;
	//....................
	if (!(dll_name.find(find_dll) != std::string::npos))
	{
		dll_name += ".dll";
	}
	// Generate Random Numbers
	system("cls");
	cout << "Generating Random Numbers.." << endl;
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
	// Sleep is unneccesary but good for a less snappy experience
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

void junk() {
	jc1 = 10;
	jc2 = 20;
	jc123 = jc1 + jc2;
	holy_thousand = jc123 * 5;
}

