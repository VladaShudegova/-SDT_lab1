#include "mainwindow.h"
#include <QTextCodec>
#include <QHBoxLayout>
//#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent){
    codec = QTextCodec::codecForName("UTF-8");
    this->setWindowTitle(codec->toUnicode("Счетчик"));
    label1 = new QLabel(codec->toUnicode("Счет по 1"), this);
    label2 = new QLabel(codec->toUnicode("Счет по 5"), this);
    edit1 = new Counter("0", this);
    edit2 = new Counter("0", this);

    edit1->setReadOnly(true);
    edit2->setReadOnly(true);

    calcbutton = new QPushButton("+1", this);
    exitbutton = new QPushButton(codec->toUnicode("Выход"), this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1->addWidget(label1);
    layout1->addWidget(label2);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1);
    layout2->addWidget(edit2);

    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcbutton);
    layout3->addWidget(exitbutton);

    QVBoxLayout *layout4 = new QVBoxLayout(this);
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    QObject::connect(exitbutton, &QPushButton::clicked, this, &QWidget::close, Qt::UniqueConnection);
    QObject::connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one, Qt::UniqueConnection);
    QObject::connect(calcbutton, &QPushButton::clicked, edit1, &Counter::add_one, Qt::UniqueConnection);
}


MainWindow::~MainWindow()
{
}

