//---------------------------------------------------------------------------

#ifndef fConfigH
#define fConfigH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>

#include <IniFiles.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <printers.hpp>

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TComboBox *cboPrinter;
        TLabel *Label14;
        TLabel *Label15;
        TBevel *Bevel1;
        TLabel *Label16;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn3;
        TBevel *Bevel2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TLabel *Label17;
        TEdit *Edit13;
        TEdit *Edit14;
        TEdit *Edit15;
        TEdit *Edit16;
        TEdit *Edit17;
        TEdit *Edit18;
        TEdit *Edit19;
        TEdit *Edit20;
        TEdit *Edit21;
        TEdit *Edit22;
        TEdit *Edit23;
        TEdit *Edit24;
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
        TBevel *Bevel4;
        TLabel *Label13;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Edit13Change(TObject *Sender);
        void __fastcall Edit14Change(TObject *Sender);
        void __fastcall Edit15Change(TObject *Sender);
        void __fastcall Edit16Change(TObject *Sender);
        void __fastcall Edit17Change(TObject *Sender);
        void __fastcall Edit18Change(TObject *Sender);
        void __fastcall Edit19Change(TObject *Sender);
        void __fastcall Edit20Change(TObject *Sender);
        void __fastcall Edit21Change(TObject *Sender);
        void __fastcall Edit22Change(TObject *Sender);
        void __fastcall Edit23Change(TObject *Sender);
        void __fastcall Edit24Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
        TPrinter *printer;
        bool precioscambiados;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
