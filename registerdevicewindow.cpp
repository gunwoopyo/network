#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "registerdevicewindow.h"
#include "ui_registerdevicewindow.h"
#include "Router.h"

RegisterDeviceWindow::RegisterDeviceWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterDeviceWindow) {
    ui->setupUi(this);
    routerListTable();
}


RegisterDeviceWindow::~RegisterDeviceWindow() {
    delete ui;
}

void RegisterDeviceWindow::on_startPushButton_clicked() {
    int ipColumn = 0;
    int commColumn = 1;

    QTableWidgetItem* selectedItem = ui->routerListTable->currentItem();
    if(selectedItem == nullptr) {
        QMessageBox::warning(this, "오류", "행을 선택해주세요  ");
        return;
    }

    int selectedLow = selectedItem->row();
    QString ip = ui->routerListTable->item(selectedLow, ipColumn)->text();
    QString community = ui->routerListTable->item(selectedLow, commColumn)->text();

    Router* router = new Router(ip, community);
    Router::routerPtr = router;

    emit startThreadRequested();
    this->deleteLater();
}



void RegisterDeviceWindow::on_registPushButton_clicked() {
    QString ipAddress =  ui->registIPAddress->text();
    QString community =  ui->registCommunity->text();


    if(ipAddress.isEmpty() || community.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "IP 주소 Community 모두 입력해주세요.  ");
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO routerList (ipAddress, community) VALUES (:ip, :commu)");
    query.bindValue(":ip", ipAddress);
    query.bindValue(":commu", community);

    if(!query.exec()) {
        if (query.lastError().nativeErrorCode() == "1062") {
            QMessageBox::warning(this, "등록 실패", "이미 존재하는 IP 주소입니다.  ");
        } else {
            qDebug() << "Insert Failed:" << query.lastError().text();
        }
        return;
    }
    QMessageBox::information(this, "등록 완료", "라우터가 등록되었습니다.");
    routerListTable();
    ui->registIPAddress->clear();
    ui->registCommunity->clear();
}



void RegisterDeviceWindow::on_deletePushButton_clicked() {
    QString ipAddress =  ui->registIPAddress->text();

    if(ipAddress.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "IP 주소를 입력해주세요.  ");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM routerList WHERE ipAddress = :ip");
    query.bindValue(":ip", ipAddress);


    if (!query.exec()) {
        qDebug() << "Delete Failed:" << query.lastError().text();
        QMessageBox::critical(this, "삭제 실패", "삭제 중 오류가 발생했습니다.  ");
        return;
    }

    if (query.numRowsAffected() == 0) {
        QMessageBox::information(this, "삭제", "해당 IP가 존재하지 않습니다.");
    } else {
        QMessageBox::information(this, "삭제 완료", "IP가 삭제되었습니다.");
        routerListTable();
    }
    ui->registIPAddress->clear();
    ui->registCommunity->clear();
}



void RegisterDeviceWindow::routerListTable() {
     ui->routerListTable->setRowCount(0);
     int row = 0;

    QSqlQuery query("SELECT ipAddress, community FROM routerList");
    while(query.next()) {
        ui->routerListTable->insertRow(row);
        ui->routerListTable->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->routerListTable->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        row++;
    }
}













