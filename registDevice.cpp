#include "registDevice.h"
#include "ui_registDevice.h"

registDevice::registDevice(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::registDevice)
{
    ui->setupUi(this);
}

registDevice::~registDevice()
{
    delete ui;
}
