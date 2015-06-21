#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "ImageLabel.h"

#include <string>
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "SpiltRectangleModel.h"
#include "SettingDialog.h"
#include "StatusLabelWidget.h"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setMenu();
    void setAction();
private:
    Ui::MainWindow *ui;
    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionOpenFileDialog;
    QAction* actionSetting;
    ImageLabel* image;
    SettingDialog* dialogSetting;
    StatusLabelWidget* statusLabelWidget;
    SpiltRectangleModel model;

signals:

public slots:
    void openLoadFileDialog();
    void openSettingDialog();
    void selectSpiltHead();
    void selectSpiltHip();
    void selectPoint();
    void changeFrame(int value);
};

#endif // MAINWINDOW_H
