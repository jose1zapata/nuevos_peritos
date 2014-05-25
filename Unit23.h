//---------------------------------------------------------------------------

#ifndef Unit23H
#define Unit23H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <jpeg.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm23 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TMemo *Memo1;
        TLabel *Label1;
        TQuery *Query1;
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm23(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm23 *Form23;
//---------------------------------------------------------------------------
#endif
