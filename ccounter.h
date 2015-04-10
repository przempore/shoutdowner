#ifndef CCOUNTER_H
#define CCOUNTER_H

#include <boost/scoped_ptr.hpp>
#include <QDialog>
#include <string>

namespace Ui {
class CCounter;
}

class CCounter : public QDialog
{
    Q_OBJECT
public:
    /// \brief option of shutdown command
    enum ShutdownOption
    {
        eRestart,
        eShutdown,
        eHibernate,
        eSuspend,

        eNull
    };

public:
    explicit CCounter( QWidget *parent = 0 );
    explicit CCounter( QTime* time, ShutdownOption SHOption, QWidget *parent = 0 );
    ~CCounter();

private slots:
    void TimeoutSlot();

    void on_Cancel_Button_clicked();

private:
    bool ManageTime( int& hour, int& minute, int& second );
    bool ManageTime( QTime* time );
    void DrawTime();
    std::string ManageSystem();
    unsigned long ComputeTime();

private:
    Ui::CCounter *ui;
    ShutdownOption m_shutdownOption;    // option od shutdown command

    boost::scoped_ptr< QTimer > m_timer;
    boost::scoped_ptr< QTime > m_time;

    const QSize m_windowSize;  //< max size of application
    const int m_timerInterval;

    int m_hour;
    int m_minute;
    int m_second;
};

#endif // CCOUNTER_H
