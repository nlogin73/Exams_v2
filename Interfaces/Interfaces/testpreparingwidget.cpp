#include "testpreparingwidget.h"
#include "ui_testpreparingwidget.h"

TestPreparingWidget::TestPreparingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestPreparingWidget)
{
    ui->setupUi(this);

    QVBoxLayout *vb = new QVBoxLayout;
    vb->setContentsMargins(0, 0, 0, 0);
    vb->setSpacing(0);
    ui->scrollAreaWidgetContents->setLayout(vb);

    for (int i = 1; i < 21; i++)
    {
        QPushButton *pb = new QPushButton();
        pb->setObjectName("navigationButton_" + QString::number(i, 10));
        pb->setFlat(true);
        pb->setText("navigationButton_" + QString::number(i, 10));
        pb->setFixedHeight(45);
        pb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);


        ui->scrollAreaWidgetContents->layout()->addWidget(pb);
    }
}

TestPreparingWidget::~TestPreparingWidget()
{
    delete ui;
}
