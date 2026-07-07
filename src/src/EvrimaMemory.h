#pragma once
#include <Windows.h>

struct Vector3 {
    float x, y, z;
};

class EvrimaMemory {
public:
    bool FindProcess();
    bool IsRunning();
    Vector3 GetPlayerPosition();

private:
    DWORD pid = 0;
    HANDLE hProc = NULL;
};
