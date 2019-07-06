#ifndef LISTMODEL_DELEGATE_H
#define LISTMODEL_DELEGATE_H

#include "list_model.h"

#include <QStyledItemDelegate>
#include <QPushButton>
#include <QCheckBox>


class ListModelDelegate : public QStyledItemDelegate
{
public:
    ListModelDelegate();

    // QAbstractItemDelegate interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};



#endif // LISTMODEL_DELEGATE_H
