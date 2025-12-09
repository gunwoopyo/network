#ifndef ROUTEWORKER_H
#define ROUTEWORKER_H

#include <QObject>


#include "Router.h"
class Router;

class RouterWorker : public QObject {
    Q_OBJECT

public:
    explicit RouterWorker(QObject* parent = nullptr)
        : QObject(parent) {
    }
public slots:
    void routerProcess();

signals:
    void routerProgress(Router* router);

    void ready();
    void finished();
};


#endif // ROUTEWORKER_H
