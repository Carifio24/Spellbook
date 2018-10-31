#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <QMainWindow>
#include <QModelIndex>
#include <QPixmap>
#include <QIcon>
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

    void on_favoritesButton_clicked();

    void on_favoritesButton_released();

    void on_favButton_clicked();

private:

    void filter_by_class(const CasterClass& cc);

    void filter_favorites();

    void filter_with_favorites(const CasterClass& cc);

    void filter();

    void save_favorites();

    void load_favorites();

    void unfilter();

    void update_button();

    Ui::Spellbook *ui;
    std::vector<Spell> spells;
    void sort(const std::string& sort_field1, const std::string& sort_field2);
    void display_spelldata(const int& ind);
    std::string favorites_file = "Favorites.txt";
    QPixmap star_empty;
    QPixmap star_filled;
    QIcon fav_icon;
    QIcon not_fav_icon;
    int iconSize = 40;
};

#endif // SPELLBOOK_H
