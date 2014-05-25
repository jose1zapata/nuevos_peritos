//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit22.h"
#include "Unit1.h"
#include "Unit11.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm22 *Form22;
//---------------------------------------------------------------------------
__fastcall TForm22::TForm22(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm22::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
        if(Key==13){
                Image1Click(Sender);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm22::Image3Click(TObject *Sender)
{
        Form22->Close();
        Edit1->Clear();
        ListBox1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm22::Image1Click(TObject *Sender)
{
        String cadena,idvehiculo,idvehiculos,asd;
        int total=0;
        cadena="select count(*) as total from vehiculo where placa='"+Edit1->Text+"'";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        todos=0;
        total=Query1->FieldByName("total")->Value;
        asd=total;
        if(total>0){
                cadena="select * from vehiculo where placa='"+Edit1->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                idvehiculo=Query1->FieldByName("id")->Value;
                cadena="select count(*) as total from accidente where vehiculo_id="+idvehiculo;
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                Query1->First();
                total=Query1->FieldByName("total")->Value;
                if(total>0){
                        asd=total;
                        if(total==1)
                                Label2->Caption="Se Encontró: "+asd+" Acta en placa '"+Edit1->Text+"'";
                        else
                                Label2->Caption="Se Encontraron: "+asd+" acta en placa '"+Edit1->Text+"'";
                        cadena="select * from accidente where vehiculo_id="+idvehiculo;
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->Active=true;
                        Query1->First();
                        ListBox1->Clear();
                        while(!Query1->Eof){
                                idvehiculo=Query1->FieldByName("id")->Value;
                                cadena="select count(*) as total from avaluo where accidente_id="+idvehiculo;
                                Query2->Close();
                                Query2->SQL->Clear();
                                Query2->SQL->Add(cadena);
                                Query2->Active=true;
                                total=Query2->FieldByName("total")->Value;
                                if(total>0){
                                        cadena="select * from avaluo where accidente_id="+idvehiculo;
                                        Query2->Close();
                                        Query2->SQL->Clear();
                                        Query2->SQL->Add(cadena);
                                        Query2->Active=true;
                                        idvehiculos=Query2->FieldByName("id")->Value;
                                        avaluos[todos]=idvehiculos;
                                        ListBox1->Items->Add(idvehiculos);
                                        todos++;
                                }
                                Query1->Next();
                        }
                }else{
                        MessageDlg("Esta placa aun no tiene un registro en accidente y avaluo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        asd=total;
                        if(total==1)
                        Label2->Caption="Se Encontró: "+asd+" Acta en placa '"+Edit1->Text+"'";
                        else
                        Label2->Caption="Se Encontraron: "+asd+" actas en placa '"+Edit1->Text+"'";
                        ListBox1->Clear();
                }
        }else{
                MessageDlg("Placa no existe", mtInformation, TMsgDlgButtons() << mbOK, 0);
                asd=total;
                if(total==1)
                        Label2->Caption="Se Encontró: "+asd+" Acta en placa '"+Edit1->Text+"'";
                else
                        Label2->Caption="Se Encontraron: "+asd+" actas en placa '"+Edit1->Text+"'";
                ListBox1->Clear();

        }


}
//---------------------------------------------------------------------------
void __fastcall TForm22::ListBox1DblClick(TObject *Sender)
{
        Form11->Edit1->Text=avaluos[ListBox1->ItemIndex];
        Form11->Image1Click(Sender);
        Image3Click(Sender);

}
//---------------------------------------------------------------------------


