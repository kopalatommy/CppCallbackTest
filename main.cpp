#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include <functional>
#include <string>

#include "testa.h"

QString NonMemberCallBack()
{
    return "Non member function";
}

void test(){
    qDebug() << "No return type";
}

QString ToQString(std::string str){
    QString toReturn;
    for(int i = 0; i < str.length(); i++){
        toReturn.append(str.at(i));
    }
    return toReturn;
}

void boolTest(bool val){
    qDebug() << "Received: " << val;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MainWindow mainWindow;

    auto callback1 = std::bind(&NonMemberCallBack);
    //qDebug() << "Callback 1: " << ToQString(mainWindow.Init(callback1));
    qDebug() << "Callback 1: " << mainWindow.Init(callback1);

    auto callback2 = std::bind(&TestA::StaticCallback);
    qDebug() << "Callback 2: " << ToQString(mainWindow.Init(callback2));

    // Class instance is passed to std::bind as second argument.
    // (heed that I call the constructor of CLoggersInfra)
    auto callback3 = std::bind(&TestA::NonstaticCallback,
                               TestA());
    qDebug() << "Callback 3: " << ToQString(mainWindow.Init(callback3));

    auto callback4 = std::bind(&test);
    mainWindow.TestInit(callback4);
    callback4();

    mainWindow.ReceiveBoolFunct(&boolTest);
    mainWindow.BoolTest(8, true, false, true, false, true, true, false, false);

    return a.exec();
}
