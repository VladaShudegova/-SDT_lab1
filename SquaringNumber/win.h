#ifndef WIN_H       // макрос избавляющий от ошибки повторной компиляции файла
#define WIN_H

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE  // Начало пространства имен Qt, которое содержит общие для всего фреймворка функции и структуры данных
namespace Ui    // Внешнее пространство имен Ui используется для хранения классов, связанных с графическим интерфейсом, созданным в Qt Designer
{
    class Win;  // Класс Win представляет графический интерфейс приложения, размеченный в Qt Designer
}
QT_END_NAMESPACE    // Конец пространства имен Qt

class Win : public QWidget
{
    Q_OBJECT    //макрос Qt, обеспечивающий корректное создание сигналов и слотов

protected:
    QTextCodec *codec;      // Перекодировщик текста(русификация интерфейса)
    QFrame *frame; // Рамка для выделения(графического) областиввода данных
    QLabel *inputLabel; // Метка для поля ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // Метка для поля вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // Кнопка "Следующее"
    QPushButton *exitButton; // Кнопка "Выход"


public:
    Win(QWidget *parent = 0);   // конструктор окна с параметром, указывающим на родительский виджет, по умолчанию стоит 0, который означет, что данное окно является корневым
    ~Win();


//public slots:
//    void begin(); // метод начальной настройки интерфейса
//    void calc(); // метод реализации вычислений(возведения в квадрат введенного числа)

//private:
  //  Ui::Win *ui;
};
#endif // WIN_H
