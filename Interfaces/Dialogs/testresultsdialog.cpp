#include "testresultsdialog.h"
#include "ui_testresultsdialog.h"

TestResultsDialog::TestResultsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestResultsDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

TestResultsDialog::~TestResultsDialog()
{
    delete ui;
}

void TestResultsDialog::on_canselPushButton_clicked()
{
    this->close();
}
