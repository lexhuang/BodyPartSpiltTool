#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QMouseEvent>
#include <QLabel>

#include <opencv2/core/core.hpp>

using namespace cv;

class ImageLabel : public QLabel
{
public:
    ImageLabel(QWidget * parent);
    ~ImageLabel();
    void setMat(Mat frameProcess);
    static QImage Mat2QImage(Mat const& src);
    void refreshImage(Mat frameProcess);
    Rect getHeadRectangle() const;
    void setHeadRectangle(const Rect &value);
    Rect getHipRectangle() const;
    void setHipRectangle(const Rect &value);
private:
    Mat frameProcess;
    Rect headRectangle;
    Rect hipRectangle;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // IMAGELABEL_H
