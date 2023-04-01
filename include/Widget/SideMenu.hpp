/**
 * @file SideMenu.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SIDE_MENU_WIDGET_HPP
#define SIDE_MENUs_WIDGET_HPP

#include <QWidget>

namespace HMI
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
