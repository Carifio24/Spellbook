#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <QMainWindow>
#include <QModelIndex>
#include "Classes.h"

namespace Ui {
class Spellbook;
}

class Spellbook : public QMainWindow
{
    Q_OBJECT

public:
    explicit Spellbook(QWidget *parent = 0);
    ~Spellbook();
    std::vector<Spell> spellsList() {return spells;}

private slots:
    void on_spellList_clicked(const QModelIndex &index);

    void on_sort1Box_currentIndexChanged(const QString &arg1);

    void on_sort2Box_currentIndexChanged(const QString &arg1);

    void on_spellList_cellActivated(int row, int column);

    void on_spellList_cellEntered(int row, int column);

    void on_filterBox_currentIndexChanged(int index);

    void on_spellList_entered(const QModelIndex &index);

    void on_spellList_activated(const QModelIndex &index);

    void on_spellList_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    Ui::Spellbook *ui;
    std::vector<Spell> spells;
    void sort(const std::string& sort_field1, const std::string& sort_field2);
    void display_spelldata(const int& ind);
};

#endif // SPELLBOOK_H
