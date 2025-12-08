#ifndef LOG_H
#define LOG_H

#include <QMainWindow>

namespace Ui {
class log;
}

class log : public QMainWindow
{
    Q_OBJECT

public:
    explicit log(QWidget *parent = nullptr);
    ~log();



private:
    Ui::log *ui;
};

#endif // LOG_H
