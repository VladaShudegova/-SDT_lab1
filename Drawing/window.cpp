#include "window.h"
#include<QTextCodec>
#include<QVBoxLayout>

window::window(){
    codec = QTextCodec::codecForName("UTF-8");
    this->setWindowTitle(codec->toUnicode("Обработка событий"));
    area = new Area(this);
    btn = new QPushButton(codec->toUnicode("Завершить"), this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    QObject::connect(btn, &QPushButton::clicked, this, &QWidget::close);
}

