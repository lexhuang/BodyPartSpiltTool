#include "StatusLabelWidget.h"
#include "ui_StatusLabelWidget.h"

StatusLabelWidget::StatusLabelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatusLabelWidget)
{
    ui->setupUi(this);
}

StatusLabelWidget::~StatusLabelWidget()
{
    delete ui;
}
