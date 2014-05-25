//---------------------------------------------------------------------------

#ifndef Unit24H
#define Unit24H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm24 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TPanel *Panel3;
        TQuery *Query1;
        TComboBox *ComboBox1;
        TLabel *Label3;
        TComboBox *ComboBox2;
        TLabel *Label4;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TDateTimePicker *DateTimePicker1;
        TLabel *Label2;
        TDateTimePicker *DateTimePicker2;
        TEdit *Edit1;
        TLabel *Label5;
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Label3DblClick(TObject *Sender);
        void __fastcall Label4DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm24(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm24 *Form24;
//---------------------------------------------------------------------------
#endif
