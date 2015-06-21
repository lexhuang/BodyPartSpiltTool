#include "SpiltRectangleModel.h"

const string SpiltRectangleModel::FILTER_TYPE = "*.yml";
const string SpiltRectangleModel::YML_TYPE = ".yml";
const string SpiltRectangleModel::BMP_TYPE = ".bmp";

string SpiltRectangleModel::getFolderPath() const
{
    return folderPath;
}

void SpiltRectangleModel::getAllFileFromFolder()
{
    dir = QDir(QString::fromStdString(folderPath));
    dir.setNameFilters(QStringList(QString::fromStdString(FILTER_TYPE)));
    dir.setSorting(QDir::LocaleAware);
    filePaths = dir.entryList();
}

int SpiltRectangleModel::getNowFileId()
{
    return nowId;
}

int SpiltRectangleModel::getFileCount()
{
    return filePaths.size();
}

string SpiltRectangleModel::getNowFileName()
{
    return filePaths.at(nowId).toStdString();
}

string SpiltRectangleModel::getNowFilePath()
{
    return (dir.absolutePath() + QDir::separator() + this->filePaths.at(nowId)).toStdString();
}

void SpiltRectangleModel::setFolderPath(const string &value)
{
    folderPath = value;
    getAllFileFromFolder();
}


int SpiltRectangleModel::getNowId() const
{
    return nowId;
}

void SpiltRectangleModel::setNowId(int value)
{
    nowId = value;
}

void SpiltRectangleModel::saveFrameToBMP(Mat frame)
{
    QString name = filePaths.at(nowId);
    name = name.replace(QString::fromStdString(YML_TYPE), QString::fromStdString(BMP_TYPE));
    imwrite(name.toStdString(), frame);
}

SpiltRectangleModel::SpiltRectangleModel()
{
    nowId = 0;
}

SpiltRectangleModel::~SpiltRectangleModel()
{

}

