#ifndef GLOBALHOOK_H
#define GLOBALHOOK_H

#include "GlobalHook_global.h"

class GLOBALHOOK_EXPORT GlobalHook
{
public:
    GlobalHook();
    static QString name();
    static QString author();
    static int version();
};

#endif // GLOBALHOOK_H
