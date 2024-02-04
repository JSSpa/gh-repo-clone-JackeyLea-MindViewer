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
    int m_maxCnt;//������
    QColor m_penColor;//������ɫ
    QVector<float> m_buff;
    int m_step;
};

#endif // EEGFRAME_H
