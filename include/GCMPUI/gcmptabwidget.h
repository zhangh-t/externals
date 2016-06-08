#pragma once
#ifndef GCMPTABWIDGET_H
#define GCMPTABWIDGET_H

#include <QTabWidget>
#include "GCMPUI/gcmpui_global.h"
#include "GCMPUI/GCMPTabDataStructure.h"
#include "GCMPUI/gcmpmousemanager.h"


class GCMPContainerWidget : public QWidget, public GCMPMouseListener
{
    Q_OBJECT
public:
    GCMPContainerWidget(QWidget* pParent = nullptr)
        :QWidget(pParent){}

    GCMPContainerWidget(GCMPToolBar* pToolBar, QWidget* pMain, QWidget* pParent = nullptr);

    virtual ~GCMPContainerWidget() {}

public:
    GCMPToolBar* toolBar() { return m_pToolBar; }
    QWidget* mainWidget() { return m_pMain; }
private:
    GCMPToolBar* m_pToolBar;
    QWidget* m_pMain;
};

enum GCMPUI_EXPORT GCMPTabMode
{
    gtmTabToolBarOnly = 0,          //切换页签时只切换工具条
    gtmTabToolBarAndMainWidget,     //工具条带主窗体一起切换
};


class GCMPUI_EXPORT GCMPTabWidget : public QWidget
{
    Q_OBJECT

public:
    GCMPTabWidget(GCMPTabMode oTabMode = gtmTabToolBarAndMainWidget, QWidget *parent = 0);
    ~GCMPTabWidget();

public:
    void addTabDataStructure(GCMPTabDataStructure* pTabData);

    void reLayoutAt(int nIndex);

    void reLayoutCur();

    void setCurrentIndex(int nIndex) { m_pTab->setCurrentIndex(nIndex); }
public:
    void loadQSS();

private:
    std::vector<GCMPTabDataStructure*> m_vecTabDataStruct;
    GCMPTabMode m_oMode;
    QTabWidget* m_pTab;
    bool m_bInitedForToolBarOnly;
};

#endif // GCMPTABWIDGET_H
