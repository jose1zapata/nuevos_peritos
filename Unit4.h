//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TPanel *Panel2;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TPanel *Panel3;
        TGroupBox *GroupBox1;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TComboBox *ComboBox5;
        TLabel *Label1;
        TImage *Image5;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TImage *Image6;
        TEdit *Edit1;
        TLabel *Label5;
        TImage *Image7;
        TImage *Image8;
        TEdit *Edit2;
        TLabel *Label6;
        TEdit *Edit3;
        TLabel *Label7;
        TLabel *Label8;
        TPanel *Panel4;
        TLabel *Label9;
        TImage *Image9;
        TEdit *Edit5;
        TLabel *Label10;
        TQuery *Query1;
        TLabel *Label11;
        TLabel *Label12;
        TComboBox *ComboBox6;
        TComboBox *ComboBox7;
        TImage *Image10;
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Image8Click(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
        void __fastcall Image9Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image10Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        AnsiString Marca[400][2],Modelo[50000][2],Tipo[50000][2],Colorete[50000][2],Seguro[50000][2];
        String Anho[10000],Uso[10000];
        int MARCA,MODELO,TIPO,COLOR,SEGURO,ANHO,USO;

        __fastcall TForm4(TComponent* Owner);
        void __fastcall marca();
        void __fastcall modelo();
        void __fastcall colores();
        void __fastcall tipo();
        void __fastcall seguro();
        void __fastcall anho();
        void __fastcall uso();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
