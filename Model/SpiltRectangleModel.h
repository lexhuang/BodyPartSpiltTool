#ifndef SPILTRECTANGLEMODEL_H
#define SPILTRECTANGLEMODEL_H

#include <QFileDialog>
#include <QDirIterator>

#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include "BasicHelper.h"


using namespace std;
using namespace cv;

class SpiltRectangleModel
{
private:
    string folderPath;
    QStringList filePaths;
    QDir dir;
    int nowId;
public:
    const static string YML_TYPE;
    const static string BMP_TYPE;
    const static string FILTER_TYPE;
    SpiltRectangleModel();
    ~SpiltRectangleModel();
    string getFolderPath() const;
    void setFolderPath(const string &value);
    void getAllFileFromFolder();
    int getNowFileId();
    int getFileCount();
    string getNowFileName();
    string getNowFilePath();
    int getNowId() const;
    void setNowId(int value);
    void saveFrameToBMP(Mat frame);
};

#endif // SPILTRECTANGLEMODEL_H
