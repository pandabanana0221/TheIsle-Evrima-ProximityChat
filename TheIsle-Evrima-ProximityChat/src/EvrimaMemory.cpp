#include "EvrimaMemory.h"
#include <windows.h>
#include <tlhelp32.h>
#include <string>

DWORD GetProcessIdByName(const wchar_t* processName)
{
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
        return 0;

    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(snapshot, &entry))
    {
        do
        {
            if (wcscmp(entry.szExeFile, processName) == 0)
            {
                CloseHandle(snapshot);
                return entry.th32ProcessID;
            }
        } while (Process32NextW(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return 0;
}

uintptr_t GetModuleBaseAddress(DWORD pid, const wchar_t* moduleName)
{
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (snapshot == INVALID_HANDLE_VALUE)
        return 0;

    MODULEENTRY32W mod;
    mod.dwSize = sizeof(MODULEENTRY32W);

    if (Module32FirstW(snapshot, &mod))
    {
        do
        {
            if (wcscmp(mod.szModule, moduleName) == 0)
            {
                CloseHandle(snapshot);
                return reinterpret_cast<uintptr_t>(mod.modBaseAddr);
            }
        } while (Module32NextW(snapshot, &mod));
    }

    CloseHandle(snapshot);
    return 0;
}

bool ReadMemory(HANDLE process, uintptr_t address, void* buffer, SIZE_T size)
{
    SIZE_T bytesRead = 0;
    return ReadProcessMemory(process, reinterpret_cast<LPCVOID>(address), buffer, size, &bytesRead);
}


