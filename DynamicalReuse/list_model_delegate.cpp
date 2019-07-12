#include "list_model_delegate.h"
#include <QApplication>
#include <QFont>

ListModelDelegate::ListModelDelegate() : QStyledItemDelegate ()
{

}

void ListModelDelegate::assembleButton(QPushButton &button,const QModelIndex &index) const
{
    QSize button_size = index.data(ButtonSizeRole).toSize();
    QString button_text = index.data(ButtonTextRole).toString();
    QFont serifFont("Times", 9);

    button.setText(button_text);
    button.resize(button_size);
    button.setFont(serifFont);
}

void ListModelDelegate::assembleCheckbox(QCheckBox &checkbox, const QModelIndex &index) const
{
    QSize checkbox_size = index.data(CheckboxSizeRole).toSize();
    QString checkbox_text = index.data(CheckboxTextRole).toString();
    Qt::CheckState state = static_cast<Qt::CheckState>(index.data(CheckboxStateRole).toInt());
    QFont serifFont("Times", 9);

    checkbox.setText(checkbox_text);
    checkbox.resize(checkbox_size);
    checkbox.setCheckState(state);
    checkbox.setAutoFillBackground(true);
    checkbox.setFont(serifFont);
}




void ListModelDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    switch (index.data(TypeRole).toInt())
    {
        case Checkbox:
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->setGeometry(option.rect);
            assembleCheckbox(*checkbox,index);
            QPixmap widget_map = QPixmap::grabWidget(checkbox);
            QApplication::style()->drawItemPixmap(painter,option.rect,Qt::AlignLeft,widget_map);
            delete checkbox;
            break;
        }
        case Button:
        {
            QPushButton *button = new QPushButton();
            button->setGeometry(option.rect);
            assembleButton(*button,index);
            QPixmap button_map = QPixmap::grabWidget(button);
            QApplication::style()->drawItemPixmap(painter,option.rect,Qt::AlignLeft,button_map);          
            delete button;
            break;
        }
    }
}


QWidget *ListModelDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    switch (index.data(TypeRole).toInt())
    {
        case Checkbox:
        {
            QCheckBox *editor = new QCheckBox(parent);
            return editor;
        }

        case Button:
        {
            QPushButton *editor = new QPushButton(parent);
            return editor;
        }
        default: return parent;
    }
}


void ListModelDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    switch (index.data(TypeRole).toInt())
    {
        case Checkbox:
        {
            QCheckBox *checkbox = static_cast<QCheckBox*>(editor);
            assembleCheckbox(*checkbox,index);
            break;
        }
        case Button:
        {
            QPushButton *button = static_cast<QPushButton*>(editor);
            assembleButton(*button,index);
            break;
        }
    }
}


void ListModelDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}


void ListModelDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    switch (index.data(TypeRole).toInt())
    {
        case Checkbox:
        {
            QCheckBox *checkbox = static_cast<QCheckBox*>(editor);
            Qt::CheckState state = checkbox->checkState();
            model->setData(index,state,CheckboxStateRole);
           // delete checkbox;
            break;
        }
    }
}


