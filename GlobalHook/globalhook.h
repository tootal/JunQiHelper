#ifndef GLOBALHOOK_H
#define GLOBALHOOK_H

#include "GlobalHook_global.h"

#include <Windows.h>

class GLOBALHOOK_EXPORT GlobalHook
{
public:
    GlobalHook();
    static QString name();
    static QString author();
    static int version();

public:
    bool installKeyHook();
};

#endif // GLOBALHOOK_H
