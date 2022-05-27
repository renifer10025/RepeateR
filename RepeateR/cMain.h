#pragma once
#include "wx/wx.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	wxString str = "Loop macro sequence?";

	wxStaticText* macroText = nullptr;
	wxTextCtrl* macroInput = nullptr;
	wxButton* btn = nullptr;		//			Change to more specific name!
	wxCheckBox* loopSequence = nullptr;
	wxStaticText* checkboxLoopSequence = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);

	void RemovePlaceholder();

	wxDECLARE_EVENT_TABLE();
};