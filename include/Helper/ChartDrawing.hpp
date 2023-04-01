/**
 * @file ChartDrawing.hpp
 * @author okano tomoyuki (okano.development@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CHART_DRAWING_HELPER_HPP
#define CHART_DRAWING_HELPER_HPP

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QBrush>
#include <QFont>
#include <QPen>

namespace HMI
{

class ChartDrawingHelper
{
public:
    ChartDrawingHelper();
    ~ChartDrawingHelper();
    void paint(QPainter* painter, QPaintEvent* event, int elapsed);

private:
    QBrush  background;
    QBrush  circleBrush;
    QFont   textFont;
    QPen    circlePen;
    QPen    textPen;
};

}


#endif