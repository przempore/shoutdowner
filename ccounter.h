#ifndef CCOUNTER_H
#define CCOUNTER_H

#include <QDialog>

namespace Ui {
class CCounter;
}

class CCounter : public QDialog
{
    Q_OBJECT

public:
    explicit CCounter(QWidget *parent = 0);
    ~CCounter();

private:
    Ui::CCounter *ui;
};

#endif // CCOUNTER_H
