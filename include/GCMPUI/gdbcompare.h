#pragma once
#ifndef GDBCOMPARE_H
#define GDBCOMPARE_H
#include "GCMPUI/gcmpframelesswidget.h"
#include "GCMPUI/gcmpui_global.h"

//������
class GCMPUI_EXPORT GDBCompare : public GCMPFramelessWidget
{
    Q_OBJECT

public:
    GDBCompare(const QString strTitle, GCMPFrameTitleStyle oStyle, QWidget *pCenterWidget, GCMPFrameBorderStyle oFrameBorderStyle, QWidget* pParent = 0);
    ~GDBCompare();

public:

};

#endif // GDBCOMPARE_H
