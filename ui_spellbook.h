/********************************************************************************
** Form generated from reading UI file 'spellbook.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPELLBOOK_H
#define UI_SPELLBOOK_H

//For MXE
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

// For local version
//#include <QtCore/QVariant>
//#include <QtWidgets/QAction>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QButtonGroup>
//#include <QtWidgets/QComboBox>
//#include <QtWidgets/QHeaderView>
//#include <QtWidgets/QLabel>
//#include <QtWidgets/QMainWindow>
//#include <QtWidgets/QMenuBar>
//#include <QtWidgets/QScrollArea>
//#include <QtWidgets/QStatusBar>
//#include <QtWidgets/QTableWidget>
//#include <QtWidgets/QToolBar>
//#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Spellbook
{
public:
    QWidget *centralWidget;
    QTableWidget *spellList;
    QLabel *nameLabel;
    QLabel *schoolLabel;
    QLabel *rangeLabel;
    QLabel *concentrationLabel;
    QLabel *ritualLabel;
    QLabel *durationLabel;
    QLabel *componentsLabel;
    QLabel *materialLabel;
    QLabel *levelLabel;
    QLabel *descriptionLabel;
    QComboBox *sort1Box;
    QLabel *sort1Label;
    QComboBox *sort2Box;
    QLabel *sort2Label;
    QLabel *classesLabel;
    QLabel *subclassesLabel;
    QLabel *filterLabel;
    QComboBox *filterBox;
    QScrollArea *descScrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *descriptionTitle;
    QLabel *castingTimeLabel;
    QLabel *pageLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Spellbook)
    {
        if (Spellbook->objectName().isEmpty())
            Spellbook->setObjectName(QString::fromUtf8("Spellbook"));
        Spellbook->resize(1225, 821);
        centralWidget = new QWidget(Spellbook);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        spellList = new QTableWidget(centralWidget);
        spellList->setObjectName(QString::fromUtf8("spellList"));
        spellList->setGeometry(QRect(50, 110, 431, 641));
        spellList->setLineWidth(1);
        spellList->setShowGrid(false);
        spellList->setGridStyle(Qt::NoPen);
        spellList->horizontalHeader()->setVisible(false);
        spellList->horizontalHeader()->setDefaultSectionSize(175);
        spellList->horizontalHeader()->setHighlightSections(false);
        spellList->horizontalHeader()->setStretchLastSection(true);
        spellList->verticalHeader()->setVisible(false);
        spellList->verticalHeader()->setHighlightSections(false);
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(499, 20, 671, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Chancery L"));
        font.setPointSize(30);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(7);
        nameLabel->setFont(font);
        nameLabel->setStyleSheet(QString::fromUtf8("font: 30pt \"Vivaldi\";\n"
"font: 57 italic 30pt \"URW Chancery L\";"));
        nameLabel->setAlignment(Qt::AlignCenter);
        schoolLabel = new QLabel(centralWidget);
        schoolLabel->setObjectName(QString::fromUtf8("schoolLabel"));
        schoolLabel->setGeometry(QRect(560, 106, 201, 21));
        rangeLabel = new QLabel(centralWidget);
        rangeLabel->setObjectName(QString::fromUtf8("rangeLabel"));
        rangeLabel->setGeometry(QRect(560, 171, 211, 17));
        rangeLabel->setTextFormat(Qt::AutoText);
        concentrationLabel = new QLabel(centralWidget);
        concentrationLabel->setObjectName(QString::fromUtf8("concentrationLabel"));
        concentrationLabel->setGeometry(QRect(560, 201, 141, 17));
        ritualLabel = new QLabel(centralWidget);
        ritualLabel->setObjectName(QString::fromUtf8("ritualLabel"));
        ritualLabel->setGeometry(QRect(800, 198, 171, 20));
        durationLabel = new QLabel(centralWidget);
        durationLabel->setObjectName(QString::fromUtf8("durationLabel"));
        durationLabel->setGeometry(QRect(560, 231, 281, 17));
        componentsLabel = new QLabel(centralWidget);
        componentsLabel->setObjectName(QString::fromUtf8("componentsLabel"));
        componentsLabel->setGeometry(QRect(560, 261, 181, 16));
        materialLabel = new QLabel(centralWidget);
        materialLabel->setObjectName(QString::fromUtf8("materialLabel"));
        materialLabel->setGeometry(QRect(560, 291, 641, 51));
        materialLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        materialLabel->setWordWrap(true);
        levelLabel = new QLabel(centralWidget);
        levelLabel->setObjectName(QString::fromUtf8("levelLabel"));
        levelLabel->setGeometry(QRect(790, 107, 121, 20));
        descriptionLabel = new QLabel(centralWidget);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));
        descriptionLabel->setGeometry(QRect(560, 441, 591, 301));
        descriptionLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        descriptionLabel->setWordWrap(true);
        sort1Box = new QComboBox(centralWidget);
        sort1Box->setObjectName(QString::fromUtf8("sort1Box"));
        sort1Box->setGeometry(QRect(60, 50, 111, 25));
        sort1Label = new QLabel(centralWidget);
        sort1Label->setObjectName(QString::fromUtf8("sort1Label"));
        sort1Label->setGeometry(QRect(60, 20, 81, 17));
        sort2Box = new QComboBox(centralWidget);
        sort2Box->setObjectName(QString::fromUtf8("sort2Box"));
        sort2Box->setGeometry(QRect(210, 50, 111, 25));
        sort2Label = new QLabel(centralWidget);
        sort2Label->setObjectName(QString::fromUtf8("sort2Label"));
        sort2Label->setGeometry(QRect(220, 20, 81, 17));
        classesLabel = new QLabel(centralWidget);
        classesLabel->setObjectName(QString::fromUtf8("classesLabel"));
        classesLabel->setGeometry(QRect(560, 351, 451, 17));
        subclassesLabel = new QLabel(centralWidget);
        subclassesLabel->setObjectName(QString::fromUtf8("subclassesLabel"));
        subclassesLabel->setGeometry(QRect(560, 381, 451, 17));
        filterLabel = new QLabel(centralWidget);
        filterLabel->setObjectName(QString::fromUtf8("filterLabel"));
        filterLabel->setGeometry(QRect(370, 20, 101, 17));
        filterBox = new QComboBox(centralWidget);
        filterBox->setObjectName(QString::fromUtf8("filterBox"));
        filterBox->setGeometry(QRect(370, 50, 101, 25));
        descScrollArea = new QScrollArea(centralWidget);
        descScrollArea->setObjectName(QString::fromUtf8("descScrollArea"));
        descScrollArea->setGeometry(QRect(560, 441, 591, 301));
        descScrollArea->setFrameShape(QFrame::NoFrame);
        descScrollArea->setLineWidth(0);
        descScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 591, 301));
        descScrollArea->setWidget(scrollAreaWidgetContents);
        descriptionTitle = new QLabel(centralWidget);
        descriptionTitle->setObjectName(QString::fromUtf8("descriptionTitle"));
        descriptionTitle->setGeometry(QRect(560, 411, 111, 20));
        castingTimeLabel = new QLabel(centralWidget);
        castingTimeLabel->setObjectName(QString::fromUtf8("castingTimeLabel"));
        castingTimeLabel->setGeometry(QRect(560, 140, 241, 21));
        pageLabel = new QLabel(centralWidget);
        pageLabel->setObjectName(QString::fromUtf8("pageLabel"));
        pageLabel->setGeometry(QRect(990, 110, 171, 17));
        Spellbook->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Spellbook);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 22));
        Spellbook->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Spellbook);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Spellbook->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Spellbook);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Spellbook->setStatusBar(statusBar);

        retranslateUi(Spellbook);

        QMetaObject::connectSlotsByName(Spellbook);
    } // setupUi

    void retranslateUi(QMainWindow *Spellbook)
    {
        Spellbook->setWindowTitle(QApplication::translate("Spellbook", "Spellbook", 0));
        nameLabel->setText(QString());
        schoolLabel->setText(QString());
        rangeLabel->setText(QString());
        concentrationLabel->setText(QString());
        ritualLabel->setText(QString());
        durationLabel->setText(QString());
        componentsLabel->setText(QString());
        materialLabel->setText(QString());
        levelLabel->setText(QString());
        descriptionLabel->setText(QString());
        sort1Label->setText(QApplication::translate("Spellbook", "Sort field 1", 0));
        sort2Label->setText(QApplication::translate("Spellbook", "Sort field 2", 0));
        classesLabel->setText(QString());
        subclassesLabel->setText(QString());
        filterLabel->setText(QApplication::translate("Spellbook", "Filter by class", 0));
        descriptionTitle->setText(QString());
        castingTimeLabel->setText(QString());
        pageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Spellbook: public Ui_Spellbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPELLBOOK_H
