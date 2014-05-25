//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit23.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm23 *Form23;
//---------------------------------------------------------------------------
__fastcall TForm23::TForm23(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm23::Image2Click(TObject *Sender)
{
        if(!Memo1->Text.IsEmpty()){
                String cadena;
                cadena="insert into observaciones values(null,'"+Memo1->Text+"','"+Form1->Label43->Caption+"')";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);

                Query1->ExecSQL();
                MessageDlg("Insertado con éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                Form23->Close();
                Form1->Memo1->Lines->Add(Memo1->Text);
        }else{
                MessageDlg("Si vas a agregar una observación, no deje los espacios en blanco", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}

//---------------------------------------------------------------------------
void __fastcall TForm23::Image3Click(TObject *Sender)
{
        Form23->Close();
}
//---------------------------------------------------------------------------

