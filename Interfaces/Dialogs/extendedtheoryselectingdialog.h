#ifndef EXTENDEDTHEORYSELECTINGDIALOG_H
#define EXTENDEDTHEORYSELECTINGDIALOG_H

#include <QDialog>

namespace Ui {
    class ExtendedTheorySelectingDialog;
}

class ExtendedTheorySelectingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExtendedTheorySelectingDialog(QWidget *parent = 0);
    ~ExtendedTheorySelectingDialog();

private slots:
    void on_okPushButton_clicked();

    void on_canselPushButton_clicked();

private:
    Ui::ExtendedTheorySelectingDialog *ui;
};

#endif // EXTENDEDTHEORYSELECTINGDIALOG_H
