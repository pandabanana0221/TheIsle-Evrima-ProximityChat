#pragma once
#include <windows.h>
#include <cstdint>

DWORD GetProcessIdByName(const wchar_t* processName);
uintptr_t GetModuleBaseAddress(DWORD pid, const wchar_t* moduleName);
bool ReadMemory(HANDLE process, uintptr_t address, void* buffer, SIZE_T size);
