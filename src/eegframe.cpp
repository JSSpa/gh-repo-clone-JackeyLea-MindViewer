#include "eegframe.h"

EEGFrame::EEGFrame(QFrame *parent)
    :QFrame(parent)
      ,m_maxCnt(100)
    ,m_penColor(qRgb(0,255,0))
    ,m_step(100)
{
    m_buff.clear();
    for(int i=0;i<100;i++){
        m_buff.append(i);
    }

    //两个点的x坐标差值
    m_step = (int)(1080/m_maxCnt);//1080x720
}

EEGFrame::~EEGFrame()
{

}

void EEGFrame::setCurveColor(QColor c)
{
    m_penColor = c;
}

void EEGFrame::appendPoint()
{
    //超过数量就把头部删除
    if(m_buff.size()>m_maxCnt){
        m_buff.pop_front();
    }
    m_buff.append(100);
}

void EEGFrame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(m_penColor);

    //画折线
    for(int i=1;i<m_buff.size();i++){
        painter.drawLine((i-1)*m_step,m_buff[i-1],i*m_step,m_buff[i]);
    }
}
