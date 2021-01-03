#include "mouseclickdialog.h"
#include "ui_mouseclickdialog.h"

#include "GlobalHook/globalhook.h"

MouseClickDialog::MouseClickDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MouseClickDialog)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    GHOOK->installKeyHook();
}

MouseClickDialog::~MouseClickDialog()
{
    GHOOK->uninstallKeyHook();
    delete ui;
}
