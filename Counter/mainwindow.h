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

class Counter: public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString &contents, QWidget *parent = 0):
        QLineEdit(contents, parent){}  // конструктор с параметрами
signals:
    void tick_signal();
public slots:
    void add_one(){
        QString str = text();
        int r = str.toInt();
        if(r !=0 && r%5 == 0){
            emit tick_signal();
        }
        r++;
        str.setNum(r);
        setText(str);
    }
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    QTextCodec *codec;
    QLabel *label, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
