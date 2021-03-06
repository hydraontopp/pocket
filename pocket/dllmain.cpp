#include <windows.h>
#include <MinHook.h>
#include <map>

// SDK
#include "SDK/Actor.h"
#include "Utils/Utils.h"

typedef void(__thiscall* tick)(Actor*, void* a2);
tick _tick;

typedef void(__thiscall* key)(uint64_t, bool);
key _key;

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();

void keyCallback(uint64_t c, bool v) {
    keymap[c] = v;
    _key(c, v);
};

void callback(Actor* player, void* a2) {

    if (keymap[(int)'C'])
        player->SetFieldOfView(0.2f);
    else player->SetFieldOfView(1);

    _tick(player, a2);
};

void Init(HMODULE c) {
    if (MH_Initialize() == MH_OK) {

        // Function hooks
        uintptr_t hookAddr = Mem::findSig("48 83 EC ? 80 B9 ? ? ? ? ? 75 23");
        uintptr_t keymapAddr = Mem::findSig("48 89 5C 24 08 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA 89");
        
        if (MH_CreateHook((void*)hookAddr, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK) {
            MH_EnableHook((void*)hookAddr);
        };
        if (MH_CreateHook((void*)keymapAddr, &keyCallback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK) {
            MH_EnableHook((void*)keymapAddr);
        };
    };
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, 0);
    }
    return TRUE;
}