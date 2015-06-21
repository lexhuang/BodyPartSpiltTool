#ifndef STATUSLABELWIDGET_H
#define STATUSLABELWIDGET_H

#include <QWidget>

namespace Ui {
class StatusLabelWidget;
}

class StatusLabelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusLabelWidget(QWidget *parent = 0);
    ~StatusLabelWidget();

private:
    Ui::StatusLabelWidget *ui;
};

#endif // STATUSLABELWIDGET_H
