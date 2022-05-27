#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(10001, OnButtonClicked)

wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "RepeateR", wxPoint(30, 30), wxSize(800, 600))
{
	//		Definitions

	macroInput = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(500, 200));
	btn = new wxButton(this, 10001, "just a button!", wxPoint(520, 10), wxSize(200, 300));
	loopSequence = new wxCheckBox(this, 1, str, wxPoint(10, 220), wxSize(200, 10), 0, wxDefaultValidator, "loopSequence");
	//checkboxLoopSequence = new wxStaticText(this, wxID_ANY, "Loop macro sequence?", wxDefaultPosition, wxSize(300, 100), 0, "loopSequenceText");



	//		Initializations

	macroInput->SetValue("Input macro sequence, example: S(500) 4(1892) Shift+T(5) Ctrl+3 Alt+F4 Wait(50000)");
	macroInput->SetFocus();


	//loopSequence->SetBackgroundColour(wxColour(*wxBLUE));
}

cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent& evt)	//			On Button Clicked
{
	wxMessageBox(macroInput->GetValue());
	evt.Skip();
}