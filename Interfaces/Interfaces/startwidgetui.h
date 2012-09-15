#ifndef STARTWIDGETUI_H
#define STARTWIDGETUI_H

#include <QWidget>

namespace Ui {
class StartWidgetUI;
}

class StartWidgetUI : public QWidget
{
    Q_OBJECT
    
public:
    explicit StartWidgetUI(QWidget *parent = 0);
    ~StartWidgetUI();
    
private:
    Ui::StartWidgetUI *ui;
};

#endif // STARTWIDGETUI_H
