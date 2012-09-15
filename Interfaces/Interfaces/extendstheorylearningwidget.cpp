#include "extendstheorylearningwidget.h"
#include "ui_extendstheorylearningwidget.h"

ExtendsTheoryLearningWidget::ExtendsTheoryLearningWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExtendsTheoryLearningWidget)
{
    ui->setupUi(this);
}

ExtendsTheoryLearningWidget::~ExtendsTheoryLearningWidget()
{
    delete ui;
}
