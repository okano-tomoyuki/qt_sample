/**
 * @file Actuator.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ACTUATOR_WIDGET_HPP
#define ACTUATOR_WIDGET_HPP

#include <QWidget>

namespace HMI
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
