//---------------------------------------------------------------------------

#ifndef Unit14H
#define Unit14H
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
class TForm14 : public TForm
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
        TLabel *Label1;
        TEdit *Edit1;
        TComboBox *ComboBox1;
        TLabel *Label2;
        TQuery *Query1;
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        String todo[100][100];
        __fastcall TForm14(TComponent* Owner);
  void  __fastcall rellenar();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm14 *Form14;
//---------------------------------------------------------------------------
#endif
