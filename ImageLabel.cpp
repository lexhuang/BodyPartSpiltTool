#include "ImageLabel.h"

ImageLabel::ImageLabel(QWidget * parent = 0) : QLabel(parent)
{

}

ImageLabel::~ImageLabel()
{

}

void ImageLabel::refreshImage(Mat frameProcess)
{
    this->setPixmap(QPixmap::fromImage(Mat2QImage(frameProcess)));
}
Rect ImageLabel::getHeadRectangle() const
{
    return headRectangle;
}

void ImageLabel::setHeadRectangle(const Rect &value)
{
    headRectangle = value;
}
Rect ImageLabel::getHipRectangle() const
{
    return hipRectangle;
}

void ImageLabel::setHipRectangle(const Rect &value)
{
    hipRectangle = value;
}



void ImageLabel::setMat(Mat frameProcess)
{
    this->frameProcess = frameProcess;
    refreshImage(frameProcess);
}

void ImageLabel::mouseMoveEvent(QMouseEvent *event)
{

}

void ImageLabel::mousePressEvent(QMouseEvent *event)
{
//    int x = event->x();
//    int y = event->y();
    headRectangle.x = x;
    headRectangle.y = y;
    Mat frameShow;
    this->frameProcess.copyTo(frameShow);
    circle(frameShow, Point(x,y), 1, Scalar(255, 255, 255));
    refreshImage(frameShow);
}

void ImageLabel::mouseReleaseEvent(QMouseEvent *event)
{

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

