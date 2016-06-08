#ifndef GCMPFRAMELESSWIDGET_H
#define GCMPFRAMELESSWIDGET_H
//�ޱ߿����ӰԲ�Ǿ��δ���
#include <QWidget>
#include <QLabel>
#include "GCMPUI/GCMPButton.h"
#include "GCMPUI/gcmpmousemanager.h"

enum GCMPUI_EXPORT GCMPFrameTitleStyle
{
    gtsNone = -1,
    gtsLeft = 0,
    gtsMiddle,
};

enum GCMPUI_EXPORT GCMPFrameBorderStyle
{
    gfbsNormalSolid = 0,
    gfbsShadow,
};
class GCMPUI_EXPORT GCMPFramelessWidget : public QWidget
{
    Q_OBJECT

public:
    GCMPFramelessWidget(const QString strTitle, GCMPFrameTitleStyle oStyle, QWidget* pCenterWidget, GCMPFrameBorderStyle oFrameStype = gfbsShadow, QWidget *parent = 0);
    ~GCMPFramelessWidget();

public:
    void setTitle(QString strTitle) { m_strTitle = strTitle; }
    GCMPFrameTitleStyle getTitleStyle() const { return m_oStyle; }
    QWidget* centerWidget() const { return m_pCenterWidget; }
    QWidget* titleWidget() const { return m_pTitleWidet; }
    QLabel* titleLabel() const { return m_pTitleLabel; }
protected:
    virtual void paintEvent(QPaintEvent * pEvent);

protected:
    virtual void addShadowEffect(); //���ʺ�������
    virtual void adaptToDesktop();
    virtual bool eventFilter(QObject *pObj, QEvent *pEvnt);

private slots:
    void onMinimize() { this->showMinimized(); }
    void onMaximize();

private:
    enum CursorPosType
    {
        cptNone = -1,       //û���ڱ�����
        cptLeftTop = 0,     //���Ͻ�
        cptLeftBottom,      //���½�
        cptRightTop,        //���Ͻ�
        cptRightBottom,     //���½�
        cptLeft,            //��߿�
        cptRight,           //�ұ߿�
        cptTop,             //�ϱ߿�
        cptBottom,          //�±߿�
    };

    enum MouseEventType
    {
        metNone = -1,
        metMouseMove = 0,
        metLButtomPress,
        metLButtomRelease,
        metElse,
    };

    void paintShadowFrame();
    void createAndInitContent();
    QWidget* createTitleWidget();
    MouseEventType processMouseEvent(QEvent* pEvent);
    void resizeWindow(QPoint oCurPoint);
    void defWindowByQSS();
private:
    //�ı������ʽ
    CursorPosType getCursorPosType(QPoint& oCursorPos);

private:
    QWidget* m_pTitleWidet;
    QLabel* m_pTitleLabel;
    QString m_strTitle;
    bool m_bMaxed;
private:
    bool m_bPressed;
    QPoint m_oPressPoint;
    QPoint m_oRefPos;
private:
    bool m_bBeginResizing;
    QPoint m_oStartPnt;
    CursorPosType m_enCursorType;
    QWidget* m_pCenterWidget;
    GCMPFrameTitleStyle m_oStyle;
    GCMPFrameBorderStyle m_oFrameBorderStyle;
};

#endif // GCMPFRAMELESSWIDGET_H
