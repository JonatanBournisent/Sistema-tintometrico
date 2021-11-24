//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uSISNAR.h"
#include "fConfig.h"
#include "fCliente.h"
#include "fResumen.h"
#include "fAcerca.h"
#include "fAyuda.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   Table1->DatabaseName = GetCurrentDir();
   Table1->ReadOnly = true;
   Table1->Active = true;
   Table2->DatabaseName = GetCurrentDir();
   DecimalSeparator = ',';
   Application->UpdateFormatSettings = false;

   Table1->First();
   while(!Table1->Eof)
   {
      CBColor->Items->Add(Table1->FieldByName("COLOR")->AsString);
      Table1->Next();
   }
   Table1->First();

   DBEdit1->Enabled = false;
   DBEdit2->Enabled = false;
   DBEdit3->Enabled = false;
   DBMemo1->Enabled = false;
   BitBtn1->Enabled = true;
   BitBtn3->Enabled = true;
   BitBtn4->Enabled = false;
   BitBtn5->Enabled = false;
   BitBtn6->Enabled = false;
   Label1->Enabled = true;
   Label2->Enabled = true;
   Label3->Enabled = true;
   Label4->Enabled = false;
   Label5->Enabled = false;
   Label6->Enabled = false;
   Label7->Enabled = false;
   Label9->Enabled = true;
   CBColor->Enabled = true;
   EdLit->Enabled = true;

   TIniFile *Configuraciones;
   AnsiString Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   bool ejecutado = Configuraciones->ReadBool("PRIMERO","EJECUTADO",false);
   if(!ejecutado)
   {
      AnsiString Mensaje;
      Mensaje = "Si dispone de un sistema operativo mas reciente que Windows XP por favor";
      Mensaje = Mensaje + '\n';
      Mensaje = Mensaje + "  lea la sección \"COMPATIBILIDAD\" proporcionada en la pestaña \"Ayuda\"";
      MessageDlg(Mensaje, mtInformation, TMsgDlgButtons() << mbOK, 0);
      Configuraciones->WriteBool("PRIMERO","EJECUTADO", true);
   }
   delete Configuraciones;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   Table2->Cancel();
   Table1->Active = false;
   Table2->Active = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Salir1Click(TObject *Sender)
{
   Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Configuraciondeprecios1Click(TObject *Sender)
{
   Form2->PageControl1->TabIndex = 0;
   Form2->precioscambiados = false;
   Form2->PageControl1->ActivePage = Form2->TabSheet1;
   Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   Form3->ShowModal();
   CBColor->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
   int oz, eti;
   float vA,vB,vC,vD,vE,vF,vI,vKX,vL,vR,vT,vV;
   eti = 0;

   AnsiString qp;

   qp = EdLit->Text;
   if(qp.Pos("."))
   {
      qp = qp.Insert(",",qp.Pos("."));
      EdLit->Text = qp.Delete(qp.Pos("."),1);
   }
   qp = CB1->Text;
   if(qp.Pos("."))
   {
      qp = qp.Insert(",",qp.Pos("."));
      CB1->Text = qp.Delete(qp.Pos("."),1);
   }
   
   Form4->ListBox1->Clear();
   Form4->ListBox1->Items->Add("COLOR: " + Table1->FieldByName("COLOR")->AsString);
   Form4->QRLabel1->Caption = "COLOR: " + Table1->FieldByName("COLOR")->AsString;
   eti++;

   Form4->ListBox1->Items->Add("Volumen: " + EdLit->Text + " [LT]");
   Form4->QRLabel2->Caption = "Vol: " + EdLit->Text + " [LT]";
   eti++;
      
   Form4->ListBox1->Items->Add("");

   vA = Table1->FieldByName("A")->AsFloat;
   vB = Table1->FieldByName("B")->AsFloat;
   vC = Table1->FieldByName("C")->AsFloat;
   vD = Table1->FieldByName("D")->AsFloat;
   vE = Table1->FieldByName("E")->AsFloat;
   vF = Table1->FieldByName("F")->AsFloat;
   vI = Table1->FieldByName("I")->AsFloat;
   vKX =Table1->FieldByName("KX")->AsFloat;
   vL = Table1->FieldByName("L")->AsFloat;
   vR = Table1->FieldByName("R")->AsFloat;
   vT = Table1->FieldByName("T")->AsFloat;
   vV = Table1->FieldByName("V")->AsFloat;

   if (CheckBox1->Checked)
   {
      Redondear(vA);
      Redondear(vB);
      Redondear(vC);
      Redondear(vD);
      Redondear(vE);
      Redondear(vF);
      Redondear(vI);
      Redondear(vKX);
      Redondear(vL);
      Redondear(vR);
      Redondear(vT);
      Redondear(vV);
   }

   TIniFile *Configuraciones;
   AnsiString Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   float psA = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio A","0,00"));
   float psB = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio B","0,00"));
   float psC = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio C","0,00"));
   float psD = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio D","0,00"));
   float psE = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio E","0,00"));
   float psF = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio F","0,00"));
   float psI = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio I","0,00"));
   float psKX= StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio KX","0,00"));
   float psL = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio L","0,00"));
   float psR = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio R","0,00"));
   float psT = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio T","0,00"));
   float psV = StrToFloat(Configuraciones->ReadString("Precios colorantes base solvente","Precio V","0,00"));

   delete Configuraciones;

   float pSoTotal = 0.0;

   AnsiString aux;

   if(vA != 0)
   {
      vA = vA * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vA);
      }

      pSoTotal = pSoTotal + (psA * (vA / 1440.0));
      if(int(vA) < 48)
      {
         aux = "Colorante A: " + FormatFloat("0.00",vA);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vA) / 48);
         vA = vA - (oz * 48);
         aux = "Colorante A: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vA);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vB != 0)
   {
      vB = vB * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vB);
      }

      pSoTotal = pSoTotal + (psB * (vB / 1440.0));

      if(int(vB) < 48)
      {
         aux = "Colorante B: " + FormatFloat("0.00",vB);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vB) / 48);
         vB = vB - (oz * 48);
         aux = "Colorante B: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vB);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vC != 0)
   {
      vC = vC * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vC);
      }
      
      pSoTotal = pSoTotal + (psC * (vC / 1440.0));

      if(int(vC) < 48)
      {
         aux = "Colorante C: " + FormatFloat("0.00",vC);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vC) / 48);
         vC = vC - (oz * 48);
         aux = "Colorante C: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vC);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vD != 0)
   {
      vD = vD * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vD);
      }

      pSoTotal = pSoTotal + (psD * (vD / 1440.0));

      if(int(vD) < 48)
      {
         aux = "Colorante D: " + FormatFloat("0.00",vD);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vD) / 48);
         vD = vD - (oz * 48);
         aux = "Colorante D: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vD);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vE != 0)
   {
      vE = vE * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vE);
      }

      pSoTotal = pSoTotal + (psE * (vE / 1440.0));

      if(int(vE) < 48)
      {
         aux = "Colorante E: " + FormatFloat("0.00",vE);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vE) / 48);
         vE = vE - (oz * 48);
         aux = "Colorante E: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vE);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vF != 0)
   {
      vF = vF * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vF);
      }

      pSoTotal = pSoTotal + (psF * (vF / 1440.0));

      if(int(vF) < 48)
      {
         aux = "Colorante F: " + FormatFloat("0.00",vF);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vF) / 48);
         vF = vF - (oz * 48);
         aux = "Colorante F: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vF);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vI != 0)
   {
      vI = vI * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vI);
      }

      pSoTotal = pSoTotal + (psI * (vI / 1440.0));

      if(int(vI) < 48)
      {
         aux = "Colorante I: " + FormatFloat("0.00",vI);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vI) / 48);
         vI = vI - (oz * 48);
         aux = "Colorante I: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vI);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vKX != 0)
   {
      vKX = vKX * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vKX);
      }

      pSoTotal = pSoTotal + (psKX * (vKX / 1440.0));

      if(int(vKX) < 48)
      {
         aux = "Colorante KX: " + FormatFloat("0.00",vKX);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vKX) / 48);
         vKX = vKX - (oz * 48);
         aux = "Colorante KX: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vKX);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vL != 0)
   {
      vL = vL * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vL);
      }

      pSoTotal = pSoTotal + (psL * (vL / 1440.0));

      if(int(vL) < 48)
      {
         aux = "Colorante L: " + FormatFloat("0.00",vL);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vL) / 48);
         vL = vL - (oz * 48);
         aux = "Colorante L: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vL);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vR != 0)
   {
      vR = vR * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vR);
      }

      pSoTotal = pSoTotal + (psR * (vR / 1440.0));

      if(int(vR) < 48)
      {
         aux = "Colorante R: " + FormatFloat("0.00",vR);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vR) / 48);
         vR = vR - (oz * 48);
         aux = "Colorante R: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vR);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vT != 0)
   {
      vT = vT * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vT);
      }

      pSoTotal = pSoTotal + (psT * (vT / 1440.0));

      if(int(vT) < 48)
      {
         aux = "Colorante T: " + FormatFloat("0.00",vT);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vT) / 48);
         vT = vT - (oz * 48);
         aux = "Colorante T: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vT);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }
   if(vV != 0)
   {
      vV = vV * StrToFloat(CB1->Text) * StrToFloat(EdLit->Text) / 100.0;
      if(CheckBox2->Checked)
      {
         Redondear(vV);
      }

      pSoTotal = pSoTotal + (psV * (vV / 1440.0));

      if(int(vV) < 48)
      {
         aux = "Colorante V: " + FormatFloat("0.00",vV);
         Form4->ListBox1->Items->Add(aux);
      }
      else
      {
         oz = int(int(vV) / 48);
         vV = vV - (oz * 48);
         aux = "Colorante V: " + IntToStr(oz)+ "Y " + FormatFloat("0.00",vV);
         Form4->ListBox1->Items->Add(aux);
      }
      eti++;
      if(eti == 3)
         Form4->QRLabel3->Caption = aux;
         else if(eti == 4)
            Form4->QRLabel4->Caption = aux;
            else if(eti == 5)
               Form4->QRLabel5->Caption = aux;
               else if(eti == 6)
                  Form4->QRLabel6->Caption = aux;
   }

   if(CheckBox1->Checked)
   {
      Form4->ListBox1->Items->Add("FORMULA BASE APROXIMADA A 1/2 u.");
      Form4->QRLabel10->Caption = "R. Inicial";
   }
   else
      Form4->QRLabel10->Caption = "";
      
   if(CheckBox2->Checked)
   {
      Form4->ListBox1->Items->Add("MEZCLA FINAL APROXIMADA A 1/2 u.");
      if(CheckBox1->Checked)
         Form4->QRLabel11->Caption = "R. Final";
      else
      {
         Form4->QRLabel10->Caption = "R. Final";
         Form4->QRLabel11->Caption = "";
      }
   }
   else
      Form4->QRLabel11->Caption = "";

   Form4->ListBox1->Items->Add("");
   Form4->ListBox1->Items->Add("BASE: " + Table1->FieldByName("BASE")->AsString);
   Form4->QRLabel7->Caption = "BASE: " + Table1->FieldByName("BASE")->AsString;
   Form4->ListBox1->Items->Add("EP: " + CB1->Text + "%");
   Form4->QRLabel8->Caption = "EP: " + CB1->Text + "%";

   Form4->ListBox1->Items->Add("BASE UNIVERSAL");
   Form4->ListBox1->Items->Add("");
   Form4->ListBox1->Items->Add("COSTO DE COLORANTES: $" + FormatFloat("0.00",pSoTotal));

   aux = "";
   DateTimeToString(aux,"d/m/yyyy",Now());
   Form4->QRLabel9->Caption = "Fecha: " + aux;

   DBGrid1->Enabled = true;

   Form4->ShowModal();

   CBColor->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
   Resize = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EdLitChange(TObject *Sender)
{
   if((EdLit->Text == "")||(CBColor->Text == ""))
   {
      BitBtn2->Enabled = false;
      BitBtn6->Enabled = false;
   }
   else
   {
      BitBtn2->Enabled = true;
      BitBtn6->Enabled = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CB1Change(TObject *Sender)
{
   if(CB1->Text == "")
   {
      BitBtn2->Enabled = false;
      BitBtn6->Enabled = false;
   }
   else
   {
      BitBtn2->Enabled = true;
      BitBtn6->Enabled = true;
   }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
   CBColor->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
   Table2->Cancel();
   Table2->Active = false;
   DBEdit1->Enabled = false;
   DBEdit2->Enabled = false;
   DBEdit3->Enabled = false;
   DBMemo1->Enabled = false;
   BitBtn1->Enabled = true;
   BitBtn2->Enabled = true;
   BitBtn3->Enabled = true;
   BitBtn4->Enabled = false;
   BitBtn5->Enabled = false;
   BitBtn6->Enabled = true;
   Label1->Enabled = true;
   Label2->Enabled = true;
   Label3->Enabled = true;
   Label4->Enabled = false;
   Label5->Enabled = false;
   Label6->Enabled = false;
   Label7->Enabled = false;
   Label9->Enabled = true;
   CBColor->Enabled = true;
   EdLit->Enabled = true;
   CB1->Enabled = true;
   CheckBox1->Enabled = true;
   CheckBox2->Enabled = true;

   CBColor->SetFocus();

   if(CBColor->Text == "")
   {
      BitBtn2->Enabled = false;
      BitBtn6->Enabled = false;
   }
   else
   {
      BitBtn2->Enabled = true;
      BitBtn6->Enabled = true;
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CBColorChange(TObject *Sender)
{
   Table1->Filtered = false;
   Table1->Filter = "COLOR = '" + CBColor->Text + "'";
   Table1->Filtered = true;
   DBGrid1->Enabled = false;

   if((Table1->IsEmpty())||(EdLit->Text == ""))
   {
      BitBtn2->Enabled = false;
      BitBtn6->Enabled = false;
   }
   else
   {
      BitBtn2->Enabled = true;
      BitBtn6->Enabled = true;
   }

   if(CBColor->Text == "")
   {
      Table1->Filtered = false;
      DBGrid1->Enabled = true;
      BitBtn6->Enabled = false;
      CBColor->Color = clWhite;
      CBColor->Font->Color = clBlack;
   }

   else
   {
      Table1->Filtered = false;
      Table1->Filter = "COLOR = '" + CBColor->Text + "*'";
      Table1->Filtered = true;
      DBGrid1->Enabled = false;
      if(!Table1->IsEmpty())
      {
         BitBtn6->Enabled = true;
         CBColor->Color = clWhite;
         CBColor->Font->Color = clBlack;
      }
      else
      {
         BitBtn6->Enabled = false;
         CBColor->Color = clRed;
         CBColor->Font->Color = clWhite;
      }
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Ayuda1Click(TObject *Sender)
{
    Form5->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Acercade2Click(TObject *Sender)
{
   Form6->ShowModal();
}
//---------------------------------------------------------------------------

void TForm1::Redondear(float& valor)
{
   if(((valor - int(valor))*1.0) < 0.25)
            valor = int(valor) * 1.0;
            else if(((valor - int(valor))*1.0) < 0.75)
               valor = int(valor) * 1.0 + 0.5;
               else
                  valor = int(valor) * 1.0 + 1.0;
}


void __fastcall TForm1::Label8Click(TObject *Sender)
{
   if(CheckBox1->Checked)
      CheckBox1->Checked = false;
   else
      CheckBox1->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label10Click(TObject *Sender)
{
   if(CheckBox2->Checked)
      CheckBox2->Checked = false;
   else
      CheckBox2->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
      AnsiString s="";
   DateTimeToString(s,"dd/mm/yyyy",Now());
   Table2->FieldByName("Fecha")->AsString = s;
   Table2->FieldByName("Base")->AsString = "Universal";
   if(CheckBox1->Checked)
      Table2->FieldByName("Col_Aprox")->AsString = "SI";
   else
      Table2->FieldByName("Col_Aprox")->AsString = "NO";

      
   if(CheckBox2->Checked)
      Table2->FieldByName("Mezcla_Aprox")->AsString = "SI";
   else
      Table2->FieldByName("Mezcla_Aprox")->AsString = "NO";

   Table2->Post();
   Table2->Active = false;
   DBEdit1->Enabled = false;
   DBEdit2->Enabled = false;
   DBEdit3->Enabled = false;
   DBMemo1->Enabled = false;
   BitBtn1->Enabled = true;
   BitBtn2->Enabled = true;
   BitBtn3->Enabled = true;
   BitBtn4->Enabled = false;
   BitBtn5->Enabled = false;
   BitBtn6->Enabled = true;
   Label1->Enabled = true;
   Label2->Enabled = true;
   Label3->Enabled = true;
   Label4->Enabled = false;
   Label5->Enabled = false;
   Label6->Enabled = false;
   Label7->Enabled = false;
   Label9->Enabled = true;
   CBColor->Enabled = true;
   EdLit->Enabled = true;
   CB1->Enabled = true;
   CheckBox1->Enabled = true;
   CheckBox2->Enabled = true;

   BitBtn2->SetFocus();
   
   if(CBColor->Text == "")
   {
      BitBtn2->Enabled = false;
      BitBtn6->Enabled = false;
   }
   else
   {
      BitBtn2->Enabled = true;
      BitBtn6->Enabled = true;
   }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
   Table2->Active = true;
   Table2->Filtered = false;
   Table2->First();
   Table2->Insert();
   Table2->FieldByName("Color")->AsString = CBColor->Text;
   DBEdit1->Enabled = true;
   DBEdit2->Enabled = true;
   DBEdit3->Enabled = true;
   DBMemo1->Enabled = true;
   BitBtn1->Enabled = false;
   BitBtn2->Enabled = false;
   BitBtn3->Enabled = false;
   BitBtn4->Enabled = true;
   BitBtn5->Enabled = true;
   BitBtn6->Enabled = false;
   Label1->Enabled = false;
   Label2->Enabled = false;
   Label3->Enabled = false;
   Label4->Enabled = true;
   Label5->Enabled = true;
   Label6->Enabled = true;
   Label7->Enabled = true;
   Label9->Enabled = false;
   CBColor->Enabled = false;
   EdLit->Enabled = false;
   CB1->Enabled = false;
   CheckBox1->Enabled = false;
   CheckBox2->Enabled = false;

   DBEdit1->SetFocus();
}
//---------------------------------------------------------------------------

