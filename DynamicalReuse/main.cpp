#include "main_window.h"
#include "list_model.h"
#include "listmodel_delegate.h"

#include <QApplication>
#include <QListView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ListModel *model = new ListModel();
    for(int i=1;i<=2000;i++){
        CheckboxItem *checkbox = new CheckboxItem();
        checkbox->text = ("Checkbox number:  "+QString::number(i));
        checkbox->size = QSize(200,40);
        model->Add(checkbox);
        ButtonItem *button = new ButtonItem();
        button->text = ("Button number:  "+QString::number(i));
        model->Add(button);
    }

    QListView view;
    view.setModel(model);
    view.setItemDelegate(new ListModelDelegate());
    view.show();

    return a.exec();
}
