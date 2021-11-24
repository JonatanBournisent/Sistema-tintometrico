//---------------------------------------------------------------------------

#ifndef uSISNARH
#define uSISNARH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBGrid1;
        TDataSource *DataSource1;
        TTable *Table1;
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Configuraciondeprecios1;
        TMenuItem *Salir1;
        TMenuItem *Acercade1;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TTable *Table2;
        TDataSource *DataSource2;
        TLabel *Label7;
        TMenuItem *Acercade2;
        TMenuItem *Ayuda1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TBevel *Bevel1;
        TBevel *Bevel2;
        TLabel *Label9;
        TBevel *Bevel3;
        TBevel *Bevel4;
        TImage *d;
        TComboBox *CBColor;
        TEdit *EdLit;
        TComboBox *CB1;
        TCheckBox *CheckBox1;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit3;
        TDBMemo *DBMemo1;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn3;
        TCheckBox *CheckBox2;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TLabel *Label8;
        TLabel *Label10;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn6;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Configuraciondeprecios1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall FormCanResize(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall EdLitChange(TObject *Sender);
        void __fastcall CB1Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall CBColorChange(TObject *Sender);
        void __fastcall Ayuda1Click(TObject *Sender);
        void __fastcall Acercade2Click(TObject *Sender);
        void __fastcall Label8Click(TObject *Sender);
        void __fastcall Label10Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void Redondear(float& valor);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
