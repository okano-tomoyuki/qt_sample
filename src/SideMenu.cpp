#include "SideMenu.hpp"
#include <QWidget>
#include <QPushButton>
#include <QApplication>

using namespace HumanMachineInterface;

SideMenu::SideMenu(QWidget* parent)
{
    QPushButton *button = new QPushButton(QApplication::translate("childwidget", "Close"), this);
    QObject::connect(button, SIGNAL(clicked(bool)), parent, SLOT(close()));
    button->move(10, 80);
    button->show();
}


SideMenu::~SideMenu()
{

}