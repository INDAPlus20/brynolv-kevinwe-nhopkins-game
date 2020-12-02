#include "mainwindow.h"

#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <Qt>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTableWidget *table = new QTableWidget(15, 15);
    for (int r = 0; r < 15; r++) {
        for (int c = 0; c < 15; c++) {
             QTableWidgetItem *item = new QTableWidgetItem(QString("Set in main to r=%1, c=%2").arg(r).arg(c));
             table->setItem(r, c, item);
             item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        }
    }
    table->show();
    return a.exec();
}
