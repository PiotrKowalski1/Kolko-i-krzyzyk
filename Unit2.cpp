 //---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

int pkt1,pkt2,remis; //zmienne do przechowywania punktów za wygrana rozgrywke
int pom=0; 
//pomocnicza, która zapamietuje, kto rozpoczynal rogrywke.
//Jej wartosc jest zmieniana po kazdej rozgrywce

int x=0,y=0,z=0;

char p1,p2,p3,p4,p5,p6,p7,p8,p9;
//nr pola w grze (ich zawartosc n=nic,o=kolko,x=krzyzyk)

char kto; //przechowuje informacje,kto ma wykonal ruch

//---------------------------------------------------------------------------
// funkcja dezaktywuje wszystkie pola po zakonczeniu rozgrywki

void blokuj()
{
Form2->Image1->Enabled=false;
Form2->Image2->Enabled=false;
Form2->Image3->Enabled=false;
Form2->Image4->Enabled=false;
Form2->Image5->Enabled=false;
Form2->Image6->Enabled=false;
Form2->Image7->Enabled=false;
Form2->Image8->Enabled=false;
Form2->Image9->Enabled=false;


}
//---------------------------------------------------------------------------
//funkcja sprawdza, czy nie nastapila wygrana

void sprawdz()
{
      if((p1==p2  && p2==p3 && p1!='n')||
       (p4==p5  && p5==p6 && p4!='n')||
       (p7==p8  && p8==p9 && p7!='n')||
       (p1==p4  && p4==p7 && p1!='n')||
       (p2==p5  && p5==p8 && p2!='n')||
       (p3==p6  && p6==p9 && p3!='n')||
       (p1==p5  && p5==p9 && p1!='n')||
       (p3==p5  && p5==p7 && p3!='n'))
       { if(kto=='x')
         {
         Form2->Label10->Caption="Koniec gry Wygrywa:"+Form1->gracz1;
         Form2->Label10->Visible=true;
         x++;
         Form2->Label5 ->Caption=IntToStr(x);
         }
         else
         {
         Form2->Label10->Caption="Koniec gry. Wygrywa:"+Form1->gracz2;
         Form2->Label10->Visible=true;
         y++;
         Form2->Label7->Caption=IntToStr(y);
         }
           blokuj();

          }
     else if((p1!='n')&&(p2!='n')&&(p3!='n')&&(p4!='n')&&(p5!='n')&&(p6!='n')
     &&(p7!='n')&&(p8!='n')&&(p9!='n'))

       { Form2->Label10->Caption="Remis";
         Form2->Label10->Visible=true;   
         z++;
         Form2->Label6 ->Caption=IntToStr(z);
       }



}
//---------------------------------------------------------------------------
// funkcja, wyswietla zegar z rzeczywistm czasem

void zegar()
{ 
Form2->Label4->Caption = TimeToStr(Time());
}


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
 Label2->Caption="remis";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCreate(TObject *Sender)
{

 Label10->Visible=false;
Label1->Caption=Form1->gracz1;
Label3->Caption=Form1->gracz2;

Image1->Picture->LoadFromFile("img/nic.bmp");//ladowanie z plikow wzoru planszy
Image2->Picture->LoadFromFile("img/nic.bmp");
Image3->Picture->LoadFromFile("img/nic.bmp");
Image4->Picture->LoadFromFile("img/nic.bmp");
Image5->Picture->LoadFromFile("img/nic.bmp");
Image6->Picture->LoadFromFile("img/nic.bmp");
Image7->Picture->LoadFromFile("img/nic.bmp");
Image8->Picture->LoadFromFile("img/nic.bmp");
Image9->Picture->LoadFromFile("img/nic.bmp");

   p1='n'; p2='n'; p3='n';     //ustawienie wartosci pol na n,czyli nic
   p4='n'; p5='n'; p6='n';
   p7='n'; p8='n'; p9='n';

   Image1->Enabled=true;     //ustawienie pol jako aktywne
   Image2->Enabled=true;
   Image3->Enabled=true;
   Image4->Enabled=true;
   Image5->Enabled=true;
   Image6->Enabled=true;
   Image7->Enabled=true;
   Image8->Enabled=true;
   Image9->Enabled=true;


   if(pom==0)   //sprawdza, kto ma rozpoczal rozgrywke
   {
   //laduje obraz,który informuje czyj jest ruch
   Tura->Picture->LoadFromFile("img/so.bmp");  
   kto='o';   //ustawia wartoœæ czyj jest ruch
   //zmieniamy wartoœæ pom,zeby w nastêpnej rozgrywce rozpoczynal drugi gracz
   pom=1;
   }

   else if(pom==1)
   {
   Tura->Picture->LoadFromFile("img/sx.bmp");
   kto='x';
   pom=0;
   }



}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1Click(TObject *Sender)
{
if(p1=='n')                          //sprawdza,czy pole jest puste
{
      if(kto=='o')                  //sprawdza, czyj jest ruch
      {
         Image1->Picture->LoadFromFile("img/o.bmp");    //laduje obraz na pole
         p1='o';        //ustawia wartosc pola,na gracza, który to pole kliknal
         kto='x';       //zmienia kolej ruchu na drugiego gracza
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image1->Picture->LoadFromFile("img/x.bmp");
         p1='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image1->Enabled=false;
           sprawdz();

}

//---------------------------------------------------------------------------

void __fastcall TForm2::Image2Click(TObject *Sender)
{
if(p2=='n')
{
      if(kto=='o')
      {
         Image2->Picture->LoadFromFile("img/o.bmp");
         p2='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image2->Picture->LoadFromFile("img/x.bmp");
         p2='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image2->Enabled=false;
           sprawdz();
}

//---------------------------------------------------------------------------


void __fastcall TForm2::Image3Click(TObject *Sender)
{
if(p3=='n')                                            
{
      if(kto=='o')                                     
      {
         Image3->Picture->LoadFromFile("img/o.bmp");   
         p3='o';                                       
         kto='x';                                       
         Tura->Picture->LoadFromFile("img/x.bmp") ;

      }
      else
      {
          Image3->Picture->LoadFromFile("img/x.bmp");
         p3='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image3->Enabled=false;  //ustawia pole jako nieaktywne
           sprawdz();               //sprawdza, czy nie nastapila wygrana
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image4Click(TObject *Sender)
{
if(p4=='n')
{
      if(kto=='o')
      {
         Image4->Picture->LoadFromFile("img/o.bmp");
         p4='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image4->Picture->LoadFromFile("img/x.bmp");
         p4='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image4->Enabled=false;
           sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image5Click(TObject *Sender)
{
if(p5=='n')
{
      if(kto=='o')
      {
         Image5->Picture->LoadFromFile("img/o.bmp");
         p5='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image5->Picture->LoadFromFile("img/x.bmp");
         p5='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image5->Enabled=false;
           sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image6Click(TObject *Sender)
{
if(p6=='n')
{
      if(kto=='o')
      {
         Image6->Picture->LoadFromFile("img/o.bmp");
         p6='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image6->Picture->LoadFromFile("img/x.bmp");
         p6='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image6->Enabled=false;
           sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image7Click(TObject *Sender)
{
if(p7=='n')
{
      if(kto=='o')
      {
         Image7->Picture->LoadFromFile("img/o.bmp");
         p7='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image7->Picture->LoadFromFile("img/o.bmp");
         p7='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image7->Enabled=false;
           sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image8Click(TObject *Sender)
{
if(p8=='n')
{
      if(kto=='o')
      {
         Image8->Picture->LoadFromFile("img/o.bmp");
         p8='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image8->Picture->LoadFromFile("img/x.bmp");
         p8='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image8->Enabled=false;
           sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image9Click(TObject *Sender)
{
if(p9=='n')
{
      if(kto=='o')
      {
         Image9->Picture->LoadFromFile("img/o.bmp");
         p9='o';
         kto='x';
         Tura->Picture->LoadFromFile("img/sx.bmp") ;

      }
      else
      {
          Image9->Picture->LoadFromFile("img/x.bmp");
         p9='x';
         kto='o';
         Tura->Picture->LoadFromFile("img/so.bmp") ;


      }

}           Image9->Enabled=false;
           sprawdz();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
zegar();
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Label8MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
   Label8->Font->Color=clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label8MouseLeave(TObject *Sender)
{
Label8->Font->Color=clMaroon;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label11Click(TObject *Sender)
{
OnCreate(Sender);

Form1->Show();
Form1->SpeedButton1Click(Sender);
Form2->Hide();
x=0;y=0;z=0;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label11MouseLeave(TObject *Sender)
{
    Label11->Font->Color=clMaroon;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Label11MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
   Label11->Font->Color=clRed;
}
//---------------------------------------------------------------------------

