//---------------------------------------------------------------------------

#ifndef Unit20H
#define Unit20H
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
class TForm20 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TPanel *Panel2;
        TImage *Image2;
        TImage *Image3;
        TPanel *Panel3;
        TComboBox *ComboBox1;
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *ComboBox2;
        TLabel *Label3;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *Edit3;
        TLabel *Label8;
        TComboBox *ComboBox5;
        TComboBox *ComboBox6;
        TLabel *Label9;
        TComboBox *ComboBox7;
        TLabel *Label10;
        TEdit *Edit4;
        TLabel *Label11;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TImage *Image8;
        TImage *Image9;
        TQuery *Query1;
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
        void __fastcall Image8Click(TObject *Sender);
        void __fastcall Image9Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm20(TComponent* Owner);
        void __fastcall acomodar(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm20 *Form20;
//---------------------------------------------------------------------------
#endif
