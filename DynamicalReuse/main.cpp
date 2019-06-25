#include "main_window.h"
#include "list_model.h"
#include <QApplication>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QListView view;
    WidgetModel *model = new WidgetModel ();

    for(int i=0;i<15;i++){
      model->newLine("Line"+QString::number(i));
    }

    view.setModel(model);
    view.show();

    return a.exec();
}
