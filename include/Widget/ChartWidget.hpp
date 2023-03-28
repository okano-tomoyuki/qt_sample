/**
 * @file ChartWidget.hpp
 * @author okano tomoyuki (okano.development@gmail.com)
 * @brief チャート情報表示用ウィジェット
 * @version 0.1
 * @date 2023-03-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
