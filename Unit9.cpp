//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit4.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Image3Click(TObject *Sender)
{
        Form9->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                String cadena;
                cadena="insert into seguro values(null,'"+Edit1->Text+"')";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->ExecSQL();
                MessageDlg("Agregado con Éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                Edit1->Clear();
                Form9->Close();
                Form4->seguro();
        }else{
                MessageDlg("No ha ingresado Seguro del Auto", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==13){
                if(Edit1->Text.IsEmpty()){
                        MessageDlg("No ha ingresado Seguro del Auto", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }else{
                        Image2Click(Sender);
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

