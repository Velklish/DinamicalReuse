#include "custom_view.h"

CustomView::CustomView()
{

}


void CustomView::mouseMoveEvent(QMouseEvent *event)
{

    QModelIndex currentIndex = indexAt(event->pos());

    if(first==true){
        first=false;
        closePersistentEditor(previousIndex);
        previousIndex=currentIndex;
        openPersistentEditor(currentIndex);
    }
    else{
        if(currentIndex!=previousIndex && isPersistentEditorOpen(previousIndex)){
            openPersistentEditor(currentIndex);
            updateEditorData();
            closePersistentEditor(previousIndex);
        }
        else{
            previousIndex=currentIndex;
            first=true;
        }
    }
}

