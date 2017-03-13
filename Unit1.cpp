//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{ 
gracz1="Player1";  //ustawiamy domyslne nazwy uzytkownikow
gracz2="Player2";
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Label2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{           
Label2->Font->Color= clLime;    
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Label2MouseLeave(TObject *Sender)
{
Label2->Font->Color=clGreen;    
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Label3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Label3->Font->Color=clLime;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label3MouseLeave(TObject *Sender)
{
     Label3->Font->Color=clGreen;   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label4MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Label4->Font->Color=clLime;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label4MouseLeave(TObject *Sender)
{
Label4->Font->Color=clGreen;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label4Click(TObject *Sender)
{
Form1->Close();   
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Label2Click(TObject *Sender)
{
Image1->Picture->LoadFromFile("img/tlo1.bmp");
Label2->Visible=false;
Label3->Visible=false;
Label4->Visible=false;
Label1->Font->Color=clPurple;

Label5->Visible=true;
Edit1->Visible=true;
Label6->Visible=true;
Edit2->Visible=true;
SpeedButton1->Visible=true;
SpeedButton2->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{ 
Image1->Picture->LoadFromFile("img/tlo.bmp");
Label1->Font->Color=clBlue;
Label2->Visible=true;
Label3->Visible=true;
Label4->Visible=true;

Label5->Visible=false;
Edit1->Visible=false;
Label6->Visible=false;
Edit2->Visible=false;
SpeedButton1->Visible=false;
SpeedButton2->Visible=false;
SpeedButton3->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Label3Click(TObject *Sender)
{ 

Image1->Picture->LoadFromFile("img/tlo1.bmp");
Label2->Visible=false;
Label3->Visible=false;
Label4->Visible=false;
Label1->Font->Color=clPurple;
Label5->Visible=true;
Edit1->Visible=true;

SpeedButton1->Visible=true;
SpeedButton3->Visible=true;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1Change(TObject *Sender)
{
 gracz1=Edit1->Text;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit2Change(TObject *Sender)
{
gracz2=Edit2->Text;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{ 
Form2->Show();
Form1->Hide();
SpeedButton2->Visible=false;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{ Form3->Show();
 SpeedButton3->Visible=false;
Form1->Hide();

}
//---------------------------------------------------------------------------

--
#endif
