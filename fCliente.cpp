//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fCliente.h"
#include "uSISNAR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
   Table1->DatabaseName = GetCurrentDir();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormShow(TObject *Sender)
{
   Table1->Active = true;
   Edit2->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1Change(TObject *Sender)
{
   if((Edit1->Text == "")&&(Edit2->Text == "")&&(Edit3->Text == ""))
      Table1->Filtered = false;
   else if((Edit1->Text == "")&&(Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Nombre = '" + Edit2->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit2->Text == "")&&(Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Apellido = '" + Edit1->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit1->Text == "")&&(Edit2->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Fecha = '" + Edit3->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit1->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Fecha = '" + Edit3->Text + "*')";
      Table1->Filtered = true;
   }
   else if((Edit2->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Apellido = '" + Edit1->Text + "*') AND (Fecha = '" + Edit3->Text + "*')";
      Table1->Filtered = true;
   }
   else if((Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Apellido = '" + Edit1->Text + "*')";
      Table1->Filtered = true;
   }
   else
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Fecha = '" + Edit3->Text + "*') AND (Apellido = '" + Edit1->Text + "*')";
      Table1->Filtered = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn4Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Edit2Change(TObject *Sender)
{
   if((Edit1->Text == "")&&(Edit2->Text == "")&&(Edit3->Text == ""))
      Table1->Filtered = false;
   else if((Edit1->Text == "")&&(Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Nombre = '" + Edit2->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit2->Text == "")&&(Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Apellido = '" + Edit1->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit1->Text == "")&&(Edit2->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Fecha = '" + Edit3->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit1->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Fecha = '" + Edit3->Text + "*')";
      Table1->Filtered = true;
   }
   else if((Edit2->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Apellido = '" + Edit1->Text + "*') AND (Fecha = '" + Edit3->Text + "*')";
      Table1->Filtered = true;
   }
   else if((Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Apellido = '" + Edit1->Text + "*')";
      Table1->Filtered = true;
   }
   else
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Fecha = '" + Edit3->Text + "*') AND (Apellido = '" + Edit1->Text + "*')";
      Table1->Filtered = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
   Table1->Cancel();
   Table1->Active = false;
   Edit1->Clear();
   Edit2->Clear();
   Edit3->Clear();
}
//---------------------------------------------------------------------------




void __fastcall TForm3::Edit3Change(TObject *Sender)
{
   if((Edit1->Text == "")&&(Edit2->Text == "")&&(Edit3->Text == ""))
      Table1->Filtered = false;
   else if((Edit1->Text == "")&&(Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Nombre = '" + Edit2->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit2->Text == "")&&(Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Apellido = '" + Edit1->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit1->Text == "")&&(Edit2->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "Fecha = '" + Edit3->Text + "*'";
      Table1->Filtered = true;
   }
   else if((Edit1->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Fecha = '" + Edit3->Text + "*')";
      Table1->Filtered = true;
   }
   else if((Edit2->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Apellido = '" + Edit1->Text + "*') AND (Fecha = '" + Edit3->Text + "*')";
      Table1->Filtered = true;
   }
   else if((Edit3->Text == ""))
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Apellido = '" + Edit1->Text + "*')";
      Table1->Filtered = true;
   }
   else
   {
      Table1->Filtered = false;
      Table1->Filter = "(Nombre = '" + Edit2->Text + "*') AND (Fecha = '" + Edit3->Text + "*') AND (Apellido = '" + Edit1->Text + "*')";
      Table1->Filtered = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{


   if(MessageDlg("Confirma que desea eleminar el cliente: \"" +Table1->FieldByName("Apellido")->AsString + "\" del registro? Esta acción no puede deshacerse.",
               mtWarning, TMsgDlgButtons() << mbOK << mbNo, 0) == mrOk)
   {
      Table1->Edit();
      Table1->Delete();
   }
}
//---------------------------------------------------------------------------


