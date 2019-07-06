#include "list_model.h"

ListModel::ListModel() : QAbstractListModel ()
{

}

ListModel::~ListModel(){

}

void ListModel::Add(CheckboxItem* item)
{
    beginInsertRows(QModelIndex(),itemList.count(),itemList.count());
    itemList.append(item);
    endInsertRows();
}

void ListModel::Add(ButtonItem* item)
{
    beginInsertRows(QModelIndex(),itemList.count(),itemList.count());
    itemList.append(item);
    endInsertRows();
}


int ListModel::rowCount(const QModelIndex &parent) const
{
    return itemList.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()){
        return QVariant();
    }
    CheckboxItem* checkbox = dynamic_cast<CheckboxItem*>(itemList.at(index.row()));
    ButtonItem* button = dynamic_cast<ButtonItem*>(itemList.at(index.row()));
    switch(role){
    case Qt::DisplayRole:{
        if(checkbox){
          return QVariant::fromValue(checkbox->type);
        }
        else if (button) {
          return QVariant::fromValue(button->type);
        }
        break;
    }
    case Qt::SizeHintRole:
        return QSize(0,60);

    case ButtonRole:{
        QVariant v;
        v.setValue(button);
        return v;
    }
    case CheckboxRole:{
        QVariant v;
        v.setValue(checkbox);
        return v;
    }

    default:
            return QVariant();
    }

return QVariant();
}
