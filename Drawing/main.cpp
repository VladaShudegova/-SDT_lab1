#include "window.h"
#include <QApplication>
#include <QLocale>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    window w;
    w.show();
    return a.exec();
}
