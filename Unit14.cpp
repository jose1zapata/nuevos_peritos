//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit14.h"
#include "Unit1.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForm14::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm14::rellenar(){
        String cadena;
        int i=0;
        cadena="select * from tipoautoparte";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        Query1->First();
        ComboBox1->Clear();
        ComboBox1->Text="Seleccione";
        while(!Query1->Eof){
                todo[i][0]=Query1->FieldByName("nombre")->Value;
                todo[i][1]=Query1->FieldByName("id")->Value;
                ComboBox1->Items->Add(todo[i][0]);
                Query1->Next();
                i++;
        }
}
void __fastcall TForm14::Image3Click(TObject *Sender)
{
        Form14->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Image2Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()){
                if(ComboBox1->ItemIndex!=-1){
                        String cadena;
                        cadena="insert into autopartes values(null,'"+Edit1->Text+"',"+todo[ComboBox1->ItemIndex][1]+")";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                        MessageDlg("Agregado con éxito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        Form14->Close();
                        Edit1->Text="";
                        Form1->rellenar();
                }else{
                        MessageDlg("Debe seleccionar si es cambiar o reparar", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("Debe rellenar el campo de la autoparte", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm14::Image4Click(TObject *Sender)
{
        ShowMessage("Debe escribir la autoparte a agregar\n Una vez hecho esto, selecciona que tipo desea cambiar/repara\n eso es todo");        
}
//---------------------------------------------------------------------------

