//
// Created by Mark Edmunds on 4/1/25.
//

#include "App.h"
#include "Frame.h"
#include <wx/wx.h>


wxIMPLEMENT_APP(App);
bool App::OnInit() {
    Frame* frame = new Frame("Zookeeper");
    frame->SetClientSize(800, 600);
    frame->Center();
    frame->Show(true);
    return true;
}