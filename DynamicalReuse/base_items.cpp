#include "base_items.h"

BaseItems::BaseItems(){}

BaseItems::~BaseItems(){}

widget_type BaseItems::getType() const
{
    return type;
}

QSize BaseItems::getSize() const
{
    return size;
}

void BaseItems::setSize(QSize size)
{
    this->size = size;
}



CheckboxItem::CheckboxItem() : BaseItems()
{
    type = Checkbox;
    size = QSize(150,60);
}

void CheckboxItem::setText(QString text)
{

    this->text = text;
}

QString CheckboxItem::getText() const
{
    return text;
}

void CheckboxItem::setState(Qt::CheckState state)
{
    this->state = state;
}

Qt::CheckState CheckboxItem::getState() const
{
    return state;
}

CheckboxItem::~CheckboxItem(){}



ButtonItem::ButtonItem():BaseItems ()
{
    type = Button;
    size = QSize(150,60);
}

ButtonItem::~ButtonItem(){}

void ButtonItem::setText(QString text)
{
    this->text = text;
}

QString ButtonItem::getText() const
{
    return text;
}


