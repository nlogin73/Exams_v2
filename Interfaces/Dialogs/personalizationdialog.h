#ifndef PERSONALIZATIONDIALOG_H
#define PERSONALIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
    class PersonalizationDialog;
}

class PersonalizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalizationDialog(QWidget *parent = 0);
    ~PersonalizationDialog();

private slots:
    void on_okPushButton_clicked();

    void on_canselPushButton_clicked();

private:
    Ui::PersonalizationDialog *ui;
};

#endif // PERSONALIZATIONDIALOG_H
