#ifndef SIDE_MENU_H
#define SIDE_MENU_H

#include <QWidget>
#include <QMainWindow>

namespace HumanMachineInterface
{

class SideMenu : public QWidget
{
    Q_OBJECT

public:
    SideMenu(QWidget* parent);
    ~SideMenu();
};

}
#endif
