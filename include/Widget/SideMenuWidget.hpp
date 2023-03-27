#ifndef SIDE_MENU_WIDGET_HPP
#define SIDE_MENU_WIDGET_HPP

#include <QWidget>

namespace HumanMachineInterface
{

class SideMenuWidget : public QWidget
{
    Q_OBJECT

public:
    SideMenuWidget(QWidget* parent);
    ~SideMenuWidget();
};

}
#endif
