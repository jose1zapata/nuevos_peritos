//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "otra.h"
#include "ctype.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm16 *Form16;
//---------------------------------------------------------------------------
__fastcall TForm16::TForm16(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm16::Image3Click(TObject *Sender)
{
        Form16->Close();
        Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm16::Image2Click(TObject *Sender)
{
        if(!Memo1->Text.IsEmpty()){
                String cadena;
                int total=0;
                cadena="select count(*) as total from direccionrevision where  lugar='"+Memo1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total<=0){
                        cadena="insert into direccionrevision value(null,'"+Memo1->Text+"')";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                        MessageDlg("ingresado con exito",mtInformation,TMsgDlgButtons()<<mbOK,0);
                        Form16->Close();
                        Memo1->Clear();
                        Form3->direccion();
                }else{
                        MessageDlg("Dirección ya registrada. intente con otra",mtInformation,TMsgDlgButtons()<<mbOK,0);
                }
        }else{
                MessageDlg("Ingrese Dirección de la revisión del Bien.",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm16::Memo1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

