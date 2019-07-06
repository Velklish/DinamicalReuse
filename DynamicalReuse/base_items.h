#ifndef BASE_ITEMS_H
#define BASE_ITEMS_H

#include <QString>
#include <QSize>
#include <QMetaType>
#include <QPushButton>

class BaseItems
{
public:
    BaseItems();
    BaseItems(const BaseItems &other);
    virtual ~BaseItems();
};

class CheckboxItem : public BaseItems {
public:
    CheckboxItem();  
    virtual ~CheckboxItem(); 
    QString type = "checkbox";
    QString text = "CheckBox Widget";
    QSize size = QSize(150,60);
    bool state = true;
protected:
};


class ButtonItem : public BaseItems {
public:
    ButtonItem();   
    virtual ~ButtonItem();   
    QString type = "button";
    QString text = "Button Widget";
    QSize size = QSize(150,60);

protected:
};

Q_DECLARE_METATYPE(ButtonItem*);
Q_DECLARE_METATYPE(ButtonItem);

Q_DECLARE_METATYPE(CheckboxItem*);
Q_DECLARE_METATYPE(CheckboxItem);

//Q_DECLARE_METATYPE(BaseItems);
//Q_DECLARE_METATYPE(BaseItems*);


#endif // BASE_ITEMS_H
