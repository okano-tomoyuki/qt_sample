#include "SideMenu.hpp"
#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QComboBox>

using namespace HumanMachineInterface;

SideMenu::SideMenu(QWidget* parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    QVBoxLayout* vBoxlay = new QVBoxLayout(this);
    vBoxlay->setContentsMargins(0,0,0,0);

    QLabel* title = new QLabel("XXXXX",this);
    title->setObjectName("Title");

    QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Close"), this);
    QObject::connect(button, SIGNAL(clicked(bool)), parent, SLOT(close()));

    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItem("First");
    comboBox->addItem("Second");
    comboBox->addItem("Third");
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleSelectionChanged(int)));   

    vBoxlay->addWidget(title);
    vBoxlay->addWidget(button);
    vBoxlay->addWidget(comboBox);
    vBoxlay->addStretch(); 

    this->setStyleSheet(
        "QLabel#Title {background-color:darkblue;color:white;font-size:36px;padding:4px;}"
        "QPushButton {margin:5px;color:white;background:qlineargradient( x1:0 y1:0, x2:1 y2:1, stop:0 cyan, stop:1 blue);border-radius:5px;font-size:24px;width:100px;height:30px;padding:2px;}"
        "QPushButton:hover {color:black;background-color:white;}"
        "QPushButton:pressed {background-color:white;}"
        "QComboBox {margin:5px;color:black;border-radius:5px;font-size:18px;height:24px;padding:2px;}"
    );

}


SideMenu::~SideMenu()
{

}