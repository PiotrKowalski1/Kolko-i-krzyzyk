 //---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int pkt1,pkt2,remis;
int pom=0;
int x=0,y=0,z=0;
char p1,p2,p3,p4,p5,p6,p7,p8,p9;
//nr pola w grze (ich zawartosc n=nic,o=kolko,x=krzyzyk)
char kto;
int tab[9];  //tablica przechowujaca numery pól zaznaczonych
int nr;      //zmienna przechowujaca informacje z numerem zaznaczonego pola 
int k;       //zmienna przechowujaca informacje,czy nastapila wygrana
int numer;   //zmienna przechowujaca informacje z numerem zaznaczonego pola 



//---------------------------------------------------------------------------

void blokuj()
{
Form3->Image1->Enabled=false;
Form3->Image2->Enabled=false;
Form3->Image3->Enabled=false;
Form3->Image4->Enabled=false;
Form3->Image5->Enabled=false;
Form3->Image6->Enabled=false;
Form3->Image7->Enabled=false;
Form3->Image8->Enabled=false;
Form3->Image9->Enabled=false;


}

//---------------------------------------------------------------------------
//funkcja, która sprawdza czy nie nastąpila wygrana

void kontrola()
{
      if((p1==p2  && p2==p3 && p1!='n')||
       (p4==p5  && p5==p6 && p4!='n')||
       (p7==p8  && p8==p9 && p7!='n')||
       (p1==p4  && p4==p7 && p1!='n')||
       (p2==p5  && p5==p8 && p2!='n')||
       (p3==p6  && p6==p9 && p3!='n')||
       (p1==p5  && p5==p9 && p1!='n')||
       (p3==p5  && p5==p7 && p3!='n'))
       { if(kto=='b')
         {Form3->Label10->Caption="Koniec gry Wygrywa:"+Form1->gracz1;
         Form3->Label10->Visible=true;

         x++;
         Form3->Label5 ->Caption=IntToStr(x);
         }
         else
         {Form3->Label10->Caption="Koniec gry. Wygrywa CPU";
         Form3->Label10->Visible=true;
         y++;
         Form3->Label7->Caption=IntToStr(y);
         }
          blokuj();
          k=1;
}
     else if((p1!='n')&&(p2!='n')&&(p3!='n')&&(p4!='n')&&(p5!='n')&&(p6!='n')
     &&(p7!='n')&&(p8!='n')&&(p9!='n'))

       { Form3->Label10->Caption="Remis";
         Form3->Label10->Visible=true;

         z++;
         Form3->Label6 ->Caption=IntToStr(z);


       }


  }
//---------------------------------------------------------------------------
//funkcja imitujaca ruchy komputera

void komputer(int nr)
{
if(nr==0)           //sprawdza,czy pierwszym ruchem jest ruch komputera
{ Form3->Image1->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image1->Enabled=false;
p1='x';
tab[1]=1;

}


else
{
tab[nr]=nr;


 if(tab[1]==0)
{
Form3->Image1->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image1->Enabled=false;
p1='x';
 tab[1]=1;

}
else  if(tab[9]==0)
{
Form3->Image9->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image9->Enabled=false;
p9='x';
tab[9]=9;
}
else if(tab[3]==0)
{
Form3->Image3->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image3->Enabled=false;
p3='x';
 tab[3]=3;
}

else   if(tab[7]==0)
{
Form3->Image7->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image7->Enabled=false;
p7='x';
tab[7]=7;
}



else   if(tab[4]==0)
{
Form3->Image4->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image4->Enabled=false;
p4='x';
tab[4]=4;
}
else  if(tab[8]==0)
{
Form3->Image8->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image8->Enabled=false;
p8='x';
tab[8]=8;
}
else if(tab[2]==0)
{
Form3->Image2->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image2->Enabled=false;
p2='x';
 tab[2]=2;

}
else   if(tab[6]==0)
{
Form3->Image6->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/o.bmp");
Form3->Image6->Enabled=false;
p6='x';
tab[6]=6;
}
else  if(tab[5]==0)
{
Form3->Image5->Picture->LoadFromFile("img/x.bmp") ;
kto='x';
Form3->Tura->Picture->LoadFromFile("img/so.bmp");
Form3->Image5->Enabled=false;
p5='x';
 tab[5]=5;
}




kontrola(); }

}


void czasomierz()
{ Form3->Label4->Caption = TimeToStr(Time());
}


//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{   Label2->Caption="remis";

  Label1->Caption=Form1->gracz1;
 Label3->Caption="CPU";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
for(int i=1;i<10;i++)
      tab[i]=0;            //tablice wypelniamy zerami
      k=0;                 //zerujemy k po kazdej rozgrywce


Label10->Visible=false;
Label1->Caption=Form1->gracz1;


Image1->Picture->LoadFromFile("img/nic.bmp");
Image2->Picture->LoadFromFile("img/nic.bmp");
Image3->Picture->LoadFromFile("img/nic.bmp");
Image4->Picture->LoadFromFile("img/nic.bmp");
Image5->Picture->LoadFromFile("img/nic.bmp");
Image6->Picture->LoadFromFile("img/nic.bmp");
Image7->Picture->LoadFromFile("img/nic.bmp");
Image8->Picture->LoadFromFile("img/nic.bmp");
Image9->Picture->LoadFromFile("img/nic.bmp");

   p1='n'; p2='n'; p3='n';
   p4='n'; p5='n'; p6='n';
   p7='n'; p8='n'; p9='n';

   Image1->Enabled=true;
   Image2->Enabled=true;
   Image3->Enabled=true;
   Image4->Enabled=true;
   Image5->Enabled=true;
   Image6->Enabled=true;
   Image7->Enabled=true;
   Image8->Enabled=true;
   Image9->Enabled=true;


   if(pom==0)
   {Tura->Picture->LoadFromFile("img/so.bmp");
   kto='w';

   pom=1;}

   else if(pom==1)
   {Tura->Picture->LoadFromFile("img/sx.bmp");
   kto='b';
   pom=0;
   numer=0;
   komputer(numer);
   }

}
//---------------------------------------------------------------------------
  void __fastcall TForm2::Timer1Timer(TObject *Sender)
   {}
//---------------------------------------------------------------------------

void __fastcall TForm3::Label8MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Label8->Font->Color=clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Label8MouseLeave(TObject *Sender)
{
Label8->Font->Color=clMaroon;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image1Click(TObject *Sender)
{
if(p1=='n')
  { if(kto=='o')
  {  Image1->Picture->LoadFromFile("img/o.bmp");
  p1='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image1->Enabled=false;


 kontrola();
  if(k==0)
  {numer=1;
  komputer(numer);}
  }

  }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2Click(TObject *Sender)
{ if(p2=='n')
  { if(kto=='o')
  {  Image2->Picture->LoadFromFile("img/o.bmp");
  p2='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image2->Enabled=false;

 kontrola();
 if(k==0)
 { numer=2;
  komputer(numer);  }

} }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image3Click(TObject *Sender)
{ if(p3=='n')
  { if(kto=='o')
  {  Image3->Picture->LoadFromFile("img/o.bmp");
  p3='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image3->Enabled=false;

kontrola();
 if(k==0)
  {numer=3;
  komputer(numer); }
        
}   }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image4Click(TObject *Sender)
{ if(p4=='n')
  { if(kto=='o')
  {  Image4->Picture->LoadFromFile("img/o.bmp");
  p4='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image4->Enabled=false;

 kontrola();
 if(k==0)
  {numer=4;
  komputer(numer);  }
        
}  }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image5Click(TObject *Sender)
{ if(p5=='n')
  { if(kto=='o')
  {  Image5->Picture->LoadFromFile("img/o.bmp");
  p5='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image5->Enabled=false;

kontrola();
if(k==0)
  {numer=5;
  komputer(numer); }
        
}  }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image6Click(TObject *Sender)
{ if(p6=='n')
  { if(kto=='o')
  {  Image6->Picture->LoadFromFile("img/o.bmp");
  p6='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image6->Enabled=false;

kontrola();
  if(k==0)
 {numer=6;
  komputer(numer);}
        
}   }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image7Click(TObject *Sender)
{ if(p7=='n')
  { if(kto=='o')
  {  Image7->Picture->LoadFromFile("img/o.bmp");
  p7='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image7->Enabled=false;

 kontrola();
 if(k==0)
  {numer=7;
  komputer(numer); }
        
}  }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image8Click(TObject *Sender)
{ if(p8=='n')
  { if(kto=='o')
  {  Image8->Picture->LoadFromFile("img/o.bmp");
  p8='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image8->Enabled=false;

 kontrola();
  if(k==0)
  {numer=8;
  komputer(numer); }
        
}    }
//---------------------------------------------------------------------------

void __fastcall TForm3::Image9Click(TObject *Sender)
{ if(p9=='n')
  { if(kto=='o')
  {  Image9->Picture->LoadFromFile("img/o.bmp");
  p9='o';
  kto='x';
  Tura->Picture->LoadFromFile("img/sx.bmp");
  }



  Image9->Enabled=false;
kontrola();
if(k==0)
 {numer=9;
  komputer(numer); }
        
}         }
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
czasomierz();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Label11MouseLeave(TObject *Sender)
{
Label11->Font->Color=clMaroon;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Label11MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
 Label11->Font->Color=clRed;        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Label11Click(TObject *Sender)
{OnCreate(Sender);

Form1->Show();
Form1->SpeedButton1Click(Sender);
Form3->Hide();
x=0;
y=0;
z=0;
}
//---------------------------------------------------------------------------

