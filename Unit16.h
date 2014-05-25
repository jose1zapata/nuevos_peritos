//---------------------------------------------------------------------------

#ifndef Unit16H
#define Unit16H
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
class TForm16 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TLabel *Label1;
        TMemo *Memo1;
        TQuery *Query1;
        void __fastcall Memo1KeyPress(TObject *Sender, char &Key);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm16(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm16 *Form16;
//---------------------------------------------------------------------------
#endif
