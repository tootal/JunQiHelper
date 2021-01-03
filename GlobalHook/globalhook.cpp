#include "globalhook.h"

#include <QString>

GlobalHook::GlobalHook()
{
}

QString GlobalHook::name()
{
    return "GloblHook";
}

int GlobalHook::version()
{
    return 0x000001;
}
