//
// Created by howard on 19/08/2020.
//

#ifndef COPY_TOOL_COPYFRAME_H
#define COPY_TOOL_COPYFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "copytoolID.h"
#include "FileHandler.h"
#include "md5_engine.h"
#include "xxh_engine.h"

class CopyFrame : public wxFrame {
public:
    CopyFrame();
    wxMenu *menuFile = new wxMenu;
    wxMenu *menuHelp = new wxMenu;
    wxMenuBar *menuBar = new wxMenuBar;

    wxPanel *panel = new wxPanel(this, -1);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox_src = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox_xxhash = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox_md5 = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText * src_label = new wxStaticText(panel, wxID_ANY, wxT("Awaiting File"));
    wxStaticText * xxhashLabel = new wxStaticText(panel, wxID_ANY, wxT("xxHash: "));
    wxStaticText * md5_label = new wxStaticText(panel, wxID_ANY, wxT("MD5: "));

    wxButton *clear = new wxButton(panel, ID_RESET, wxT("Clear"));
    wxButton *calculate = new wxButton(panel, ID_CALC, wxT("Calculate"));

    FileHandler source_file;

private:
    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void Calculate(wxCommandEvent& event);
    void OnClearForm(wxCommandEvent& event);
};


#endif //COPY_TOOL_COPYFRAME_H
