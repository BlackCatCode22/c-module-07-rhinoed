#ifndef FRAME_H
#define FRAME_H
#include <wx/wx.h>
#include "ZooManager.h"

class Frame : public wxFrame {

public:
    Frame(const wxString& title);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnHello(wxCommandEvent &event);

    void generateReport(wxCommandEvent &event);

    void processAnimals(wxCommandEvent &event);

    wxStaticText* lion_count_label;
    wxStaticText* hyena_count_label;
    wxStaticText* tiger_count_label;
    wxStaticText* bear_count_label;
    wxListBox * hyena_list_box;
    wxListBox * lion_list_box;
    wxListBox * tiger_list_box;
    wxListBox * bear_list_box;
    wxListBox * report_box;

private:
    zooManager::ZooManager zoo; // Declare zoo as a member variable
    void onOpenFile(wxCommandEvent &event);
};

#endif // FRAME_H