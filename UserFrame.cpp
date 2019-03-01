#include "UserFrame.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

#include <stdio.h>
#include <winsock2.h>
#include <mysql.h>
/*���ݿ������ú�*/
#define HOST "localhost"
#define USERNAME "root"
#define PASSWORD "root"
#define DATABASE "sct"


using std::string;
using std::stringstream;

//(*InternalHeaders(UserFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//ȫ�ֱ���
int  cbx_id_checked, cbx_name_checked, cbx_agest_checked, cbx_sex_checked,
     cbx_class_checked, cbx_dept_checked, cbx_addr_checked;
string  sle_id_text,  sle_name_text,  sle_agest_text,  sle_ageed_text, sle_sex_text,
        sle_class_text,  sle_dept_text,  sle_addr_text;
string sql_text;

//(*IdInit(UserFrame)
const long UserFrame::ID_CHECKBOX1 = wxNewId();
const long UserFrame::ID_CHECKBOX2 = wxNewId();
const long UserFrame::ID_TEXTCTRL1 = wxNewId();
const long UserFrame::ID_TEXTCTRL2 = wxNewId();
const long UserFrame::ID_CHECKBOX3 = wxNewId();
const long UserFrame::ID_TEXTCTRL3 = wxNewId();
const long UserFrame::ID_STATICTEXT1 = wxNewId();
const long UserFrame::ID_TEXTCTRL4 = wxNewId();
const long UserFrame::ID_CHECKBOX4 = wxNewId();
const long UserFrame::ID_TEXTCTRL5 = wxNewId();
const long UserFrame::ID_CHECKBOX5 = wxNewId();
const long UserFrame::ID_TEXTCTRL6 = wxNewId();
const long UserFrame::ID_CHECKBOX6 = wxNewId();
const long UserFrame::ID_TEXTCTRL7 = wxNewId();
const long UserFrame::ID_CHECKBOX7 = wxNewId();
const long UserFrame::ID_TEXTCTRL8 = wxNewId();
const long UserFrame::ID_BUTTON1 = wxNewId();
const long UserFrame::ID_TEXTCTRL9 = wxNewId();
const long UserFrame::ID_TEXTCTRL10 = wxNewId();
const long UserFrame::ID_STATICTEXT2 = wxNewId();
const long UserFrame::ID_STATICTEXT3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(UserFrame,wxFrame)
    //(*EventTable(UserFrame)
    //*)
END_EVENT_TABLE()

UserFrame::UserFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(UserFrame)
    Create(parent, id, _("���ݿ��ѯ"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(800,600));
    Move(wxDefaultPosition);
    cbx_id = new wxCheckBox(this, ID_CHECKBOX1, _("ѧ��"), wxPoint(48,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    cbx_id->SetValue(false);
    cbx_name = new wxCheckBox(this, ID_CHECKBOX2, _("����"), wxPoint(48,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    cbx_name->SetValue(false);
    sle_id = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(128,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    sle_name = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(128,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    cbx_agest = new wxCheckBox(this, ID_CHECKBOX3, _("������"), wxPoint(48,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    cbx_agest->SetValue(false);
    sle_agest = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(128,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("��"), wxPoint(256,208), wxSize(33,26), 0, _T("ID_STATICTEXT1"));
    sle_ageed = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(320,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    cbx_sex = new wxCheckBox(this, ID_CHECKBOX4, _("�Ա�"), wxPoint(48,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    cbx_sex->SetValue(false);
    sle_sex = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(128,256), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    cbx_dept = new wxCheckBox(this, ID_CHECKBOX5, _("ϵ��"), wxPoint(440,96), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    cbx_dept->SetValue(false);
    sle_dept = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(528,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    cbx_class = new wxCheckBox(this, ID_CHECKBOX6, _("�༶"), wxPoint(440,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    cbx_class->SetValue(false);
    sle_class = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxPoint(528,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    cbx_addr = new wxCheckBox(this, ID_CHECKBOX7, _("��ַ"), wxPoint(440,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    cbx_addr->SetValue(false);
    sle_addr = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxPoint(528,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    Button1 = new wxButton(this, ID_BUTTON1, _("��ѯ"), wxPoint(664,144), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxPoint(48,320), wxSize(712,96), 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxPoint(48,456), wxSize(712,128), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("SQL���"), wxPoint(48,304), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("��ѯ���"), wxPoint(48,440), wxDefaultSize, 0, _T("ID_STATICTEXT3"));

    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserFrame::Oncbx_idClick);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserFrame::Oncbx_nameClick);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_idText);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_nameText);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserFrame::Oncbx_agestClick);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_agestText);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_ageedText);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserFrame::Oncbx_sexClick);
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_sexText);
    Connect(ID_CHECKBOX5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserFrame::Oncbx_deptClick);
    Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_deptText);
    Connect(ID_CHECKBOX6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserFrame::Oncbx_classClick);
    Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_classText);
    Connect(ID_CHECKBOX7,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&UserFrame::Oncbx_addrClick);
    Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&UserFrame::Onsle_addrText);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&UserFrame::OnButton1Click);
    //*)
}

UserFrame::~UserFrame()
{
    //(*Destroy(UserFrame)
    //*)
}

void UserFrame::Oncbx_idClick(wxCommandEvent& event)
{
    cbx_id_checked=cbx_id->GetValue();
}

void UserFrame::Onsle_idText(wxCommandEvent& event)
{
    sle_id_text=sle_id->GetValue();
}

void UserFrame::Oncbx_nameClick(wxCommandEvent& event)
{
    cbx_name_checked=cbx_name->GetValue();
}

void UserFrame::Onsle_nameText(wxCommandEvent& event)
{
    sle_name_text=sle_name->GetValue();
}

void UserFrame::Oncbx_agestClick(wxCommandEvent& event)
{
    cbx_agest_checked=cbx_agest->GetValue();
}

void UserFrame::Onsle_agestText(wxCommandEvent& event)
{
    sle_agest_text=sle_agest->GetValue();
}

void UserFrame::Onsle_ageedText(wxCommandEvent& event)
{
    sle_ageed_text=sle_ageed->GetValue();
}

void UserFrame::Oncbx_sexClick(wxCommandEvent& event)
{
    cbx_sex_checked=cbx_sex->GetValue();
}

void UserFrame::Onsle_sexText(wxCommandEvent& event)
{
    sle_sex_text=sle_sex->GetValue();
}

void UserFrame::Oncbx_deptClick(wxCommandEvent& event)
{
    cbx_dept_checked=cbx_dept->GetValue();
}

void UserFrame::Onsle_deptText(wxCommandEvent& event)
{
    sle_dept_text=sle_dept->GetValue();
}

void UserFrame::Oncbx_classClick(wxCommandEvent& event)
{
    cbx_class_checked=cbx_class->GetValue();
}

void UserFrame::Onsle_classText(wxCommandEvent& event)
{
    sle_class_text=sle_class->GetValue();
}

void UserFrame::Oncbx_addrClick(wxCommandEvent& event)
{
    cbx_addr_checked=cbx_addr->GetValue();
}

void UserFrame::Onsle_addrText(wxCommandEvent& event)
{
    sle_addr_text=sle_addr->GetValue();
}

//����SQL���
string Make_SQL()
{
    string str_temp="";
    str_temp="select * from Student where ";
    int firstflag = 0;

    if (cbx_id_checked)
    {
        str_temp=str_temp+"(Sid like '"+sle_id_text+"') ";
        firstflag=1;
    }

    if (cbx_name_checked)
    {
        if(firstflag)
        {
            str_temp=str_temp+"and (Sname like '"+sle_name_text+"') ";
        }
        else
        {
            str_temp=str_temp+"(Sname like '"+sle_name_text+"') ";
            firstflag=1;
        }
    }

    if (cbx_sex_checked)
    {
        if(firstflag)
        {
            str_temp=str_temp+"and (Ssex like '"+sle_sex_text+"') ";
        }
        else
        {
            str_temp=str_temp+"(Ssex='"+sle_sex_text+"') ";
            firstflag=1;
        }
    }

    if (cbx_class_checked)
    {
        if(firstflag)
        {
            str_temp=str_temp+"and (Sclass like '"+sle_class_text+"') ";
        }
        else
        {
            str_temp=str_temp+"(Sclass like '"+sle_class_text+"') ";
            firstflag=1;
        }
    }

    if (cbx_dept_checked)
    {
        if(firstflag)
        {
            str_temp=str_temp+"and (Did='"+sle_dept_text+"') ";
        }
        else
        {
            str_temp=str_temp+"(Did='"+sle_dept_text+"') ";
            firstflag=1;
        }
    }

    if (cbx_addr_checked)
    {
        if(firstflag)
        {
            str_temp=str_temp+"and (Saddress like '"+sle_addr_text+"') ";
        }
        else
        {
            str_temp=str_temp+"(Saddress like '"+sle_addr_text+"') ";
            firstflag=1;
        }
    }

    if (cbx_agest_checked)
    {
        stringstream agest(sle_agest_text);
        stringstream ageed(sle_ageed_text);
        if (firstflag)
        {
            str_temp=str_temp+"and (Sage >= '"+sle_agest_text+"') ";
            if(ageed>agest)
            {
                str_temp=str_temp+"and (Sage <= '"+sle_ageed_text+"') ";
            }
        }
        else
        {
            str_temp=str_temp+"(Sage >= '"+sle_agest_text+"') ";
            if(ageed>agest)
            {
                str_temp=str_temp+"and (Sage <= '"+sle_ageed_text+"') ";
            }
        }
        firstflag=1;
    }
    str_temp=str_temp+";";
    return str_temp;
}

void UserFrame::OnButton1Click(wxCommandEvent& event)
{
    sql_text = Make_SQL();
    TextCtrl1->WriteText(sql_text);
    const char* query= sql_text.c_str();
    //���ݿ��ѯ
    MYSQL my_connection; /*����һ�����ݿ�����*/
    int res; /*ִ��sql�Z���ķ��ر�־*/
    MYSQL_RES *res_ptr; /*ָ���ѯ�����ָ��*/
    MYSQL_FIELD *field; /*�ֶνṹָ��*/
    MYSQL_ROW result_row; /*���з��صĲ�ѯ��Ϣ*/
    int row, column; /*��ѯ���ص�����������*/
    int i, j;
    /*��ʼ��mysql����my_connection*/
    mysql_init(&my_connection);
    /*����mysql����*/
    if (NULL != mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD,
                                   DATABASE, 0, NULL, CLIENT_FOUND_ROWS))  /*���ӳɹ�*/
    {
        printf("���ݿ��ѯquery_sql���ӳɹ���\n");
        /*���ò�ѯ����Ϊgbk����֧������*/
        mysql_query(&my_connection, "set names gbk");
        res = mysql_query(&my_connection, query);
        if (res)   /*ִ��ʧ��*/
        {
            printf("Error�� mysql_query !\n");
            /*�ر�����*/
            mysql_close(&my_connection);
        }
        else     /*���ھʹ���ִ�гɹ���*/
        {
            /*����ѯ�ĽY����res_ptr*/
            res_ptr = mysql_store_result(&my_connection);
            /*��������Ϊ�գ��Ͱѽ��print*/
            if (res_ptr)
            {
                /*ȡ�ýY����������*/
                column = mysql_num_fields(res_ptr);
                row = mysql_num_rows(res_ptr);
                printf("��ѯ�� %d �� \n", row);
                /*����Y�����ֶ���*/
                for (i = 0; field = mysql_fetch_field(res_ptr); i++)
                {
                    TextCtrl2->AppendText(wxString::Format(("%10s "),  field->name));
                }
                TextCtrl2 ->AppendText("\n");
            }
            /*��������Y��*/
            for (i = 1; i < row+1; i++)
            {
                result_row = mysql_fetch_row(res_ptr);
                for (j = 0; j < column; j++)
                {
                    TextCtrl2->AppendText(wxString::Format(("%10s "), result_row[j]));
                }
                TextCtrl2 ->AppendText("\n");
            }
        }
        /*��Ҫ���˹ر�����*/
        mysql_close(&my_connection);
    }
}
