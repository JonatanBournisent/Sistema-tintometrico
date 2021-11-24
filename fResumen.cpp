//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fResumen.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BitBtn1Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
   if(QRLabel3->Caption.Pos("Colorante"))
      QRLabel3->Caption = QRLabel3->Caption.Delete(1,10);
   else QRLabel3->Caption ="";

   if(QRLabel4->Caption.Pos("Colorante"))
      QRLabel4->Caption = QRLabel4->Caption.Delete(1,10);
   else QRLabel4->Caption ="";

   if(QRLabel5->Caption.Pos("Colorante"))
      QRLabel5->Caption = QRLabel5->Caption.Delete(1,10);
   else QRLabel5->Caption ="";

   if(QRLabel6->Caption.Pos("Colorante"))
      QRLabel6->Caption = QRLabel6->Caption.Delete(1,10);
   else QRLabel6->Caption ="";

   BitBtn2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn2Click(TObject *Sender)
{
   CanPrint = false;
   AnsiString imp_actual;
   
   TIniFile *Configuraciones;
   AnsiString Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);
   imp_actual = Configuraciones->ReadString("Impresion","Impresora","NO_CONFIGURADA");


   if(imp_actual != "NO_CONFIGURADA")
   {
      CanPrint = true;

      int imp_index;

      if(CanPrint)
      {
         TPrinter *printer;
         printer = new TPrinter;
         for(imp_index=0; imp_index<printer->Printers->Count; imp_index++)
         {
            if(printer->Printers->Strings[imp_index] == imp_actual)
               break;
         }
         if(imp_index < printer->Printers->Count)
            CanPrint = true;
         else
         {
            CanPrint = false;
            Configuraciones->WriteString("Impresion","Impresora","NO CONFIGURADA");
         }
      }
      delete Configuraciones;

      if(CanPrint)
      {
         QR1->Prepare();
         QR1->PrinterSettings->PrinterIndex = imp_index;
         QR1->Print();
      }
      else
      {
         AnsiString Mensaje;
         Mensaje = "Se produjo un error al intentar localizar la impresora seleccionada.";
         Mensaje = Mensaje + '\n';
         Mensaje = Mensaje + "La reconfiguraracion de la impresora podria solucionar el problema.";
         MessageDlg(Mensaje, mtInformation, TMsgDlgButtons() << mbOK, 0);
      }
   }
   else
   {
      MessageDlg("Debe configurar una impresora antes de imprimir.",
                  mtInformation, TMsgDlgButtons() << mbOK, 0);
   }
}
//---------------------------------------------------------------------------





