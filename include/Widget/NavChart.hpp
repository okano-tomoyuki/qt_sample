/**
 * @file NavChart.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NAV_CHART_WIDGET_HPP
#define NAV_CHART_WIDGET_HPP

#include <QWidget>

namespace HMI
{

class NavChartWidget : public QWidget
{
    Q_OBJECT

public:
    NavChartWidget(QWidget* parent);
    ~NavChartWidget();
};

}
#endif
