# DinamicalReuse

Задание:

Спроектировать и реализовать класс ListWidget, который будет динамически создавать минимальное количество ListItemWidget'ов для отображения данных (ListModelItem) из модели ListModel.
Суть в том, чтобы ListWidget умел отображать, например, две тысячи ListModelItem'ов, не создавая при этом две тысячи ListItemWidget'ов.
Пример использования:

Я хочу отобразить в листе 1000 кнопок и 1000 чекбоксов.
Для кнопки я создам наследников ButtonListItemWidget, ButtonListModelItem, а для чекбоксов CheckBoxListItemWidget, CheckBoxListModelItem.
Я должен буду заполнить модель, грубо говоря, вот так:

``` 
ListModel model;
for (auto i = 0; i < 1000; ++i) {
    model.add(new ButtonListModelItem());
    model.add(new CheckBoxListModelItem());
}
ListWidget list;
list.setModel(model);

```
Лист сам должен создавать/переиспользовать подходящие виджеты (в данном случае ButtonListItemWidget и CheckBoxListItemWidget).
