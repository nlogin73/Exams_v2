#ifndef TESTRESULTSDIALOG_H
#define TESTRESULTSDIALOG_H

#include <QDialog>

namespace Ui {
    class TestResultsDialog;
}

class TestResultsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestResultsDialog(QWidget *parent = 0);
    ~TestResultsDialog();

private slots:
    void on_canselPushButton_clicked();

private:
    Ui::TestResultsDialog *ui;
};

#endif // TESTRESULTSDIALOG_H
