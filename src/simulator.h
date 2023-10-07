/////////////////////////////////////////////
///
/// \author jacky lea
/// \date 2020-12-26
/// \note 用于产生测试数据
///
////////////////////////////////////////////

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QObject>
#include <QTimer>
#include <QThread>
#include <QRandomGenerator>

inline int getNum(int max){
    return QRandomGenerator::global()->bounded(0,max);
}

inline bool getBool(){
    return getNum(2);
}

inline QByteArray getOne(uchar mn, int max){
    QByteArray data;
    data.append(mn);
    data.append(getNum(max));
    return data;
}

class Simulator : public QObject
{
    Q_OBJECT
public:
    explicit Simulator(QObject *parent = nullptr);
    ~Simulator();

    QByteArray getFixPackage();
    QByteArray getRandomPackage();

signals:
    void sendPackage(QByteArray ba);

private:
    QTimer *m_timer;
};

#endif // SIMULATOR_H
