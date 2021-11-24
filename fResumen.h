//---------------------------------------------------------------------------

#ifndef fResumenH
#define fResumenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>

#include <printers.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include <Dialogs.hpp>
#include <IniFiles.hpp>
#include <jpeg.hpp>


//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TListBox *ListBox1;
        TBevel *Bevel1;
        TQuickRep *QR1;
        TQRBand *QRBand1;
        TQRLabel *QRLabel1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn1;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel6;
        TQRLabel *QRLabel7;
        TQRLabel *QRLabel8;
        TQRLabel *QRLabel9;
        TQRImage *QRImage1;
        TQRLabel *QRLabel10;
        TQRLabel *QRLabel11;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);
        bool CanPrint;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
