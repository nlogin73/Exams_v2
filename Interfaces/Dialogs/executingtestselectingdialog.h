#ifndef EXECUTINGTESTSELECTINGDIALOG_H
#define EXECUTINGTESTSELECTINGDIALOG_H

#include <QDialog>

namespace Ui {
class ExecutingTestSelectingDialog;
}

class ExecutingTestSelectingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ExecutingTestSelectingDialog(QWidget *parent = 0);
    ~ExecutingTestSelectingDialog();
    
private slots:
    void on_canselPushButton_clicked();

private:
    Ui::ExecutingTestSelectingDialog *ui;
};

#endif // EXECUTINGTESTSELECTINGDIALOG_H
