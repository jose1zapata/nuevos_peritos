//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"                                    '
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit17.h"
#include "Unit20.h"
#include "Unit24.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::uso(){
        ComboBox7->Clear();
        ComboBox7->Text="Seleccione";
        Form24->ComboBox1->Clear();
        Form24->ComboBox1->Text="Seleccione";

        Form20->ComboBox6->Clear();
        Form20->ComboBox6->Text="Seleccione";
        String cadena;
        cadena="select * from uso";
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(cadena);
        Query1->Active=true;
        Query1->First();
        USO=0;
        while(!Query1->Eof){
                cadena=Query1->FieldByName("nombre")->Value;
                Uso[USO]=cadena;
                ComboBox7->Items->Add(cadena);
                Form20->ComboBox6->Items->Add(cadena);
                Form24->ComboBox1->Items->Add(cadena);
                USO++;
                Query1->Next();
        }
}
void __fastcall TForm4::marca()
{
        String consulta="select * from marca",marquita;
        int id=0;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox1->Clear();
        ComboBox1->Text="Seleccione";
        Form20->ComboBox1->Clear();
        Form20->ComboBox1->Text="Seleccione";
        MARCA=0;
        Query1->First();
        while(!Query1->Eof){
                marquita=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Marca[MARCA][0]=marquita;
                Marca[MARCA][1]=id;
                ComboBox1->Items->Add(marquita);
                Form20->ComboBox1->Items->Add(marquita);
                MARCA++;
                Query1->Next();
        }
}
void __fastcall TForm4::anho()
{
        String year;
        String aux;
        int resta=1950;
        int total=0;
        int valor;
        year=Date();
        aux=year.c_str()[6];
        aux+=year.c_str()[7];
        aux+=year.c_str()[8];
        aux+=year.c_str()[9];
        total=atoi(aux.c_str())-resta;
        valor=atoi(aux.c_str());
        ComboBox6->Clear();
        ComboBox6->Text="Seleccione";
        Form20->ComboBox5->Clear();
        Form20->ComboBox5->Text="Seleccione";
        for (int i=0;i<=total;i++)
        {
                ComboBox6->Items->Add(valor);
                Form20->ComboBox5->Items->Add(valor);
                Anho[i]=valor;
                valor=valor-1;
                ANHO=i;
        }


}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image3Click(TObject *Sender)
{
        Form4->Close();
        ComboBox1->Clear();
        ComboBox2->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image5Click(TObject *Sender)
{
        Form5->ShowModal();
}
//--------------------------- ------------------------------------------------

void __fastcall TForm4::Image6Click(TObject *Sender)
{
        AnsiString x;
        if(ComboBox1->ItemIndex!=-1){
                Form6->Label2->Caption=""+Marca[ComboBox1->ItemIndex][0]+"";
                x=Marca[ComboBox1->ItemIndex][1];
                Form6->marca_id=x;
                Form6->ShowModal();
        }
        else{
                if(Form20->ComboBox1->ItemIndex!=-1){
                        Form6->Label2->Caption=""+Marca[Form20->ComboBox1->ItemIndex][0]+"";
                        x=Marca[Form20->ComboBox1->ItemIndex][1];
                        Form6->marca_id=x;
                        Form6->ShowModal();
                }else
                        MessageDlg("Seleccione una marca de vehiculo antes de agregar un modelo", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }

}
//---------------------------------------------------------------------------
void __fastcall TForm4::modelo(){
        String consulta,modelito;
        int total=0,id;

        if(ComboBox1->ItemIndex!=-1){
                consulta="select count(*) as total from modelo where marca_id="+Marca[ComboBox1->ItemIndex][1]+"";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(consulta);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total>0){
                        consulta="select * from modelo where marca_id="+Marca[ComboBox1->ItemIndex][1]+"";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(consulta);
                        Query1->Active=true;
                        ComboBox2->Clear();
                        ComboBox2->Text="Seleccione";
                        Form20->ComboBox2->Clear();
                        Form20->ComboBox2->Text="Seleccione";
                        MODELO=0;
                        Query1->First();
                        while(!Query1->Eof){
                                modelito=Query1->FieldByName("nombre")->Value;
                                id=Query1->FieldByName("id")->Value;
                                Modelo[MODELO][0]=modelito;
                                Modelo[MODELO][1]=id;
                                ComboBox2->Items->Add(modelito);
                                Form20->ComboBox2->Items->Add(modelito);
                                MODELO++;
                                Query1->Next();
                        }
                }
                else{
                        ComboBox2->Clear();
                        ComboBox2->Text="No hay Registros para la marca: "+Marca[Form20->ComboBox1->ItemIndex][0];
                }
        }else{
                if(Form20->ComboBox1->ItemIndex!=-1){
                consulta="select count(*) as total from modelo where marca_id="+Marca[Form20->ComboBox1->ItemIndex][1]+"";
                Query1->Close();
                Query1->SQL->Clear();
                Query1->SQL->Add(consulta);
                Query1->Active=true;
                total=Query1->FieldByName("total")->Value;
                if(total>0){
                        consulta="select * from modelo where marca_id="+Marca[Form20->ComboBox1->ItemIndex][1]+"";
                        Query1->Close();
                        Query1->SQL->Clear();
                        Query1->SQL->Add(consulta);
                        Query1->Active=true;
                        ComboBox2->Clear();
                        ComboBox2->Text="Seleccione";
                        Form20->ComboBox2->Clear();
                        Form20->ComboBox2->Text="Seleccione";
                        MODELO=0;
                        Query1->First();
                        while(!Query1->Eof){
                                modelito=Query1->FieldByName("nombre")->Value;
                                id=Query1->FieldByName("id")->Value;
                                Modelo[MODELO][0]=modelito;
                                Modelo[MODELO][1]=id;
                                ComboBox2->Items->Add(modelito);
                                Form20->ComboBox2->Items->Add(modelito);
                                MODELO++;
                                Query1->Next();
                        }
                }else{
                        Form20->ComboBox2->Clear();
                        Form20->ComboBox2->Text="No hay Registros para la marca: "+Marca[Form20->ComboBox1->ItemIndex][0];

                }
                }else{
                        MessageDlg("No teclee para agregar una marca. Si no existe, agregue una marca en la imagen del simbolo (+) que se encuentra justo al lado del titulo 'seleccione marca'", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }

        }
        /*
        if(ComboBox1->ItemIndex!=-1)
                consulta="select count(*) as total from modelo where marca_id="+Marca[ComboBox1->ItemIndex][1]+"";
        else
                if(Form20->ComboBox1->ItemIndex!=-1)
                        consulta="select count(*) as total from modelo where marca_id="+Marca[Form20->ComboBox1->ItemIndex][1]+"";
                else
                        if(ComboBox1->ItemIndex==-1)
                                consulta="select count(*) as total from modelo where marca_id="+Marca[ComboBox1->ItemIndex][1]+"";
                        else
                                if(Form20->ComboBox1->ItemIndex==-1)
                                consulta="select count(*) as total from modelo where marca_id="+Marca[Form20->ComboBox1->ItemIndex][1]+"";

        if(ComboBox1->ItemIndex!=-1||Form20->ComboBox1->ItemIndex!=-1){
        int id=0;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        total=Query1->FieldByName("total")->Value;
        }
        if(total>0){


        if(ComboBox1->ItemIndex!=-1)
        consulta="select * from modelo where marca_id="+Marca[ComboBox1->ItemIndex][1]+"";
        else
        consulta="select * from modelo where marca_id="+Marca[Form20->ComboBox1->ItemIndex][1]+"",modelito;
        int id=0;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox2->Clear();
        ComboBox2->Text="Seleccione";
        Form20->ComboBox2->Clear();
        Form20->ComboBox2->Text="Seleccione";
        MODELO=0;
        Query1->First();
        while(!Query1->Eof){
                modelito=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Modelo[MODELO][0]=modelito;
                Modelo[MODELO][1]=id;
                ComboBox2->Items->Add(modelito);
                Form20->ComboBox2->Items->Add(modelito);
                MODELO++;
                Query1->Next();
        }
        }else{
                if(ComboBox1->ItemIndex==-1&&Form20->ComboBox1->ItemIndex==-1)
                MessageDlg("no teclee para agregar una marca. si no existe agregue una marca en la imagen del simbolo (+) que se encuentra justo al lado del titulo 'seleccione marca'", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
        */
}
void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
        modelo();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::colores()
{
        String consulta="select * from color",Colors;
        int id;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox4->Clear();
        ComboBox4->Text="Seleccione";
        Form20->ComboBox4->Clear();
        Form20->ComboBox4->Text="Seleccione";
        COLOR=0;
        Query1->First();
        while(!Query1->Eof){
                Colors=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Colorete[COLOR][0]=Colors;
                Colorete[COLOR][1]=id;
                ComboBox4->Items->Add(Colors);
                Form20->ComboBox4->Items->Add(Colors);
                COLOR++;
                Query1->Next();
        }
}
//--------------------------------------------------------------
void __fastcall TForm4::Image8Click(TObject *Sender)
{
        Form7->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::tipo(){
        String consulta="select * from tipo",Tipos;
        int id;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox3->Clear();
        ComboBox3->Text="Seleccione";
        Form20->ComboBox3->Clear();
        Form20->ComboBox3->Text="Seleccione";
        Form24->ComboBox2->Clear();
        Form24->ComboBox2->Text="Seleccione";
        TIPO=0;
        Query1->First();
        while(!Query1->Eof){
                Tipos=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Tipo[TIPO][0]=Tipos;
                Tipo[TIPO][1]=id;
                ComboBox3->Items->Add(Tipos);
                Form20->ComboBox3->Items->Add(Tipos);
                Form24->ComboBox2->Items->Add(Tipos);
                TIPO++;
                Query1->Next();
        }
}


void __fastcall TForm4::Image7Click(TObject *Sender)
{
        Form8->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image9Click(TObject *Sender)
{
        Form9->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit1KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit2KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit3KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit4KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8){
                Key=NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit5KeyPress(TObject *Sender, char &Key)
{
        Key=toupper(Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::seguro(){
        String consulta="select * from seguro",seguross;
        int id;
        Query1->Close();
        Query1->SQL->Clear();
        Query1->SQL->Add(consulta);
        Query1->Active=true;
        ComboBox5->Clear();
        ComboBox5->Text="Seleccione";

        Form20->ComboBox7->Clear();
        Form20->ComboBox7->Text="Seleccione";
        Form24->ComboBox2->Clear();
        Form24->ComboBox2->Text="Seleccione";
        SEGURO=0;
        Query1->First();
        while(!Query1->Eof){
                seguross=Query1->FieldByName("nombre")->Value;
                id=Query1->FieldByName("id")->Value;
                Seguro[SEGURO][0]=seguross;
                Seguro[SEGURO][1]=id;
                ComboBox5->Items->Add(seguross);
                Form20->ComboBox7->Items->Add(seguross);
                Form24->ComboBox2->Items->Add(seguross);
                SEGURO++;
                Query1->Next();
        }
}
void __fastcall TForm4::Image2Click(TObject *Sender)
{
        String cadena;
        if(ComboBox1->ItemIndex!=-1){
                if(ComboBox2->ItemIndex!=-1){
                        if(ComboBox3->ItemIndex!=-1){
                                if(ComboBox4->ItemIndex!=-1){
                                        if(!Edit1->Text.IsEmpty()){
                                                if(!Edit2->Text.IsEmpty()){
                                                        if(!Edit3->Text.IsEmpty()){
                                                                if(ComboBox6->ItemIndex!=-1){
                                                                        if(ComboBox5->ItemIndex!=-1){
                                                                                if(!Edit5->Text.IsEmpty()){
                                                                                  if(ComboBox7->ItemIndex!=-1){
                                                                                        String q,w,e,r,t,y,u,i,o,p;
                                                                                        q=Edit2->Text;
                                                                                        w=Edit3->Text;
                                                                                        e=Edit5->Text;
                                                                                        r=Edit1->Text;
                                                                                        t=Anho[ComboBox6->ItemIndex];
                                                                                        Form1->activado=2;
                                                                                        y=Marca[ComboBox1->ItemIndex][1];
                                                                                        u=Modelo[ComboBox2->ItemIndex][1];
                                                                                        i=Tipo[ComboBox3->ItemIndex][1];
                                                                                        o=Colorete[ComboBox4->ItemIndex][1];
                                                                                        p=Seguro[ComboBox5->ItemIndex][1];
                                                                                        cadena="INSERT INTO vehiculo values(null,";
                                                                                        cadena+="'"+Edit2->Text+"',";
                                                                                        cadena+="'"+Edit3->Text+"',";
                                                                                        cadena+="'"+Edit5->Text+"',";
                                                                                        cadena+="'"+Edit1->Text+"',";
                                                                                        cadena+="'"+Anho[ComboBox6->ItemIndex]+"',";
                                                                                        cadena+=""+Marca[ComboBox1->ItemIndex][1]+",";
                                                                                        cadena+=""+Modelo[ComboBox2->ItemIndex][1]+",";
                                                                                        cadena+=""+Tipo[ComboBox3->ItemIndex][1]+",";
                                                                                        cadena+=""+Colorete[ComboBox4->ItemIndex][1]+",";
                                                                                        cadena+=""+Seguro[ComboBox5->ItemIndex][1]+",";
                                                                                        String x=(ComboBox7->ItemIndex+1);
                                                                                        cadena+=""+(x)+",";
                                                                                        cadena+=""+Form1->Label17->Caption+")";

                                                                                        Query1->Close();
                                                                                        Query1->SQL->Clear();
                                                                                        Query1->SQL->Add(cadena);
                                                                                        Query1->ExecSQL();
                                                                                        MessageDlg("Vehiculo insertado con �xito", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                                        cadena="select id from vehiculo where placa='"+Edit1->Text+"'";
                                                                                        Query1->Close();
                                                                                        Query1->SQL->Clear();
                                                                                        Query1->SQL->Add(cadena);
                                                                                        Query1->Active=true;

                                                                                        Form1->Label19->Caption=Marca[ComboBox1->ItemIndex][0];//marca
                                                                                        Form1->Label21->Caption=Modelo[ComboBox2->ItemIndex][0];//modelo
                                                                                        Form1->Label23->Caption=Tipo[ComboBox3->ItemIndex][0];//tipo
                                                                                        Form1->Label25->Caption=Anho[ComboBox6->ItemIndex];;//a�o
                                                                                        Form1->Label27->Caption=Colorete[ComboBox4->ItemIndex][0];//color
                                                                                        Form1->Label29->Caption=Edit1->Text;//Numero de placa
                                                                                        Form1->Label31->Caption=Edit2->Text;//Serial Carroceria
                                                                                        Form1->Label33->Caption=Edit3->Text;//serial Motor
                                                                                        Form1->Label35->Caption=Seguro[ComboBox5->ItemIndex][0];//seguro
                                                                                        Form1->Label37->Caption=Edit5->Text;//numero y poliza
                                                                                        Form1->Label39->Caption=Query1->FieldByName("id")->Value;//idvehiculo
                                                                                        Form1->Label59->Caption=Uso[ComboBox7->ItemIndex];
                                                                                        Form4->Close();
                                                                                        Edit1->Clear();
                                                                                        Edit2->Clear();
                                                                                        Edit3->Clear();
                                                                                        ComboBox6->Clear();
                                                                                        Edit5->Clear();
                                                                                  }
                                                                                  else{
                                                                                        MessageDlg("Ingrese Uso del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                                  }
                                                                                }else{
                                                                                        MessageDlg("Ingrese numero de poliza", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                                }
                                                                        }else{
                                                                                MessageDlg("Seleccione el seguro del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                        }
                                                                }else{
                                                                        MessageDlg("Ingrese a�o del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                                }
                                                        }else{
                                                                MessageDlg("Ingrese serial del motor", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                        }
                                                }else{
                                                        MessageDlg("Ingrese serial de carroceria del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                                }
                                        }else{
                                                MessageDlg("Ingrese Placa del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                        }
                                }
                                else{
                                        MessageDlg("Seleccione el color del tipo del modelo de la marca del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                                }
                        }else{
                                MessageDlg("Seleccione el tipo del modelo de la marca del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                        }
                }else{
                        MessageDlg("Seleccione el modelo de la marca del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
                }
        }else{
                MessageDlg("Seleccione la marca del vehiculo", mtInformation, TMsgDlgButtons() << mbOK, 0);
        }
}
//---------------------------------------------------------------------------





void __fastcall TForm4::Image10Click(TObject *Sender)
{
        Form17->ShowModal();
}
//---------------------------------------------------------------------------

