#pragma once
#include <QFont>
#include <map>
#include "GCMPUI/gcmpui_global.h"
//�������������
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

