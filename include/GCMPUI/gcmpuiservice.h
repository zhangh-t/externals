#ifndef GCMPUISERVICE_H
#define GCMPUISERVICE_H

#include <QObject>
#include "GCMPUI/gdbcompare.h"
#include "GCMPUI/gcmpcenterwidget.h"
#include "GCMPUI/gcmpui_global.h"
#include "GCMPUI/GCMPTabDataStructure.h"
#include "GCMPUI/GCMPUIFontManager.h"
#include "GCMPUI/gcmpmousemanager.h"

//CenterWidget 界面服务
typedef GCMPUI_EXPORT std::vector<GCMPTabDataStructure*> GCMPTabContainer;


class GCMPUI_EXPORT GCMPUIService
{
public:
    GCMPUIService();

    void setCenterWidget(QWidget* pCenter);
    QWidget* centerWidget() { return m_pGCMPCenterWidget; }

    void setMainFrame(QWidget* pMainFrame);
    QWidget* mainFrame() { return m_pGDBCompareMainFrame; }

    void setTabWidget(GCMPTabWidget* pTabWidget);
    GCMPTabWidget* tabWidget() { return m_pTabWidget; }

    GCMPUIFontManager* fontMgr() { return m_pFontManager; }

    GCMPMouseManager* mouseManager() { return m_pMouseManager; }

    void addTab(GCMPTabDataStructure* pTab) 
    { 
        if (pTab != nullptr)
        {
            m_Container.push_back(pTab);
            m_pTabWidget->addTabDataStructure(pTab);
        }
    }

    GCMPTabContainer& tabContainer() { return m_Container; }

    //重新组织布局
    void init();
protected:
    virtual ~GCMPUIService();
private:
   QWidget* m_pGDBCompareMainFrame;
   QWidget* m_pGCMPCenterWidget;
   GCMPTabContainer m_Container;
   GCMPTabWidget* m_pTabWidget;
   GCMPUIFontManager* m_pFontManager;
   GCMPMouseManager* m_pMouseManager;
private:
    bool m_bCreated;
    bool m_bInited;
};

#endif // GCMPUISERVICE_H
