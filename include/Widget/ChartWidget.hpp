#ifndef CHART_WIDGET_HPP
#define CHART_WIDGET_HPP

#include <QWidget>

namespace HumanMachineInterface
{

class ChartWidget : public QWidget
{
    Q_OBJECT

public:
    ChartWidget(QWidget* parent);
    ~ChartWidget();
};

}
#endif
