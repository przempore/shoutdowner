#include <string>
#include <QTimer>
#include <iostream>
#include <qmessagebox.h>
#include <string>
#include "ccounter.h"
#include "ui_ccounter.h"

CCounter::CCounter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CCounter),
    m_timerInterval( 1000 )
{
    ui->setupUi(this);
}

CCounter::CCounter( QTime* time, ShutdownOption SHOption, QWidget *parent ) :
                                                     QDialog(parent),
                                                     ui(new Ui::CCounter),
                                                     m_shutdownOption( SHOption ),
                                                     m_windowSize( 350, 280 ),
                                                     m_hour( time->hour() ),
                                                     m_minute( time->minute() ),
                                                     m_second( 0 ),
                                                     m_timerInterval( 1000 )
{
    ui->setupUi( this );

    setMaximumSize( m_windowSize );
    setMinimumSize( m_windowSize );

    m_time.reset( new QTime( *time ) );
    DrawTime();

    m_timer.reset( new QTimer( this ) );
    connect( m_timer.get(), SIGNAL( timeout() ),
             this, SLOT( TimeoutSlot() ) );
    m_timer->start();

    m_exitProcess.reset( new QProcess( this ) );
//    m_pElapsedTimer.reset( new QElapsedTimer( this ) );

    std::string countedTime = std::to_string( ComputeTime() );

    ui->Cancel_Button->setText( "Cancel" );
}

CCounter::~CCounter()
{
    delete ui;
}

void CCounter::TimeoutSlot()
{
   if( ManageTime( m_time.get() ) ) {
       system( ManageSystem().c_str() );
       disconnect( m_timer.get(), SIGNAL( timeout() ),
             this, SLOT( TimeoutSlot() ) );
   }
   DrawTime();

   m_timer->start( m_timerInterval ); }

bool CCounter::ManageTime( int& hour, int& minute, int& second )
{
   if( hour <= 0
       && minute <= 0
       && second <= 0 )
   {
       return true;
   }
   else
   {
       --second;
       if( second < 0 )
       {
           second = 59;
           --minute;
           if( minute < 0 )
           {
               minute = 59;
               --hour;
           }
       }
   }

   return false;
}

bool CCounter::ManageTime( QTime* time )
{
   int second = time->second();
   int minute = time->minute();
   int hour = time->hour();

   bool bRet = ManageTime( hour, minute, second );
   time->setHMS( hour, minute, second );

   return bRet;
}

void CCounter::DrawTime()
{
   std::string my_string( m_time->toString().toStdString() );
   ui->hour_label->setText( my_string.c_str() );
}

std::string CCounter::ManageSystem()
{
    switch( m_shutdownOption )
    {
        case eRestart:
            return "/r";
        case eShutdown:
            return "/s";
        default:
            return NULL;
    }
}

unsigned long CCounter::ComputeTime()
{
    return m_hour * 60 * 60 + m_minute * 60 + m_second;
}

void CCounter::on_Cancel_Button_clicked()
{
    close();
}

void CCounter::OnProcessExit( int exit )
{
//   disconnect( m_exitProcess.get(), SIGNAL( finished( int ) ),
//             this, SLOT( OnProcessExit() ) );

    std::cout << exit;
    QMessageBox msgBox;
    msgBox.setText( QString( ( std::to_string( exit ) ).c_str() ) );
    msgBox.exec();
//   m_exitProcess->start( "shutdown", QStringList() << ManageSystem().c_str() );
}
