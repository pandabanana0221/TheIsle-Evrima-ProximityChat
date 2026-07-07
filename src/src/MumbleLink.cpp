#include "MumbleLink.h"
#include <string>

MumbleLink::MumbleLink() {
    hMapObject = OpenFileMappingW(FILE_MAP_ALL_ACCESS, FALSE, L"MumbleLink");
    if (!hMapObject) {
        hMapObject = CreateFileMappingW(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
                                        0, sizeof(LinkedMem), L"MumbleLink");
    }
    lm = (LinkedMem*)MapViewOfFile(hMapObject, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(LinkedMem));
}

void MumbleLink::Update(float x, float y, float z) {
    if (!lm) return;

    lm->uiVersion = 2;
    lm->uiTick++;

    lm->fAvatarPosition[0] = x;
    lm->fAvatarPosition[1] = y;
    lm->fAvatarPosition[2] = z;

    lm->fAvatarFront[0] = 0;
    lm->fAvatarFront[1] = 0;
    lm->fAvatarFront[2] = 1;

    lm->fAvatarTop[0] = 0;
    lm->fAvatarTop[1] = 1;
    lm->fAvatarTop[2] = 0;

    wcscpy_s(lm->name, L"The Isle Evrima");
    wcscpy_s(lm->identity, L"EvrimaPlayer");
}
