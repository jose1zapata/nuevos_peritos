//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit25.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm25 *Form25;
//---------------------------------------------------------------------------
__fastcall TForm25::TForm25(TComponent* Owner)
        : TForm(Owner)
{ ban=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm25::codigo(){
        String cadena;
        int total;
        cadena="select count(*) as total from perito_code";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        total=Query1->FieldByName("total")->Value;
        if(total==0){
                Form25->ShowModal();
        }

}
void __fastcall TForm25::Image1Click(TObject *Sender)
{
        String cadena,id;
        int total;
        cadena="select count(*) as total from code where codigo=MD5('"+Edit1->Text+"')";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        total=Query1->FieldByName("total")->Value;
        if(total>0){
        cadena="select * from code where codigo=MD5('"+Edit1->Text+"')";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        id=Query1->FieldByName("id")->Value;
        cadena="insert into perito_code values(NULL,'"+Edit2->Text+"',1,"+id+")";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->ExecSQL();
        MessageDlg("Insertado con exito, ahora puedes usar el programa...\nBienvenido...",mtInformation,TMsgDlgButtons()<<mbOK,0);
        cadena="select * from perito_code";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        cadena=Query1->FieldByName("nombreempresa")->Value;
        Form1->Panel23->Caption=cadena;
        ban=1;
        Form25->Close();
        }else{
                MessageDlg("Codigo invalido o mal escrito. Intentalo de Nuevo",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm25::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(ban==0)
        exit(0);
}
//---------------------------------------------------------------------------

