#ifndef MOUSECLICKDIALOG_H
#define MOUSECLICKDIALOG_H

#include <QDialog>

namespace Ui {
class MouseClickDialog;
}

class MouseClickDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MouseClickDialog(QWidget *parent = nullptr);
    ~MouseClickDialog();

private:
    Ui::MouseClickDialog *ui;
};

#endif // MOUSECLICKDIALOG_H
