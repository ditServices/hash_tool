//
// Created by howard on 19/08/2020.
//

#include "CopyTool.h"
#include "CopyFrame.h"

wxIMPLEMENT_APP(CopyTool);

bool CopyTool::OnInit() {
    CopyFrame *frame = new CopyFrame();
    frame->SetSize(500, 150);
    //frame->SetIcon(wxIcon(wxT("icon.xpm")));
    frame->Show(true);
    return true;
}
