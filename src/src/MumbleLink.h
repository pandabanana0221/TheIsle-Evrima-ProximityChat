#pragma once
#include <Windows.h>

struct LinkedMem {
    UINT32 uiVersion;
    DWORD uiTick;
    float fAvatarPosition[3];
    float fAvatarFront[3];
    float fAvatarTop[3];
    float fCameraPosition[3];
    float fCameraFront[3];
    float fCameraTop[3];
    wchar_t name[256];
    wchar_t description[2048];
    BYTE context[256];
    UINT32 context_len;
    wchar_t identity[256];
};

class MumbleLink {
public:
    MumbleLink();
    void Update(float x, float y, float z);

private:
    HANDLE hMapObject;
    LinkedMem* lm;
};
