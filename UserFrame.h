#ifndef USERFRAME_H
#define USERFRAME_H

//(*Headers(UserFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class UserFrame: public wxFrame
{
	public:

		UserFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~UserFrame();

		//(*Declarations(UserFrame)
		wxCheckBox* cbx_id;
		wxTextCtrl* sle_class;
		wxCheckBox* cbx_dept;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxTextCtrl* sle_name;
		wxTextCtrl* sle_agest;
		wxTextCtrl* sle_addr;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxCheckBox* cbx_name;
		wxTextCtrl* sle_sex;
		wxTextCtrl* sle_id;
		wxCheckBox* cbx_agest;
		wxTextCtrl* TextCtrl2;
		wxCheckBox* cbx_addr;
		wxTextCtrl* TextCtrl1;
		wxCheckBox* cbx_class;
		wxCheckBox* cbx_sex;
		wxTextCtrl* sle_dept;
		wxTextCtrl* sle_ageed;
		//*)

	protected:

		//(*Identifiers(UserFrame)
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_CHECKBOX3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL4;
		static const long ID_CHECKBOX4;
		static const long ID_TEXTCTRL5;
		static const long ID_CHECKBOX5;
		static const long ID_TEXTCTRL6;
		static const long ID_CHECKBOX6;
		static const long ID_TEXTCTRL7;
		static const long ID_CHECKBOX7;
		static const long ID_TEXTCTRL8;
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL9;
		static const long ID_TEXTCTRL10;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		//*)

	private:

		//(*Handlers(UserFrame)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void Oncbx_idClick(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void Onsle_idTextEnter(wxCommandEvent& event);
		void Onsle_idText(wxCommandEvent& event);
		void Oncbx_nameClick(wxCommandEvent& event);
		void Onsle_nameText(wxCommandEvent& event);
		void Oncbx_agestClick(wxCommandEvent& event);
		void Onsle_agestText(wxCommandEvent& event);
		void Onsle_ageedText(wxCommandEvent& event);
		void Oncbx_sexClick(wxCommandEvent& event);
		void Onsle_sexText(wxCommandEvent& event);
		void Oncbx_deptClick(wxCommandEvent& event);
		void Onsle_deptText(wxCommandEvent& event);
		void Oncbx_classClick(wxCommandEvent& event);
		void Onsle_classText(wxCommandEvent& event);
		void Oncbx_addrClick(wxCommandEvent& event);
		void Onsle_addrText(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
