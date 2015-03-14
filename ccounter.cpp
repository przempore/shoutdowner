#include "ccounter.h"
#include "ui_ccounter.h"

CCounter::CCounter(QTime( int hours, int minutes ), QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::CCounter)
{
    ui->setupUi(this);
    ui->timeEdit->setTime( );
}

CCounter::~CCounter()
{
    delete ui;
}
