#include "MumbleLink.h"
#include <windows.h>

struct LinkedMem {
    UINT32 uiVersion;
    UINT32 uiTick;
    float fAvatarPosition[3];
    float fAvatarFront[3];
    float fAvatarTop[3];
    float fCameraPosition[3];
    float fCameraFront[3];
    float fCameraTop[3];
    wchar_t name[256];
    wchar_t identity[256];
    UINT32 context_len;
    unsigned char context[256];
    wchar_t description[2048];
};

static HANDLE hMapObject = nullptr;
static LinkedMem* lm = nullptr;

bool InitMumbleLink()
{
    hMapObject = CreateFileMappingW(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, 0, sizeof(LinkedMem), L"MumbleLink");
    if (!hMapObject)
        return false;

    lm = (LinkedMem*)MapViewOfFile(hMapObject, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(LinkedMem));
    if (!lm)
        return false;

    lm->uiVersion = 2;
    lm->uiTick = 0;

    return true;
}

void UpdateMumblePosition(float x, float y, float z)
{
    if (!lm)
        return;

    lm->fAvatarPosition[0] = x;
    lm->fAvatarPosition[1] = y;
    lm->fAvatarPosition[2] = z;

    lm->fCameraPosition[0] = x;
    lm->fCameraPosition[1] = y;
    lm->fCameraPosition[2] = z;

    lm->uiTick++;
}
