#include <QApplication>
#include "fenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString fileName;
    MaFenetre fenetre(fileName);
    fenetre.show();

    return app.exec();
}


