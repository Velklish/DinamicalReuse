#ifndef CUSTOM_VIEW_H
#define CUSTOM_VIEW_H


#include <list_model.h>

#include <QtWidgets>
#include <QListView>

class CustomView : public QListView
{
public:
    CustomView();
    QModelIndex previousIndex;
    bool first = true;

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;

};














#endif // CUSTOM_VIEW_H
