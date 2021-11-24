//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
   AnsiString k;

   k = Edit13->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit13->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit14->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit14->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit15->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit15->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit16->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit16->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit17->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit17->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit18->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit18->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit19->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit19->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit20->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit20->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit21->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit21->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit22->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit22->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit23->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit23->Text = k.Delete(k.Pos("."),1);
   }

   k = Edit24->Text;
   if(k.Pos("."))
   {
      k = k.Insert(",",k.Pos("."));
      Edit24->Text = k.Delete(k.Pos("."),1);
   }

   TIniFile *Configuraciones;
   AnsiString Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   Configuraciones->WriteString("Precios colorantes base solvente","Precio A",Edit13->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio B",Edit14->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio C",Edit15->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio D",Edit16->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio E",Edit17->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio F",Edit18->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio I",Edit19->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio KX",Edit20->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio L",Edit21->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio R",Edit22->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio T",Edit23->Text);
   Configuraciones->WriteString("Precios colorantes base solvente","Precio V",Edit24->Text);

   delete Configuraciones;

   precioscambiados = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
   TIniFile *Configuraciones;
   AnsiString Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   Edit13->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio A","0,00");
   Edit14->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio B","0,00");
   Edit15->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio C","0,00");
   Edit16->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio D","0,00");
   Edit17->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio E","0,00");
   Edit18->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio F","0,00");
   Edit19->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio I","0,00");
   Edit20->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio KX","0,00");
   Edit21->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio L","0,00");
   Edit22->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio R","0,00");
   Edit23->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio T","0,00");
   Edit24->Text = Configuraciones->ReadString("Precios colorantes base solvente","Precio V","0,00");
   delete Configuraciones;
   precioscambiados = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
   printer = new TPrinter;        
}
//---------------------------------------------------------------------------


void __fastcall TForm2::PageControl1Change(TObject *Sender)
{
   if(PageControl1->TabIndex == 1)
   {
      TIniFile *Configuraciones;
      AnsiString Dir = GetCurrentDir()+"//Config.ini";
      Configuraciones = new TIniFile(Dir);

      if(printer->Printers->Count != 0)
      {
         cboPrinter->Items->Assign(printer->Printers);
         cboPrinter->ItemIndex = printer->PrinterIndex;
         BitBtn4->Enabled = true;
      }
      else
      {
         MessageDlg("Se recuerda que Ud. no posee impresoras instaladas en el sistema.",
                  mtInformation, TMsgDlgButtons() << mbOK, 0);

         cboPrinter->Text = "SIN IMPRESORAS";
         Configuraciones->WriteString("Impresion","Impresora","NO CONFIGURADA");
         BitBtn4->Enabled = false;
      }

      Label15->Caption = Configuraciones->ReadString("Impresion","Impresora","NO_CONFIGURADA");

      delete Configuraciones;
   }
}
//---------------------------------------------------------------------------



void __fastcall TForm2::BitBtn4Click(TObject *Sender)
{
   TIniFile *Configuraciones;
   AnsiString Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   Configuraciones->WriteString("Impresion","Impresora",cboPrinter->Text);
   Label15->Caption = cboPrinter->Text;

   delete Configuraciones;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BitBtn3Click(TObject *Sender)
{
   PageControl1->TabIndex = 0;
   PageControl1->ActivePage = TabSheet1;  
   Close();        
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(precioscambiados)
   {
      if(MessageDlg("Los cambios realizados en los precios no han sido guardados, desea guardarlos antes de salir?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
      {
        AnsiString k;

        k = Edit13->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit13->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit14->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit14->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit15->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit15->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit16->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit16->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit17->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit17->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit18->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit18->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit19->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit19->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit20->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit20->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit21->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit21->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit22->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit22->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit23->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit23->Text = k.Delete(k.Pos("."),1);
        }

        k = Edit24->Text;
        if(k.Pos("."))
        {
           k = k.Insert(",",k.Pos("."));
           Edit24->Text = k.Delete(k.Pos("."),1);
        }

        TIniFile *Configuraciones;
        AnsiString Dir = GetCurrentDir()+"//Config.ini";
        Configuraciones = new TIniFile(Dir);

        Configuraciones->WriteString("Precios colorantes base solvente","Precio A",Edit13->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio B",Edit14->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio C",Edit15->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio D",Edit16->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio E",Edit17->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio F",Edit18->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio I",Edit19->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio KX",Edit20->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio L",Edit21->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio R",Edit22->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio T",Edit23->Text);
        Configuraciones->WriteString("Precios colorantes base solvente","Precio V",Edit24->Text);

        delete Configuraciones;

        precioscambiados = false;
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit13Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit14Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit15Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit16Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit17Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit18Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit19Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit20Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit21Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit22Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit23Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit24Change(TObject *Sender)
{
   precioscambiados = true;        
}
//---------------------------------------------------------------------------

