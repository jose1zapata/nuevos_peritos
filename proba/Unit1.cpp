//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        String data;
        data=DateTimePicker1->Date;
        ShowMessage(data);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DateTimePicker1Click(TObject *Sender)
{
        String ok;
        ok=DateTimePicker1->DateTime;
        ShowMessage(ok);
}
//---------------------------------------------------------------------------
