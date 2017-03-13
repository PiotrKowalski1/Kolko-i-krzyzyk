 //---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1; //tlo w menu
        TLabel *Label1; //napis powitalny na górze menu 
        TLabel *Label2; //przycisk umozliwiajacy grê 1 vs 1
        TLabel *Label3; //przycisk umozliwiajacy grê vs CPU
        TLabel *Label4; //przycisk umozliwiajacy zakoñczenie gry
        TLabel *Label5; //napis "Player1" 
        TLabel *Label6; //napis "Player2"
        TEdit *Edit1;   //pole do, którego wprowadzamy nazwe gracza 1
        TEdit *Edit2;   //pole do, którego wprowadzamy nazwe gracza 2
        TSpeedButton *SpeedButton1;  //przycisk, umozliwiajacy powrót do menu
        TSpeedButton *SpeedButton2;  //przycisk, umozliwiajacy przejœcie do rozgrywki 1vs1
        TSpeedButton *SpeedButton3;  //przycisk, umozliwiajacy przejœcie do rogrywki vs CPU
        //funkcja podœwietla przycisk po najechaniu kursora
        void __fastcall Label2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        //funkcja przywraca poprzednie wlasciwosci przycisku
        void __fastcall Label2MouseLeave(TObject *Sender); 
        void __fastcall Label3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Label3MouseLeave(TObject *Sender);
        void __fastcall Label4MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Label4MouseLeave(TObject *Sender);
        //funkcja konczy program
        void __fastcall Label4Click(TObject *Sender);
        //funkcja wyswietla menu dla rozgrywki 1vs1
        void __fastcall Label2Click(TObject *Sender);
        //funkcja umozliwia powrot do menu
        void __fastcall SpeedButton1Click(TObject *Sender);
        //funkcja wyœwietla menu dla rozgrywki vs CPU
        void __fastcall Label3Click(TObject *Sender);
        //funkcje umozliwiajaca uzytkownikowi wprowadzanie nazw uzytkownika
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        //funkcja wyswietla plansze dla rozgrywki 1vs1
        void __fastcall SpeedButton2Click(TObject *Sender);
        //funkcja wyswietla plansze dla rozgrywki vs CPU
        void __fastcall SpeedButton3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
AnsiString gracz1;//zmienne sluzace do przechowywania nazw graczy wprowadzonych
AnsiString gracz2;//przez uzytkownika

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
