#ifndef ROUTETABLEWINDOW_H
#define ROUTETABLEWINDOW_H

#include <QMainWindow>
#include <QThread>

class RouteTableWorker;
class RouteTable;



namespace Ui {
class RouteTableWindow;
}

class RouteTableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RouteTableWindow(QWidget *parent = nullptr);
    ~RouteTableWindow();

private:
    RouteTableWorker* routeTableWorker = nullptr;
    QThread* routeTableThread = nullptr;

    Ui::RouteTableWindow *ui;

public slots:
    void onRouteTableThreadStarted();
    void onRouteTableThreadFinished();
    void showRouteTableInfo(RouteTable* table);
};

#endif // ROUTETABLEWINDOW_H
