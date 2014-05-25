//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit17.h"
#include "Unit4.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm17 *Form17;
//---------------------------------------------------------------------------
__fastcall TForm17::TForm17(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm17::Image1Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                String cadena;
                int total;
                cadena="select count(*) as total from uso where nombre='"+Edit1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total<=0){
                cadena="insert into uso value(null,'"+Edit1->Text+"')";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->ExecSQL();
                MessageDlg("Agregado con éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                Edit1->Text="";
                Form4->uso();
                Form17->Close();
                }else{
                        MessageDlg("Uso del vehiculo repetido, intente con otro", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }

        }else{
                MessageDlg("No ha ingresado el uso del vehiculo.", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm17::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm17::Image2Click(TObject *Sender)
{
        Edit1->Text="";
        Form17->Close();        
}
//---------------------------------------------------------------------------
