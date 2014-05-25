//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit4.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image3Click(TObject *Sender)
{
        Form5->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                String cadena;
                int total;
                cadena="select count(*) as total from marca where nombre='"+Edit1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total!=1){
                cadena="insert into marca values(null,'"+Edit1->Text+"')";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->ExecSQL();
                MessageDlg("Agregado con Éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                Edit1->Clear();
                Form5->Close();
                Form4->marca();
                }else{
                        MessageDlg("La marca está ya repetida. Intente con otra", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }
        else{
                MessageDlg("No haz agregado nada", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

