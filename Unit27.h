//---------------------------------------------------------------------------

#ifndef Unit27H
#define Unit27H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm27 : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRBand1;
        TQRBand *QRBand2;
        TQRBand *QRBand3;
        TQRDBText *QRDBText1;
        TQuery *Query1;
        TQRDBText *QRDBText3;
        TQRLabel *QRLabel1;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
private:	// User declarations
public:		// User declarations
        __fastcall TForm27(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm27 *Form27;
//---------------------------------------------------------------------------
#endif
