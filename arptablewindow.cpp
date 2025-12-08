#include "arptablewindow.h"
#include "ui_arptablewindow.h"
#include "ArpTableWorker.h"
#include "ArpTable.h"
ArpTableWindow::ArpTableWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TableWindow)
{
    ui->setupUi(this);

    arpTableWorker = new ArpTableWorker();
    arpTableThread = new QThread();
    arpTableWorker->moveToThread(arpTableThread);
    arpTableThread->start();
    QObject::connect(arpTableThread, &QThread::started, this, &ArpTableWindow::onArpTableThreadStarted);
    QObject::connect(arpTableThread, &QThread::started, arpTableWorker, &ArpTableWorker::arpTableProcess);
    QObject::connect(arpTableWorker, &ArpTableWorker::arpTableProgress, this, &ArpTableWindow::showArpTableInfo);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, arpTableThread, &QThread::quit);
    QObject::connect(arpTableThread, &QThread::finished, arpTableWorker, &QObject::deleteLater);
    QObject::connect(arpTableThread, &QThread::finished, arpTableThread, &QObject::deleteLater);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, this, &ArpTableWindow::onArpTableThreadFinished);

}

ArpTableWindow::~ArpTableWindow()
{

    delete arpTableWorker;
    delete arpTableThread;

    // arpTableThread->quit();
    // arpTableThread->wait();
    //onArpTableThreadFinished();

    delete ui;
}

// 전체 조회
void ArpTableWindow::on_searchTotalPushButton_clicked() {
    //ui->portNumberComboBox->clear();
    arpTableWorker = new ArpTableWorker();
    arpTableThread = new QThread();
    arpTableWorker->moveToThread(arpTableThread);
    arpTableThread->start();
    QObject::connect(arpTableThread, &QThread::started, this, &ArpTableWindow::onArpTableThreadStarted);
    QObject::connect(arpTableThread, &QThread::started, arpTableWorker, &ArpTableWorker::arpTableProcess);
    QObject::connect(arpTableWorker, &ArpTableWorker::arpTableProgress, this, &ArpTableWindow::showArpTableInfo);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, arpTableThread, &QThread::quit);
    QObject::connect(arpTableThread, &QThread::finished, arpTableWorker, &QObject::deleteLater);
    QObject::connect(arpTableThread, &QThread::finished, arpTableThread, &QObject::deleteLater);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, this, &ArpTableWindow::onArpTableThreadFinished);

}


// 조회
void ArpTableWindow::on_searchPushButton_clicked() {

    //ui->portNumberComboBox->clear();
    arpTableWorker = new ArpTableWorker();
    arpTableThread = new QThread();
    arpTableWorker->moveToThread(arpTableThread);
    arpTableThread->start();
    QObject::connect(arpTableThread, &QThread::started, this, &ArpTableWindow::onArpTableThreadStarted);
    QObject::connect(arpTableThread, &QThread::started, arpTableWorker, &ArpTableWorker::arpTableProcess);
    QObject::connect(arpTableWorker, &ArpTableWorker::arpTableProgress, this, &ArpTableWindow::showArpTableInfo);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, arpTableThread, &QThread::quit);
    QObject::connect(arpTableThread, &QThread::finished, arpTableWorker, &QObject::deleteLater);
    QObject::connect(arpTableThread, &QThread::finished, arpTableThread, &QObject::deleteLater);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, this, &ArpTableWindow::onArpTableThreadFinished);
}

void ArpTableWindow::onArpTableThreadStarted() {
    qDebug() << "ARP 테이블 스레드 시작";
}

void ArpTableWindow::onArpTableThreadFinished() {
    qDebug() << "ARP 테이블 스레드 종료";
}


void ArpTableWindow::showArpTableInfo(ArpTable* table) {
    ui->arpTable->setRowCount(0);
    QString portNumberText = ui->portNumberComboBox->currentText();

    for(const ArpTableEntry& entry : table->arpTable) {
        QString idx = QString::number(entry.ifIndex);
        if (ui->portNumberComboBox->findText(idx) == -1) {
            ui->portNumberComboBox->addItem(idx);
        }


        if(portNumberText.isEmpty()) {
            int row = ui->arpTable->rowCount();
            ui->arpTable->insertRow(row);
            ui->arpTable->setItem(row, 0, new QTableWidgetItem(QString::number(entry.ifIndex)));
            ui->arpTable->setItem(row, 1, new QTableWidgetItem(entry.IPAddress));
            ui->arpTable->setItem(row, 2, new QTableWidgetItem(entry.macAddress));
            ui->arpTable->setItem(row, 3, new QTableWidgetItem(QString::number(entry.type)));
        }
        else {
            if(portNumberText == idx) {
                int row = ui->arpTable->rowCount();
                ui->arpTable->insertRow(row);
                ui->arpTable->setItem(row, 0, new QTableWidgetItem(QString::number(entry.ifIndex)));
                ui->arpTable->setItem(row, 1, new QTableWidgetItem(entry.IPAddress));
                ui->arpTable->setItem(row, 2, new QTableWidgetItem(entry.macAddress));
                ui->arpTable->setItem(row, 3, new QTableWidgetItem(QString::number(entry.type)));
            }
        }
    }

    ui->portNumberComboBox->setCurrentIndex(0);
    delete table;
}















