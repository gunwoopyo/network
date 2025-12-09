#ifndef ARPTABLEWINDOW_H
#define ARPTABLEWINDOW_H

#include <QMainWindow>
#include <QThread>

class ArpTableWorker;
class ArpTable;

namespace Ui {
class ArpTableWindow;
}

class ArpTableWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArpTableWindow(QWidget *parent = nullptr);
    ~ArpTableWindow();

private:
    ArpTableWorker *arpTableWorker = nullptr;
    QThread *arpTableThread = nullptr;

    Ui::ArpTableWindow *ui;

public slots:
    void on_searchPushButton_clicked();
    void on_searchTotalPushButton_clicked();

    void showArpTableInfo(ArpTable *port);
    void onArpTableThreadFinished();
    void onArpTableThreadStarted();
};

#endif // ARPTABLEWINDOW_H
