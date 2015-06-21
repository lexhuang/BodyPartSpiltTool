#include "ImageLabel.h"

ImageLabel::ImageLabel(QWidget * parent = 0) : QLabel(parent)
{
    isTimeSample = false;
}

ImageLabel::~ImageLabel()
{

}

void ImageLabel::refreshImage(Mat frameProcess)
{
    this->setPixmap(QPixmap::fromImage(Mat2QImage(frameProcess)));
}

string int2str(int i) {
    string s;
    stringstream ss(s);
    ss << i;

    return ss.str();
}

bool ImageLabel::loadMatFromFilepath(string path)
{
    FileStorage fs(path, FileStorage::READ );
    fs["process"] >> frameProcess;
    fs["float"] >> framePhaseData;
    fs["isTimeSample"] >> isTimeSample;
    fs["smapleCount"] >> sampleCount;
    framesSample.clear();
    if(isTimeSample){
        for(int i = 0; i < sampleCount; i++){
            Mat temp;
            fs["time" + int2str(i)] >> temp;
            framesSample.push_back(temp);
        }
    }
    refreshImage(frameProcess);
}

Rect ImageLabel::getChooseRectangle() const
{
    return chooseRectangle;
}

void ImageLabel::setChooseRectangle(const Rect &value)
{
    chooseRectangle = value;
}

Mat ImageLabel::getFrameProcess() const
{
    return frameProcess;
}

void ImageLabel::setFrameProcess(const Mat &value)
{
    frameProcess = value;
}

Mat ImageLabel::getFramePhaseData() const
{
    return framePhaseData;
}

void ImageLabel::setFramePhaseData(const Mat &value)
{
    framePhaseData = value;
}

void ImageLabel::mouseMoveEvent(QMouseEvent *event)
{
    chooseRectangle.width = event->x() - chooseRectangle.x;
    chooseRectangle.height = event->y() - chooseRectangle.y;
    this->frameProcess.copyTo(frameShow);
    rectangle(frameShow, chooseRectangle, Scalar(255,255,255));
    refreshImage(frameShow);
}

void ImageLabel::mousePressEvent(QMouseEvent *event)
{
    chooseRectangle.width = 0;
    chooseRectangle.height = 0;
    chooseRectangle.x = event->x();
    chooseRectangle.y = event->y();
    this->frameProcess.copyTo(frameShow);
//    circle(frameShow, Point(x,y), 1, Scalar(255, 255, 255));
    rectangle(frameShow, chooseRectangle, Scalar(255,255,255));
    refreshImage(frameShow);
}

void ImageLabel::mouseReleaseEvent(QMouseEvent *event)
{
    cout << framePhaseData.at<u_int16_t>(event->y(), event->x()) << endl;
    if(isTimeSample){
        for(int i = 0; i < framesSample.size(); i++){
            cout << framesSample.at(i).at<u_int32_t>(event->y(), event->x()) << " ";
        }
        cout << endl;
    }
}

QImage ImageLabel::Mat2QImage(Mat const& src)
{
    Mat temp = src; // make the same cv::Mat
    //Do cvtColor only if color map needs to be inverted
    //Mat temp;
    //cvtColor(src, temp,CV_BGR2RGB);
    QImage dest((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    QImage dest2(dest);
    dest2.detach(); // enforce deep copy
    return dest2;
}

