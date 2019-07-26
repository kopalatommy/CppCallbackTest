#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <functional>
#include <string>

#include "testa.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    std::string Init(std::function<std::string(void)> f){
        return f();
    }
    QString Init(std::function<QString(void)>f){
        return f();
    }
    /*void Init(std::function<void(void)>f){
        f();
    }*/
    void TestInit(std::function<void(void)>f){
        f();
    }
    void BoolTest(int count,...){
        va_list args;
        va_start(args, count);
        int index = 0;
        while (index < count) {
            index++;
            boolFunct(va_arg(args, bool));
        }
    }
    void ReceiveBoolFunct(std::function<void(bool)>f){
        boolFunct = f;
    }

private:
    Ui::MainWindow *ui;

    std::function<void(bool)> boolFunct;
};

#endif // MAINWINDOW_H
