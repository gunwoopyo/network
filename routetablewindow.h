#ifndef ROUTETABLEWINDOW_H
#define ROUTETABLEWINDOW_H

#include <QMainWindow>
#include <QThread>

class RouteTableWorker;
class RouteTable;



namespace Ui {
class routetablewindow;
}

class routetablewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit routetablewindow(QWidget *parent = nullptr);
    ~routetablewindow();

private:
    RouteTableWorker* routeTableWorker = nullptr;
    QThread* routeTableThread = nullptr;

    Ui::routetablewindow *ui;

public slots:
    void onRouteTableThreadStarted();
    void onRouteTableThreadFinished();
    void showRouteTableInfo(RouteTable* table);
};

#endif // ROUTETABLEWINDOW_H
