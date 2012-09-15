#ifndef TESTHELPSELECTINGDIALOG_H
#define TESTHELPSELECTINGDIALOG_H

#include <QDialog>

namespace Ui {
    class TestHelpSelectingDialog;
}

class TestHelpSelectingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestHelpSelectingDialog(QWidget *parent = 0);
    ~TestHelpSelectingDialog();

private slots:
    void on_canselPushButton_clicked();

private:
    Ui::TestHelpSelectingDialog *ui;
};

#endif // TESTHELPSELECTINGDIALOG_H
