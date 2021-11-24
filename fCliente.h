//---------------------------------------------------------------------------

#ifndef fClienteH
#define fClienteH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TTable *Table1;
        TLabel *Label1;
        TBevel *Bevel3;
        TLabel *Label6;
        TLabel *Label7;
        TDBMemo *DBMemo1;
        TLabel *Label2;
        TImage *Image1;
        TBevel *Bevel1;
        TLabel *Label3;
        TEdit *Edit2;
        TEdit *Edit1;
        TEdit *Edit3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
