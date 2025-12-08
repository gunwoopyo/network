#ifndef DEVICEINFOWORKER_H
#define DEVICEINFOWORKER_H

#include <QObject>
#include <QTimer>

#include "Router.h"



class DeviceWorker : public QObject {
    Q_OBJECT

public:
    QTimer* timer;
    explicit DeviceWorker(QObject* parent = nullptr)
        : QObject(parent) {
        timer = new QTimer(this);
    }

public slots:
    void deviceProcess();
    void stop() {
        timer->stop();
    }
signals:

};



#endif // DEVICEINFOWORKER_H
