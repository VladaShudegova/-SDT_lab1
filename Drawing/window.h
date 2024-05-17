#ifndef WINDOW_H
#define WINDOW_H
#include "area.h"
#include <QPushButton>

#include <QMainWindow>



class window : public QWidget
{

    protected:
        QTextCodec *codec;
        Area *area;
        QPushButton *btn;

    public:
        window();


};
#endif // WINDOW_H
