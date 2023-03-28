/**
 * @file SideMenuWidget.hpp
 * @author okano tomoyuki (okano.development@gmail.com)
 * @brief サイドメニュー用ウィジェット
 * @version 0.1
 * @date 2023-03-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
