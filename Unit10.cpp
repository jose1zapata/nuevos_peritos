//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
#include "Unit25.h"
#include "ctype.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
String estados[100]={"AMAZONAS.",
"ANZOÁTEGUI.",
"APURE.",
"ARAGUA.",
"BARINAS.",
"BOLÍVAR.",
"CARABOBO.",
"COJEDES.",
"DELTA AMACURO.",
"DISTRITO FEDERAL.",
"FALCÓN.",
"GUÁRICO.",
"LARA.",
"MÉRIDA.",
"MIRANDA.",
"MONAGAS.",
"NUEVA ESPARTA.",
"PORTUGUESA.",
"SUCRE.",
"TÁCHIRA.",
"VARGAS.",
"YARACUY.",
"ZULIA.",
};
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
        : TForm(Owner)
{
        ComboBox1->Clear();
        ComboBox1->Text="Estado...";
        for (int i=0;i<23;i++)
        {
                ComboBox1->Items->Add(estados[i]);
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm10::Image4Click(TObject *Sender)
{
        exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Edit1KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)){
                Key=toupper(Key);
        }
        else{
                Key=NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit2KeyPress(TObject *Sender, char &Key)
{
        Edit1KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit3KeyPress(TObject *Sender, char &Key)
{
        Edit2KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit4KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8){
            Key=NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit5KeyPress(TObject *Sender, char &Key)
{
        Edit4KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Image2Click(TObject *Sender)
{
        String cadena,aux,encabezado,primeraparte,x,T;
        char palabrota[30000],*p;
        if(!Edit1->Text.IsEmpty()){
                if(!Edit2->Text.IsEmpty()){
                        if(!Edit4->Text.IsEmpty()){
                                if(!Edit5->Text.IsEmpty()){
                                   if(!Edit6->Text.IsEmpty()){
                                        if(ComboBox1->ItemIndex!=-1){
                                                String nombre,cedula,codigo,titulo,sitio;
                                                String cabecera, segundaparte,terceraparte,cuartaparte,quintaparte,sd,ps;
                                                int i=0;
                                                ps="V-"           ;
                                                sd=FormatFloat("##,###,###",Edit4->Text.ToDouble());
                                                Edit4->Text=ps+sd;
                                                aux=Edit5->Text+" ESTADO "+estados[ComboBox1->ItemIndex];
                                                cadena="INSERT INTO perito VALUES(1,'"+Edit1->Text+"','"+Edit2->Text+"','"+Edit3->Text+"','"+Edit4->Text+"','"+aux+"','"+Edit6->Text+"')";
                                                Query1->Close();
                                                Query1->SQL->Clear();
                                                Query1->SQL->Add(cadena);
                                                Query1->ExecSQL();

                                                Form10->Close();
                                                encabezado="REPÚBLICA BOLIVARIANA DE VENEZUELA\nINSTITUTO NACIONAL DE TRANSPORTE TERRESTRE\nGERENCIA DE SERVICIOS CONEXOS\nASOCIACIÓN DE PERITOS AVALUADORES DE TRÁNSITO DE VENEZUELA\nUNIDAD "+aux;
                                                primeraparte="QUIEN SUSCRIBE ++++, TITULAR DE LA CÉDULA DE IDENTIDAD Nº ++++, MIEMBRO ACTIVO DE LA ASOCIACIÓN DE PERITOS  AVALUADORES  DE TRÁNSITO DE VENEZUELA CON EL CÓDIGO Nº ++++ EN  MI CARÁCTER DE  EXPERTO DESIGNADO POR LA GERENCIA DE SERVICIOS CONEXOS DEL INSTITUTO NACIONAL DEL TRANSPORTE TERRESTRE  Y ESTANDO LEGALMENTE JURAMENTADO  COMO PERITO AVALUADOR, DE CONFORMIDAD CON EL ARTÍCULO 200, ORDINAL 3 DE LA LEY DE TRANSPORTE TERRESTRE; SE EFECTÚA EL PRESENTE AVALUÓ, SIGUIENDO INSTRUCCIONES DE LA OFICINA PROCESADORA DE ACCIDENTES, SEGÚN ORDEN/OFICIO Nº\n\n++++\n\nA.- VALOR   DE  MERCADO  PARA   EL  BIEN  INVOLUCRADO   EN  EL  SINIESTRO  (VEHÍCULO,  PARTES  Y  PIEZAS  O  CISTERNAS  QUE  LO INTEGRAN  Y  OTROS  BIENES  SUSCEPTIBLES DE SUFRIR  DAÑOS EN EL ACCIDENTE) B.- MÉTODO DE DEPRECIACIÓN APLICADA (LÍNEA";
                                                x="RECTA) C.- EL CÁLCULO DE  LA  MANO  DE  OBRA  ESTÁ  BASADA  EN  LA  METODOLOGÍA  UTILIZADA  POR  LA  CÁMARA  NACIONAL  DE TALLERES  MECÁNICOS  (HORAS  HOMBRES,  MANO DE  OBRA  ESPECIALIZADA  Y/O   SIN   ESPECIALIZACIÓN,   TIEMPO  ESTIMADO  DE REPARACIÓN  POR  PIEZA  O  UNIDAD  VEHICULAR).";
                                                primeraparte+=x;
                                                StrCopy(palabrota,primeraparte.c_str());
                                                p=strtok(palabrota,"++++");
                                                nombre=Edit1->Text+" "+Edit2->Text;
                                                primeraparte=p;
                                                while(p!=NULL){
                                                        if(i==1){//cedula
                                                                segundaparte=p;
                                                                cedula=Edit4->Text;
                                                        }
                                                        if(i==2){
                                                                terceraparte=p;
                                                                codigo=Edit6->Text;
                                                        }
                                                        if(i==3){
                                                                cuartaparte=p;
                                                                titulo="METODOLOGIA APLICADA";

                                                        }
                                                        if(i==4){
                                                               quintaparte=p;
                                                        }
                                                        p=strtok(NULL,"++++");
                                                        i++;
                                                }
                                                cadena="insert into encabezado values(1,'"+encabezado+"','"+primeraparte+"','"+nombre+"','"+segundaparte+"','"+cedula+"','"+terceraparte+"','"+codigo+"','"+cuartaparte+"','"+titulo+"','"+quintaparte+"','SAN CRISTÓBAL')";
                                                Query1->Close();
                                                Query1->SQL->Clear();
                                                Query1->SQL->Add(cadena);
                                                Query1->ExecSQL();
                                                Form25->ShowModal();

                                        }else{
                                                MessageDlg("Seleccione el estado de la unidad",mtInformation,TMsgDlgButtons()<<mbOK,0);
                                        }
                                   }else{
                                        MessageDlg("Ingrese codigo del perito",mtInformation,TMsgDlgButtons()<<mbOK,0);
                                   }
                                }else{
                                        MessageDlg("Ingrese unidad",mtInformation,TMsgDlgButtons()<<mbOK,0);
                                }
                        }else{
                                MessageDlg("Ingrese la cedula",mtInformation,TMsgDlgButtons()<<mbOK,0);
                        }
                }else{
                        MessageDlg("Ingrese el apellido",mtInformation,TMsgDlgButtons()<<mbOK,0);
                }
        }else{
                MessageDlg("Ingrese el nombre",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Image3Click(TObject *Sender)
{
        MessageDlg("Todos los campos se llenan obligatoriamente, menos, el campo profesión que es opcional",mtInformation,TMsgDlgButtons()<<mbOK,0);        
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Edit6KeyPress(TObject *Sender, char &Key)
{
        Edit4KeyPress(Sender,Key);        
}
//---------------------------------------------------------------------------

void __fastcall TForm10::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Form25->ban==0)
        exit(0);
}
//---------------------------------------------------------------------------

