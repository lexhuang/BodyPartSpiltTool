#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QMouseEvent>
#include <QLabel>
#include <iostream>

#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

class ImageLabel : public QLabel
{
public:
    ImageLabel(QWidget * parent);
    ~ImageLabel();
    static QImage Mat2QImage(Mat const& src);
    void refreshImage(Mat frameProcess);
    bool loadMatFromFilepath(string path);
    Rect getChooseRectangle() const;
    void setChooseRectangle(const Rect &value);
    Mat getFrameProcess() const;
    void setFrameProcess(const Mat &value);
    Mat getFramePhaseData() const;
    void setFramePhaseData(const Mat &value);
private:
    Mat framePhaseData;
    Mat frameProcess;
    Mat frameShow;
    vector<Mat> framesSample;
    Rect chooseRectangle;
    bool isTimeSample;
    int sampleCount;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // IMAGELABEL_H
