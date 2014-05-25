//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit28.h"
#include "Unit27.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm28 *Form28;
//---------------------------------------------------------------------------
__fastcall TForm28::TForm28(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm28::Image1Click(TObject *Sender)
{
        if(ComboBox1->ItemIndex!=-1){
        Form27->Query1->Close();
        if(ComboBox1->ItemIndex==0)
        Form27->QRLabel3->Caption="LISTA DE AUTOPARTES: CAMBIAR";
        else
        Form27->QRLabel3->Caption="LISTA DE AUTOPARTES: REPARA";;
        Form27->Query1->SQL->Clear();
        String x=ComboBox1->ItemIndex+1;
        Form27->Query1->SQL->Add("select id,nombre from autopartes where tipoautoparte_id="+(x)+" order by nombre");
        Form27->Query1->Active=true;
        Form27->QuickRep1->Preview();
        }
}
//---------------------------------------------------------------------------
