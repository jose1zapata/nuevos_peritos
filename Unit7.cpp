//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit4.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm7::Image3Click(TObject *Sender)
{
        Form7->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                String cadena;
                int total;
                cadena="select count(*) as total from color where nombre='"+Edit1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total!=1){
                cadena="insert into color values(null,'"+Edit1->Text+"')";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->ExecSQL();
                MessageDlg("Agregado con Éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                Edit1->Clear();
                Form7->Close();
                Form4->colores();
                }else{
                        MessageDlg("El Color está ya registrado. Intente con otro",mtInformation,TMsgDlgButtons()<<mbOK,0);
                }
        }else{
                MessageDlg("No ha ingresado Color", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==13){
                if(Edit1->Text.IsEmpty()){
                        MessageDlg("No ha Ingresado Color", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }else{
                        Image2Click(Sender);
                }
        }        
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------

