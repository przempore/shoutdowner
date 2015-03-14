#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace SD::Logic;

MainWindow::MainWindow(QWidget *parent) :
                    QMainWindow(parent),
                    ui(new Ui::MainWindow),
                    m_maxHourValue( 27 ),
                    m_maxMinuteValue( 60 ),
                    m_applicationSize( 450, 380 )
{
    ui->setupUi(this);
    setMaximumSize( m_applicationSize );
    setMinimumSize( m_applicationSize );
    m_pTimeControl.reset( new CTimeController() );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hours_spinBox_valueChanged(int arg1)
{
   if( arg1 >= m_maxHourValue )
   {
      ui->hours_spinBox->setValue( 0 );
   }
   else if( arg1 < 0 )
   {
       ui->hours_spinBox->setValue( m_maxHourValue - 1);
   }
}

void MainWindow::on_minutes_spinBox_valueChanged(int arg1)
{
   if( arg1 >= m_maxMinuteValue )
   {
      ui->minutes_spinBox->setValue( 0 );
   }
   else if( arg1 < 0 )
   {
       ui->minutes_spinBox->setValue( m_maxMinuteValue - 1);
   }
}

void MainWindow::on_start_button_clicked()
{
    m_pTimeControl->SetTime( ui->hours_spinBox->value(), ui->minutes_spinBox->value() );
}

void MainWindow::on_restart_radioButton_toggled(bool checked)
{
   if( checked )
   {
       m_pTimeControl->SetOption( CTimeController::eRestart );
   }
}

void MainWindow::on_shutdown_radioButton_clicked(bool checked)
{
   if( checked )
   {
       m_pTimeControl->SetOption( CTimeController::eShutdown );
   }
}
