/**
 * @file SamplePainter.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SAMPLE_PAINTER_WIDGET_HPP
#define SAMPLE_PAINTER_WIDGET_HPP

#include <QWidget>

namespace HMI
{

class SamplePainter : public QWidget
{
    Q_OBJECT

public:
    SamplePainter(QWidget* parent);
    ~SamplePainter();

protected:
    void paintEvent(QPaintEvent* event);

signals:
public slots:
    
};

}
#endif
