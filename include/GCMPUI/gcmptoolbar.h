#pragma once
#include <vector>
#include <functional>
#include <QIcon>
#include <QSplitter>
#include <QLabel>
#include "GCMPUI/GCMPButton.h"
#include "GCMPUI/gcmpmousemanager.h"



typedef GCMPUI_EXPORT std::function<void(void)> GCMPActionDefaultSlot;

const QColor g_sDefaultHoverColor = QColor(211, 240, 224);
const QColor g_sDefaultPressedColor = QColor(134, 191, 160);
const QColor g_sBKColor = QColor(255, 255, 255);
const QSize g_DefualtActionMinSize = QSize(100, 30);
//按钮
class GCMPUI_EXPORT GCMPAction : public QPushButton
{
    Q_OBJECT

public:
    GCMPAction(QString strTitle,
        QPixmap icon = QPixmap(),
        QColor hoverColor = QColor(0, 0, 0, 0),
        QColor pressedColor = QColor(0, 0, 0, 0),
        QColor bkColor = QColor(255, 255, 255, 255),
        QSize minSize = QSize(0, 0),
        bool bEnableBorder = false, GCMPActionDefaultSlot* pDefualt = nullptr, QWidget* pParent = nullptr);

    virtual ~GCMPAction(){}

    int minHeight() { return m_oMinSize.height(); }

public:
    void onMouseLeave(){}

private slots:
    void onPressed();

protected:
    virtual void paintEvent(QPaintEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void leaveEvent(QEvent *e);
private:
    GCMPActionDefaultSlot* m_pDefaultSlot;
    QPixmap m_oIcon;
    QRect m_iconRect;
    QRect m_oMinSize;

private:
    enum GCMPUI_EXPORT EnMouseState
    {
        enNone = -1,
        enHovered = 0,
        enPressed,
    };
private:
    QColor m_oBKColor;
    QColor m_oHoverColor;
    QColor m_oPressedColor;
    EnMouseState m_oState;
};

//在label上画一条分割线
enum GCMPUI_EXPORT SplitterOrientation
{
    soVertical = 0,
    soHorizontal,
};

class GCMPUI_EXPORT GCMPSplitterLabel : public QLabel
{
public:
    GCMPSplitterLabel(SplitterOrientation orientation, 
        int nLineWidth,
        QColor splitLineColor,
        QColor backgroundColor);

protected:
    void paintEvent(QPaintEvent *);

private:
    SplitterOrientation m_orientation;
    QColor m_oLineColor;
    QColor m_oBackgroundColor;
    int m_nLineWidth;
};

struct GCMPUI_EXPORT GCMPActionGeometry
{
    int nRow;
    int nCol;
    int nRowCount;
    int nColCount;
    QWidget* pWidget;
    GCMPActionGeometry(int _nRow, int _nCol, int _nRowCount, int _nColCount, QWidget* _pWidget)
        :pWidget(_pWidget), nRow(_nRow), nCol(_nCol), nRowCount(_nRowCount), nColCount(_nColCount)
    {}
    ~GCMPActionGeometry(){}
};
typedef GCMPUI_EXPORT std::vector<GCMPActionGeometry*> GCMPActionContainer;

class GCMPUI_EXPORT GCMPToolBarGroup
{
public:
    //网格布局
    GCMPToolBarGroup(QString& strGroupName, int nRow, int nCol);
    virtual ~GCMPToolBarGroup();

public:
    virtual int minimumHeight();

    int rowCount() const { return m_nRow; }
    int colCount() const { return m_nCol; }

    int itemCount() const { return (int)m_actionContainer.size(); }
    GCMPActionGeometry* item(int nIndex) { return m_actionContainer.at(nIndex); }

    void addAction(GCMPActionGeometry* pActionGeometry);

    QString groupName() { return m_strGroupName; }
protected:
    virtual bool exsited(GCMPActionGeometry* pActionGeometry);

protected:
    QString m_strGroupName;
    GCMPActionContainer m_actionContainer;
    int m_nRow;
    int m_nCol;
};
typedef GCMPUI_EXPORT std::vector<GCMPToolBarGroup*> GCMPToolBarGroupContainer;


class GCMPUI_EXPORT GCMPToolBar : public QWidget
{
public:
    GCMPToolBar(QColor splitterColor = QColor(0x8E, 0x8E, 0x8E, 0xFF));
    virtual ~GCMPToolBar();

public:
    void addGroup(GCMPToolBarGroup* pGroup);
    void reLayout();

protected:
    QLayout* createGroupLayout(GCMPToolBarGroup* pGroup);
protected:
    GCMPToolBarGroupContainer m_groupContainer;
    QColor m_splitterColor;
private:
    bool m_bLayouted;
    int m_nCurMinHeight;
};