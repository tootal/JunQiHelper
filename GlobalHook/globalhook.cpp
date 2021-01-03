#include "globalhook.h"

#include <QString>

// Global Variables
HHOOK g_keyHookHandle = nullptr;
bool g_keyHookInstalled = false;

// Global Functions
LRESULT CALLBACK KeyboardProcedure(int code, WPARAM wParam, LPARAM lParam) {
    if (g_keyHookInstalled) {
        // point to keyboard hook struct
        auto pkbhs = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
        // ignore key release event
        if (pkbhs->flags & LLKHF_UP) {
            qInfo("Key Code: %u", pkbhs->vkCode);
        }
    }
    return CallNextHookEx(g_keyHookHandle, code, wParam, lParam);
}

// GlobalHook Methods

Q_GLOBAL_STATIC(GlobalHook, globalHook);

GlobalHook::~GlobalHook()
{
    uninstallKeyHook();
}

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
    return 0x000007;
}

GlobalHook *GlobalHook::instance()
{
    return globalHook();
}

bool GlobalHook::installKeyHook()
{
    g_keyHookInstalled = true;
    SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProcedure, 0, 0);
    return g_keyHookHandle;
}

bool GlobalHook::uninstallKeyHook()
{
    g_keyHookInstalled = false;
    if (!g_keyHookHandle) return true;
    if (UnhookWindowsHookEx(g_keyHookHandle)) {
        g_keyHookHandle = nullptr;
        return true;
    }
    return false;
}
