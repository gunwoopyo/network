#ifndef ROUTETABLEWINDOW_H
#define ROUTETABLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class routetablewindow;
}

class routetablewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit routetablewindow(QWidget *parent = nullptr);
    ~routetablewindow();

private:
    Ui::routetablewindow *ui;
};

#endif // ROUTETABLEWINDOW_H
