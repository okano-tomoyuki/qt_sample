/**
 * @file ActuatorWidget.hpp
 * @author okano tomoyuki (okano.development@gmail.com)
 * @brief アクチュエーター情報表示用ウィジェット
 * @version 0.1
 * @date 2023-03-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ACTUATOR_WIDGET_HPP
#define ACTUATOR_WIDGET_HPP

#include <QWidget>

namespace HumanMachineInterface
{

class ActuatorWidget : public QWidget
{
    Q_OBJECT

public:
    ActuatorWidget(QWidget* parent);
    ~ActuatorWidget();
};

}
#endif
