#ifndef SAMPLE_PAINTER_HPP
#define SAMPLE_PAINTER_HPP

#include <QWidget>

namespace HumanMachineInterface
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
