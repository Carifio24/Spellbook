#include "spellbook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Spellbook w;
    w.show();

    return a.exec();
}
