//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit16.h"
#include "Unit3.h"
#include "ctype.h"
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



void __fastcall TForm16::Memo1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm16::Image3Click(TObject *Sender)
{
        Form16->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm16::Image2Click(TObject *Sender)
{
        String cadena;
        int total=0;
        if(!Memo1->Text.IsEmpty()){
                cadena="select count(*) as total form direccionrevision where lugar='"+Memo1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total<1){
                        cadena="insert into direccionrevision value(null,'"+Memo1->Text+"')";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                        MessageDlg("Agregado con éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        Form16->Close();

                }else{
                        MessageDlg("Ya está repetida la direccion de revision del bien. Ingrese otra", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("No ha ingresado la dirección de revisión del bien", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------
