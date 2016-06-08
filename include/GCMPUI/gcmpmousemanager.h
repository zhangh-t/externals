
#ifndef GCMPMOUSEMANAGER_H
#define GCMPMOUSEMANAGER_H

#include <QObject>
#include "gcmpui_global.h"
#include <vector>

//��������¼�
class GCMPUI_EXPORT GCMPMouseListener
{
public:
    GCMPMouseListener();
    virtual ~GCMPMouseListener(){}

public:
    //����뿪�¼�
    void onMouseLeave() {}
};


class GCMPUI_EXPORT GCMPMouseManager : public QObject
{
    Q_OBJECT
public:
    GCMPMouseManager();
    virtual ~GCMPMouseManager();

public:
    void registerMouseListener(GCMPMouseListener* pListener);

protected:
    virtual bool eventFilter(QObject *pOb, QEvent *e);

private:
    std::vector<GCMPMouseListener*> m_vecMouseListeners;
    GCMPMouseListener* m_pCurListener;
};

#endif // GCMPWIDGET_H
