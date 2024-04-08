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
    QObject::connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
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

void Win::calc()
{
    bool Ok=true; float r,a;                                    // Параметр &Ok в то же время предоставляет информацию о том, успешно ли прошла операция конвертации.
    QString str=inputEdit->text();                              //сохраняем считанные данные в строку str
    a=str.toDouble(&Ok);                                        //преверка, что в строке было действительно число, сохраняем в переменную а
    if (Ok)                                                     // Код, который выполняется, если конвертация прошла успешно
    {
        r=a*a;                                                  // квадрат числа
        str.setNum(r);                                          // в строку записываем результат
        outputEdit->setText(str);                               // резултат выводим в строку вывода
        inputEdit->setEnabled(false);                           // СТРОКА ВВОДА НЕ АКТИВНА
        outputLabel->setVisible(true);                          //метка вывода данных становится видима
        outputEdit->setVisible(true);                           // резултат видим
        nextButton->setDefault(true);                           //кнопка Следующий может активировтаься по нажатию на клавишу Enter
        nextButton->setEnabled(true);                           //кнопка может быть нажата
        nextButton->setFocus();                                 //курсор клавиатуры указывает на кнопку Следующий
    }
    else                                                        // Код, который выполняется, если конвертация не удалась
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               QString::fromUtf8("Возведение в квадрат."),
                               QString::fromUtf8("Введено неверное значение."),
                               QMessageBox::Ok);
        msgBox.exec();
    }
}
Win::~Win()
{
    //delete ui;
}

