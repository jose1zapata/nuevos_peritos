//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
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
class TForm2 : public TForm
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
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TEdit *Edit3;
        TLabel *Label4;
        TEdit *Edit4;
        TLabel *Label5;
        TEdit *Edit5;
        TMemo *Memo1;
        TLabel *Label6;
        TComboBox *ComboBox1;
        TQuery *Query1;
        TImage *Image5;
        TEdit *Edit6;
        TLabel *Label7;
        TImage *Image6;
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall Memo1KeyPress(TObject *Sender, char &Key);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Edit2Enter(TObject *Sender);
        void __fastcall Edit2Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Edit4Enter(TObject *Sender);
        void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
        void __fastcall Image6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        String codigo[100];
        int ban,ban1,prueba;
        struct vehiculo{
                String id;
                String serialcarroceria;
                String serialmotor;
                String numeropoliza;
                String placa;
                String anho;
                String marca_id;
                String modelo_id;
                String tipo_id;
                String color_id;
                String seguro_id;
                String uso;
                String condutores_id;
        }var;
        struct marca{
              String nombre;
        }var2;
        struct modelo{
              String nombre;
        }var3;
        struct tipo{
              String nombre;
        }var4;
        struct color{
              String nombre;
        }var5;
        struct seguro{
              String nombre;
        }var6;
        __fastcall TForm2(TComponent* Owner);
        void __fastcall formular();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
