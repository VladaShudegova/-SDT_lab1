#include "figura.h"
#include <math.h>

void Figura::move(float Alpha, QPainter *Painter)       //угол поворота в радианах, указателем на объект QPainter Qt, используемый для рисования в графическом контексте
{
    dx=halflen*cos(Alpha);  //  горизонтальное смещение от центральной точки
    dy=halflen*sin(Alpha);  //  вертикальное смещение от центральной точки
    draw(Painter);      //перересовка
}

void MyLine::draw(QPainter *Painter)
{
    if (Painter->isActive()) {  //проверка на готовность к использованию
    Painter -> drawLine(x+dx, y+dy, x-dx, y-dy);    //Рисует линию из ( x1, y1) к ( x2, y2).
    }
}

void MyRect::draw(QPainter *Painter){
    if (Painter->isActive()) {
        Painter->drawLine(x+dx, y+dy, x+dy, y-dx);  //рисуем диагонали
        Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
        Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
        Painter->drawLine(x-dy,y+dx,x+dx,y+dy);

    }

}
