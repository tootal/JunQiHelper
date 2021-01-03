#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

#include "mouseclickdialog.h"
#include "GlobalHook/globalhook.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_Mouse_Click_triggered()
{
    auto dialog = new MouseClickDialog(this);
    dialog->show();
}

void MainWindow::on_action_About_triggered()
{
    auto dllname = GlobalHook::name();
    auto v = GlobalHook::version();
    auto dllverstr = QString("%3.%2.%1")
            .arg((v >> 0x0) & 0xFF)
            .arg((v >> 0x8) & 0xFF)
            .arg((v >> 0x10) & 0xFF);
    QMessageBox::about(this, qAppName(),
                       QString("%1: %2").arg(dllname, dllverstr));
}
