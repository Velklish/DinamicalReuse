#include "list_model.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringListModel>
#include <QAbstractListModel>
#include <QLineEdit>
#include <QCheckBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QListWidget * list_widget = new QListWidget;
    QVBoxLayout *vertical_layout = new QVBoxLayout;
    vertical_layout->addWidget(new QPushButton("UP"));

    for (int i=0;i<4;i++)
    {
        QWidget *widget = new QWidget;
        QLayout *layout = new QHBoxLayout;
        layout->addWidget(new QPushButton("Random Button"));
        layout->addWidget(new QCheckBox);
        widget->setLayout(layout);

        QListWidgetItem *item = new QListWidgetItem( list_widget);
        item->setSizeHint(widget->sizeHint());
        list_widget->setItemWidget(item,widget);
    }
    vertical_layout->addWidget( list_widget);
    vertical_layout->addWidget(new QPushButton("Down"));

    QWidget *window = new QWidget;

    window->setLayout(vertical_layout);
    window->resize(150,270);
    window->show();

    return a.exec();
}
