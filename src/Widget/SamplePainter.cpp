#include "Widget/SamplePainter.hpp"

#include <QWidget>
#include <QPainter>
#include <QPen>

using namespace HumanMachineInterface;

SamplePainter::SamplePainter(QWidget* parent)
{
}

SamplePainter::~SamplePainter()
{

}

void SamplePainter::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
 
    // painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::gray, 2, Qt::DotLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::darkBlue, Qt::SolidPattern));

    QSize size = this->size();

    int meshSize = 100;

    for(int i=0;i<size.width()/meshSize+1;i++){
        for(int j=0;j<size.height()/meshSize+1;j++){
            painter.drawRect(i*meshSize, j*meshSize, (i+1)*meshSize, (j+1)*meshSize);
        }
    }

    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter.drawEllipse(200,200,20,20);
    
    this->show();
    
}