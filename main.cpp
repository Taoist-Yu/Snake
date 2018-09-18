#include "GameWidget.h"
#include <QApplication>

#include<ctime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    srand((unsigned)time(NULL));

    GameWidget w;
    w.show();

    return app.exec();
}
