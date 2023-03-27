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
