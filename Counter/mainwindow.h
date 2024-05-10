#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QLineEdit>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <limits.h>



// приложение, которое считает отдельные нажатия на
//кнопку и серии по пять нажатий

class Counter: public QLineEdit
{
    Q_OBJECT

public:
    Counter(const QString &contents, QWidget *parent = 0):
        QLineEdit(contents, parent){}  // конструктор с параметрами инициализирует базовый класс QLineEdit с этими параметрами
    //Создает строку,
    //содержащую текстовое содержимое в качестве дочернего элемента
    //Позиция курсора устанавливается в конец строки, а максимальная длина текста — 32767 символов.


signals:
    void tick_signal();

public slots:
    void add_one(){
        QString str = text(); //свойство text() содержит текст  line edit
        int r = str.toInt();

        if(r < INT_MAX){
            r++;
            if(r !=0 && r % 5 == 0){    //проверка на новое нажатие и на серию из 5 нажатий
                emit tick_signal();
                }
        }
        else{
            r = 0;
        }
        str.setNum(r);  //перевод числа в строку
        setText(str);   //устанавливает текст виджета QLineEdit равным строке str, обновляя отображаемое содержимое этого виджета.

    }
};


class MainWindow : public QWidget
{
    Q_OBJECT

protected:
    QTextCodec *codec;
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
