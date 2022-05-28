#include "cMain.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(10001, OnButtonClicked)
EVT_BUTTON(1, ListenForKeyInput1)
EVT_BUTTON(2, ListenForKeyInput2)
EVT_BUTTON(3, ListenForKeyInput3)

wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "RepeateR", wxPoint(30, 30), wxSize(800, 600))
{
	//		Definitions
	kbd = SetWindowsHookEx(WH_KEYBOARD_LL, cMain::KBDHook, 0, 0);

	macroCreator1 = new wxButton(this, 1, "Button 1", wxPoint(10, 10), wxSize(100, 20));
	plus1 = new wxStaticText(this, wxID_ANY, "+", wxPoint(120, 10), wxSize(10, 20), 0, "");

	macroCreator2 = new wxButton(this, 2, "Button 2", wxPoint(140, 10), wxSize(100, 20));
	plus2 = new wxStaticText(this, wxID_ANY, "+", wxPoint(250, 10), wxSize(10, 20), 0, "");

	macroCreator3 = new wxButton(this, 3, "Button 3", wxPoint(270, 10), wxSize(100, 20));

	
	macroInput = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 50), wxSize(500, 200));
	btn = new wxButton(this, 10001, "just a button!", wxPoint(570, 10), wxSize(200, 300));
	loopSequence = new wxCheckBox(this, 1, loopMacroString, wxPoint(10, 270), wxSize(200, 10), 0, wxDefaultValidator, "loopSequence");



	//		Initializations

	macroInput->SetValue("Input macro sequence (in ms), example: S(500) 4(1892) Shift+T(5) Ctrl+3 Alt+F4 Wait(50000)");
	macroInput->SetFocus();


	//loopSequence->SetBackgroundColour(wxColour(*wxBLUE));
}

cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent& evt)	//			On Button Clicked
{
	wxMessageBox(macroInput->GetValue());
	auxiliary = macroInput->GetValue();





	evt.Skip();
}

void cMain::ListenForKeyInput1(wxCommandEvent& evt)
{
	keyInput = true;
	while (keyInput)
	{
		if (GetAsyncKeyState(VK_LCONTROL))
		{
			keyInput = false;
			macroCreator1->SetLabel("Left Control");
			wxMessageBox("1 Left control pressed!");
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			keyInput = false;
			wxMessageBox("Escape pressed on 1");
		}
		Sleep(10);
	}

	evt.Skip();
}

void cMain::ListenForKeyInput2(wxCommandEvent& evt)
{
	keyInput = true;
	if (GetMessage(&message, NULL, NULL, NULL) > 0)
		keyInput = true;

	while (keyInput)
	{
		if (GetAsyncKeyState(VK_LCONTROL))
		{
			keyInput = false;
			macroCreator2->SetLabel("Left Control");
			wxMessageBox("2 Left control pressed!");
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			keyInput = false;
			wxMessageBox("Escape pressed on 2");
		}

		TranslateMessage(&message);
		DispatchMessage(&message);

		Sleep(10);
	}

	UnhookWindowsHookEx(kbd);
	evt.Skip();
}

void cMain::ListenForKeyInput3(wxCommandEvent& evt)
{
	keyInput = true;
	while (keyInput)
	{
		if (GetAsyncKeyState(VK_LCONTROL))
		{
			keyInput = false;
			macroCreator3->SetLabel("Left Control");
			wxMessageBox("3 Left control pressed!");
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			keyInput = false;
			wxMessageBox("Escape pressed on 3");
		}
		Sleep(10);
	}

	evt.Skip();
}

void cMain::testFunc(char c)
{
	macroCreator1->SetLabel(c);
}

LRESULT CALLBACK cMain::KBDHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT* s = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);

	switch (wParam)
	{
	case WM_KEYDOWN:
		char c = MapVirtualKey(s->vkCode, MAPVK_VK_TO_CHAR);
		//&macroCreator1->SetLabel(c);
		break;
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}
