#include "area.h"
#include <QTimerEvent>
using std::nothrow;

Area::Area(QWidget *parent): QWidget(parent)
{
    this->setFixedSize(QSize(300,200)); //(w,h)
    myline = new(nothrow) MyLine(80, 100,50);
    myrect = new(nothrow) MyRect(220,100,50);        //(,parent)
    if(myline != nullptr && myrect != nullptr)
    {
        alpha = 0;
    }
}

void Area::showEvent(QShowEvent *)    // для сохранения сигнатуры вызываемого события
{
    myTimer=startTimer(50);     //создат таймер
    //Число, возвращаемое функцией – номер таймера. Этот номер необходимо проверить,
    //когда активизируется событие timerEvent(),
    //чтобы быть уверенным, что обрабатывается сигнал от нужного таймера
}

void Area::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline->move(alpha,&painter);           //Без передачи ссылки на painter функции move не смогли бы рисовать на виджете Area, так как у них не было бы доступа к объекту, отвечающему за рисование.
    myrect->move(alpha* (-0.5), &painter);
}

void Area::timerEvent(QTimerEvent *event){
    if(event->timerId() == myTimer){        //проверка на нужный таймер
        alpha = alpha + 0.2;
        update();
    }
    else{
        QWidget::timerEvent(event);
    }
}


void Area::hideEvent(QHideEvent *){
    killTimer(myTimer);
}

Area::~Area(){
    delete myline;
    delete myrect;
}
