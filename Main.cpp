#include <Windows.h>
#include <TlHelp32.h>
#include "iostream"
#include <string>
#include <thread>
#include <cstdlib>
#include <ctime>

using namespace std;

//could have made a header file, but works. you can make a header file and copy all of theese into it and add using namespace std;  / and then you #include "your_header_name.h" in the main.cpp
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
string dll_name;
string find_dll;
int x;
int y;
int z;
int _x;
int _y;
int _z;
// _________________________READ_________________________
/*
Injector is made by the creator of randoinjector, then fixed by martinjanas to fix with trustlaunch, then I added some misc stuff here.
It is nothing special but it works, is UD and is free.
Feel free to use it in your videos etc.
*/



//READ: CHANGE theese __asm _emit 0x86 \ with a generator. This is what makes the injector ud.
#define JUNKS \
__asm _emit 0x3F \
__asm _emit 0x91 \
__asm _emit 0x60 \
__asm _emit 0x25 \
__asm _emit 0x5D \
__asm _emit 0x8F \
__asm _emit 0x90 \
__asm _emit 0xB8 \
__asm _emit 0x22 \
__asm _emit 0xA7 \
__asm _emit 0x05 \
__asm _emit 0x40 \
__asm _emit 0x63 \
__asm _emit 0xAA \
__asm _emit 0xC3 \
__asm _emit 0x96 \
__asm _emit 0x4D \
__asm _emit 0x7C \
__asm _emit 0xFE \
__asm _emit 0xC8 \
__asm _emit 0x1D \
__asm _emit 0x35 \
__asm _emit 0x2E \
__asm _emit 0x08 \
__asm _emit 0x67 \
__asm _emit 0x41 \
__asm _emit 0x02 \
__asm _emit 0xFD \
__asm _emit 0x23 \
__asm _emit 0x50 \
__asm _emit 0x8A \
__asm _emit 0x51 \
__asm _emit 0x6A \
__asm _emit 0x66 \
__asm _emit 0xEB \
__asm _emit 0x22 \
__asm _emit 0x7E \
__asm _emit 0x8C \
__asm _emit 0xA0 \
__asm _emit 0xC2 \
__asm _emit 0xF0 \
__asm _emit 0x2D \
__asm _emit 0x83 \
__asm _emit 0xB6 \
__asm _emit 0xC8 \
__asm _emit 0xFA \
__asm _emit 0x78 \
__asm _emit 0xCA \
__asm _emit 0xF0 \
__asm _emit 0xD6 \






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
	Sleep(100);
	system("cls");
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "Injection successful" << endl;
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


// ================================= P A S T E _ Y O U R _ J U N K _ C O D E _ H E R E  =================================




//============================================== J U N K _ C O D E _ E N D  ============================================
