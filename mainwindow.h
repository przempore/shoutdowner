#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <boost/shared_ptr.hpp>
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
    void SetTime(const QTime &time);

private slots:
    void on_hours_spinBox_valueChanged(int arg1);

    void on_minutes_spinBox_valueChanged(int arg1);

    void on_start_button_clicked();

    void on_restart_radioButton_toggled(bool checked);

    void on_shutdown_radioButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    const int m_maxHourValue;       //< max number of posibily hours to count
    const int m_maxMinuteValue;     //< max number of posibily minutes to count
    const QSize m_applicationSize;  //< max size of application
    CCounter::ShutdownOption m_shutdownOption;

    QTime m_time;

};

#endif // MAINWINDOW_H
