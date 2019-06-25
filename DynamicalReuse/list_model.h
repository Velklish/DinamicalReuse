#ifndef LIST_MODEL_H
#define LIST_MODEL_H

#include <QAbstractListModel>
#include <QObject>

class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    int _RowCount = 0;
    ListModel(QObject *parent = nullptr);
private:

protected:
    QHash<QModelIndex, QVariant> _itemdata;

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
};

class WidgetModel : public ListModel
{
    Q_OBJECT
public:
    WidgetModel (QObject *parent = nullptr);
    void newLine(QString wid);

};

#endif // LIST_MODEL_H
