#ifndef GLOBALHOOK_H
#define GLOBALHOOK_H

#include "GlobalHook_global.h"
#include <QObject>
#include <Windows.h>

#define GHOOK GlobalHook::instance()

class GLOBALHOOK_EXPORT GlobalHook : public QObject
{
    Q_OBJECT
public:
    static QString name();
    static QString author();
    static int version();

public:
    static GlobalHook* instance();
    bool installKeyHook();
};

#endif // GLOBALHOOK_H
