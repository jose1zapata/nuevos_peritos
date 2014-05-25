//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit16.h"
#include "Unit18.h"
#include "Unit1.h"
#include "Unit21.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
String DIA[100],MESES[100],HORA[100],MINUTOS[100],AMPM[100]={"AM","PM"};

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
        AMPM[0]="AM";
        AMPM[1]="PM";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ciudad(){
        String cadena;
        bool band=false;
        cadena="select * from ciudadinspeccion";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        Query1->First();
        ComboBox9->Clear();
        ComboBox9->Text="Seleccione";
        Form21->ComboBox9->Clear();
        Form21->ComboBox9->Text="Seleccione";
        CIUDAD=0;
        while(!Query1->Eof){
                band=true;
                cadena=Query1->FieldByName("nombre")->Value;
                Ciudad[CIUDAD]=cadena;
                Form21->ComboBox9->Items->Add(cadena);
                ComboBox9->Items->Add(cadena);
                CIUDAD++;
                Query1->Next();
        }
        if(band==false){
                ComboBox9->Text="No Hay Registros";
                Form21->ComboBox9->Text="No Hay Registros";
        }
}
void __fastcall TForm3::direccion(){
        String cadena;
        bool band=false;
        cadena="select * from direccionrevision";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        Query1->First();
        ComboBox8->Clear();
        ComboBox8->Text="Seleccione";
        Form21->ComboBox8->Clear();
        Form21->ComboBox8->Text="Seleccione";
        DIRECCION=0;
        while(!Query1->Eof){
                band=true;
                cadena=Query1->FieldByName("lugar")->Value;
                Direccion[DIRECCION]=cadena;
                ComboBox8->Items->Add(cadena);
                Form21->ComboBox8->Items->Add(cadena);
                DIRECCION++;
                Query1->Next();
        }
        if(band==false){
                ComboBox8->Text="No Hay Registro";
                Form21->ComboBox8->Text="No Hay Registro";
        }
}
void __fastcall TForm3::formularXD(){
        int aux;


        Edit2->Clear();
        Memo1->Clear();
//        Memo2->Clear();
        Edit3->Clear();
        Edit4->Clear();
//        Memo2->Clear();
        Edit2->Text="1";
        Form21->Edit3->Clear();
        Form21->Edit4->Clear();
        Form21->ComboBox5->Clear();
        Form21->ComboBox4->Clear();
        Form21->ComboBox3->Clear();
        ComboBox3->Clear();
        ComboBox4->Clear();
        ComboBox5->Clear();


        ComboBox3->Text="Hora";


        ComboBox4->Text="Min";
        ComboBox5->Text="AM/PM";
        Form21->ComboBox3->Text="Hora";


        Form21->ComboBox4->Text="Min";
        Form21->ComboBox5->Text="AM/PM";

        ComboBox5->Items->Add(AMPM[0]);
        ComboBox5->Items->Add(AMPM[1]);
        Form21->ComboBox5->Items->Add(AMPM[0]);
        Form21->ComboBox5->Items->Add(AMPM[1]);

        for (int i=0;i<12;i++){
                MESES[i]=NULL;
                HORA[i]=NULL;
        }
        for (int i=0;i<12;i++)//HORAS,MESES
        {
                if(i<9){
                        MESES[i]="0";
                        HORA[i]="0";
                        aux=i+1;
                        MESES[i]+=aux;
                        HORA[i]+=aux;

                        ComboBox3->Items->Add(HORA[i]);
                        Form21->ComboBox3->Items->Add(HORA[i]);

                }else{
                        aux=i+1;
                        MESES[i]=aux;
                        HORA[i]=aux;

                        ComboBox3->Items->Add(HORA[i]);
                        Form21->ComboBox3->Items->Add(HORA[i]);
                }
        }
        for (int i=0;i<31;i++){
                DIA[i]=NULL;
        }//dias
        for (int i=0;i<31;i++)//dias
        {
                if(i<9){
                        DIA[i]="0";
                        aux=i+1;
                        DIA[i]+=aux;
                }else{
                        aux=i+1;
                        DIA[i]=aux;
                }
        }
        for (int i=0;i<60;i++){
                MINUTOS[i]=NULL;
        }
        for (int i=0;i<60;i++)//MINUTOS
        {
                if(i<=9){
                        MINUTOS[i]="0";
                        aux=i;
                        MINUTOS[i]+=aux;
                        ComboBox4->Items->Add(MINUTOS[i]);
                        Form21->ComboBox4->Items->Add(MINUTOS[i]);
                }else{
                        aux=i;
                        MINUTOS[i]=aux;
                        ComboBox4->Items->Add(MINUTOS[i]);
                        Form21->ComboBox4->Items->Add(MINUTOS[i]);
                }
        }

}

void __fastcall TForm3::Image3Click(TObject *Sender)
{
        Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::super(String sms){

        MessageDlg(sms, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
void __fastcall TForm3::Image2Click(TObject *Sender)
{
        String dia,mes,anho;
        char cadenota[1000],*p;

                                if(ComboBox3->ItemIndex!=-1){
                                        if(ComboBox4->ItemIndex!=-1){
                                                if(ComboBox5->ItemIndex!=-1){
                                                        if(!Edit2->Text.IsEmpty()){
                                                                if(!Memo1->Text.IsEmpty()){
                                                                        if(!Edit3->Text.IsEmpty()){

                                                                                                        if(ComboBox8->ItemIndex!=-1){
                                                                                                           if(ComboBox9->ItemIndex!=-1){
                                                                                                                Form1->activado=3;

                                                                                                                Form1->returntonumber(Edit2->Text);
                                                                                                                String fechaaccidente,horaaccidente,fechaavaluo,cadena,totale,VE,veremos;
                                                                                                                int total,pp=0;
                                                                                                                veremos=FormatFloat("##,###,###",Edit2->Text.ToDouble());
                                                                                                                Edit2->Text=veremos;
                                                                                                                fechaaccidente=DateTimePicker1->Date;
                                                                                                                StrCopy(cadenota,fechaaccidente.c_str());
                                                                                                                p=strtok(cadenota,"-/ ");
                                                                                                                while(p!=NULL){
                                                                                                                        if(pp==0)
                                                                                                                                dia=p;
                                                                                                                        if(pp==1)
                                                                                                                                mes=p;
                                                                                                                        if(pp==2)
                                                                                                                                anho=p;
                                                                                                                        pp++;
                                                                                                                        p=strtok(NULL,"-/ ");
                                                                                                                }

                                                                                                                fechaaccidente=anho+"-"+mes+"-"+dia;

                                                                                                                pp=0;
                                                                                                                horaaccidente=HORA[ComboBox3->ItemIndex]+":"+MINUTOS[ComboBox4->ItemIndex]+" "+AMPM[ComboBox5->ItemIndex];
                                                                                                                //----------------------------------insertar accidente----------------------
                                                                                                                cadena="select count(*) as total from accidente";
                                                                                                                Query1->Close();
                                                                                                                Query1->SQL->Clear();
                                                                                                                Query1->SQL->Add(cadena);
                                                                                                                Query1->Active=true;
                                                                                                                total=Query1->FieldByName("total")->Value;
                                                                                                                total++;
                                                                                                                totale=total;
                                                                                                                cadena="INSERT INTO accidente VALUES("+totale+",'"+Memo1->Text+"','"+fechaaccidente+"','"+horaaccidente+"',"+veremos+","+Form1->Label39->Caption+","+idperito+",'"+CADENA+"')";
                                                                                                                Query1->Close();
                                                                                                                Query1->SQL->Clear();
                                                                                                                Query1->SQL->Add(cadena);
                                                                                                                Query1->ExecSQL();
                                                                                                                //---------------------------------------------------------------------------
                                                                                                                //fechaavaluo=Edit5->Text+"-"+MESES[ComboBox7->ItemIndex]+"-"+DIA[ComboBox6->ItemIndex];
                                                                                                                fechaavaluo=DateTimePicker2->Date;
                                                                                                                StrCopy(cadenota,fechaavaluo.c_str());
                                                                                                                p=strtok(cadenota,"-/ ");
                                                                                                                while(p!=NULL){
                                                                                                                        if(pp==0)
                                                                                                                                dia=p;
                                                                                                                        if(pp==1)
                                                                                                                                mes=p;
                                                                                                                        if(pp==2)
                                                                                                                                anho=p;
                                                                                                                        pp++;
                                                                                                                        p=strtok(NULL,"-/ ");
                                                                                                                }
                                                                                                                fechaavaluo=anho+"-"+mes+"-"+dia;
                                                                                                                ShowMessage(fechaavaluo+"datapiker2");
                                                                                                                VE="INSERT INTO avaluo VALUES('"+numerito+"','"+Edit4->Text+"',"+(ComboBox8->ItemIndex+1)+",'"+fechaavaluo+"',"+totale+","+(ComboBox9->ItemIndex+1)+",'"+Edit6->Text+"')";
                                                                                                                Query1->Close();
                                                                                                                Query1->SQL->Clear();
                                                                                                                Query1->SQL->Add(VE);
                                                                                                                Query1->ExecSQL();
                                                                                                                String x=ComboBox8->ItemIndex+1;
                                                                                                                VE="select * from direccionrevision where id="+(x);
                                                                                                                Query1->Close();
                                                                                                                Query1->SQL->Clear();
                                                                                                                Query1->SQL->Add(VE);
                                                                                                                Query1->Active=true;
                                                                                                                super("Acta levantada con éxito.");
                                                                                                                Form1->Label41->Caption=fechaavaluo;
                                                                                                                Form1->Label43->Caption=Edit3->Text;
                                                                                                                Form1->Label45->Caption=Edit4->Text;
                                                                                                                Form1->Label53->Caption=horaaccidente;
                                                                                                                Form1->Label55->Caption=Edit2->Text+" Bs. ("+CADENA+")";
                                                                                                                Form1->Label51->Caption=fechaaccidente;
                                                                                                                Form1->Label49->Caption=Memo1->Text;
                                                                                                                Form1->Label47->Caption=Query1->FieldByName("lugar")->Value;
                                                                                                                Form1->Label57->Caption=totale;
                                                                                                                Form1->Label61->Caption=Edit6->Text;
                                                                                                                Form3->Close();


                                                                                                                Edit2->Clear();
                                                                                                                Memo1->Clear();
                                                                                                                //Memo2->Clear();
                                                                                                                Edit3->Clear();
                                                                                                                Edit4->Clear();


                                                                                                                ComboBox3->Clear();
                                                                                                                ComboBox4->Clear();
                                                                                                                ComboBox5->Clear();


                                                                                                           }else{
                                                                                                                super("Ingrese Ciudad de revision del bien");
                                                                                                           }
                                                                                                        }else{
                                                                                                                super("Ingrese Dirección de revision del bien");
                                                                                                        }
                                                                                                
                                                                        }else{
                                                                                super("Ingrese o haga Clic para generar el Numero de Experticia");
                                                                        }
                                                                }else{
                                                                        super("Ingrese Dirección donde fue el accidente");
                                                                }
                                                        }else{
                                                            super("Ingrese Valor aproximado en Daños");
                                                        }
                                                }else{
                                                        super("Seleccione si es AM o PM");
                                                }
                                        }else{
                                                super("Selecione minutos del accidente");
                                        }
                                }else{
                                        super("Seleccione Hora del accidente");
                                }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit2KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8){
                Key=NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit3Click(TObject *Sender)
{
        String cadena,inicialesperito,aux,totale;
        int cantidad;
        //--------------select peritos---------------------------
        cadena="select * from perito";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        idperito=Query1->FieldByName("id")->Value;
        aux=Query1->FieldByName("nombre")->Value;
        inicialesperito=aux.c_str()[0];
        aux=Query1->FieldByName("apellido")->Value;
        inicialesperito+=aux.c_str()[0];
        //------------------revisando cuantas actas hasta ahora estan registradas
        cadena="select count(*) as total from avaluo";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        cantidad=Query1->FieldByName("total")->Value;
        //----------------------------------------------------
        cantidad++;
        if(cantidad<100){
                if(cantidad<10){
                        totale="00";
                        totale+=cantidad;
                }else{
                        totale="0";
                        totale+=cantidad;
                }
        }else{
                totale=cantidad;
        }
        numerito=totale+"/"+inicialesperito;
        Edit3->Text=numerito;

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit3Enter(TObject *Sender)
{
        Edit3Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Memo1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Memo2KeyPress(TObject *Sender, char &Key)
{
        Memo1KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit3KeyPress(TObject *Sender, char &Key)
{
        Memo2KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8){
                Key=NULL;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit5KeyPress(TObject *Sender, char &Key)
{
        Edit2KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image5Click(TObject *Sender)
{
        Form16->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image6Click(TObject *Sender)
{
        Form18->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit6KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);        
}
//---------------------------------------------------------------------------

