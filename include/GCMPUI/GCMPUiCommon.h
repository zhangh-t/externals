#pragma once
#include <QSize>
#include <QWidget>
#include "GCMPUI/gcmpui_global.h"
#include "GCMPUI/gcmpuiservice.h"

template <typename T>
class GCMPUI_EXPORT GCMPuiGarbo
{
public:
    GCMPuiGarbo(T* t){ m_pt = t; }
    ~GCMPuiGarbo()
    {
        if (m_pt != nullptr)
        {
            delete m_pt;
            m_pt = nullptr;
        }
    }
private:
    T* m_pt;
};

GCMPUI_EXPORT void saveGlobalUIService(GCMPUIService* pUIServicer);
GCMPUI_EXPORT GCMPUIService* globalUIService();
GCMPUI_EXPORT void setGlobalUIResourcePrefix(QString& strPrefix);
GCMPUI_EXPORT QString globalUIResourcePrefix();

static  const QSize g_MinmumFrameSize = QSize(500, 500);


