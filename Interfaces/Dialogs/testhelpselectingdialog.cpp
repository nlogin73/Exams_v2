#include "testhelpselectingdialog.h"
#include "ui_testhelpselectingdialog.h"

TestHelpSelectingDialog::TestHelpSelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestHelpSelectingDialog)
{
    ui->setupUi(this);
}

TestHelpSelectingDialog::~TestHelpSelectingDialog()
{
    delete ui;
}

void TestHelpSelectingDialog::on_canselPushButton_clicked()
{
    this->close();
}
