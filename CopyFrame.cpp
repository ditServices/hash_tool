//
// Created by howard on 19/08/2020.
//

#include <filesystem>

#include "CopyFrame.h"
#include "copytoolID.h"
#include "copytool_errors.h"

namespace fs = std::filesystem;

CopyFrame::CopyFrame() : wxFrame(NULL, wxID_ANY, "Hash Tool"){
    menuFile->Append(wxID_OPEN);
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    menuHelp->Append(wxID_ABOUT);

    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    hbox1->Add(new wxPanel(panel, -1));
    vbox->Add(hbox1, 1, wxEXPAND);

    hbox2->Add(clear);
    hbox2->Add(calculate);

    hbox_src->Add(src_label);
    hbox_xxhash->Add(xxhashLabel);
    hbox_md5->Add(md5_label);

    vbox->Add(hbox_src, 0, wxALIGN_LEFT, 5);
    vbox->Add(hbox_xxhash, 0, wxALIGN_LEFT, 5);
    vbox->Add(hbox_md5, 0, wxALIGN_LEFT, 5);

    vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);

    panel->SetSizer(vbox);

    Bind(wxEVT_MENU, &CopyFrame::OnOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &CopyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &CopyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &CopyFrame::Calculate, this, ID_CALC);
    Bind(wxEVT_BUTTON, &CopyFrame::OnClearForm, this, ID_RESET);

}

void CopyFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void CopyFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("Generate MD5 and XXHash of Selected File - By Howard Colin",
                 "About Hash Tool", wxOK | wxICON_INFORMATION);
}

void CopyFrame::OnOpen(wxCommandEvent &event) {

    wxFileDialog openFile(this, ("Select A File"), "", "", "", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFile.ShowModal() == wxID_CANCEL) {
        return;
    }
    try {
        wxString path = openFile.GetPath();
        char c_path[PATH_MAX];
        strncpy(c_path, (const char *) path.mb_str(), PATH_MAX);
        this->source_file = FileHandler(c_path);
        this->src_label->SetLabel("Input File: \t" + openFile.GetFilename());
    } catch (GeneralError& e) {
        std::cout << e.what() << std::endl;
    }
}

void CopyFrame::Calculate(wxCommandEvent &event) {
    md5_engine engine;
    xxh_engine xxh_engine;

    if(source_file.check_path() == 0) {
        try {
            xxh_engine.calculate_xxh(source_file);
            engine.calculate_md5(source_file);
        }
        catch(GeneralError& e) {
            wxMessageBox("Memory Error",
                         "Hash Tool", wxOK | wxICON_ERROR);
        }
        catch (FileError& e) {
            wxMessageBox("File Error",
                         "Hash Tool", wxOK | wxICON_ERROR);
        }
        catch (xxhError& e) {
            wxMessageBox("xxHash Error",
                         "Hash Tool", wxOK | wxICON_ERROR);
        }
        catch (md5Error& e) {
            wxMessageBox("MD5 Error",
                         "Hash Tool", wxOK | wxICON_ERROR);
        }

        wxString digest;
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
            digest.Append(wxString::Format(wxT("%02x"), engine.final[i]));
        }

        wxString xxhash_digest = wxString::Format(wxT("%llx"), xxh_engine.digest);
        this->md5_label->SetLabel("MD5: " + digest);
        this->xxhashLabel->SetLabel("xxHash: " + xxhash_digest);
    } else {
        wxMessageBox("Please select a source file",
                     "Hash Tool", wxOK | wxICON_ERROR);
    }
}

void CopyFrame::OnClearForm(wxCommandEvent &event) {
    this->src_label->SetLabel(wxT("Awaiting File: "));
    this->xxhashLabel->SetLabel(wxT("xxHash: "));
    this->md5_label->SetLabel(wxT("MD5: "));
}



