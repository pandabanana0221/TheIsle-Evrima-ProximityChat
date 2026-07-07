#include <windows.h>
#include <iostream>
#include "MumbleLink.h"
#include "EvrimaMemory.h"

int main()
{
    std::wcout << L"[Evrima Proximity Chat] Starting..." << std::endl;

    // Find Evrima process
    DWORD pid = GetProcessIdByName(L"TheIsle-Win64-Shipping.exe");
    if (!pid)
    {
        std::wcout << L"[Error] Could not find Evrima process." << std::endl;
        return 1;
    }

    std::wcout << L"[OK] Found Evrima process. PID = " << pid << std::endl;

    // Open process
    HANDLE process = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (!process)
    {
        std::wcout << L"[Error] Failed to open Evrima process." << std::endl;
        return 1;
    }

    // Get module base
    uintptr_t base = GetModuleBaseAddress(pid, L"TheIsle-Win64-Shipping.exe");
    if (!base)
    {
        std::wcout << L"[Error] Could not find module base." << std::endl;
        CloseHandle(process);
        return 1;
    }

    std::wcout << L"[OK] Module base: 0x" << std::hex << base << std::endl;

    // Initialize MumbleLink
    if (!InitMumbleLink())
    {
        std::wcout << L"[Error] Failed to initialize MumbleLink." << std::endl;
        CloseHandle(process);
        return 1;
    }

    std::wcout << L"[OK] MumbleLink initialized." << std::endl;

    // Main loop
    while (true)
    {
        float playerPos[3] = { 0 };

        // Placeholder offset — replace with real Evrima offsets later
        uintptr_t posAddress = base + 0x00000000;

        ReadMemory(process, posAddress, &playerPos, sizeof(playerPos));

        UpdateMumblePosition(playerPos[0], playerPos[1], playerPos[2]);

        Sleep(10);
    }

    CloseHandle(process);
    return 0;
}

