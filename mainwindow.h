#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QThread>
#include "Router.h"
#include "PortWorker.h"

#include "arptablewindow.h"
#include "registerdevicewindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Port;
class RouterWorker;
class DeviceWorker;

class MainWindow : public QMainWindow {
    Q_OBJECT
private:

    RouterWorker* routerWorker = nullptr;
    QThread* routerThread = nullptr;



    PortWorker* portWorker = nullptr;
    QThread* portThread = nullptr;



    Ui::MainWindow *ui;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startMyThread();

    void showRouterInfo(Router* routerInfo);
    void showPortInfo(Port* portInfo);   // 포트 정보 UI에 표시
    void showLoadInfo(Router* routerInfo);
    void showPortView(Router* routerInfo);

    void onRouterThreadStarted();
    void onRouterThreadFinished();

    void onPortThreadStarted();
    void onPortThreadFinished();  // 수집 완료 후 UI 업데이트/버튼 활성화
};
#endif // MAINWINDOW_H
