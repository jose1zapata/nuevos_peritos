//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include <jpeg.hpp>
#include <DBCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "UCrpe32.hpp"
#include "UCrpeClasses.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMainMenu *MainMenu1;
        TMenuItem *menu11;
        TMenuItem *menu21;
        TMenuItem *Autopartes1;
        TMenuItem *NuevaActa1;
        TPanel *Panel2;
        TPanel *Panel3;
        TSplitter *Splitter2;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel7;
        TTable *Table1;
        TDataSource *DataSource1;
        TQuery *Query1;
        TQuery *Query3;
        TQuery *Query4;
        TDataSource *DataSource2;
        TPanel *Panel8;
        TLabel *Label1;
        TPanel *Panel9;
        TLabel *Label2;
        TCheckListBox *CheckListBox1;
        TCheckListBox *CheckListBox2;
        TSplitter *Splitter3;
        TSplitter *Splitter4;
        TPanel *Panel10;
        TPanel *Panel11;
        TPanel *Panel12;
        TPanel *Panel4;
        TLabel *Label3;
        TPanel *Panel13;
        TImage *Image5;
        TPanel *Panel14;
        TImage *Image3;
        TImage *Image2;
        TImage *Image1;
        TImage *Image4;
        TPanel *Panel15;
        TPanel *Panel16;
        TPanel *Panel17;
        TPanel *Panel18;
        TImage *Image6;
        TPanel *Panel19;
        TLabel *Label4;
        TQuery *Query2;
        TDataSource *DataSource3;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TPanel *Panel20;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TMenuItem *PeritoAvaluador1;
        TPanel *Panel21;
        TLabel *Label40;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *Label43;
        TLabel *Label44;
        TLabel *Label45;
        TLabel *Label46;
        TLabel *Label47;
        TLabel *Label48;
        TLabel *Label49;
        TLabel *Label50;
        TLabel *Label51;
        TLabel *Label52;
        TLabel *Label53;
        TLabel *Label54;
        TLabel *Label55;
        TPanel *Panel22;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TListBox *ListBox1;
        TListBox *ListBox2;
        TPanel *Panel23;
        TImage *Image9;
        TImage *Image10;
        TImage *Image8;
        TImage *Image11;
        TImage *Image12;
        TLabel *Label56;
        TLabel *Label57;
        TLabel *Label58;
        TLabel *Label59;
        TMenuItem *Salir1;
        TImage *Image7;
        TImage *Image13;
        TImage *Image14;
        TImage *Image15;
        TImage *Image16;
        TImage *Image17;
        TImage *Image18;
        TImage *Image19;
        TLabel *Label60;
        TLabel *Label61;
        TMemo *Memo1;
        TImage *Image20;
        TPanel *Panel24;
        TImage *Image21;
        TMenuItem *Buscarplacavehiculo1;
        TMenuItem *Reportedeactasperito1;
        TCrpe *Crpe1;
        TDatabase *Database1;
        TDatabase *Database2;
        TDatabase *Database3;
        TMenuItem *Modificar1;
        TMenuItem *Visualizar1;
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image9Click(TObject *Sender);
        void __fastcall Image10Click(TObject *Sender);
        void __fastcall Image11Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall PeritoAvaluador1Click(TObject *Sender);
        void __fastcall Image12Click(TObject *Sender);
        void __fastcall NuevaActa1Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image13Click(TObject *Sender);
        void __fastcall Image14Click(TObject *Sender);
        void __fastcall Image15Click(TObject *Sender);
        void __fastcall Image16Click(TObject *Sender);
        void __fastcall Image17Click(TObject *Sender);
        void __fastcall Image18Click(TObject *Sender);
        void __fastcall Image19Click(TObject *Sender);
        void __fastcall Image20Click(TObject *Sender);
        void __fastcall Image21Click(TObject *Sender);
        void __fastcall Buscarplacavehiculo1Click(TObject *Sender);
        void __fastcall Reportedeactasperito1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Visualizar1Click(TObject *Sender);
        void __fastcall Modificar1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        String reparar[30000],selectreparar[30000],idreparar[30000];
        int totalreparar,totalselectreparar;
        String cambiar[30000],selectcambiar[30000],idcambiar[30000],numerocadena,valores[30000];
        int activado,totalconsulta;
        int totalcambiar,totalselectcambiar;
        __fastcall TForm1(TComponent* Owner);
void __fastcall rellenar();
void __fastcall llamalo();

void __fastcall returntonumber(String cadena);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
