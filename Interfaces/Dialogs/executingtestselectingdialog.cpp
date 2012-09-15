#include "executingtestselectingdialog.h"
#include "ui_executingtestselectingdialog.h"

ExecutingTestSelectingDialog::ExecutingTestSelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExecutingTestSelectingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

ExecutingTestSelectingDialog::~ExecutingTestSelectingDialog()
{
    delete ui;
}

void ExecutingTestSelectingDialog::on_canselPushButton_clicked()
{
    this->close();
}
