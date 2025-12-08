#ifndef REGISTDEVICE_H
#define REGISTDEVICE_H

#include <QMainWindow>

namespace Ui {
class registDevice;
}

class registDevice : public QMainWindow
{
    Q_OBJECT

public:
    explicit registDevice(QWidget *parent = nullptr);
    ~registDevice();

private:
    Ui::registDevice *ui;
};

#endif // REGISTDEVICE_H
