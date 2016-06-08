#ifndef GCMPCENTERWIDGET_H
#define GCMPCENTERWIDGET_H

#include <QWidget>
#include "GCMPUI/gcmptabwidget.h"
#include "GCMPUI/gcmpmousemanager.h"
#include "GCMPUI/gcmpui_global.h"

class GCMPUI_EXPORT GCMPCenterWidget : public QWidget
{
    Q_OBJECT

public:
    GCMPCenterWidget(GCMPTabWidget* pTab, QWidget *parent = 0);
    ~GCMPCenterWidget();

private:
    GCMPTabWidget* m_pTabWidget;
};

#endif // GCMPCENTERWIDGET_H
