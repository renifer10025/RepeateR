#pragma once
#include "wx/wx.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

	wxString loopMacroString = "Loop macro sequence?";
	wxString auxiliary = "";
	bool keyInput = true;

	wxStaticText* macroText = nullptr;
	wxTextCtrl* macroInput = nullptr;
	//wxTextCtrl* macroCreator1 = nullptr;
	//wxTextCtrl* macroCreator2 = nullptr;
	//wxTextCtrl* macroCreator3 = nullptr;
	wxButton* macroCreator1 = nullptr;
	wxButton* macroCreator2 = nullptr;
	wxButton* macroCreator3 = nullptr;
	wxButton* btn = nullptr;		//			Change to more specific name!
	wxCheckBox* loopSequence = nullptr;
	wxStaticText* checkboxLoopSequence = nullptr;

	wxStaticText* plus1 = nullptr;
	wxStaticText* plus2 = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);
	void ListenForKeyInput1(wxCommandEvent& evt);
	void ListenForKeyInput2(wxCommandEvent& evt);
	void ListenForKeyInput3(wxCommandEvent& evt);

	void RemovePlaceholder();

	wxDECLARE_EVENT_TABLE();
};