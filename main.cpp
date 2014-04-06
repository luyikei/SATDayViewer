#include "satdayviewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SATDayViewer w;
    w.show();

    return a.exec();
}
