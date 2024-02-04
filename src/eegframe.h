#ifndef EEGFRAME_H
#define EEGFRAME_H

#include <QFrame>
#include <QPainter>

class EEGFrame : public QFrame
{
public:
    EEGFrame(QFrame *parent = nullptr);
    ~EEGFrame();

    void setCurveColor(QColor c);
    void appendPoint();

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_maxCnt;//最大点数
    QColor m_penColor;//折线颜色
    QVector<float> m_buff;
    int m_step;
};

#endif // EEGFRAME_H
