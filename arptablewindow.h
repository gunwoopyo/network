#ifndef ARPTABLEWINDOW_H
#define ARPTABLEWINDOW_H

#include <QMainWindow>
#include <QThread>


class ArpTableWorker;
class ArpTable;


namespace Ui {
class arptablewindow;
}


class arptablewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit arptablewindow(QWidget *parent = nullptr);
    ~arptablewindow();

private:
    ArpTableWorker* arpTableWorker = nullptr;
    QThread* arpTableThread = nullptr;

    Ui::arptablewindow *ui;

public slots:
    void on_searchPushButton_clicked();
    void on_searchTotalPushButton_clicked();

    void showArpTableInfo(ArpTable* port);
    void onArpTableThreadFinished();
    void onArpTableThreadStarted();


};

#endif // ARPTABLEWINDOW_H







