#ifndef LIST_WIDGET_H
#define LIST_WIDGET_H

#include <QMainWindow>

class ListWidget : public QMainWindow
{
    Q_OBJECT

public:
    ListWidget(QWidget *parent = 0);
    ~ListWidget();
};

#endif // LIST_WIDGET_H
