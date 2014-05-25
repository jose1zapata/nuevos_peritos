//---------------------------------------------------------------------------

#ifndef Unit15H
#define Unit15H
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
class TForm15 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TPanel *Panel2;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TPanel *Panel3;
        TComboBox *ComboBox1;
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *ComboBox2;
        TEdit *Edit1;
        TComboBox *ComboBox3;
        TEdit *Edit2;
        TComboBox *ComboBox4;
        TLabel *Label3;
        TLabel *Label4;
        TQuery *Query1;
        TImage *Image5;
        TEdit *Edit3;
        TEdit *Edit4;
        TImage *Image6;
        TImage *Image7;
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        String todo[100][100];
        String x,y;
        __fastcall TForm15(TComponent* Owner);
   void __fastcall rellenar();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm15 *Form15;
//---------------------------------------------------------------------------
#endif
