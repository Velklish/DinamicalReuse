#ifndef BASE_ITEMS_H
#define BASE_ITEMS_H

#include <QString>
#include <QSize>
#include <QMetaType>
#include <QPushButton>

enum widget_type{
    Checkbox,
    Button,
};

class BaseItems
{
public:
    BaseItems();
    virtual ~BaseItems();

    widget_type getType() const;

    QSize getSize() const;
    void setSize(QSize size);

protected:
    widget_type type;
    QSize size;
};

class CheckboxItem : public BaseItems {
public:
    CheckboxItem();
    virtual ~CheckboxItem(); 

    void setText(QString text);
    QString getText() const;

    void setState(Qt::CheckState state);
    Qt::CheckState getState() const;

private:
    QString text = "CheckBox Widget";
    Qt::CheckState state = Qt::Unchecked;


};


class ButtonItem : public BaseItems {
public:
    ButtonItem();   
    virtual ~ButtonItem();   

    void setText(QString text);
    QString getText() const;

private:
    QString text = "Button Widget";
};

Q_DECLARE_METATYPE(ButtonItem*);
Q_DECLARE_METATYPE(ButtonItem);

Q_DECLARE_METATYPE(CheckboxItem*);
Q_DECLARE_METATYPE(CheckboxItem);

Q_DECLARE_METATYPE(widget_type);


#endif // BASE_ITEMS_H
