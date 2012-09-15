#include "extendedtheoryselectingdialog.h"
#include "ui_extendedtheoryselectingdialog.h"

ExtendedTheorySelectingDialog::ExtendedTheorySelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtendedTheorySelectingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

ExtendedTheorySelectingDialog::~ExtendedTheorySelectingDialog()
{
    delete ui;
}

void ExtendedTheorySelectingDialog::on_okPushButton_clicked()
{

}

void ExtendedTheorySelectingDialog::on_canselPushButton_clicked()
{
    this->close();
}
