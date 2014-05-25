//---------------------------------------------------------------------------

#ifndef Unit22H
#define Unit22H
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
class TForm22 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TLabel *Label1;
        TEdit *Edit1;
        TImage *Image1;
        TImage *Image2;
        TPanel *Panel3;
        TListBox *ListBox1;
        TLabel *Label2;
        TImage *Image3;
        TQuery *Query1;
        TQuery *Query2;
        TQuery *Query3;
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall ListBox1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        String avaluos[30000];
        int todos;
        __fastcall TForm22(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm22 *Form22;
//---------------------------------------------------------------------------
#endif
