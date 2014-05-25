//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit4.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Image3Click(TObject *Sender)
{
        Form6->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                String cadena;
                int total;
                cadena="select count(*) as total from modelo where nombre='"+Edit1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total!=1){
                cadena="insert into modelo values(null,'"+Edit1->Text+"',"+marca_id+")";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->ExecSQL();
                MessageDlg("Agregado con Éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                Edit1->Clear();
                Form6->Close();
                Form4->modelo();
                }else{
                        MessageDlg("El modelo está ya repetido. Intente con otro", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("No ha ingresado Modelo", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==13){
                if(Edit1->Text.IsEmpty()){
                        MessageDlg("No ha ingresado Modelo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }else{
                        Image2Click(Sender);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------

