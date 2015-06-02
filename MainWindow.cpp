#include "MainWindow.h"
#include "ui_MainWindow.h"

const string MainWindow::FILE_TYPE = ".yml";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->centralWidget->setContentsMargins(10, 10, 10 ,10);
//    this->resize(1280, 720);
    setMenu();
    this->image = (ImageLabel*)this->ui->label;
    setAction();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAction()
{
    QObject::connect(actionOpenFileDialog, SIGNAL(triggered()), this, SLOT(openLoadFileDialog()));
//    QOjbect::connect()
}

void MainWindow::openLoadFileDialog()
{
//    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
//    string folderName = dir.toStdString();
    string folderName = "/home/lexhuang/humanSample/";
//    string folderName = "/home/lexhuang/1m2m/";

    dirIterator = new QDirIterator(QString::fromStdString(folderName), QDirIterator::Subdirectories);
    while (dirIterator->hasNext()) {
        string name = dirIterator->next().toStdString();
        if( name.at(name.length() - 1) == FILE_TYPE.at(FILE_TYPE.length() - 1) &&
            name.at(name.length() - 2) == FILE_TYPE.at(FILE_TYPE.length() - 2) &&
            name.at(name.length() - 3) == FILE_TYPE.at(FILE_TYPE.length() - 3)){
            filePaths.push_back(name);
            cout << name << endl;
        }
    }
    FileStorage fs(filePaths.at(0), FileStorage::READ );
    fs["process"] >> processFrame;
    fs["float"] >> phaseDataFloat;
    image->setMat(processFrame);
}

void MainWindow::imageLabelLeftButtonDown()
{

}

void MainWindow::imageLabelLeftButtonMove()
{

}

void MainWindow::imageLabelLeftButtonUp()
{

}

void MainWindow::setMenu()
{
    menuBar = new QMenuBar(this);
    menuBar->setObjectName(QString::fromUtf8("menubar"));
    menuBar->setGeometry(QRect(0, 0, 200, 100));
    actionOpenFileDialog = new QAction(this);
    actionOpenFileDialog->setObjectName(QString::fromUtf8("open file"));
    actionOpenFileDialog->setText("Open file");
    menuFile = new QMenu(menuBar);
    menuFile->setTitle("File");
    menuFile->addAction(actionOpenFileDialog);
    menuFile->setObjectName(QString::fromUtf8("File"));
    menuBar->addAction(menuFile->menuAction());
    this->setMenuBar(menuBar);
}
