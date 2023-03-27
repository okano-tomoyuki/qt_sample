#ifndef ALERT_LOG_WIDGET_HPP
#define ALERT_LOG_WIDGET_HPP

#include <QWidget>

namespace HumanMachineInterface
{

class AlertLogWidget : public QWidget
{
    Q_OBJECT

public:
    AlertLogWidget(QWidget* parent);
    ~AlertLogWidget();
};

}
#endif