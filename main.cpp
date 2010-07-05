#include <QtGui/QApplication>
#include "tiltnroll.h"
#ifdef Q_OS_SYMBIAN
#include <qsysteminfo.h>
#else
#include <QSystemInfo> //(1)
#endif
using namespace QtMobility; //(2)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile f(":/tnr.css");
    if (f.open(QIODevice::ReadOnly)) {
        a.setStyleSheet(f.readAll());
        f.close();
    }

    TiltNRoll w;
#if defined(Q_WS_S60)
    w.showFullScreen();
#else
    w.showFullScreen();
#endif

    return a.exec();
}
