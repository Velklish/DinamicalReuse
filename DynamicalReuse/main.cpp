#include "main_window.h"
#include "list_model.h"
#include "list_model_delegate.h"
#include "custom_listview.h"
//#include <vld.h>

#include <QApplication>
#include <QListView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ListModel *model = new ListModel();

    for(int i=1;i<=1000;i++){
        ButtonItem *button = new ButtonItem();
        button->setText("button "+QString::number(i));
        model->Add(button);
        CheckboxItem *checkbox = new CheckboxItem();
        checkbox->setText("checkbox "+QString::number(i));
        checkbox->setSize(QSize(200,40));
        model->Add(checkbox);

    }

    CustomListView view;

    view.setMouseTracking(true);
    view.setEditTriggers(QListView::NoEditTriggers);
    view.setModel(model);
    view.setItemDelegate(new ListModelDelegate());
    view.resize(350,600);
    view.show();

    return a.exec();
}
