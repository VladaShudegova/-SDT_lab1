#include "win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Win w(0);
    w.show();
    return app.exec();

}
