//---------------------------------------------------------------------------

#ifndef Unit25H
#define Unit25H
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
class TForm25 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TImage *Image1;
        TLabel *Label1;
        TEdit *Edit2;
        TQuery *Query1;
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm25(TComponent* Owner);
        int ban;
        void __fastcall codigo();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm25 *Form25;
//---------------------------------------------------------------------------
#endif
