#ifndef LIST_MODEL_H
#define LIST_MODEL_H

#include <base_items.h>


#include <QAbstractListModel>

enum CustomRoles{
  ButtonRole=Qt::UserRole+1,
  CheckboxRole,

};


class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ListModel();
    ~ListModel() override;

private:
    typedef QList<BaseItems*> BaseItem;
    BaseItem itemList;

    // QAbstractItemModel interface
public:

    void Add(CheckboxItem*);
    void Add(ButtonItem*);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

};



#endif // LIST_MODEL_H
