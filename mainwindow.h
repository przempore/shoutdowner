#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QLabel>
#include <QTime>
#include <ccounter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTime GetTime() const;
    void SetTime( const QTime &time );

private slots:
    void on_hours_spinBox_valueChanged( int arg1 );

    void on_minutes_spinBox_valueChanged(int arg1);

    void on_start_button_clicked();

    void on_restart_radioButton_toggled(bool checked);

    void on_shutdown_radioButton_clicked(bool checked);

    void on_suspend_radioButton_clicked( bool checked );

    void on_hibernate_radioButton_clicked(bool checked);

    void on_action_Exit_triggered();

    void on_action_Reset_triggered();

protected:
    void SetUiTexts();
    void SetWindowSize();
    QFont SetLabelFontSize( QLabel* label, int size );

private:
    Ui::MainWindow *ui;

    const int m_maxHourValue = 27;       //< max number of posibily hours to count
    const int m_maxMinuteValue = 60;     //< max number of posibily minutes to count
    const QSize m_applicationSize = QSize(450, 350);  //< max size of application

    CCounter::ShutdownOption m_shutdownOption = CCounter::eNull;

    QTime m_time;

    const int m_hourFontSize = 28;
    const int m_minutesFontSize = 18;
    const int m_titleFontSize = 10;
};

#endif // MAINWINDOW_H
