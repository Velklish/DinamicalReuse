#include "listmodel_delegate.h"
#include <QApplication>

ListModelDelegate::ListModelDelegate() : QStyledItemDelegate ()
{

}

void ListModelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QFont font;
    font.setBold(true);
    font.setStretch(2);

    if(index.data(Qt::DisplayRole).toString()=="checkbox"){
        CheckboxItem *item = index.data(CheckboxRole).value<CheckboxItem*>();
        QCheckBox checkbox;
        QSize checkbox_size = item->size;
        QString checkbox_text = item->text;
        bool state = item->state;
        checkbox.setGeometry(option.rect);
        checkbox.setText(checkbox_text);
        checkbox.resize(checkbox_size);
        checkbox.setCheckState(Qt::CheckState(state));      
        checkbox.setFont(font);

        QPixmap widget_map = QPixmap::grabWidget(&checkbox);
        QApplication::style()->drawItemPixmap(painter,option.rect,Qt::AlignCenter,widget_map);

    }
    else if(index.data(Qt::DisplayRole).toString()=="button"){
        ButtonItem *item = index.data(ButtonRole).value<ButtonItem*>();
        QPushButton button;
        QSize button_size = item->size;
        QString button_text = item->text;
        button.setGeometry(option.rect);
        button.setText(button_text);
        button.resize(button_size);
        button.setFont(font);

        QPixmap button_map = QPixmap::grabWidget(&button);
        QApplication::style()->drawItemPixmap(painter,option.rect,Qt::AlignCenter,button_map);
    }
}
