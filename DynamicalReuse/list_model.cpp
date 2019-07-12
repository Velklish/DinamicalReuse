#include "list_model.h"

ListModel::ListModel() : QAbstractListModel (){}


ListModel::~ListModel()
{
    int count = itemList.count();

    for (int i=0; i < count; i++)
        delete itemList[i];
}

void ListModel::Add(BaseItems *item)
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
    if (!index.isValid())
        return QVariant();

    BaseItems *item = itemList.at(index.row());

    switch(role){

    case Qt::SizeHintRole:
        return item->getSize();

    case TypeRole:
    {
        return item->getType();
    }
    case ButtonTextRole:
    {
        ButtonItem* button = dynamic_cast<ButtonItem*>(itemList.at(index.row()));
        return QVariant::fromValue(button->getText());
    }
    case ButtonSizeRole:
    {
        ButtonItem* button = dynamic_cast<ButtonItem*>(itemList.at(index.row()));
        return QVariant::fromValue(button->getSize());
    }
    case CheckboxTextRole:
    {
        CheckboxItem* checkbox = dynamic_cast<CheckboxItem*>(itemList.at(index.row()));
        return QVariant::fromValue(checkbox->getText());
    }
    case CheckboxStateRole:
    {
        CheckboxItem* checkbox = dynamic_cast<CheckboxItem*>(itemList.at(index.row()));
        return QVariant::fromValue(checkbox->getState());
    }
    case CheckboxSizeRole:
    {
        CheckboxItem* checkbox = dynamic_cast<CheckboxItem*>(itemList.at(index.row()));
        return QVariant::fromValue(checkbox->getSize());
    }

    default:
        return QVariant();
    }
}

bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == CheckboxStateRole)
    {
      CheckboxItem *checkbox = dynamic_cast<CheckboxItem*>(itemList.value(index.row()));
      checkbox->setState(static_cast<Qt::CheckState>(value.toUInt()));
      return true;
    }
    else
    {
       return false;
    }
}


Qt::ItemFlags ListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    else
        return Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsSelectable;
}
