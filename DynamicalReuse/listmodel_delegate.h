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

public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;


    // QAbstractItemDelegate interface
public:
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void assembleButton(QPushButton &button,const QModelIndex &index) const;
    void assembleCheckbox(QCheckBox &checkbox,const QModelIndex &index) const;
    // QAbstractItemDelegate interface
public:

};







#endif // LISTMODEL_DELEGATE_H
