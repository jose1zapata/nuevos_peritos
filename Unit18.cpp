//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit18.h"
#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm18 *Form18;
//---------------------------------------------------------------------------
__fastcall TForm18::TForm18(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm18::Image3Click(TObject *Sender)
{
        Form18->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm18::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                String cadena;
                int total;
                cadena="select count(*) as total from ciudadinspeccion where nombre='"+Edit1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total<=0){
                        cadena="insert into ciudadinspeccion value(null,'"+Edit1->Text+"')";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                        MessageDlg("ingresado con exito",mtInformation,TMsgDlgButtons()<<mbOK,0);
                        Form18->Close();
                        Edit1->Clear();
                        Form3->ciudad();
                }else{
                        MessageDlg("Ciudad ya resgistrada. Ingrese otra.",mtInformation,TMsgDlgButtons()<<mbOK,0);
                }
        }else{
                MessageDlg("El campo de la ciudad está vacio",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------
