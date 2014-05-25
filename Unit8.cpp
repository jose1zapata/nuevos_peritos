//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image3Click(TObject *Sender)
{
        Form8->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                String cadena;
                int total;
                cadena="select count(*) as total from tipo where nombre='"+Edit1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total!=1){
                cadena="insert into tipo values(null,'"+Edit1->Text+"')";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->ExecSQL();
                MessageDlg("Agregado con Éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                Edit1->Clear();
                Form8->Close();
                Form4->tipo();
                }else{
                        MessageDlg("El Tipo está ya registrado. Intente con otro", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("No ha ingresado Tipo", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==13){
                if(Edit1->Text.IsEmpty()){
                        MessageDlg("No ha Ingresado Tipo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }else{
                        Image2Click(Sender);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------

