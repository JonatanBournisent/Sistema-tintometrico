//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fAyuda.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm6::LBDrawItem(TWinControl *Control, int Index,
      TRect &Rect, TOwnerDrawState State)
{
   if(Index==2 || Index==31 || Index==49)
      LB->Canvas->Font->Color = clRed;
   else
      LB->Canvas->Font->Color == clBlack;
   LB->Canvas->TextOut(Rect.Left+2, Rect.Top+2,LB->Items->Strings[Index]);
}
//---------------------------------------------------------------------------








void __fastcall TForm6::BitBtn1Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------


void __fastcall TForm6::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
   ScrollBox1->VertScrollBar->Position = ScrollBox1->VertScrollBar->Position - 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
   ScrollBox1->VertScrollBar->Position = ScrollBox1->VertScrollBar->Position + 5;
}
//---------------------------------------------------------------------------

