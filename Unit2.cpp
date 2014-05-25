//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int banss=0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        formular();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::formular(){
        codigo[0]="0414";
        codigo[1]="0424";
        codigo[2]="0416";
        codigo[3]="0426";
        codigo[4]="0276";
        for (int i=0;i<=codigo->Length();i++)
        {
                ComboBox1->Items->Add(codigo[i]);
        }
}


void __fastcall TForm2::Edit2KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)){
                Key=toupper(Key);
        }else{
                Key=NULL;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit4KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)){
                Key=toupper(Key);
        }else{
                Key=NULL;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Memo1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image3Click(TObject *Sender)
{
        Form2->Close();
        Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        Edit4->Clear();
        Edit5->Clear();
        Memo1->Clear();
        Image2->Visible=true;
        Image5->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8)
                Key=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit3KeyPress(TObject *Sender, char &Key)
{
        String cadena;
        int total=0;
        if(!isdigit(Key)&&Key!=8)
                Key=NULL;
        else{
                if(Key==8){
                        Edit3->Text="";
                        Edit4->Text="";
                        Edit5->Text="";
                        Memo1->Text="";
                        Image2->Visible=true;
                        Image5->Visible=false;
                        total=Edit1->Text.Length();
                        if(total==10){
                                cadena=Edit1->Text.c_str()[0];
                                cadena+=Edit1->Text.c_str()[1];
                                cadena+=Edit1->Text.c_str()[3];
                                cadena+=Edit1->Text.c_str()[4];
                                cadena+=Edit1->Text.c_str()[5];
                                cadena+=Edit1->Text.c_str()[7];
                                cadena+=Edit1->Text.c_str()[8];
                                cadena+=Edit1->Text.c_str()[9];
                                Edit1->Text=cadena;
                        }else{
                                cadena=Edit1->Text.c_str()[0];
                                cadena+=Edit1->Text.c_str()[2];
                                cadena+=Edit1->Text.c_str()[3];
                                cadena+=Edit1->Text.c_str()[4];
                                cadena+=Edit1->Text.c_str()[6];
                                cadena+=Edit1->Text.c_str()[7];
                                cadena+=Edit1->Text.c_str()[8];
                                Edit1->Text=cadena;
                        }

                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit5KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8)
                Key=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image4Click(TObject *Sender)
{
        MessageDlg("Ejemplo Cedula Conductor: 17877864 (solo numeros)\n\n"
                   "Ejemplo Nombre Conductor: Luis Perez (solo letras)\n\n"
                   "Ejemplo Cedula Propietario: 17827822 (solo numero)\n\n"
                   "Ejemplo Nombre Conductor: Carlos Perez (solo letras)\n\n"
                   "Ejemplo Telefono Propietario: 04141234567 (Solo numeros)\n\n"
                   "Ejemplo Direcci�n: Urb Merida 100-24 (Texto y numeros)\n\n"
                   "Los datos se ingresan as� y autom�ticamente adquieren formato una vez guardado", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image2Click(TObject *Sender)
{
        String cadena, total;
        int totals=0;
        if(!Edit1->Text.IsEmpty()){
                if(!Edit2->Text.IsEmpty()){
                        if(!Edit3->Text.IsEmpty()){
                                if(!Edit4->Text.IsEmpty()){
                                        if(ComboBox1->ItemIndex!=-1){
                                                if(!Edit5->Text.IsEmpty()){
                                                        if(!Memo1->Text.IsEmpty()){
                                                                        Form1->activado=1;
                                                                        Form4->Edit1->Text=Edit6->Text;
                                                                        Edit1->Text=FormatFloat("##,###,###",Edit1->Text.ToDouble());
                                                                        Edit3->Text=FormatFloat("##,###,###",Edit3->Text.ToDouble());
                                                                        Edit5->Text=codigo[ComboBox1->ItemIndex]+"-"+Edit5->Text;
                                                                        cadena="select count(*) as total from conductores";
                                                                        Query1->Close();
                                                                        Query1->SQL->Clear();
                                                                        Query1->SQL->Add(cadena);
                                                                        Query1->Active=true;
                                                                        totals=Query1->FieldByName("total")->Value;
                                                                        totals++;
                                                                        total=totals;
                                                                        cadena="insert into conductores values("+total+",'"+Edit2->Text+"','"+Edit1->Text+"','"+Edit4->Text+"','"+Edit3->Text+"','"+Memo1->Text+"','"+Edit5->Text+"')";
                                                                        Query1->Close();
                                                                        Query1->SQL->Clear();
                                                                        Query1->SQL->Add(cadena);
                                                                        Query1->ExecSQL();
                                                                        MessageDlg("Datos Guardados Con �xito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                        Form1->Label5->Caption=Edit2->Text;//nombre conductor
                                                                        Form1->Label7->Caption=Edit1->Text;//cedula conductor
                                                                        Form1->Label9->Caption=Edit4->Text;//nombre propietario
                                                                        Form1->Label11->Caption=Edit3->Text;//cedula propietario
                                                                        Form1->Label13->Caption=Edit5->Text;//telefono
                                                                        Form1->Label15->Caption=Memo1->Text;//direcci�n
                                                                        Form1->Label17->Caption=total;//id
                                                                        Edit1->Clear();
                                                                        Edit2->Clear();
                                                                        Edit3->Clear();
                                                                        Edit4->Clear();
                                                                        Edit5->Clear();
                                                                        Memo1->Clear();
                                                                        Form2->Close();
                                                        }else{
                                                                MessageDlg("Falta la Direcci�n del Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                        }
                                                }else{
                                                        MessageDlg("Ingrese Numero de telefono del propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                }
                                        }else{
                                                MessageDlg("Seleccione Codigo telefono Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                        }
                                }else{
                                        MessageDlg("Ingrese Nombre del Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                }
                        }else{
                                MessageDlg("Ingrese cedula del Propietario", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        }
                }else{
                        MessageDlg("Ingrese el nombre del conductor", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("Ingrese la cedula del conductor", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit2Enter(TObject *Sender)
{
        String cadena="",cadena2="",x;
        int total=0;
        if(!Edit1->Text.IsEmpty()&&ban==0){
                cadena2=FormatFloat("##,###,###",Edit1->Text.ToDouble());
                cadena="SELECT count(*) as total FROM conductores where cedulaconductor='"+cadena2+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total>0){
                        cadena="SELECT * FROM conductores where cedulaconductor='"+cadena2+"'";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->Active=true;
                        Image2->Visible=false;
                        Image5->Visible=true;
                        Query1->First();

                        Edit1->Text=Query1->FieldByName("cedulaconductor")->Value;
                        Edit2->Text=Query1->FieldByName("nombreconductor")->Value;
                        Edit3->Text=Query1->FieldByName("cedulapropietario")->Value;
                        Edit4->Text=Query1->FieldByName("nombrepropietario")->Value;
                        Edit5->Text=Query1->FieldByName("telefono")->Value;
                        cadena=Edit5->Text.c_str()[0];
                        cadena+=Edit5->Text.c_str()[1];
                        cadena+=Edit5->Text.c_str()[2];
                        cadena+=Edit5->Text.c_str()[3];
                        x=Edit5->Text.c_str()[5];
                        x+=Edit5->Text.c_str()[6];
                        x+=Edit5->Text.c_str()[7];
                        x+=Edit5->Text.c_str()[8];
                        x+=Edit5->Text.c_str()[9];
                        x+=Edit5->Text.c_str()[10];
                        x+=Edit5->Text.c_str()[11];

                        for(int i=0;i<codigo->Length();i++){
                                if(cadena==codigo[i]){
                                        ComboBox1->ItemIndex=i;
                                        Edit5->Text=x;
                                        break;
                                }
                        }
                        Memo1->Lines->Add(Query1->FieldByName("direccionpropietario")->Value);
                        ban=1;
                }

        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit2Click(TObject *Sender)
{
        Edit2Enter(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image5Click(TObject *Sender)
{
        String cadena;
        cadena="SELECT * FROM conductores WHERE cedulaconductor='"+Edit1->Text+"'";
        if(banss==1)
        Form1->activado=2;
        else
        Form1->activado=1;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        Image2->Visible=true;
        Image5->Visible=false;
        Form4->Edit1->Text=Edit6->Text;
        Form1->Label5->Caption=Edit2->Text;//nombre conductor
        Form1->Label7->Caption=Edit1->Text;//cedula conductor
        Form1->Label9->Caption=Edit4->Text;//nombre propietario
        Form1->Label11->Caption=Edit3->Text;//cedula propietario

        Form1->Label13->Caption=codigo[ComboBox1->ItemIndex]+"-"+Edit5->Text;//telefono
        Form1->Label15->Caption=Memo1->Text;//direcci�n
        Form1->Label17->Caption=Query1->FieldByName("id")->Value;//id
        Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        Edit4->Clear();
        Edit5->Clear();
        Memo1->Clear();
        Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit4Enter(TObject *Sender)
{
        String cadena="",cadena2="",cadena22="";
        String x;
        int total=0;
        cadena22=Edit3->Text;
        if(!Edit3->Text.IsEmpty()&&ban1==0){
                cadena2=FormatFloat("##,###,###",Edit3->Text.ToDouble());
                cadena="SELECT count(*) as total FROM conductores where cedulapropietario='"+cadena2+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total>0){
                        cadena="SELECT * FROM conductores where cedulapropietario='"+cadena2+"'";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(cadena);
                        Query1->Active=true;
                        if(ban==1){
                                Image2->Visible=false;
                                Image5->Visible=true;
                        }
                        Query1->First();
                        Edit4->Text=Query1->FieldByName("nombrepropietario")->Value;
                        Edit5->Text=Query1->FieldByName("telefono")->Value;
                        cadena=Edit5->Text.c_str()[0];
                        cadena+=Edit5->Text.c_str()[1];
                        cadena+=Edit5->Text.c_str()[2];
                        cadena+=Edit5->Text.c_str()[3];
                        x=Edit5->Text.c_str()[5];
                        x+=Edit5->Text.c_str()[6];
                        x+=Edit5->Text.c_str()[7];
                        x+=Edit5->Text.c_str()[8];
                        x+=Edit5->Text.c_str()[9];
                        x+=Edit5->Text.c_str()[10];
                        x+=Edit5->Text.c_str()[11];
                        for(int i=0;i<codigo->Length();i++){
                                if(cadena==codigo[i]){
                                        ComboBox1->ItemIndex=i;
                                        Edit5->Text=x;
                                        break;
                                }
                        }
                        Memo1->Lines->Add(Query1->FieldByName("direccionpropietario")->Value);
                        ban1=1;
                }
        }

        if(cadena22==Edit1->Text){
                Edit4->Text=Edit2->Text;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit6KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
        String cadena,x;
        if(Key==13){
                Form4->Edit1->Text=Edit6->Text;
                cadena="select count(*) as total from vehiculo where placa='"+Edit6->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                if(Query1->FieldByName("total")->Value!=0){
                banss=1;
                cadena="select * from vehiculo where placa='"+Edit6->Text+"'";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                var.id=Query1->FieldByName("id")->Value;
                var.serialcarroceria=Query1->FieldByName("serialcarroceria")->Value;
                var.serialmotor=Query1->FieldByName("serialmotor")->Value;
                var.numeropoliza=Query1->FieldByName("numeropoliza")->Value;
                var.placa=Query1->FieldByName("placa")->Value;
                var.anho=Query1->FieldByName("anho")->Value;
                var.marca_id=Query1->FieldByName("marca_id")->Value;
                var.modelo_id=Query1->FieldByName("modelo_id")->Value;
                var.tipo_id=Query1->FieldByName("tipo_id")->Value;
                var.color_id=Query1->FieldByName("color_id")->Value;
                var.seguro_id=Query1->FieldByName("seguro_id")->Value;
                var.uso=Query1->FieldByName("uso_id")->Value;
                var.condutores_id=Query1->FieldByName("conductores_id")->Value;
                cadena="select * from marca where id="+var.marca_id;
	        Query1->Close();
	        Query1->SQL->Clear();
	        Query1->SQL->Add(cadena);
	        Query1->Active=true;
	        var2.nombre=Query1->FieldByName("nombre")->Value;
         //----------------------------------------------------
                cadena="select * from uso where id="+var.uso;
	        Query1->Close();
	        Query1->SQL->Clear();
	        Query1->SQL->Add(cadena);
	        Query1->Active=true;
	        var.uso=Query1->FieldByName("nombre")->Value;
	//-----------------------------------------------------
	        cadena="select * from modelo where id="+var.modelo_id;
	        Query1->Close();
	        Query1->SQL->Clear();
	        Query1->SQL->Add(cadena);
	        Query1->Active=true;
	        var3.nombre=Query1->FieldByName("nombre")->Value;
	//-----------------------------------------------------
        	cadena="select * from tipo where id="+var.tipo_id;
	        Query1->Close();
        	Query1->SQL->Clear();
	        Query1->SQL->Add(cadena);
        	Query1->Active=true;
	        var4.nombre=Query1->FieldByName("nombre")->Value;
	//-----------------------------------------------------
        	cadena="select * from color where id="+var.color_id;
	        Query1->Close();
        	Query1->SQL->Clear();
	        Query1->SQL->Add(cadena);
        	Query1->Active=true;
	        var5.nombre=Query1->FieldByName("nombre")->Value;
	//-----------------------------------------------------
        	cadena="select * from seguro where id="+var.seguro_id;
	        Query1->Close();
        	Query1->SQL->Clear();
	        Query1->SQL->Add(cadena);
        	Query1->Active=true;
	        var6.nombre=Query1->FieldByName("nombre")->Value;
	//-----------------------------------------------------
        	Form1->Label19->Caption=var2.nombre;
	        Form1->Label21->Caption=var3.nombre;
        	Form1->Label23->Caption=var4.nombre;
	        Form1->Label25->Caption=var.anho;
        	Form1->Label27->Caption=var5.nombre;
	        Form1->Label29->Caption=var.placa;
        	Form1->Label31->Caption=var.serialcarroceria;
	        Form1->Label33->Caption=var.serialmotor;
        	Form1->Label35->Caption=var6.nombre;
	        Form1->Label37->Caption=var.numeropoliza;
        	Form1->Label39->Caption=var.id;

	        Form1->activado=2;
                cadena="select * from conductores where id="+var.condutores_id+"";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(cadena);
                Query1->Active=true;
                x=Query1->FieldByName("cedulaconductor")->Value;
                Edit1->Text=x;
                int total=0;
                total=Edit1->Text.Length();
                Form1->Label59->Caption=var.uso;
                        if(total==10){
                                cadena=Edit1->Text.c_str()[0];
                                cadena+=Edit1->Text.c_str()[1];
                                cadena+=Edit1->Text.c_str()[3];
                                cadena+=Edit1->Text.c_str()[4];
                                cadena+=Edit1->Text.c_str()[5];
                                cadena+=Edit1->Text.c_str()[7];
                                cadena+=Edit1->Text.c_str()[8];
                                cadena+=Edit1->Text.c_str()[9];
                                Edit1->Text=cadena;
                        }else{
                                cadena=Edit1->Text.c_str()[0];
                                cadena+=Edit1->Text.c_str()[2];
                                cadena+=Edit1->Text.c_str()[3];
                                cadena+=Edit1->Text.c_str()[4];
                                cadena+=Edit1->Text.c_str()[6];
                                cadena+=Edit1->Text.c_str()[7];
                                cadena+=Edit1->Text.c_str()[8];
                                Edit1->Text=cadena;
                        }
                        Edit2Enter(Sender);
                        Image2->Visible=false;
                        Image5->Visible=true;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image6Click(TObject *Sender)
{
        Edit6KeyPress(Sender,'\r');        
}
//---------------------------------------------------------------------------

