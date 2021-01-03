#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "GlobalHook/globalhook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Mouse_Click_triggered();

    void on_action_About_triggered();

private:
    Ui::MainWindow *ui;
    GlobalHook globalHook;
};
#endif // MAINWINDOW_H
