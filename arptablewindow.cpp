#include "arptablewindow.h"
#include "ui_arptablewindow.h"
#include "ArpTableWorker.h"
#include "ArpTable.h"

arptablewindow::arptablewindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::arptablewindow)
{
    ui->setupUi(this);

    arpTableWorker = new ArpTableWorker();
    arpTableThread = new QThread();
    arpTableWorker->moveToThread(arpTableThread);
    arpTableThread->start();
    QObject::connect(arpTableThread, &QThread::started, this, &arptablewindow::onArpTableThreadStarted);
    QObject::connect(arpTableThread, &QThread::started, arpTableWorker, &ArpTableWorker::arpTableProcess);
    QObject::connect(arpTableWorker, &ArpTableWorker::arpTableProgress, this, &arptablewindow::showArpTableInfo);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, arpTableThread, &QThread::quit);
    QObject::connect(arpTableThread, &QThread::finished, arpTableWorker, &QObject::deleteLater);
    QObject::connect(arpTableThread, &QThread::finished, arpTableThread, &QObject::deleteLater);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, this, &arptablewindow::onArpTableThreadFinished);
}


arptablewindow::~arptablewindow()
{

    delete arpTableWorker;
    delete arpTableThread;

    // arpTableThread->quit();
    // arpTableThread->wait();
    // onArpTableThreadFinished();

    delete ui;
}

// 전체 조회
void arptablewindow::on_searchTotalPushButton_clicked() {
    //ui->portNumberComboBox->clear();
    arpTableWorker = new ArpTableWorker();
    arpTableThread = new QThread();
    arpTableWorker->moveToThread(arpTableThread);
    arpTableThread->start();
    QObject::connect(arpTableThread, &QThread::started, this, &arptablewindow::onArpTableThreadStarted);
    QObject::connect(arpTableThread, &QThread::started, arpTableWorker, &ArpTableWorker::arpTableProcess);
    QObject::connect(arpTableWorker, &ArpTableWorker::arpTableProgress, this, &arptablewindow::showArpTableInfo);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, arpTableThread, &QThread::quit);
    QObject::connect(arpTableThread, &QThread::finished, arpTableWorker, &QObject::deleteLater);
    QObject::connect(arpTableThread, &QThread::finished, arpTableThread, &QObject::deleteLater);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, this, &arptablewindow::onArpTableThreadFinished);

}


// 조회
void arptablewindow::on_searchPushButton_clicked() {

    //ui->portNumberComboBox->clear();
    arpTableWorker = new ArpTableWorker();
    arpTableThread = new QThread();
    arpTableWorker->moveToThread(arpTableThread);
    arpTableThread->start();
    QObject::connect(arpTableThread, &QThread::started, this, &arptablewindow::onArpTableThreadStarted);
    QObject::connect(arpTableThread, &QThread::started, arpTableWorker, &ArpTableWorker::arpTableProcess);
    QObject::connect(arpTableWorker, &ArpTableWorker::arpTableProgress, this, &arptablewindow::showArpTableInfo);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, arpTableThread, &QThread::quit);
    QObject::connect(arpTableThread, &QThread::finished, arpTableWorker, &QObject::deleteLater);
    QObject::connect(arpTableThread, &QThread::finished, arpTableThread, &QObject::deleteLater);
    QObject::connect(arpTableWorker, &ArpTableWorker::finished, this, &arptablewindow::onArpTableThreadFinished);
}

void arptablewindow::onArpTableThreadStarted() {
    qDebug() << "ARP 테이블 스레드 시작";
}

void arptablewindow::onArpTableThreadFinished() {
    qDebug() << "ARP 테이블 스레드 종료";
}


void arptablewindow::showArpTableInfo(ArpTable* table) {
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















