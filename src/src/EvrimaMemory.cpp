#include "EvrimaMemory.h"
#include <TlHelp32.h>

bool EvrimaMemory::FindProcess() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snapshot, &pe)) {
        do {
            if (wcscmp(pe.szExeFile, L"TheIsle-Win64-Shipping.exe") == 0) {
                pid = pe.th32ProcessID;
                hProc = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pid);
                CloseHandle(snapshot);
                return true;
            }
        } while (Process32Next(snapshot, &pe));
    }

    CloseHandle(snapshot);
    return false;
}

bool EvrimaMemory::IsRunning() {
    DWORD exitCode;
    GetExitCodeProcess(hProc, &exitCode);
    return exitCode == STILL_ACTIVE;
}

Vector3 EvrimaMemory::GetPlayerPosition() {
    Vector3 pos{0,0,0};

    // Placeholder: You will update this with the correct memory offsets
    // once you confirm your Evrima build version.

    return pos;
}
