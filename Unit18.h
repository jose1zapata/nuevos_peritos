//---------------------------------------------------------------------------

#ifndef Unit18H
#define Unit18H
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
class TForm18 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TPanel *Panel2;
        TPanel *Panel3;
        TImage *Image2;
        TImage *Image3;
        TLabel *Label1;
        TEdit *Edit1;
        TQuery *Query1;
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm18(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm18 *Form18;
//---------------------------------------------------------------------------
#endif
