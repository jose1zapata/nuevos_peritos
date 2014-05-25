//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit19.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm19 *Form19;
//---------------------------------------------------------------------------
__fastcall TForm19::TForm19(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm19::Image3Click(TObject *Sender)
{
        Form19->Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm19::Image2Click(TObject *Sender)
{
        String cadena;
        cadena="UPDATE conductores SET cedulaconductor='"+Edit1->Text+"', nombreconductor='"+Edit2->Text+"', cedulapropietario='"+Edit3->Text+"', direccionpropietario='"+Memo1->Text+"', telefono='"+Edit5->Text+"', nombrepropietario='"+Edit4->Text+"' where id="+Label8->Caption;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->ExecSQL();
        MessageDlg("Modificado con exito",mtInformation,TMsgDlgButtons()<<mbOK,0);
        Form1->Label7->Caption=Edit1->Text;
        Form1->Label5->Caption=Edit2->Text;
        Form1->Label11->Caption=Edit3->Text;
        Form1->Label9->Caption=Edit4->Text;
        Form1->Label13->Caption=Edit5->Text;
        Form1->Label15->Caption=Memo1->Text;
        Form1->Label17->Caption=Label8->Caption;
        Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        Edit4->Clear();
        Edit5->Clear();
        Memo1->Clear();
        Form19->Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm19::Edit2KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------
void __fastcall TForm19::Edit4KeyPress(TObject *Sender, char &Key)
{
        Edit2KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm19::Memo1KeyPress(TObject *Sender, char &Key)
{
        Edit2KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------



