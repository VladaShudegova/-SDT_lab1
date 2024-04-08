#include "win.h"
#include <QTextCodec>
#include <QVBoxLayout>
//#include "ui_win.h"

//Win::Win(QWidget *parent)
//    : QWidget(parent)
//    , ui(new Ui::Win)
//{
//    ui->setupUi(this);
//}

Win::Win(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("Windows-1251");           //добавление таблицы кодов русского языка 1251
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));   //добавление заголовка приложения, русский язык меняет кодировку на Unicode
    frame = new QFrame(this);                                   //инициализация рамки в данном окне
    frame->setFrameShadow(QFrame::Raised);                      // устанавливаем тип тени рамки(приподнятая)
    frame->setFrameShape(QFrame::Panel);                        //установка формы рамки(панель)
    inputLabel = new QLabel(codec->toUnicode("Введите число:"), //добавление метки для ввода числа, русский язык менят кодировку
                            this);
    inputEdit = new QLineEdit("",this);                         //в строку для полученния входных данных ничего не записываем

    outputLabel = new QLabel(codec->toUnicode("Результат:"),    //добавление метки для вывода числа, русский язык менят кодировку
                             this);
    outputEdit = new QLineEdit("",this);                        //в строку для вывода результата ничего не записываем
    nextButton = new QPushButton(codec->toUnicode("Следующее"), //инициализируем кнопку, меняя русскму названию кодировку
                                 this);
    exitButton = new QPushButton(codec->toUnicode("Выход"),     //инициализируем кнопку, меняя русскму названию кодировку
                                 this);

    // компоновка приложения
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);             //инициализируем вертикальный компановщик внутри рамки
    vLayout1->addWidget(inputLabel);                            //добавляем в данный компановщик метку ввода данных
    vLayout1->addWidget(inputEdit);                             //добавляем в данный компановщик поле для ввода числа
    vLayout1->addWidget(outputLabel);                           //добавляем в данный компановщик метку для вывода данных
    vLayout1->addWidget(outputEdit);                            //добавляем в данный компановщик поле для вывода резултата
    vLayout1->addStretch();                                     //добавляем в данный компановщик пружинку между полем вывода резултата
                                                                //и нижним краем вертикального компановщика
    QVBoxLayout *vLayout2 = new QVBoxLayout();                  //инициализируем вертикальный компановщик пока без родительского виджета
    vLayout2->addWidget(nextButton);                            //добавление кнопки в компановщик
    vLayout2->addWidget(exitButton);                            //добавление кнопки в компановщик
    vLayout2->addStretch();                                     //добавляем в данный компановщик пружинку между кнопкой выход
                                                                //и нижним краем вертикального компановщика
    QHBoxLayout *hLayout = new QHBoxLayout(this);               //инициализируем вертикальный компановщик внутри окна
    hLayout->addWidget(frame);                                  //добавление рамки во внутрь компановщика
    hLayout->addLayout(vLayout2);                               //добавление вертикального компановщика, хранящего кнопки, в горизонтальный компановщик

    QObject::connect(exitButton, &QPushButton::clicked, this, &QWidget::close); //по нажатию на кнопку вызывается существующий слот закрытия окна

}


Win::~Win()
{
    //delete ui;
}

