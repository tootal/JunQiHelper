#include "mouseclickdialog.h"
#include "ui_mouseclickdialog.h"

#include "GlobalHook/globalhook.h"

MouseClickDialog::MouseClickDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MouseClickDialog)
{
    ui->setupUi(this);
    GHOOK->installKeyHook();
}

MouseClickDialog::~MouseClickDialog()
{
    delete ui;
}
