#include "mainwindow.h"
#include "map.h"

#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <Qt>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	QTableWidget *table = new QTableWidget(10, 10);
	Map map=Map(10);
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) {
			 QTableWidgetItem *item = new QTableWidgetItem(map.getTile(r,c)->getDisplay());
			 table->setItem(r, c, item);
			 item->setFlags(item->flags() ^ Qt::ItemIsEditable);
		}
	}
	table->show();
	return a.exec();
}
