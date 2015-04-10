#include <qmessagebox.h>
#include "ccounter.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent),
                        ui(new Ui::MainWindow),
                        m_maxHourValue( 27 ),
                        m_maxMinuteValue( 60 ),
                        m_applicationSize( 450, 380 ),
                        m_shutdownOption( CCounter::eNull ),
                        m_hourFontSize( 28 ),
                        m_minutesFontSize( 18 ),
                        m_titleFontSize( 10 )
{
    ui->setupUi(this);

    SetWindowSize();

    SetUiTexts();

    ui->shutdown_radioButton->setChecked( true );
}

void MainWindow::SetWindowSize()
{
    setMaximumSize( m_applicationSize );
    setMinimumSize( m_applicationSize );
}

void MainWindow::SetUiTexts()
{
    ui->restart_radioButton->setText( "Uruchom ponownie." );
    ui->shutdown_radioButton->setText( "Zamknij." );
    ui->suspend_radioButton->setText( "Wstrzymaj." );
    ui->hibernate_radioButton->setText( "Hibernate." );
    ui->hour_label->setText( "Godziny:" );
    ui->minutes_label->setText( "Minuty:" );
    ui->title_label->setText( "Wyłączanie komputera\nsterowane czasowo." );

    ui->title_label->setAlignment( Qt::AlignRight );

    ui->title_label->setFont( SetLabelFontSize( ui->title_label, m_titleFontSize ) );
    ui->hour_label->setFont( SetLabelFontSize( ui->hour_label, m_hourFontSize ) );
    ui->minutes_label->setFont( SetLabelFontSize( ui->minutes_label, m_minutesFontSize ) );

}

QFont MainWindow::SetLabelFontSize( QLabel* label, int size )
{
   QFont font = label->font();
   font.setPointSize( size );
   return font;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hours_spinBox_valueChanged( int arg1 )
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

void MainWindow::on_minutes_spinBox_valueChanged( int arg1 )
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
    if( ui->hours_spinBox->value() <= 0
        && ui->minutes_spinBox->value() <= 0 )
    {
       QMessageBox msgBox;
       msgBox.setText( QString( "Cannot count zero time!!!!!" ) );
       msgBox.exec();
       return;
    }
    SetTime( QTime( ui->hours_spinBox->value(), ui->minutes_spinBox->value() ) );
    CCounter cCounter( &m_time, m_shutdownOption, this );
    cCounter.setModal( true );
    cCounter.exec();
}

void MainWindow::on_restart_radioButton_toggled( bool checked )
{
   if( checked )
   {
        m_shutdownOption = CCounter::eRestart;
   }
}

void MainWindow::on_shutdown_radioButton_clicked( bool checked )
{
   if( checked
       || ui->shutdown_radioButton->isChecked() )
   {
        m_shutdownOption = CCounter::eShutdown;
   }
}

void MainWindow::on_suspend_radioButton_clicked( bool checked )
{
   if( checked
       || ui->suspend_radioButton->isChecked() )
   {
        m_shutdownOption = CCounter::eSuspend;
   }
}

void MainWindow::on_hibernate_radioButton_clicked( bool checked )
{
   if( checked
       || ui->suspend_radioButton->isChecked() )
   {
        m_shutdownOption = CCounter::eSuspend;
   }
}

QTime MainWindow::GetTime() const
{
    return m_time;
}

void MainWindow::SetTime( const QTime &time )
{
    m_time = time;
}
