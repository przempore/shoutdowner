#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boost/shared_ptr.hpp>
#include "ctimecontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_hours_spinBox_valueChanged(int arg1);

    void on_minutes_spinBox_valueChanged(int arg1);

    void on_start_button_clicked();

    void on_restart_radioButton_toggled(bool checked);

    void on_shutdown_radioButton_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    const int m_maxHourValue;
    const int m_maxMinuteValue;
    QSize m_applicationSize;
    boost::shared_ptr< SD::Logic::CTimeController > m_pTimeControl;
};

#endif // MAINWINDOW_H
