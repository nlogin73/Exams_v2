#include "learningtestselectingdialog.h"
#include "ui_learningtestselectingdialog.h"

LearningTestSelectingDialog::LearningTestSelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LearningTestSelectingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

LearningTestSelectingDialog::~LearningTestSelectingDialog()
{
    delete ui;
}

void LearningTestSelectingDialog::on_canselPushButton_clicked()
{
    this->close();
}
