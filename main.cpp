#include "mainwindow.hpp"

#include <QApplication>

#include <QWidget>
#include <QPushButton>

#include "DBsource/DBTypes.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DBDate date = "2002-12-20";
    QPushButton *button = new QPushButton(date.GetValue(), &w);
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));

    button->show();
    w.show();
    return a.exec();
}
