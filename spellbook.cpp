#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "spellbook.h"
#include "ui_spellbook.h"
#include "Classes.h"
#include "Parse.h"
#include "Sort.h"
#include "Filter.h"
#include "jsoncpp/json/json.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <QFile>

Spellbook::Spellbook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Spellbook)
{
    ui->setupUi(this);

    // Set the title
    setWindowTitle(QString::fromStdString("D&D 5th edition spellbook"));

    // Set the background image
    QPixmap bkgnd(":/resources/BookBackground.jpeg");
    bkgnd = bkgnd.scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->descScrollArea->setStyleSheet("background-color:transparent");
    ui->spellList->setStyleSheet("background-color:transparent");
    ui->favButton->setStyleSheet("background-color:transparent");
    //ui->searchBar->setStyleSheet("background-color:rgb(231,208,166);");


    // Set the table widget to highlight its entire row
    ui->spellList->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Set the table headers
    QStringList headers = {"Name", "School", "Level"};
    //ui->spellList->setHorizontalHeaderLabels(headers);
//    for (int i = 0; i < headers.size(); i++) {
//        ui->spellList->setHorizontalHeaderItem(i, new QTableWidgetItem(headers[i]));
//    }
    //ui->spellList->horizontalHeader()->setVisible(true);


    // Read and parse the spell list
    //std::string filename = "5e-SRD-Spells.json";
    QFile qspellfile(":/resources/Spells.json");
    qspellfile.open(QIODevice::ReadOnly);
    spells = read_spellfile(&qspellfile);
    qspellfile.close();

    // Add the spells to the QTableWidget and display them
    ui->spellList->setRowCount(spells.size());
    ui->spellList->setColumnCount(3);
    for (int i = 0; i < spells.size(); i++) {
        ui->spellList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(spells[i].name)));
        ui->spellList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(schoolNames[static_cast<int>(spells[i].school)])));
        ui->spellList->setItem(i,2,new QTableWidgetItem(QString::number(spells[i].level)));
    }

    // Add the "None" option for the second sort ComboBox
    ui->sort2Box->addItem(QString::fromStdString("None"));

    // Add the options to the sort ComboBoxes
    for (int i = 0; i < N_SORTABLE; i++) {
        ui->sort1Box->addItem(QString::fromStdString(sortablePropertyNames[i]));
        ui->sort2Box->addItem(QString::fromStdString(sortablePropertyNames[i]));
    }

    // Set the Name option on the second sort box to be red, as this is the starting selection for the first sort box
    ui->sort2Box->setItemData(1, QBrush(Qt::red), Qt::TextColorRole);

    // Add the class and subclass names to the filter ComboBox
    ui->filterBox->addItem(QString::fromStdString("None"));
    for (const std::string& cname : casterNames) {
        ui->filterBox->addItem(QString::fromStdString(cname));
    }

    /*
    for (const std::string& sname : subclassNames) {
        ui->filterBox->addItem(QString::fromStdString(sname));
    }
    */

    // Put the description label inside the scroll area
    ui->descScrollArea->setWidget(ui->descriptionLabel);

    // Font settings
    QString fontstyle = QString::fromStdString("font-weight: 750");
    ui->sort1Label->setStyleSheet(fontstyle);
    ui->sort2Label->setStyleSheet(fontstyle);
    ui->filterLabel->setStyleSheet(fontstyle);

    // Make the table view not editable
    ui->spellList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Make the labels selectable
    ui->nameLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->schoolLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->ritualLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->concentrationLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->levelLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->rangeLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->descriptionTitle->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->descriptionLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->durationLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->componentsLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->castingTimeLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->pageLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->materialLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->classesLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);

    // Create the button pixmaps
    star_empty = QPixmap(":/resources/star_empty.png");
    star_filled = QPixmap(":/resources/star_filled_2.png");
    fav_icon = QIcon(star_filled);
    not_fav_icon = QIcon(star_empty);

    // Load favorites
    load_favorites();

}

Spellbook::~Spellbook()
{
    delete ui;
}

void Spellbook::display_spelldata(const int& ind) {
    // Get the spell
    Spell spell = spellsList()[ind];
    // Create the display text
    QString nameText = QString::fromStdString(spell.name);
    QString schoolText = "<b>School: </b>" + QString::fromStdString(schoolNames[static_cast<int>(spell.school)]);
    QString ritualText = "<b>Ritual: </b>" + QString::fromStdString(bool_to_yn((spell.ritual)));
    QString concentrationText = "<b>Concentration: </b>" + QString::fromStdString(bool_to_yn(spell.concentration));
    QString levelText = "<b>Level: </b>" + QString::fromStdString(std::to_string(spell.level));
    QString rangeText = "<b>Range: </b>" + QString::fromStdString(spell.range);
    QString descTitleText = "<b>Description:</b>";
    QString descriptionText = QString::fromStdString(spell.description + "\n\n" + spell.higherLevel);
    QString durationText = "<b>Duration: </b>" + QString::fromStdString(spell.duration);
    QString castingTimeText = "<b>Casting Time: </b>" + QString::fromStdString(spell.castingTime);
    QString pageText = "<b>Location: </b> PHB " + QString::fromStdString(std::to_string(spell.page));
    std::string compStr = "";
    if (spell.components[0]) {
        compStr += "V";
    }
    if (spell.components[1]) {
        compStr += "S";
    }
    if (spell.components[2]) {
        compStr += "M";
    }
    QString compText = "<b>Components: </b>" + QString::fromStdString(compStr);
    QString materialText;
    if (spell.components[2]) {
        materialText = "<b>Materials:\n</b>" + QString::fromStdString(spell.material);
    } else {
        materialText = "";
    }

    std::string classesString;
    QString classesText;
    for (const CasterClass& cclass : spell.classes) {
        classesString += casterNames[static_cast<int>(cclass)];
        classesString += ", ";
    }
    if (spell.classes.size() > 0) {
        classesString.erase(classesString.end()-2,classesString.end());
        classesText = "<b>Classes: </b>" + QString::fromStdString(classesString);
    } else {
        classesText = "";
    }

    /*
    std::string subclassesString;
    QString subclassesText;
    for (const Subclass& sclass : spell.subclasses) {
        subclassesString += subclassNames[static_cast<int>(sclass)];
        subclassesString += ", ";
    }
    if (spell.subclasses.size() > 0) {
        subclassesString.erase(subclassesString.end()-2,subclassesString.end());
        subclassesText = "<b>Subclasses: </b>" + QString::fromStdString(subclassesString);
    } else {
        subclassesText = "";
    }
    */

    // Add the appropriate text to the labels
    ui->nameLabel->setText(nameText);
    ui->schoolLabel->setText(schoolText);
    ui->ritualLabel->setText(ritualText);
    ui->concentrationLabel->setText(concentrationText);
    ui->levelLabel->setText(levelText);
    ui->rangeLabel->setText(rangeText);
    ui->descriptionTitle->setText(descTitleText);
    ui->descriptionLabel->setText(descriptionText);
    ui->durationLabel->setText(durationText);
    ui->componentsLabel->setText(compText);
    ui->castingTimeLabel->setText(castingTimeText);
    ui->pageLabel->setText(pageText);
    ui->materialLabel->setText(materialText);
    ui->classesLabel->setText(classesText);
    //ui->subclassesLabel->setText(subclassesText);

    // Show the favorite button image
    update_button();
}

void Spellbook::on_spellList_clicked(const QModelIndex &index)
{
    display_spelldata(index.row());
}

void Spellbook::on_spellList_cellActivated(int row, int column)
{
    //display_spelldata(row);
    ;
}

void Spellbook::on_spellList_entered(const QModelIndex &index)
{
    //display_spelldata(index.row());
    ;
}

void Spellbook::on_spellList_activated(const QModelIndex &index)
{
;
}

void Spellbook::sort(const std::string& sort_field1, const std::string& sort_field2) {

    // Do the appropriate sorting
    // No two spells have the same name, so we don't need the double sort in that case
    if ( (sort_field2 == "None") || (sort_field1 == "Name") || (sort_field1 == sort_field2) ) {
        if (sort_field1 == "Name") {
            auto mvc = MemValComp<std::string>(&Spell::name);
            mvc.doSort(spells);
        }
        if (sort_field1 == "Level") {
            auto mvc = MemValComp<int>(&Spell::level);
            mvc.doSort(spells);
        }
        if(sort_field1 == "School") {
            auto mvc = MemValComp<School>(&Spell::school);
            mvc.doSort(spells);
        }
    } else {
        if (sort_field1 == "Name" && sort_field2 == "Level") {
            auto mvc = MemValTwoComp<std::string, int>(&Spell::name, &Spell::level);
            mvc.doSort(spells);
        }
        if (sort_field1 == "Name" && sort_field2 == "School") {
            auto mvc = MemValTwoComp<std::string, School>(&Spell::name, &Spell::school);
            mvc.doSort(spells);
        }
        if (sort_field1 == "Level" && sort_field2 == "School") {
            auto mvc = MemValTwoComp<int, School>(&Spell::level, &Spell::school);
            mvc.doSort(spells);
        }
        if (sort_field1 == "Level" && sort_field2 == "Name") {
            auto mvc = MemValTwoComp<int, std::string>(&Spell::level, &Spell::name);
            mvc.doSort(spells);
        }
        if (sort_field1 == "School" && sort_field2 == "Name") {
            auto mvc = MemValTwoComp<School, std::string>(&Spell::school, &Spell::name);
            mvc.doSort(spells);
        }
        if (sort_field1 == "School" && sort_field2 == "Level") {
            auto mvc = MemValTwoComp<School, int>(&Spell::school, &Spell::level);
            mvc.doSort(spells);
        }
    }

    // Clear the QListWidget and repopulate with the sorted list
    for (int i = 0; i < spells.size(); i++) {
        //std::cout << i << std::endl;
        ui->spellList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(spells[i].name)));
        ui->spellList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(schoolNames[static_cast<int>(spells[i].school)])));
        ui->spellList->setItem(i,2,new QTableWidgetItem(QString::number(spells[i].level)));
    }

    // Redo hiding, if necessary
    int index = ui->filterBox->currentIndex();
    on_filterBox_currentIndexChanged(index);
}

void Spellbook::on_sort1Box_currentIndexChanged(const QString &arg1)
{

    // Set the appropriate second sort to be greyed out, make all others black
    int index = ui->sort1Box->currentIndex();
    for (int i = 0; i < ui->sort2Box->count(); i++) {
        if (i != index+1) {
            ui->sort2Box->setItemData(i, QBrush(Qt::black), Qt::TextColorRole);
        } else {
            ui->sort2Box->setItemData(i, QBrush(Qt::red), Qt::TextColorRole);
        }
    }

    // Get the sort fields
    std::string sort_field1 = arg1.toStdString();
    std::string sort_field2 = ui->sort2Box->currentText().toStdString();

    // Sort
    sort(sort_field1, sort_field2);

}

void Spellbook::on_sort2Box_currentIndexChanged(const QString &arg1)
{

    // If this entry is greyed out, do nothing
    int index1 = ui->sort1Box->currentIndex();
    int index2 = ui->sort2Box->currentIndex();
    if (index2 == index1 + 1) {return;}

    // If the entry is set to None, do nothing
    if (arg1.toStdString() == "None") {return;}

    // Get the sort fields
    std::string sort_field1 = ui->sort1Box->currentText().toStdString();
    std::string sort_field2 = arg1.toStdString();

    // Sort
    sort(sort_field1, sort_field2);
}



void Spellbook::on_spellList_cellEntered(int row, int column)
{
    //display_spelldata(row);
}

void Spellbook::on_filterBox_currentIndexChanged(int index)
{
    filter();
}

bool Spellbook::filter_item(const bool& isClass, const bool& isFav, const bool& isText, const Spell& s, const CasterClass& cc, const std::string& text) {
    bool toHide = false;
    std::string spname = s.name;
    boost::to_lower(spname);
    toHide = toHide || (isClass && !usableByClass(s, cc));
    toHide = toHide || (isFav && !s.favorite);
    toHide = toHide || (isText && !boost::contains(spname, text));
    return toHide;
}


//void Spellbook::filter_by_class(const CasterClass& cc) {
//    for (int i = 0; i < spells.size(); i++) {
//        if (usableByClass(spells[i], cc)) {
//            ui->spellList->setRowHidden(i, false);
//        } else {
//            ui->spellList->setRowHidden(i, true);
//        }
//    }
//}

//void Spellbook::filter_with_favorites(const CasterClass& cc) {
//    for (int i = 0; i < spells.size(); i++) {
//        if (usableByClass(spells[i], cc) && spells[i].favorite) {
//            ui->spellList->setRowHidden(i, false);
//        } else {
//            ui->spellList->setRowHidden(i, true);
//        }
//    }
//}

//void Spellbook::filter_favorites() {
//    for (int i = 0; i < spells.size(); i++) {
//        if (spells[i].favorite) {
//            ui->spellList->setRowHidden(i, false);
//        } else {
//            ui->spellList->setRowHidden(i, true);
//        }
//    }
//}

void Spellbook::filter() {
    int classIndex = ui->filterBox->currentIndex();
    bool isClass = (classIndex != 0);
    CasterClass cc;
    if (isClass) {
        cc = static_cast<CasterClass>(classIndex-1);
    } else {
        cc = static_cast<CasterClass>(0);
    }
    bool favorites = ui->favoritesButton->isChecked();
    std::string searchText = ui->searchBar->text().toStdString();
    boost::to_lower(searchText);
    bool isText = (searchText != "");
    if (!(isText || favorites || isClass) ) {
        unfilter();
    } else {
        for (int i = 0; i < spells.size(); i++) {
            ui->spellList->setRowHidden(i, filter_item(isClass, favorites, isText, spells[i], cc, searchText));
        }
    }
//    if (isClass && favorites) {
//        filter_with_favorites(static_cast<CasterClass>(classIndex-1));
//    } else if (isClass) {
//        filter_by_class(static_cast<CasterClass>(classIndex-1));
//    } else if (favorites) {
//        filter_favorites();
//    } else {
//        unfilter();
//    }
}

void Spellbook::on_spellList_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    display_spelldata(currentRow);
}

void Spellbook::on_favoritesButton_clicked()
{
    filter();
}

void Spellbook::unfilter() {
    for (int i = 0; i < spells.size(); i++) {
        ui->spellList->setRowHidden(i, false);
    }
}

void Spellbook::save_favorites() {
    std::ofstream ofs{favorites_file};
    for (int i = 0; i < spells.size(); i++) {
        if (spells[i].favorite) {
            ofs << spells[i].name << std::endl;
        }
    }
}

void Spellbook::load_favorites() {
    std::string line;
    std::ifstream ifs{favorites_file};
    while (std::getline(ifs, line)) {
        bool inSpellbook = false;
        for (int i = 0; i < spells.size(); i++) {
            if (line == spells[i].name) {
                spells[i].favorite = true;
                inSpellbook = true;
                break;
            }
        }

        if (!inSpellbook) {
            throw std::runtime_error("Bad spell name!");
        }
    }
}

void Spellbook::on_favoritesButton_released()
{
    filter();
}

void Spellbook::update_button() {
    int index = ui->spellList->currentRow();
    Spell s = spells[index];
    if (s.favorite) {
        ui->favButton->setIcon(fav_icon);
    } else {
        ui->favButton->setIcon(not_fav_icon);
    }
    ui->favButton->setIconSize(QSize(iconSize,iconSize));
}

void Spellbook::on_favButton_clicked()
{
    int index = ui->spellList->currentRow();
    spells[index].favorite = !spells[index].favorite;
    update_button();
    save_favorites();

    if (ui->favoritesButton->isChecked()) {
        filter();
    }
}

void Spellbook::on_searchBar_textEdited(const QString &arg1)
{
    filter();
}
