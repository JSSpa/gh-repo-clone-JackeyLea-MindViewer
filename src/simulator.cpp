#include "simulator.h"

Simulator::Simulator(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);//һ���ӷ�һ�ΰ�
    connect(m_timer,&QTimer::timeout,[=](){
        QByteArray buff;
        buff.clear();

        buff = getFixPackage();//TODO

        emit sendPackage(buff);
    });
    m_timer->start();
}

Simulator::~Simulator()
{
    if(m_timer->isActive()){
        m_timer->stop();
    }
    m_timer->deleteLater();
}
//һ���������512��ԭʼ��ֵ����EEG��
QByteArray Simulator::getFixPackage()
{
    QByteArray buff;
    buff.clear();

    //ԭʼֵ
    for(int i=0;i<512;i++){
        buff.append(0xAA);
        buff.append(0xAA);
        buff.append(0x04);//����С
        buff.append(0x80);//ԭʼ���ݱ�־
        buff.append(0x02);//���ݴ�С
        if(i%2==0){//���֣�Ҫ��Ȼ����һ��ֱ����
            buff.append(0xFC);
            buff.append(0xEE);
            buff.append(0x93);
        }else{
            buff.append(0xFA);
            buff.append(0x79);
            buff.append(0x0A);
        }
    }

    //EEG
    buff.append(0xAA);
    buff.append(0xAA);
    buff.append(0x20);//����С
    buff.append(0x02);//�ź�ֵ
    buff.append(0xc8);
    buff.append(0x83);//EEG
    buff.append(0x18);//EEG��СΪ24��
    buff.append(0x18);// delta 1/3
    buff.append(0xd4);// delta 2/3
    buff.append(0x8b);// delta 3/3
    buff.append(0x13);// theta 1/3
    buff.append(0xd1);// theta 2/3
    buff.append(0x69);// theta 3/3
    buff.append(0x02);// LowAlpha 1/3
    buff.append(0x58);// LowAlpha 2/3
    buff.append(0xc1);// LowAlpha 3/3
    buff.append(0x17);// HighAlpha 1/3
    buff.append(0x3b);// HighAlpha 2/3
    buff.append(0xdc);// HighAlpha 3/3
    buff.append(0x02);// LowBeta 1/3
    buff.append(0x50);// LowBeta 2/3
    buff.append((char)0x00);// LowBeta 3/3
    buff.append(0x03);// HighBeta 1/3
    buff.append(0xcb);// HighBeta 2/3
    buff.append(0x9d);// HighBeta 3/3
    buff.append(0x03);// LowGamma 1/3
    buff.append(0x6d);// LowGamma 2/3
    buff.append(0x3b);// LowGamma 3/3
    buff.append(0x03);// MiddleGamma 1/3
    buff.append(0x7e);// MiddleGamma 2/3
    buff.append(0x89);// MiddleGamma 3/3
    buff.append(0x04);// רע��
    buff.append((char)0x00);
    buff.append(0x05);// ���ɶ�
    buff.append((char)0x00);
    buff.append(0xd5);

    return buff;
}

QByteArray Simulator::getRandomPackage()
{
    QByteArray buff;
    buff.clear();

    return buff;
}
