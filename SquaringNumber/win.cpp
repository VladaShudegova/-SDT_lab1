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
    codec = QTextCodec::codecForName("UTF-8");           //добавление таблицы кодов русского языка 1251
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));   //добавление заголовка приложения, русский язык меняет кодировку на Unicode
    frame = new QFrame(this);                                   //инициализация рамки в данном окне
    frame->setFrameShadow(QFrame::Raised);                      // устанавливаем тип тени рамки(приподнятая)
    frame->setFrameShape(QFrame::Panel);                        //установка формы рамки(панель)
    inputLabel = new QLabel(QString::fromUtf8("Введите число:"), //добавление метки для ввода числа, русский язык менят кодировку
                            this);
    inputEdit = new QLineEdit("",this);                         //в строку для полученния входных данных ничего не записываем
    StrValidator *v=new StrValidator(inputEdit);                // Создаем экземпляр пользовательского валидатора StrValidator
    inputEdit->setValidator(v);                                 // Устанавливаем валидатор для поля ввода inputEdit
    outputLabel = new QLabel(QString::fromUtf8("Результат:"),    //добавление метки для вывода числа, русский язык менят кодировку
                             this);
    outputEdit = new QLineEdit("",this);                        //в строку для вывода результата ничего не записываем
    nextButton = new QPushButton(QString::fromUtf8("Следующее"), //инициализируем кнопку, меняя русскму названию кодировку
                                 this);
    exitButton = new QPushButton(QString::fromUtf8("Выход"),     //инициализируем кнопку, меняя русскму названию кодировку
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

    begin();                                                    //обновление окна для новых данных
    QObject::connect(exitButton, &QPushButton::clicked, this, &QWidget::close); //по нажатию на кнопку вызывается существующий слот закрытия окна
    QObject::connect(nextButton, &QPushButton::clicked, this, &Win::begin);

}


void Win::begin()
{
    inputEdit->clear();                                         //отчистка значений в поле ввода после предыдущего использывания
    nextButton->setEnabled(false);                              //кнопка Следующее не активна
    nextButton->setDefault(false);                              //кнопка "Следующее" не будет активироваться при нажатии клавиши Enter.
    inputEdit->setEnabled(true);                                //поле ввода данных активно
    outputLabel->setVisible(false);                             //метка для вывода не видима
    outputEdit->setVisible(false);                              //поле вывода результата не видимо
    outputEdit->setEnabled(false);                              //поле с выводом результата не активно
    inputEdit->setFocus();                                      // курсор клавиатуры сразу устанавливается в поле ввода
}


Win::~Win()
{
    //delete ui;
}

