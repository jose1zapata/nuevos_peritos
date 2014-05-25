//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit26.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm26 *Form26;
//---------------------------------------------------------------------------
__fastcall TForm26::TForm26(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm26::Image2Click(TObject *Sender)
{
                String x[30000],y[30000],s,ss;
                char cadenota[1000],*p;

                s=Edit1->Text;
                ss=Edit2->Text;
                Form1->totalselectreparar=0;
                Form1->totalselectreparar=0;
                Form1->totalselectcambiar=0;
                Form1->ListBox1->Clear();
                Form1->ListBox2->Clear();
                for (int i=0;i<Form1->totalcambiar;i++){
                        Form1->CheckListBox2->Checked[i]=false;
                }
                for (int i=0;i<Form1->totalreparar;i++){
                        Form1->CheckListBox1->Checked[i]=false;
                }
                if(!Edit1->Text.IsEmpty()&&Edit2->Text.IsEmpty()){
                        StrCopy(cadenota,s.c_str());
                        p=strtok(cadenota,",");
                        while(p!=NULL){
                                for (int i=0;i<Form1->totalreparar;i++)
                                {
                                        if(Form1->idreparar[i]==atoi(p))
                                        {
                                                Form1->CheckListBox1->Checked[i]=true;
                                                Form1->selectreparar[Form1->totalselectreparar]=Form1->idreparar[i];
                                                Form1->ListBox1->Items->Add(Form1->reparar[i]);
                                                Form1->totalselectreparar++;
                                        }
                                }
                                p=strtok(NULL,",");
                        }
                        for (int i=0;i<Form1->totalcambiar;i++){
                                Form1->CheckListBox2->Checked[i]=false;
                        }
                }else{
                        if(Edit1->Text.IsEmpty()&&!Edit2->Text.IsEmpty()){
                                for (int i=0;i<Form1->totalreparar;i++){
                                        Form1->CheckListBox1->Checked[i]=false;
                                }
                                StrCopy(cadenota,ss.c_str());
                                        p=strtok(cadenota,",");
                                        while(p!=NULL){
                                                for (int i=0;i<Form1->totalcambiar;i++)
                                                {
                                                        if(Form1->idcambiar[i]==atoi(p))
                                                        {
                                                                Form1->CheckListBox2->Checked[i]=true;
                                                                Form1->selectcambiar[Form1->totalselectcambiar]=Form1->idcambiar[i];
                                                                Form1->ListBox2->Items->Add(Form1->cambiar[i]);
                                                                Form1->totalselectcambiar++;
                                                        }
                                                }
                                                p=strtok(NULL,",");
                                         }
                        }else{
                                if(!Edit1->Text.IsEmpty()&&!Edit2->Text.IsEmpty()){
                                        StrCopy(cadenota,s.c_str());
                                        p=strtok(cadenota,",");
                                        while(p!=NULL){
                                                for (int i=0;i<Form1->totalreparar;i++)
                                                {
                                                        if(Form1->idreparar[i]==atoi(p))
                                                        {
                                                                Form1->CheckListBox1->Checked[i]=true;
                                                                Form1->selectreparar[Form1->totalselectreparar]=Form1->idreparar[i];
                                                                Form1->ListBox1->Items->Add(Form1->reparar[i]);
                                                                Form1->totalselectreparar++;
                                                        }
                                                }
                                                p=strtok(NULL,",");
                                       }
                                        StrCopy(cadenota,ss.c_str());
                                        p=strtok(cadenota,",");
                                        while(p!=NULL){
                                                for (int i=0;i<Form1->totalcambiar;i++)
                                                {
                                                        if(Form1->idcambiar[i]==atoi(p))
                                                        {
                                                                Form1->CheckListBox2->Checked[i]=true;
                                                                Form1->selectcambiar[Form1->totalselectcambiar]=Form1->idcambiar[i];
                                                                Form1->ListBox2->Items->Add(Form1->cambiar[i]);
                                                                Form1->totalselectcambiar++;
                                                        }
                                                }
                                                p=strtok(NULL,",");
                                       }
                                }else{
                                        if(Edit1->Text.IsEmpty()&&Edit2->Text.IsEmpty()){
                                                for (int i=0;i<Form1->totalcambiar;i++){
                                                        Form1->CheckListBox2->Checked[i]=false;
                                                }
                                                for (int i=0;i<Form1->totalreparar;i++){
                                                        Form1->CheckListBox1->Checked[i]=false;
                                                }
                                        }
                                }
                        }

                }
}
//---------------------------------------------------------------------------
void __fastcall TForm26::Image3Click(TObject *Sender)
{
        Form26->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm26::Edit1KeyPress(TObject *Sender, char &Key)
{
        if(!isdigit(Key)&&Key!=8&&Key!=44)
                Key=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm26::Edit2KeyPress(TObject *Sender, char &Key)
{
        Edit1KeyPress(Sender,Key);
}
//---------------------------------------------------------------------------

