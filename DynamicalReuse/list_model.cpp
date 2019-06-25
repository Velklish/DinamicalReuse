#include "list_model.h"

#include <QLocale>

ListModel::ListModel(QObject *parent)
    :QAbstractListModel(parent)
{

}


int ListModel::rowCount(const QModelIndex &parent) const
{
    return _RowCount;
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        return _itemdata.value(index,QVariant());
    }
    return QVariant();
}

bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
    if(role == Qt::DisplayRole || role == Qt::EditRole){
        _itemdata.insert(index,value);
        emit dataChanged(index, index);
    }
    return false;
}

Qt::ItemFlags ListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

WidgetModel::WidgetModel(QObject *parent) : ListModel (parent)
{

}

void WidgetModel::newLine(QString wid)
{
   insertRow(_RowCount);
   _RowCount++;
   setData(index(_RowCount-1),wid,Qt::EditRole);
}



