#pragma once
#include <QFont>
#include <map>
#include "GCMPUI/gcmpui_global.h"
//界面字体管理器
class GCMPUI_EXPORT GCMPUIFontManager
{
public:
    GCMPUIFontManager();
    ~GCMPUIFontManager();

public:
    void saveFont(QString& strKey, QFont* pFont);
    QFont* getFont(QString& strKey);
private:
    std::map<QString, QFont*> s_mapFonts;
};

