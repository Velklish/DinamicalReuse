#ifndef LIST_MODEL_H
#define LIST_MODEL_H

#include <QMainWindow>

class ListModel : public QMainWindow
{
    Q_OBJECT

public:
    ListModel(QWidget *parent = 0);
    ~ListModel();
};

#endif // LIST_MODEL_H
