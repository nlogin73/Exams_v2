#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "executingtestselectingdialog.h"
#include "extendedtheoryselectingdialog.h"
#include "learningtestselectingdialog.h"
#include "personalizationdialog.h"
#include "testhelpselectingdialog.h"
#include "testresultsdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialogs.append(new ExecutingTestSelectingDialog);
    dialogs.append(new ExtendedTheorySelectingDialog);
    dialogs.append(new LearningTestSelectingDialog);
    dialogs.append(new PersonalizationDialog);
    dialogs.append(new TestHelpSelectingDialog);
    dialogs.append(new TestResultsDialog);

    index = 0;
}

MainWindow::~MainWindow()
{
    delete ui;

    for (int i = 0; i < dialogs.length(); i++)
    {
        delete dialogs.at(i);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int key = event->button();
    if (key == Qt::LeftButton)
    {
        if (index - 1 >= 0)
        {
            index--;
            dialogs.at(index)->exec();
        }
        else
        {
            index = dialogs.count() - 1;
            dialogs.at(index)->exec();
        }
    }

    if (key == Qt::RightButton)
    {
        if (index + 1 < dialogs.length())
        {
            index++;
            dialogs.at(index)->exec();
        }
        else
        {
            index = 0;
            dialogs.at(index)->exec();
        }
    }
    event->ignore();
   // event->accept();
}
