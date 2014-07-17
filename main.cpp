#include "ui/mainwindow.h"
#include "network/httpsclient.h"
#include <QApplication>
//#include "qwet.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //QWET w;
    w.show();
    return a.exec();
}
