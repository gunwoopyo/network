#ifndef DEVICEWORKER_H
#define DEVICEWORKER_H
#include <QObject>
#include <Port.h>



class DeviceWorker : public QObject {
    Q_OBJECT

public:
    explicit DeviceWorker(QObject* parent = nullptr)
        : QObject(parent) { }

public slots:
    void deviceProcess();

signals:
    void deviceProgress(Port* port);
    void finished();
};




#endif // DEVICEWORKER_H
