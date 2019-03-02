#include "qgameboard.h"
#include "qmainwindow.h"
#include <QApplication>
#include "tile.h"
#include "qtile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(nullptr));

    QMainWindow window;
    window.show();
}
