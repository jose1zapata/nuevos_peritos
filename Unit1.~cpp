//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit10.h"
#include "Unit11.h"
#include "Unit12.h"
#include "Unit13.h"
#include "Unit14.h"
#include "Unit15.h"
#include "Unit19.h"
#include "Unit20.h"
#include "Unit21.h"
#include "Unit22.h"
#include "Unit23.h"
#include "Unit24.h"
#include "Unit25.h"
#include "Unit26.h"
#include "Unit27.h"
#include "Unit28.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UCrpe32"
#pragma link "UCrpeClasses"
#pragma link "UCrpe32"
#pragma link "UCrpeClasses"
#pragma link "UCrpe32"
#pragma link "UCrpe32"
#pragma link "UCrpeClasses"
#pragma link "UCrpe32"
#pragma link "UCrpeClasses"
#pragma resource "*.dfm"
TForm1 *Form1;
bool press=0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{


        String cadena;
        int total=0;
        activado=0;
        cadena="select count(*) as total from perito_code";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        total=Query1->FieldByName("total")->Value;
        if(total>0){
                cadena="select * from perito_code";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                cadena=Query1->FieldByName("nombreempresa")->Value;
                Form1->Panel23->Caption=cadena;
        }else{
                Panel23->Caption="Software Asociación de Peritos Avaluadores de Venezuela.";
        }


        Form1->WindowState=wsMaximized;
        Panel1->Width=400;
        Panel6->Width=200;
        Panel7->Width=200;

        rellenar();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::llamalo(){
        int total=0;
        Query2->Close();
        Query2->SQL->Clear();
        Query2->SQL->Add("select count(*) as total from perito");
        Query2->Active=true;
        total=Query2->FieldByName("total")->Value;
        if(total==0){
                Form10->ShowModal();
        }

}
void __fastcall TForm1::rellenar(){
        Form1->Left=0;
        Form1->Top=0;
        int i=0,y,j=0;
        CheckListBox1->Clear();
        CheckListBox2->Clear();
        String x="select * from autopartes order by nombre asc",var;

        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(x);
        Query1->Active=true;

        Query1->First();
        while(!Query1->Eof){

                y=Query1->FieldByName("tipoautoparte_id")->Value;
                if(y==1){
                        var=Query1->FieldByName("nombre")->Value;
                        CheckListBox1->Items->Add(var.UpperCase());
                        reparar[i]=var.UpperCase();
                        idreparar[i]=Query1->FieldByName("id")->Value;
                        i++;
                }else{
                        var=Query1->FieldByName("nombre")->Value;
                        CheckListBox2->Items->Add(var.UpperCase());
                        cambiar[j]=var.UpperCase();
                        idcambiar[j]=Query1->FieldByName("id")->Value;
                        j++;
                }
                Query1->Next();
        }
        totalreparar=i;
        totalcambiar=j;
}
//--------------Agregar Conductor'-------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{

        llamalo();
        Form25->codigo();
        Form2->ShowModal();
        Form2->ban=0;
        Form2->ban1=0;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image4Click(TObject *Sender)
{

        llamalo();
        Form25->codigo();
       if(activado==2){

        Form3->Edit3Click(Sender);
        Form3->formularXD();
        Form3->direccion();
        Form3->ciudad();
        Form3->ShowModal();
       }else{
        MessageDlg("Debes registrar el vehiculo primero", mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
       if(activado==1){
        Form4->marca();
        Form4->colores();
        Form4->tipo();
        Form4->seguro();
        Form4->anho();
        Form4->uso();
        Form4->ShowModal();
       }else{
        MessageDlg("Debes registrar el conductor primero", mtInformation, TMsgDlgButtons() << mbOK, 0);
       }
}
//---------------------------------------------------------------------------









        //Form1->WindowState=wsMaximized;

void __fastcall TForm1::Image9Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        Form1->WindowState=wsMinimized;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10Click(TObject *Sender)
{
        if( Application->MessageBox(
			"Desea Salir de la Aplicación",
			"Saliendo de Apasoft",
			MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES )
		exit(0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image11Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        MessageDlg("Debes hacer Clic a las imagenes de la izquierda. Son 4 estaciones en total.\n\n"
                   "Para empezar a trabajar, haz clic en 'Agregar Conductor' y rellena los campos de texto.\n\n"
                   "Una vez trabajó en la primera estación, haz clic en 'Agregar vehiculo' y rellena los campos de texto.\n\n"
                   "Una vez trabajó en la segunda estación, haz clic en 'Acta Avaluo Accidente' y rellena los campos de texto.\n\n"
                   "Una vez Trabajó en la tercera estación, procedemos a ver el lado derecho del programa y procedemos a seleccionar las autopartes a cambiar y/o reparar.\n\n"
                   "Una vez seleccionado en la sección derecha de 'AutoPartes', haz clic en la imagen asignar\n\n"
                   "Si falta una autoparte en la lista, haz clic en la parte inferior izquierda, donde dice 'Agregar autopartes'.", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        String cadena;
        String accidente=Label57->Caption;
        if(activado==4){
                for (int i=0;i<totalselectreparar;i++)
                {
                        cadena="INSERT INTO accidentesautoparte VALUES(null,"+selectreparar[i]+","+accidente+")";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                }
                for (int i=0;i<totalselectcambiar;i++)
                {
                        cadena="INSERT INTO accidentesautoparte VALUES(null,"+selectcambiar[i]+","+accidente+")";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                }
                MessageDlg("Agregado con éxito",mtInformation,TMsgDlgButtons()<<mbOK,0);
                Image6->Visible=false;
                Image12->Visible=true;
        }else{
                MessageDlg("Debes seleccionar autopartes de cambio o reparación primero", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        totalselectreparar=0;
        totalselectcambiar=0;
        ListBox1->Clear();
        ListBox2->Clear();
        if(activado==3||activado==4){
                for (int i=0;i<totalreparar;i++)
                {
                        if(CheckListBox1->Checked[i]==true)
                        {
                                selectreparar[totalselectreparar]=idreparar[i];
                                ListBox1->Items->Add(reparar[i]);
                                totalselectreparar++;
                        }
                }
                for (int i=0;i<totalcambiar;i++)
                {
                        if(CheckListBox2->Checked[i]==true)
                        {
                                selectcambiar[totalselectcambiar]=idcambiar[i];
                                ListBox2->Items->Add(cambiar[i]);
                                totalselectcambiar++;
                        }
                }
                activado=4;
        }else{
                MessageDlg("Debe primero Ingresar 'Acta Avaluo accidente'",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Salir1Click(TObject *Sender)
{
        Image10Click(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PeritoAvaluador1Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        Form11->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image12Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        String cadena,sitio,primera,fecha,x,y,z,estas,obsevaciones,aja;
        String meses[13]={"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
        char cadenota[200],FECHA[10],*p,primero[10000];
        int js;
        int j=0;
        String cambio,repararlo;
        Form11->Edit1->Text=Label43->Caption;
        sitio=Label43->Caption;
        NuevaActa1Click(Sender);
        Form11->Image1Click(Sender);
        cadena="select c.nombre as nombre from ciudadinspeccion c, avaluo a where c.id=a.ciudadinspeccion_id and a.id='"+sitio+"'";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        estas=Query1->FieldByName("nombre")->Value;
        cadena="DELETE FROM reporte WHERE id=1";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->ExecSQL();
        fecha=Label41->Caption;
        StrCopy(cadenota,fecha.c_str());
        fecha=NULL;
        p=strtok(cadenota,"-/");
        aja=p;
        js=aja.Length();
        while(p!=NULL){

                if(j==0){
                        if(js==4){
                                z=" DEL ";
                                z+=p;
                        }else{
                                x=", ";
                                x+=p;
                        }
                }
                if(j==1){
                        y=" DE ";
                        y+=meses[atoi(p)-1];
                }
                if(j==2){
                        if(js==4){
                                x=", ";
                                x+=p;
                        }else{
                                z=" DEL ";
                                z+=p;
                        }
                }
                p=strtok(NULL,"-/");
                j++;
        }
        fecha=estas;
        fecha+=x+y+z;
        for (int i=0;i<totalselectreparar;i++)
        {
                if((i+1)==totalselectreparar){
                        for (int j=0;j<totalreparar;j++)
                        {
                                if(idreparar[j]==selectreparar[i]){
                                        cambio+=reparar[j]+". ";
                                        break;
                                }
                        }

                }
                else{
                        for (int j=0;j<totalreparar;j++)
                        {
                                if(idreparar[j]==selectreparar[i]){
                                        cambio+=reparar[j]+", ";
                                        break;
                                }
                        }
                }
        }
        for (int i=0;i<totalselectcambiar;i++)
        {
                if((i+1)==totalselectcambiar){
                        for (int j=0;j<totalcambiar;j++)
                        {
                                if(idcambiar[j]==selectcambiar[i]){
                                        repararlo+=cambiar[j]+". ";
                                        break;
                                }
                        }
                }
                else{
                        for (int j=0;j<totalcambiar;j++)
                        {
                                if(idcambiar[j]==selectcambiar[i]){
                                        repararlo+=cambiar[j]+", ";
                                        break;
                                }
                        }

                }
        }

        cadena="insert into reporte value(1,";
        cadena+="'"+Label5->Caption+"',";//nc
        cadena+="'"+Label7->Caption+"',";//cc
        cadena+="'"+Label9->Caption+"',";//np
        cadena+="'"+Label11->Caption+"',";//cp
        cadena+="'"+Label13->Caption+"',";//tl
        cadena+="'"+Label15->Caption+"',";//di
        cadena+="'"+Label19->Caption+"',";//marca
        cadena+="'"+Label21->Caption+"',";//modelo
        cadena+="'"+Label23->Caption+"',";//tipo
        cadena+="'"+Label25->Caption+"',";//año
        cadena+="'"+Label27->Caption+"',";//color
        cadena+="'"+Label29->Caption+"',";//placa
        cadena+="'"+Label31->Caption+"',";//carroceria
        cadena+="'"+Label33->Caption+"',";//motor
        cadena+="'"+Label35->Caption+"',";//seguro
        cadena+="'"+Label37->Caption+"',";//poliza
        cadena+="'"+Label59->Caption+"',";//uso
        cadena+="'"+fecha+"',";//fecha acta avaluo
        cadena+="'"+Label43->Caption+"',";//experticia
        cadena+="'"+Label45->Caption+"',";//pendiente
        cadena+="'"+Label53->Caption+"',";//hora
        cadena+="'"+Label55->Caption+"',";//monto
        cadena+="'"+Label51->Caption+"',";//fechaacidente
        cadena+="'"+Label49->Caption+"',";//direccionaccidente
        cadena+="'"+Label47->Caption+"',";//direccionrevision
        if(!cambio.IsEmpty()&&repararlo.IsEmpty()){
                cadena+="'LAS PIEZAS QUE SE DESCRIBEN ESTAN DAÑADAS Y AMERITAN CAMBIO: "+cambio+"',";//piezas cambio
                cadena+="'',";
        }else{
                if(cambio.IsEmpty()&&!repararlo.IsEmpty()){
                        cadena+="'',";
                        cadena+="'ESTAS PIEZAS A MENCIONAR POSEE DEFORMACION REPARABLE: "+repararlo+"',";//piezas reparar
                }
                else{
                        if(!cambio.IsEmpty()&&!repararlo.IsEmpty()){
                                cadena+="'LAS PIEZAS QUE SE DESCRIBEN ESTAN DAÑADAS Y AMERITAN CAMBIO: "+cambio+"',";//piezas cambio
                                cadena+="'ESTAS OTRAS PIEZAS A MENCIONAR POSEE DEFORMACION REPARABLE: "+repararlo+"',";//piezas reparar
                        }else{
                                if(cambio.IsEmpty()&&repararlo.IsEmpty()){
                                        MessageDlg("No se puede generar el reporte. Debes agregar la lista de cambio o reparación",mtInformation,TMsgDlgButtons()<<mbOK,0);
                                }
                        }
                }
        }

        obsevaciones=Memo1->Text;
        cadena+="'"+obsevaciones+"')";
        if(!cambio.IsEmpty()&&!repararlo.IsEmpty()){
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->ExecSQL();
                Crpe1->Clear();
                Crpe1->ReportName="REPORTE\\reporte.rpt";
                Crpe1->Connect->Password="";
                Crpe1->Selection->Formula->Clear();
                Crpe1->Selection->Formula->Add("{reporte.id}=1");
                Crpe1->Execute();
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::returntonumber(String cadena){
        int x=0;
        String Cadena;
        char valor[100];
        StrCopy(valor,cadena.c_str());
        x=atoi(valor);
        if(x>=1000000){
                Cadena+="UN MILLÓN ";
                x=x-1000000;
        }
        if(x>900000){
                Cadena+="NOVECIENTOS ";
                x=x-900000;
        }
        if(x==900000){
                Cadena+="NOVECIENTOS MILL ";
                x=x-900000;
        }
        if(x>800000){
                Cadena+="OCHOCIENTOS ";
                x=x-800000;
        }
        if(x==800000){
                Cadena+="OCHOCIENTOS MIL ";
                x=x-800000;
        }
        if(x>700000){
                Cadena+="SETECIENTOS ";
                x=x-700000;
        }
        if(x==700000){
                Cadena+="SETECIENTOS MIL ";
                x=x-700000;
        }
        if(x>600000){
                Cadena+="SEISCIENTOS ";
                x=x-600000;
        }
        if(x==600000){
                Cadena+="SEISCIENTOS MIL ";
                x=x-600000;
        }
        if(x>500000){
                Cadena+="QUINIENTOS ";
                x=x-500000;
        }
        if(x==500000){
                Cadena+="QUINIENTOS MIL ";
                x=x-500000;
        }
        if(x>400000){
                Cadena+="CUATROCIENTOS ";
                x=x-400000;
        }
        if(x==400000){
                Cadena+="CUATROCIENTOS MIL ";
                x=x-400000;
        }
        if(x>300000){
                Cadena+="TRESCIENTOS ";
                x=x-300000;
        }
        if(x==300000){
                Cadena+="TRESCIENTOS MIL ";
                x=x-300000;
        }
        if(x>200000){
                Cadena+="DOSCIENTOS ";
                x=x-200000;
        }
        if(x==200000){
                Cadena+="DOSCIENTOS MIL ";
                x=x-200000;
        }
        if(x>100000){
                Cadena+="CIENTO ";
                x=x-100000;
        }
        if(x==100000){
                Cadena+="CIEN MIL ";
                x=x-100000;
        }
        if(x>90000){
                Cadena+="NOVENTA Y ";
                x=x-90000;
        }
        if(x==90000){
                Cadena+="NOVENTA MIL ";
                x=x-90000;
        }
        if(x>80000){
                Cadena+="OCHENTA Y ";
                x=x-80000;
        }
        if(x==80000){
                Cadena+="OCHENTA MIL ";
                x=x-80000;
        }
        if(x>70000){
                Cadena+="SETENTA Y ";
                x=x-70000;
        }
        if(x==70000){
                Cadena+="SETENTA MIL ";
                x=x-70000;
        }
        if(x>60000){
                Cadena+="SESENTA Y ";
                x=x-60000;
        }
        if(x==60000){
                Cadena+="SESENTA MIL ";
                x=x-60000;
        }
        if(x>50000){
                Cadena+="CINCUENTA Y ";
                x=x-50000;
        }
        if(x==50000){
                Cadena+="CINCUENTA MIL ";
                x=x-50000;
        }
        if(x>40000){
                Cadena+="CUARENTA Y ";
                x=x-40000;
        }
        if(x==40000){
                Cadena+="CUARENTA MIL ";
                x=x-40000;
        }
        if(x>30000){
                Cadena+="TREINTA Y ";
                x=x-30000;
        }
        if(x==30000){
                Cadena+="TREINTA MIL ";
                x=x-30000;
        }
        if(x>20000){
                Cadena+="VEINTI";
                x=x-20000;
        }
        if(x==20000){
                Cadena+="VEINTE MIL ";
                x=x-20000;
        }
        if(x>=19000){
                Cadena+="DIECINUEVE MIL ";
                x=x-19000;
        }
        if(x>=18000){
                Cadena+="DIECIOCHO MIL ";
                x=x-18000;
        }
        if(x>=17000){
                Cadena+="DIECISIETE MIL ";
                x=x-17000;
        }
        if(x>=16000){
                Cadena+="DIECISEIS MIL ";
                x=x-16000;
        }
        if(x>=15000){
                Cadena+="QUINCE MIL ";
                x=x-15000;
        }
        if(x>=14000){
                Cadena+="CATORCE MIL ";
                x=x-14000;
        }
        if(x>=13000){
                Cadena+="TRECE MIL ";
                x=x-13000;
        }
        if(x>=12000){
                Cadena+="DOCE MIL ";
                x=x-12000;
        }
        if(x>=11000){
                Cadena+="ONCE MIL ";
                x=x-11000;
        }
        if(x>=10000){
                Cadena+="DIEZ MIL ";
                x=x-10000;
        }
        if(x>=9000){
                Cadena+="NUEVE MIL ";
                x=x-9000;
        }
        if(x>=8000){
                Cadena+="OCHO MIL ";
                x=x-8000;
        }
        if(x>=7000){
                Cadena+="SIETE MIL ";
                x=x-7000;
        }
        if(x>=6000){
                Cadena+="SEIS MIL ";
                x=x-6000;
        }
        if(x>=5000){
                Cadena+="CINCO MIL ";
                x=x-5000;
        }
        if(x>=4000){
                Cadena+="CUATRO MIL ";
                x=x-4000;
        }
        if(x>=3000){
                Cadena+="TRES MIL ";
                x=x-3000;
        }
        if(x>=2000){
                Cadena+="DOS MIL ";
                x=x-2000;
        }
        if(x>=1000){
                Cadena+="UN MIL ";
                x=x-1000;
        }
        if(x>=900){
                Cadena+="NOVECIENTOS ";
                x=x-900;
        }
        if(x>=800){
                Cadena+="OCHOCIENTOS ";
                x=x-800;
        }
        if(x>=700){
                Cadena+="SETECIENTOS ";
                x=x-700;
        }
        if(x>=600){
                Cadena+="SEISCIENTOS ";
                x=x-600;
        }
        if(x>=500){
                Cadena+="QUINIENTOS ";
                x=x-500;
        }
        if(x>=400){
                Cadena+="CUATROCIENTOS ";
                x=x-400;
        }
        if(x>=300){
                Cadena+="TRESCIENTOS ";
                x=x-300;
        }
        if(x>=200){
                Cadena+="DOSCIENTOS ";
                x=x-200;
        }
        if(x>100){
                Cadena+="CIENTO ";
                x=x-100;
        }
        if(x==100){
                Cadena+="CIEN ";
                x=x-100;
        }
        if(x>90){
                Cadena+="NOVENTA Y";
                x=x-90;
        }
        if(x==90){
                Cadena+="NOVENTA ";
                x=x-90;
        }
        if(x>80){
                Cadena+="OCHENTA Y ";
                x=x-80;
        }
        if(x==80){
                Cadena+="OCHENTA ";
                x=x-80;
        }
        if(x>70){
                Cadena+="SETENTA Y ";
                x=x-70;
        }
        if(x==70){
                Cadena+="SETENTA ";
                x=x-70;
        }
        if(x>60){
                Cadena+="SESENTA Y ";
                x=x-60;
        }
        if(x==60){
                Cadena+="SESENTA ";
                x=x-60;
        }
        if(x>50){
                Cadena+="CINCUENTA Y ";
                x=x-50;
        }
        if(x==50){
                Cadena+="CINCUENTA ";
                x=x-50;
        }
        if(x>40){
                Cadena+="CUARENTA Y ";
                x=x-40;
        }
        if(x==40){
                Cadena+="CUARENTA ";
                x=x-40;
        }
        if(x>30){
                Cadena+="TREINTA Y ";
                x=x-30;
        }
        if(x==30){
                Cadena+="TREINTA ";
                x=x-30;
        }
        if(x>20){
                Cadena+="VEINTI";
                x=x-20;
        }
        if(x==20){
                Cadena+="VEINTE ";
                x=x-20;
        }
        if(x>=19){
                Cadena+="DIECINUEVE ";
                x=x-19;
        }
        if(x>=18){
                Cadena+="DIECIOCHO ";
                x=x-18;
        }
        if(x>=17){
                Cadena+="DIECISIETE ";
                x=x-17;
        }
        if(x>=16){
                Cadena+="DIECISEIS ";
                x=x-16;
        }
        if(x>=15){
                Cadena+="QUINCE ";
                x=x-15;
        }
        if(x>=14){
                Cadena+="CATORCE ";
                x=x-14;
        }
        if(x>=13){
                Cadena+="TRECE ";
                x=x-13;
        }
        if(x>=12){
                Cadena+="DOCE ";
                x=x-12;
        }
        if(x>=11){
                Cadena+="ONCE ";
                x=x-11;
        }
        if(x>=10){
                Cadena+="DIEZ ";
                x=x-10;
        }
        if(x>=9){
                Cadena+="NUEVE ";
                x=x-9;
        }
        if(x>=8){
                Cadena+="OCHO ";
                x=x-8;
        }
        if(x>=7){
                Cadena+="SIETE ";
                x=x-7;
        }
        if(x>=6){
                Cadena+="SEIS ";
                x=x-6;
        }
        if(x>=5){
                Cadena+="CINCO ";
                x=x-5;
        }
        if(x>=4){
                Cadena+="CUATRO ";
                x=x-4;
        }
        if(x>=3){
                Cadena+="TRES ";
                x=x-3;
        }
        if(x>=2){
                Cadena+="DOS ";
                x=x-2;
        }
        if(x>=1){
                Cadena+="UN ";
                x=x-1;
        }
        if(x>=0){
                Cadena+="BOLIVARES ";
        }
        Form3->CADENA=Cadena;
}



void __fastcall TForm1::NuevaActa1Click(TObject *Sender)
{
        ListBox1->Clear();
        ListBox2->Clear();
        Memo1->Text="";
        Image6->Visible=true;
        Image12->Visible=false;
        for (int i=0;i<totalreparar;i++)
                CheckListBox1->Checked[i]=false;
        for (int i=0;i<totalcambiar;i++)
                CheckListBox2->Checked[i]=false;
        Label5->Caption="";
        Label7->Caption="";
        Label9->Caption="";
        Label11->Caption="";
        Label13->Caption="";
        Label15->Caption="";
        Label17->Caption="";
        Label19->Caption="";
        Label21->Caption="";
        Label23->Caption="";
        Label25->Caption="";
        Label27->Caption="";
        Label29->Caption="";
        Label31->Caption="";
        Label33->Caption="";
        Label35->Caption="";
        Label37->Caption="";
        Label39->Caption="";
        Label41->Caption="";
        Label43->Caption="";
        Label45->Caption="";
        Label47->Caption="";
        Label49->Caption="";
        Label51->Caption="";
        Label53->Caption="";
        Label55->Caption="";
        Label57->Caption="";
        Label59->Caption="";
        Label61->Caption="";

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image3Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();

        Form14->rellenar();
        Form14->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image13Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        Image13->Visible=false;
        Image14->Visible=true;
        Panel1->Width=800;
        Panel6->Width=400;
        Panel7->Width=400;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image14Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        Image14->Visible=false;
        Image13->Visible=true;
        Panel1->Width=400;
        Panel6->Width=200;
        Panel7->Width=200;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image15Click(TObject *Sender)
{

        llamalo();
        Form25->codigo();
        if(!Label17->Caption.IsEmpty()){
        Form19->Edit1->Text=Label7->Caption;
        Form19->Edit2->Text=Label5->Caption;
        Form19->Edit3->Text=Label11->Caption;
        Form19->Edit4->Text=Label9->Caption;
        Form19->Edit5->Text=Label13->Caption;
        Form19->Memo1->Text=Label15->Caption;
        Form19->Label8->Caption=Label17->Caption;
        Form19->ShowModal();
        }else{
                MessageDlg("Debe agregar un conductor con su respectivo propietario primero, para luego modificar...",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image16Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        if(!Label39->Caption.IsEmpty()){
        Form4->marca();
        Form4->colores();
        Form4->tipo();
        Form4->seguro();
        Form4->anho();
        Form4->uso();
        Form20->acomodar(Sender);
        Form20->ShowModal();
        }else{
                MessageDlg("Debe estar agregado un vehiculo primero para luego modificar...",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image17Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        if(!Label43->Caption.IsEmpty()){
                Form3->formularXD();
                Form3->direccion();
                Form3->ciudad();
                Form21->DateTimePicker1->Date=Label51->Caption;
                Form21->DateTimePicker2->Date=Label41->Caption;
                Form21->Edit1->Text=Label61->Caption;
                Form21->ajustar();
                Form21->ShowModal();
        }else{
                MessageDlg("Aun no se ha levantado un acta",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image18Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        if(!Label43->Caption.IsEmpty()){
                activado=3;
                MessageDlg("Ahora puede seleccionar y asignar autopartes",mtInformation,TMsgDlgButtons()<<mbOK,0);
                Image12->Visible=false;
                Image19->Visible=true;
        }else{
                MessageDlg("Aun no se ha levantado un acta",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image19Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        String cadena;
        String accidente=Label57->Caption;
        cadena="select * from accidentesautoparte where accidente_id="+accidente;
        Query3->Close();
        Query3->SQL->Clear();
        Query3->SQL->Add(cadena);
        Query3->Active=true;
        Query3->First();
        while(!Query3->Eof){
                cadena="delete from accidentesautoparte where id="+Query3->FieldByName("id")->Value;
                Query4->Close();
                Query4->SQL->Clear();
                Query4->SQL->Add(cadena);
                Query4->ExecSQL();
                Query3->Next();
        }
        if(activado==4){
                accidente=Label57->Caption;
                for (int i=0;i<totalselectreparar;i++)
                {
                        cadena="insert into accidentesautoparte values(null,"+selectreparar[i]+","+accidente+")";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                }
                for (int i=0;i<totalselectcambiar;i++)
                {
                        cadena="insert into accidentesautoparte values(null,"+selectcambiar[i]+","+accidente+")";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->ExecSQL();
                }
                MessageDlg("Modificado con éxito",mtInformation,TMsgDlgButtons()<<mbOK,0);
                Image19->Visible=false;
                Image12->Visible=true;
        }else{
                MessageDlg("Debes seleccionar autopartes de cambio o reparación primero", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image20Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();


                Form26->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image21Click(TObject *Sender)
{
                llamalo();
        Form25->codigo();
        if(!Label43->Caption.IsEmpty()){
                Form23->ShowModal();
        }
        else{
                MessageDlg("Aun no se ha levantado el acta. o no haz modificado el archivo",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Buscarplacavehiculo1Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        Form22->ShowModal();
        Form25->codigo();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Reportedeactasperito1Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        Form4->uso();
        Form4->tipo();
        Form24->ShowModal();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{         Image10Click(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Visualizar1Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();
        Form28->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Modificar1Click(TObject *Sender)
{
        llamalo();
        Form25->codigo();

        Form15->rellenar();
        Form15->ShowModal();
}
//---------------------------------------------------------------------------

