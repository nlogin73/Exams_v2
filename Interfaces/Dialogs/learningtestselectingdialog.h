#ifndef LEARNINGTESTSELECTINGDIALOG_H
#define LEARNINGTESTSELECTINGDIALOG_H

#include <QDialog>

namespace Ui {
    class LearningTestSelectingDialog;
}

class LearningTestSelectingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LearningTestSelectingDialog(QWidget *parent = 0);
    ~LearningTestSelectingDialog();

private slots:
    void on_canselPushButton_clicked();

private:
    Ui::LearningTestSelectingDialog *ui;
};

#endif // LEARNINGTESTSELECTINGDIALOG_H
