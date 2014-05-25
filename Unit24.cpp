//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit24.h"
#include "Unit13.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm24 *Form24;
//---------------------------------------------------------------------------
__fastcall TForm24::TForm24(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm24::Image3Click(TObject *Sender)
{
        Form24->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm24::Image2Click(TObject *Sender)
{
        String cadena,x,desde,hasta,SESA;
        String diad,mesd,anhod,fechad,aux;
        String diah,mesh,anhoh,fechah;
        char cadenas[1000],*p,cadenas2[1000],dc[1000];
        int pp=0;
        float resultado=0;
        Form13->QRLabel18->Left=30000;

        Form13->QRLabel19->Left=30000;
        Form13->QRLabel20->Left=30000;
        Form13->QRLabel21->Left=30000;
        cadena="select * from perito";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        aux=Query1->FieldByName("nombre")->Value;
        aux+=" "+Query1->FieldByName("apellido")->Value;
        Form13->QRLabel11->Caption=aux;
        Form13->QRLabel15->Caption=Query1->FieldByName("cedula")->Value;
        Form13->QRLabel17->Caption=Query1->FieldByName("codigo")->Value;

        SESA=Edit1->Text;
        desde=DateTimePicker1->Date;
        hasta=DateTimePicker2->Date;
        StrCopy(cadenas2,desde.c_str());
        p=strtok(cadenas2,"-/ ");
        while(p!=NULL){
                if(pp==0)
                        diad=p;
                if(pp==1)
                        mesd=p;
                if(pp==2)
                        anhod=p;
                pp++;
                p=strtok(NULL,"-/ ");
        }
        fechad=diad+"-"+mesd+"-"+anhod;
        SESA+=" "+fechad+" HASTA EL DIA ";
        fechad=anhod+"-"+mesd+"-"+diad;
        desde=fechad;
        pp=0;
        StrCopy(cadenas2,hasta.c_str());
        p=strtok(cadenas2,"-/ ");
        while(p!=NULL){
                if(pp==0)
                        diah=p;
                if(pp==1)
                        mesh=p;
                if(pp==2)
                        anhoh=p;
                pp++;
                p=strtok(NULL,"-/ ");
        }
        fechah=diah+"-"+mesh+"-"+anhoh;
        SESA+=fechah;
        Form13->QRLabel1->Caption=SESA;
        fechah=anhoh+"-"+mesh+"-"+diah;
        hasta=fechah;
        pp=0;
        cadena="select concat(monto,' Bs.') monto, placa, m.nombre,nombrepropietario, serialcarroceria, numeroplanilla, av.id, av.fecha ";
        cadena+="from conductores c, vehiculo v, modelo m,avaluo av, accidente ac ";
        cadena+="where conductores_id=c.id ";
        cadena+="and modelo_id=m.id ";
        cadena+="and vehiculo_id=v.id ";
        cadena+="and accidente_id=ac.id and av.fecha between '"+desde+"' and '"+hasta+"' ";

        if(ComboBox1->ItemIndex!=-1){
                anhoh=Form4->Uso[ComboBox1->ItemIndex];
                Form13->QRLabel19->Caption=anhoh;
                anhoh=ComboBox1->ItemIndex+1;
                cadena+=" and v.uso_id="+(anhoh)+" ";

                Form13->QRLabel18->Left=719;
                Form13->QRLabel19->Left=854;
                if(ComboBox2->ItemIndex!=-1){
                        Form13->QRLabel20->Left=749;
                        Form13->QRLabel21->Left=854;
                }else{
                        Form13->QRLabel20->Left=30000;
                        Form13->QRLabel21->Left=30000;
                }
        }

        if(ComboBox2->ItemIndex!=-1){
                anhoh=Form4->Tipo[ComboBox2->ItemIndex][0];
                Form13->QRLabel21->Caption=Form4->Tipo[ComboBox2->ItemIndex][0];
                anhoh=ComboBox2->ItemIndex+1;
                cadena+=" and v.tipo_id="+(anhoh)+" ";
                if(ComboBox1->ItemIndex!=-1){
                        Form13->QRLabel18->Left=719;
                        Form13->QRLabel19->Left=854;
                }
                else{
                        Form13->QRLabel18->Left=30000;
                        Form13->QRLabel19->Left=30000;
                }
                Form13->QRLabel20->Left=749;
                Form13->QRLabel21->Left=854;
        }
        Form13->Query1->Close();
        Form13->Query1->SQL->Clear();
        Form13->Query1->SQL->Add(cadena);
        Form13->Query1->Active=true;

        cadena="select * from encabezado";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        x=Query1->FieldByName("cabecera")->Value;
        StrCopy(cadenas,x.c_str());
        p=strtok(cadenas,"\n");
        while(p!=NULL){
                x=p;
                Form13->QRMemo1->Lines->Add(x);
                p=strtok(NULL,"\n");
        }
        cadena="select monto, placa, m.nombre,nombrepropietario, serialcarroceria, numeroplanilla, av.id, av.fecha ";
        cadena+="from conductores c, vehiculo v, modelo m,avaluo av, accidente ac ";
        cadena+="where conductores_id=c.id ";
        cadena+="and modelo_id=m.id ";
        cadena+="and vehiculo_id=v.id ";
        cadena+="and accidente_id=ac.id and av.fecha between '"+desde+"' and '"+hasta+"' ";
        if(ComboBox1->ItemIndex!=-1){
                anhoh=ComboBox1->ItemIndex+1;

                cadena+=" and v.uso_id="+(anhoh)+" ";
        }

        if(ComboBox2->ItemIndex!=-1){
                anhoh=ComboBox2->ItemIndex+1;
                cadena+=" and v.tipo_id="+(anhoh)+" ";
        }
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        Query1->First();

        resultado=0;
        while(!Query1->Eof){
                aux=Query1->FieldByName("monto")->Value;
                StrCopy(dc,aux.c_str());
                p=strtok(dc,".");
                aux=p;
                pp=0;
                while(p!=NULL){
                        if(pp==1)
                                aux+=p;
                        pp++;
                        p=strtok(NULL,".");
                }
                resultado+=atoi(aux.c_str());
                Query1->Next();
        }
        aux=resultado;
        aux=FormatFloat("##,###,###",aux.ToDouble());
        Form13->QRLabel13->Caption=aux+" Bs.";
        Form13->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm24::Label3DblClick(TObject *Sender)
{
        Form4->uso();
}
//---------------------------------------------------------------------------


void __fastcall TForm24::Label4DblClick(TObject *Sender)
{
        Form4->tipo();        
}
//---------------------------------------------------------------------------

