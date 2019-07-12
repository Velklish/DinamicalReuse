#include "custom_listview.h"

CustomListView::CustomListView(){}


void CustomListView::mouseMoveEvent(QMouseEvent *event)
{
    QModelIndex currentIndex = indexAt(event->pos());

    if (currentIndex.isValid())
    {
        if (!previousIndex.isValid())
        {
            previousIndex=currentIndex;
        }
        else if (previousIndex.isValid() && (previousIndex != currentIndex))
        {
            closePersistentEditor(previousIndex);
            openPersistentEditor(currentIndex);
            previousIndex=currentIndex;
        }
     }
}

