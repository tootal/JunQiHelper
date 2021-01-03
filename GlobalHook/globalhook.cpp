#include "globalhook.h"

#include <QString>

GlobalHook::GlobalHook()
{
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
    return 0x000002;
}
