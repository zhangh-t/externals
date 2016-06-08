#ifndef GCMPDBCOMPARETABLEWIDGET_H
#define GCMPDBCOMPARETABLEWIDGET_H

#include "GCMPUI/gcmpwidget.h"

class GCMPDBCompareTableWidget : public GCMPWidget
{
    Q_OBJECT

public:
    GCMPDBCompareTableWidget(QWidget *parent = 0);

    ~GCMPDBCompareTableWidget();

protected:
    virtual void paintEvent(QPaintEvent* e);
private:

};

#endif // GCMPDBCOMPARETABLEWIDGET_H
