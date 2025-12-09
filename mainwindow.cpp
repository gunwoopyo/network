#include <QMainWindow>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RouteWorker.h"
#include "DeviceInfoWorker.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 등록 창
    RegisterDeviceWindow* registerDeviceWindow = new RegisterDeviceWindow(this);
    registerDeviceWindow->setWindowModality(Qt::WindowModal);
    QSize dlgSize = registerDeviceWindow->size();
    QPoint center = this->geometry().center();
    QPoint topLeft = center - QPoint(dlgSize.width()/2, dlgSize.height()/2);
    registerDeviceWindow->move(topLeft);
    registerDeviceWindow->show();
    connect(registerDeviceWindow, &RegisterDeviceWindow::startThreadRequested, this, &MainWindow::startMyThread);

    // route 테이블
    connect(ui->routeTable, &QPushButton::clicked, this, [this]() {
        RouteTableWindow* routeTableWindow = new RouteTableWindow(nullptr);
        routeTableWindow->show(); });

    // arp 테이블
    connect(ui->searchTable, &QPushButton::clicked, this, []() {
        arptablewindow* tableWindow = new arptablewindow(nullptr);
        tableWindow->show();});
}

MainWindow::~MainWindow() {
    portWorker->stop(); // 타이머 멈춤
    portThread->quit();
    portThread->wait();
    delete portWorker;
    delete portThread;
    onPortThreadFinished();

    routerThread->quit();
    routerThread->wait();
    delete routerWorker;
    delete routerThread;
    onRouterThreadFinished();

    delete Router::routerPtr;
    delete ui;
}

void MainWindow::startMyThread() {
    routerWorker = new RouterWorker();
    routerThread = new QThread;
    routerWorker->moveToThread(routerThread);
    routerThread->start();
    QObject::connect(routerThread, &QThread::started, this, &MainWindow::onRouterThreadStarted);
    QObject::connect(routerThread, &QThread::started, routerWorker, &RouterWorker::routerProcess);
    QObject::connect(routerWorker, &RouterWorker::routerProgress, this, &MainWindow::showRouterInfo);
    QObject::connect(routerWorker, &RouterWorker::finished, routerThread, &QThread::quit);
    QObject::connect(routerThread, &QThread::finished, routerWorker, &QObject::deleteLater);
    QObject::connect(routerThread, &QThread::finished, routerThread, &QObject::deleteLater);
    QObject::connect(routerWorker, &RouterWorker::finished, this, &MainWindow::onRouterThreadFinished);




    portWorker = new PortWorker();
    portThread = new QThread();
    portWorker->moveToThread(portThread);
    QObject::connect(portThread, &QThread::started, this, &MainWindow::onPortThreadStarted);
    QObject::connect(portThread, &QThread::started, portWorker, &PortWorker::portProcess);
    QObject::connect(portWorker, &PortWorker::portViewProgress, this, &MainWindow::showPortView);
    QObject::connect(portWorker, &PortWorker::portInfoProgress, this, &MainWindow::showPortInfo);
    QObject::connect(portWorker, &PortWorker::loadInfoProgress, this, &MainWindow::showLoadInfo);
    QObject::connect(routerWorker, &RouterWorker::ready, portThread, [=]() {
        portThread->start();
    });

}

void MainWindow::onRouterThreadStarted() {
    qDebug() << "#1 라우터 스레드 시작";
}
void MainWindow::onRouterThreadFinished() {
    qDebug() << "#1 라우터 스레드 종료";
}
void MainWindow::onPortThreadStarted() {
    qDebug() << "#2 포트 스레드 시작";
}
void MainWindow::onPortThreadFinished() {
    qDebug() << "#2 포트 스레드 종료";
}







void MainWindow::showPortView(Router* router) {
    for(int i = 1; i <= router->ports.size(); i++) {
        QFrame* frame = this->findChild<QFrame*>(QString("port%1Frame").arg(i));

        if(router->ports[i-1].portOperStatus == 1) {
            frame->setStyleSheet("background-color: green;");
        }
        else
            frame->setStyleSheet("background-color: gray;");
        QLabel* label = this->findChild<QLabel*>(QString("port%1Text").arg(i));
        label->setText(router->ports[i-1].portName);
    }
}



void MainWindow::showLoadInfo(Router* router) {
    int runningCount = 0;
    int normalCount = 0;
    int warningCount = 0;
    int dangerCount = 0;

    for(Port& port : router->ports) {
        if(port.portOperStatus == 1)
            runningCount++;

        if(port.trafficBuffer.last().loadStatus == "normal") {
            normalCount++;
        }
        else if(port.trafficBuffer.last().loadStatus == "warning") {
            warningCount++;
        }
        else if(port.trafficBuffer.last().loadStatus == "danger") {
            dangerCount++;
        }
    }
    ui->loadTotalText->setText(QString::number(runningCount));
    ui->loadNormalText->setText(QString::number(normalCount));
    ui->loadWarningText->setText(QString::number(warningCount));
    ui->loadDangerText->setText(QString::number(dangerCount));
}


void MainWindow::showRouterInfo(Router* routerInfo) {
    ui->routerTable->setRowCount(1);
    ui->routerTable->setItem(0, 0, new QTableWidgetItem(routerInfo->routerName));
    ui->routerTable->setItem(0, 1, new QTableWidgetItem(routerInfo->routerIP));
    ui->routerTable->setItem(0, 2, new QTableWidgetItem(QString::number(routerInfo->cpu) + "%"));
    ui->routerTable->setItem(0, 3, new QTableWidgetItem(QString::number(routerInfo->memory, 'f', 1) + "%"));

    int seconds = routerInfo->time / 100;
    int day = seconds / 86400;
    int hour = (seconds % 86400) / 3600;
    ui->routerTable->setItem(0, 4, new QTableWidgetItem(QString::number(day) + "일" + QString::number(hour) + "시간"));
}




void MainWindow::showPortInfo(Port* port) {
    static QMap<QString,int> portRows;
    int row = portRows.value(port->portName, -1);
    if(row == -1) {
        row = ui->interfaceTable->rowCount();
        ui->interfaceTable->insertRow(row);
        portRows[port->portName] = row;
    }
    ui->interfaceTable->setItem(row, 0, new QTableWidgetItem(QString::number(port->ifIndex)));
    ui->interfaceTable->setItem(row, 1, new QTableWidgetItem(port->portName));


    QString adminText;
    switch (port->portAdminStatus) {
        case 1: adminText = "On";
            break;
        case 2: adminText = "Off";
            break;
        case 3: adminText = "Testing";
            break;
        default: adminText = "Unknown";
            break;
    }
    ui->interfaceTable->setItem(row, 2, new QTableWidgetItem(adminText));


    QString operText;
    switch (port->portOperStatus) {
        case 1: operText = "Running";
            break;
        case 2: operText = "Not Running";
            break;
        case 3: operText = "테스트 중";
            break;
        default: operText = "Unknown";
            break;
    }
    ui->interfaceTable->setItem(row, 3, new QTableWidgetItem(operText));

    ui->interfaceTable->setItem(row, 4, new QTableWidgetItem(port->macAddress));

    if(!port->trafficBuffer.isEmpty()) {
        Traffic traffic = port->trafficBuffer.last();

        double inBpsValue = traffic.InBPS;
        QString unit = "bps";

        if (inBpsValue >= 1e9) {
            inBpsValue /= 1e9;
            unit = "Gbps";
        } else if (inBpsValue >= 1e6) {
            inBpsValue /= 1e6;
            unit = "Mbps";
        } else if (inBpsValue >= 1e3) {
            inBpsValue /= 1e3;
            unit = "Kbps";
        }
        ui->interfaceTable->setItem(row, 5, new QTableWidgetItem(QString::number(inBpsValue, 'f', 2) + unit));

        double outBpsValue = traffic.OutBps;
        if (outBpsValue >= 1e9) {
            outBpsValue /= 1e9;
            unit = "Gbps";
        } else if (outBpsValue >= 1e6) {
            outBpsValue /= 1e6;
            unit = "Mbps";
        } else if (outBpsValue >= 1e3) {
            outBpsValue /= 1e3;
            unit = "Kbps";
        }
        ui->interfaceTable->setItem(row, 6, new QTableWidgetItem(QString::number(outBpsValue, 'f', 2) + unit));
        ui->interfaceTable->setItem(row, 7, new QTableWidgetItem(QString::number(traffic.InPPS)));
        ui->interfaceTable->setItem(row, 8, new QTableWidgetItem(QString::number(traffic.OutPPS)));
    }
}








