#pragma once

#include <windows.h>
#include <string>
#include <sstream>
#include <iostream>

class HardwareCheck
{
public:
	/**
		Displays the users CPU speed and architecture of the system
	*/
	void DisplayCPUStats()
	{
		char Buffer[_MAX_PATH];
		DWORD BufSize = _MAX_PATH;
		DWORD dwMHz = _MAX_PATH;
		HKEY hKey;

		// open the key where the proc speed is hidden:
		long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
			"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
			0,
			KEY_READ,
			&hKey);

		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, NULL, (LPBYTE)&dwMHz, &BufSize);

		std::string Freq = "CPU Frequency: " + std::to_string(dwMHz) + "MHz\n";
		// convert the DWORD to a CString:
		OutputDebugStringA(Freq.c_str());

		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);

		std::string process = "Processor Architecture: ";
		switch (sysInfo.wProcessorArchitecture) {
		case 0: process += "Intel x86\n";
			break;
		case 5: process += "ARM\n";
			break;
		case 6: process += "Intel Itanium-based\n";
			break;
		case 9: process += "AMD x64\n";
			break;
		case 12: process += "ARM64\n";
			break;
		default: process += "Unknown\n";
			break;
		}
		OutputDebugStringA(process.c_str());


		
	}

	void Memory()
	{
		MEMORYSTATUSEX statex;

		statex.dwLength = sizeof(statex);

		GlobalMemoryStatusEx(&statex);

		std::string totalPhys = std::to_string(statex.ullTotalPhys / 1024);
		std::string availPhys = std::to_string(statex.ullAvailPhys / 1024);
		std::string totalVirt = std::to_string(statex.ullTotalVirtual / 1024);
		std::string availVirt = std::to_string(statex.ullAvailVirtual / 1024);
		std::string memUsage = "There is " + std::to_string(statex.dwMemoryLoad) + " percent of memory in use.\n";
		totalPhys = "There are " + totalPhys + " total KB of physical memory.\n";
		availPhys = "There are " + availPhys + " free  KB of physical memory.\n";
		totalVirt = "There are " + totalVirt + " total KB of virtual memory.\n";
		availVirt = "There are " + availVirt + " free  KB of virtual memory.\n";
		OutputDebugStringA(memUsage.c_str());
		OutputDebugStringA(totalPhys.c_str());
		OutputDebugStringA(availPhys.c_str());
		OutputDebugStringA(totalVirt.c_str());
		OutputDebugStringA(availVirt.c_str());
		
	}

	bool Storage()
	{
		unsigned long long Qfree = 0;

		ULARGE_INTEGER freeBytes;
		GetDiskFreeSpaceEx(TEXT("c:\\"), &freeBytes, 0, 0);
		Qfree = freeBytes.QuadPart;
		std::cout << "Bytes available: " << Qfree << "\nMB available: " << Qfree / 1024 / 1024 << " MB" << std::endl;
		if (Qfree / 1024 / 1024 >= 300)
			return true;
		return false;
	}

};