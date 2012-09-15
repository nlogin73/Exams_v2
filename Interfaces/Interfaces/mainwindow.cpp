#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(new ExtendsTheoryLearningWidget());
    ui->stackedWidget->addWidget(new StartWidgetUI());
    ui->stackedWidget->addWidget(new TestingWidget());
    ui->stackedWidget->addWidget(new TestPreparingWidget());

    ui->stackedWidget->setCurrentIndex(0);

    setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int key = event->button();
    if (key == Qt::LeftButton)
    {
        int index = ui->stackedWidget->currentIndex();
        if (index - 1 >= 0)
        {
            ui->stackedWidget->setCurrentIndex(index - 1);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
        }
    }

    if (key == Qt::RightButton)
    {
        int index = ui->stackedWidget->currentIndex();
        if (index + 1 < ui->stackedWidget->count())
        {
            ui->stackedWidget->setCurrentIndex(index + 1);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    event->ignore();
   // event->accept();
}
