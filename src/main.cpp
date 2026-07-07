#include <Windows.h>
#include <iostream>
#include "MumbleLink.h"
#include "EvrimaMemory.h"

int main() {
    std::cout << "The Isle Evrima Positional Audio (DX11)\n";
    std::cout << "Waiting for Evrima...\n";

    EvrimaMemory mem;

    while (!mem.FindProcess()) {
        Sleep(1000);
    }

    std::cout << "Evrima detected. Starting positional audio...\n";

    MumbleLink link;

    while (mem.IsRunning()) {
        Vector3 pos = mem.GetPlayerPosition();
        link.Update(pos.x, pos.y, pos.z);
        Sleep(50);
    }

    std::cout << "Evrima closed. Exiting.\n";
    return 0;
}
