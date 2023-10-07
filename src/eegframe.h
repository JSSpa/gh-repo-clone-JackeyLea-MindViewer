#ifndef EEGFRAME_H
#define EEGFRAME_H

#include <QFrame>

class EEGFrame : public QFrame
{
public:
    EEGFrame();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // EEGFRAME_H
