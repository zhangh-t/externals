#pragma once
#include "GCMPUI/gcmpui_global.h"
#include "GCMPUI/gcmptoolbar.h"
#include "GCMPUI/gcmpmousemanager.h"
// һ��ҳǩ
//һ��ҳǩ�� -> 1��toolbar
//          -> 1��Widget
//���ҳǩ���Զ�Ӧ���Widget
class GCMPUI_EXPORT GCMPTabDataStructure : public QObject
{
    Q_OBJECT
public:
    GCMPTabDataStructure(QString& strTabName);
    ~GCMPTabDataStructure();

public:
    GCMPToolBar* getToolBar() { return m_pToolBar; }
    QWidget* getMainWidget() { return m_pMainWidget; }
    QString getTabName() { return m_strTabName; }
protected:
    GCMPToolBar* m_pToolBar;
    QWidget* m_pMainWidget;
    QString m_strTabName;
};

class GCMPUI_EXPORT GCMPGGDBCompareTabDataStructure : public GCMPTabDataStructure
{
    Q_OBJECT
public:
    GCMPGGDBCompareTabDataStructure();

protected:
    void createToolBar();
    void createMainWidget();

private:
    GCMPToolBarGroup* createFindDiffGroup();

private slots:
    void onNextDiffPressed();
    void onLastDiffPressed();

private:
    GCMPAction* m_pNextDiffBtn;
    GCMPAction* m_pLastDiffBtn;
};

