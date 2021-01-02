#include "mouseclickdialog.h"
#include "ui_mouseclickdialog.h"

MouseClickDialog::MouseClickDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MouseClickDialog)
{
    ui->setupUi(this);
}

MouseClickDialog::~MouseClickDialog()
{
    delete ui;
}
