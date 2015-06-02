#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include <QDirIterator>
#include "ImageLabel.h"

#include <string>
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    const static string FILE_TYPE;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setMenu();
    void setAction();
private:
    Ui::MainWindow *ui;
    QMenuBar* menuBar;
    QMenu* menuFile;
    QAction* actionOpenFileDialog;
    ImageLabel* image;
    QDirIterator* dirIterator;
    vector<string> filePaths;
    Mat processFrame;
    Mat phaseDataFloat;
signals:

public slots:
    void openLoadFileDialog();
    void imageLabelLeftButtonDown();
    void imageLabelLeftButtonMove();
    void imageLabelLeftButtonUp();
};

#endif // MAINWINDOW_H
