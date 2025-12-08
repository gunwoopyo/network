#include "routetablewindow.h"
#include "ui_routetablewindow.h"

routetablewindow::routetablewindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::routetablewindow)
{
    ui->setupUi(this);
}

routetablewindow::~routetablewindow()
{
    delete ui;
}
