#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->centralWidget->setContentsMargins(10, 10, 10 ,10);
    this->ui->horizontalSlider->setEnabled(false);
    selectPoint();
    setMenu();
    this->image = (ImageLabel*)this->ui->imageLabel;
    setAction();
    this->statusLabelWidget = new StatusLabelWidget(this);
    this->dialogSetting = new SettingDialog(this);
    this->ui->statusBar->addWidget(this->statusLabelWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAction()
{
    QObject::connect(actionOpenFileDialog, SIGNAL(triggered()), this, SLOT(openLoadFileDialog()));
    QObject::connect(actionSetting, SIGNAL(triggered()), this, SLOT(openSettingDialog()));
    QObject::connect(this->ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(changeFrame(int)));
    QObject::connect(this->ui->actionPoint, SIGNAL(triggered()), this, SLOT(selectPoint()));
    QObject::connect(this->ui->actionSpiltHead, SIGNAL(triggered()), this, SLOT(selectSpiltHead()));
    QObject::connect(this->ui->actionSpiltHip, SIGNAL(triggered()), this, SLOT(selectSpiltHip()));
}

void MainWindow::openLoadFileDialog()
{
//    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
//    string folderPath = dir.toStdString();
    string folderPath = "/home/lexhuang/humanSample/";
//    string folderPath = "/home/lexhuang/1m2m/";
    model.setFolderPath(folderPath);
    this->ui->horizontalSlider->setRange(0, model.getFileCount() - 1);
    this->ui->horizontalSlider->setValue(0);
    changeFrame(0);
    this->ui->horizontalSlider->setEnabled(true);
    this->ui->horizontalSlider->setFocus();
}

void MainWindow::openSettingDialog()
{
    this->dialogSetting->show();
}

void MainWindow::selectSpiltHead()
{
    this->ui->actionPoint->setChecked(false);
    this->ui->actionSpiltHead->setChecked(true);
    this->ui->actionSpiltHip->setChecked(false);
}

void MainWindow::selectSpiltHip()
{
    this->ui->actionPoint->setChecked(false);
    this->ui->actionSpiltHead->setChecked(false);
    this->ui->actionSpiltHip->setChecked(true);
}

void MainWindow::selectPoint()
{
    this->ui->actionPoint->setChecked(true);
    this->ui->actionSpiltHead->setChecked(false);
    this->ui->actionSpiltHip->setChecked(false);
}

void MainWindow::changeFrame(int value)
{
    model.setNowId(value);
    this->ui->fileCountlabel->setText(QString::fromStdString(BasicHelper::intToString(model.getNowFileId() + 1) + "/" + BasicHelper::intToString(model.getFileCount())));
    this->ui->fileNameLabel->setText(QString::fromStdString(model.getNowFileName()));
    image->loadMatFromFilepath(model.getNowFilePath());
}

void MainWindow::setMenu()
{
    menuBar = new QMenuBar(this);
    menuBar->setObjectName(QString::fromUtf8("menubar"));
    menuBar->setGeometry(QRect(0, 0, 200, 100));
    actionOpenFileDialog = new QAction(this);
    actionOpenFileDialog->setObjectName(QString::fromUtf8("open file"));
    actionOpenFileDialog->setText("Open file");
    actionSetting = new QAction(this);
    actionSetting->setObjectName(QString::fromUtf8("Setting"));
    actionSetting->setText("Setting");
//    menuFile = new QMenu(menuBar);
//    menuFile->setTitle("File");
//    menuFile->addAction(actionOpenFileDialog);
//    menuFile->setObjectName(QString::fromUtf8("File"));
    menuBar->addAction(actionOpenFileDialog);
    menuBar->addAction(actionSetting);
    this->setMenuBar(menuBar);
}
