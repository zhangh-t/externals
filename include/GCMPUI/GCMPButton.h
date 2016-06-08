#pragma once
#include <QString>
#include <QPushButton>
#include <QIcon>
#include <QPoint>
#include <QLabel>
#include "GCMPUI/gcmpmousemanager.h"
#include "GCMPUI/gcmpui_global.h"

//GCMPButton
class GCMPUI_EXPORT GCMPButton : public QPushButton
{
    Q_OBJECT
public:
    //暂时就这俩把
    GCMPButton(QString strTitle,
        QColor hoverColor = QColor(0, 0, 0, 0),
        QColor pressedColor = QColor(0, 0, 0, 0),
        QSize minSize = QSize(0, 0),
        QWidget* pParent = nullptr,
        bool bEnableBorder = false);

    GCMPButton(QIcon& oIcon,
        QColor hoverColor = QColor(0, 0, 0, 0),
        QColor pressedColor = QColor(0, 0, 0, 0),
        QSize minSize = QSize(0, 0),
        QWidget* pParent = nullptr,
        bool bEnableBorder = false);

    virtual ~GCMPButton(){}

public:
    void setBKColor(QColor bkColor) { m_bkColor = bkColor; loadQSS(); }
    void setTextColor(QColor textColor) { m_textColor = textColor; loadQSS(); }
    void setBorderColor(QColor borderColor) { m_borderColor = borderColor; loadQSS(); }
protected:
    virtual void loadQSS();
    virtual void loadQSSForIcon();
    virtual void setTextFont();
protected:
    QSize m_oMinSize;
private:
    QColor m_hoverColor;
    QColor m_pressedColor;
    QColor m_bkColor;
    QColor m_textColor;
    QColor m_borderColor;
    QIcon m_oImage;
    QString m_strTitle;
    bool m_bEnableBorder;
};


class GCMPUI_EXPORT GCMPLabel : public QLabel
{
public:
    GCMPLabel(QString& strLabelName, QWidget* pParent) : m_strLabelName(strLabelName), QLabel(strLabelName, pParent) {}
    virtual ~GCMPLabel() {}

public:
    virtual void setTextFont(QFont& oFont);

protected:
    QString m_strLabelName;
};