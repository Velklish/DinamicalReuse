#ifndef CUSTOM_VIEW_H
#define CUSTOM_VIEW_H


#include <list_model.h>

#include <QtWidgets>
#include <QListView>

class CustomListView : public QListView
{
public:
    CustomListView();
    QModelIndex previousIndex;

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;

};



#endif // CUSTOM_VIEW_H
