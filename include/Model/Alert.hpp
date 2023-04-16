#ifndef ALERT_MODEL_HPP
#define ALERT_MODEL_HPP

#include <QAbstractItemModel>
#include <QObject>

namespace HMI
{

class Alert : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit Alert(QObject* parent = nullptr);


};

}

#endif