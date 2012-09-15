#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QList>
#include <QMouseEvent>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    QList<QDialog *> dialogs;
    int index;
};

#endif // MAINWINDOW_H
