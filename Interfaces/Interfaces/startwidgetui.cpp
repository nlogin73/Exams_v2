#include "startwidgetui.h"
#include "ui_startwidgetui.h"

StartWidgetUI::StartWidgetUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWidgetUI)
{
    ui->setupUi(this);
}

StartWidgetUI::~StartWidgetUI()
{
    delete ui;
}
