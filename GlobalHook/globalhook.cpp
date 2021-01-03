#include "globalhook.h"

#include <QString>

// Global Variables
HINSTANCE g_instanceHandle = nullptr;
HHOOK g_keyHookHandle = nullptr;

// Global Functions

LRESULT CALLBACK KeyboardProcedure(int code, WPARAM wParam, LPARAM lParam) {
    // point to keyboard hook struct
    auto pkbhs = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
    qInfo("Key Code: %u", pkbhs->vkCode);
    return CallNextHookEx(g_keyHookHandle, code, wParam, lParam);
}

// GlobalHook Methods

Q_GLOBAL_STATIC(GlobalHook, globalHook);

QString GlobalHook::name()
{
    return "GloblHook";
}

QString GlobalHook::author()
{
    return "tootal";
}

int GlobalHook::version()
{
    return 0x000004;
}

GlobalHook *GlobalHook::instance()
{
    return globalHook();
}

bool GlobalHook::installKeyHook()
{
    SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProcedure, g_instanceHandle, 0);
    return g_keyHookHandle;
}
