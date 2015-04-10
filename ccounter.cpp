#include <string>
#include <QTimer>
#include <QMessageBox>
#include <QProcess>
#include <iostream>
#include <string>
#include "ccounter.h"
#include "ui_ccounter.h"
#include "mainwindow.h"

CCounter::CCounter(QWidget *parent) :
                    QDialog(parent),
                    ui(new Ui::CCounter),
                    m_timerInterval( 1000 )
{
    ui->setupUi( this );
}

CCounter::CCounter( QTime* time, ShutdownOption SHOption, QWidget *parent ) :
                                                     QDialog(parent),
                                                     ui(new Ui::CCounter),
                                                     m_shutdownOption( SHOption ),
                                                     m_windowSize( 350, 280 ),
                                                     m_timerInterval( 1000 ),
                                                     m_hour( time->hour() ),
                                                     m_minute( time->minute() ),
                                                     m_second( 0 )
{
    ui->setupUi( this );

    setMinimumSize( m_windowSize );
    setMaximumSize( m_windowSize );

    m_time.reset( new QTime( *time ) );
    DrawTime();

    m_timer.reset( new QTimer( this ) );
    connect( m_timer.get(), SIGNAL( timeout() ),
             this, SLOT( TimeoutSlot() ) );
    m_timer->start();

    ui->Cancel_Button->setText( "Cancel" );
}

CCounter::~CCounter()
{
    delete ui;
}

void CCounter::TimeoutSlot()
{
   if( ManageTime( m_time.get() ) )
   {
       system( ManageSystem().c_str() );
       ManageSystem();
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
       } }

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
   ui->hour_label->setText( m_time->toString().toStdString().c_str() );
}

std::string CCounter::ManageSystem()
{
    QProcess process;
    QMessageBox message( this );
    switch( m_shutdownOption )
    {
        case eRestart:
            process.execute( "shutdown", QStringList() << "/r" );
        case eShutdown:
            process.execute( "shutdown", QStringList() << "/s" );
        case eHibernate:
            process.execute( "rundll32.exe", QStringList() << "powrprof.dll" << "SetSuspendState 0" << "1" << "0" );
        case eSuspend:
//            process.execute( "rundll32.exe", QStringList() << "powrprof.dll" << "SetSuspendState" );
            message.setText( "still working on that" );
            message.exec();
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
