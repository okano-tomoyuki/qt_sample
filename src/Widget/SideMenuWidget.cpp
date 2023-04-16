/**
 * @file SideMenuWidget.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Widget/SideMenu.hpp"
#include "Dialog/SemiFallback.hpp"

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QLineEdit>
#include <QTreeWidget>

using namespace HMI;

SideMenuWidget::SideMenuWidget(QWidget* parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    auto vBoxlay = new QVBoxLayout(this);
    vBoxlay->setContentsMargins(0,0,0,0);

    auto title = new QLabel("Menu",this);
    title->setObjectName("Title");

    auto button = new QPushButton(QApplication::translate("childwidget", "Semi Fallback"), this);
    button->setObjectName("SemiFallback");

    // QObject::connect(button, SIGNAL(clicked(bool)), parent, SLOT(close()));
    QObject::connect(button, SIGNAL(clicked(bool)), this, SLOT(openSemiFallbackDialog()));

    auto navModeComboBox = new QComboBox(this);
    QList<QString> navModeNameList = {  
                                        "Unberthing",
                                        "Leaving", 
                                        "Harbor Out", 
                                        "Coastal", 
                                        "Ocean", 
                                        "Habor In", 
                                        "Approaching", 
                                        "Berthing"
                                    };
    
    for (auto navModeName: navModeNameList){
        navModeComboBox->addItem(navModeName);
    }
    connect(navModeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));

    /** Own Ship Info items are defined below. */
    auto ownShipInfoGroupBox = new QGroupBox("Own Ship Info", this);
    auto ownShipInfoLayout = new QGridLayout(ownShipInfoGroupBox);
    auto ownShipVelocityLabel = new QLabel("Velocity", this);
    auto ownShipVelocityValue = new QLineEdit("XXX.XX", this);
    ownShipVelocityValue->setReadOnly(true);
    ownShipVelocityValue->setAlignment(Qt::AlignRight);
    auto ownShipVelocityUnitLabel = new QLabel("knot", this);
    auto ownShipDirectionLabel = new QLabel("Direction", this);
    auto ownShipDirectionValue = new QLineEdit("XXX.XX", this);
    ownShipDirectionValue->setReadOnly(true);
    ownShipDirectionValue->setAlignment(Qt::AlignRight);
    auto ownShipDirectionUnitLabel = new QLabel("degree", this);
    ownShipInfoGroupBox->setObjectName("OwnShipInfo");
    ownShipInfoLayout->addWidget(ownShipVelocityLabel, 0, 0);
    ownShipInfoLayout->addWidget(ownShipVelocityValue, 0, 1);
    ownShipInfoLayout->addWidget(ownShipVelocityUnitLabel, 0, 2);
    ownShipInfoLayout->addWidget(ownShipDirectionLabel, 1, 0);
    ownShipInfoLayout->addWidget(ownShipDirectionValue, 1, 1);
    ownShipInfoLayout->addWidget(ownShipDirectionUnitLabel, 1, 2);


    /** Disturb Info items are defined below. */
    auto disturbInfoGroupBox = new QGroupBox("Disturbance Info", this);
    auto disturbInfoLayout = new QGridLayout(disturbInfoGroupBox);
    auto windInfoLabel = new QLabel("Wind", this);
    auto windVelocityLabel = new QLabel("  Velocity", this);
    auto windVelocityValue = new QLineEdit("XXX.XX", this);
    windVelocityValue->setReadOnly(true);
    windVelocityValue->setAlignment(Qt::AlignRight);
    auto windVelocityUnitLabel = new QLabel("knot", this);
    auto windDirectionLabel = new QLabel("  Direction", this);
    auto windDirectionValue = new QLineEdit("XXX.XX", this);
    windDirectionValue->setReadOnly(true);
    windDirectionValue->setAlignment(Qt::AlignRight);
    auto windDirectionUnitLabel = new QLabel("degree", this);
    disturbInfoLayout->addWidget(windInfoLabel, 0, 0);
    disturbInfoLayout->addWidget(windVelocityLabel, 1, 0);
    disturbInfoLayout->addWidget(windVelocityValue, 1, 1);
    disturbInfoLayout->addWidget(windVelocityUnitLabel, 1, 2);
    disturbInfoLayout->addWidget(windDirectionLabel, 2, 0);
    disturbInfoLayout->addWidget(windDirectionValue, 2, 1);
    disturbInfoLayout->addWidget(windDirectionUnitLabel, 2, 2);

    /** Tree View items are defined below.*/
    auto menuTree = new QTreeWidget(this);
    menuTree->setHeaderHidden(true);
    auto a = new QTreeWidgetItem({"A"});
    a->addChild(new QTreeWidgetItem({"A-1"}));
    a->addChild(new QTreeWidgetItem({"A-2"}));
    auto b = new QTreeWidgetItem({"B"});
    b->addChild(new QTreeWidgetItem({"B-1"}));
    b->addChild(new QTreeWidgetItem({"B-2"}));
    menuTree->addTopLevelItems({a, b});
    menuTree->show();


    vBoxlay->addWidget(title);
    vBoxlay->addWidget(button);
    vBoxlay->addWidget(navModeComboBox);
    vBoxlay->addWidget(ownShipInfoGroupBox);
    vBoxlay->addWidget(disturbInfoGroupBox);
    vBoxlay->addWidget(menuTree);
    vBoxlay->addStretch();

    this->setStyleSheet(
        "QLabel {"
            "color:white;"
            "font-size:18px;"
        "}"
        "QLineEdit {"
            "color:white;"
            "text-align:right;"
            "background-color:black;"
            "border-style:none;"
            "font-size:18px;"
        "}"
        "QTreeWidget {"
            "color:white;"
            "text-align:right;"
            "background-color:black;"
            "border-style:none;"
            "font-size:18px;"
        "}"
        "QLabel#Title {"
            "background-color:darkblue;"
            "color:white;"
            "font-size:36px;"
            "padding:4px;"
        "}"
        "QPushButton#SemiFallback {"
            "margin:5px;"
            "border-style:none;"
            "color:black;"
            "background:qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 yellow, stop:1 orange);"
            "border-radius:10px;"
            "font-size:24px;"
            "width:100px;"
            "height:45px;"
            "padding:2px;"
        "}"
        "QPushButton#SemiFallback:hover {"
            "color:black;"
            "background-color:white;"
        "}"
        "QPushButton#SemiFallback:pressed {"
            "background-color:white;"
        "}"
        "QGroupBox{"
            "color:white;"
            "font-size:18px;"
        "}"
        "QGroupBox:title{"
            "color:white;"
            "font-size:18px;"
            "subcontrol-origin:margin;"
            "subcontrol-position:top left;"
            "padding:3px 3px;"
        "}"
        "QComboBox {"
            "margin:5px;"
            "color:black;"
            "border-radius:5px;"
            "font-size:18px;"
            "height:24px;"
            "padding:2px;"
        "}"
    );

}


SideMenuWidget::~SideMenuWidget()
{

}

void SideMenuWidget::openSemiFallbackDialog()
{
    auto semiFallbackDialog = new SemiFallbackDialog(this);
    semiFallbackDialog->show();

}