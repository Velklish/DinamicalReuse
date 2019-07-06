#include "base_items.h"

BaseItems::BaseItems()
{

}


BaseItems::BaseItems(const BaseItems &other){}
BaseItems::~BaseItems(){}


CheckboxItem::CheckboxItem() : BaseItems(){}
CheckboxItem::~CheckboxItem(){}


ButtonItem::ButtonItem():BaseItems (){}
ButtonItem::~ButtonItem(){}


