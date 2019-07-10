#ifndef LIST_MODEL_H
#define LIST_MODEL_H

#include <base_items.h>


#include <QAbstractListModel>

enum CustomRoles{

  ButtonTextRole=Qt::UserRole+1,
  ButtonSizeRole,
  CheckboxTextRole,
  CheckboxStateRole,
  CheckboxSizeRole,
  TypeRole,

};


class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ListModel();
    ~ListModel() override;

private:
    QList<BaseItems*> itemList;

public:

    void Add(BaseItems*);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
};






#endif // LIST_MODEL_H
