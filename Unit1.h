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
        TLabel *Label1; //napis powitalny na g�rze menu 
        TLabel *Label2; //przycisk umo�liwiaj�cy gr� 1 vs 1
        TLabel *Label3; //przycisk umo�liwiaj�cy gr� vs CPU
        TLabel *Label4; //przycisk umo�liwiaj�cy zako�czenie gry
        TLabel *Label5; //napis "Player1" 
        TLabel *Label6; //napis "Player2"
        TEdit *Edit1;   //pole do, kt�rego wprowadzamy nazw� gracza 1
        TEdit *Edit2;   //pole do, kt�rego wprowadzamy nazw� gracza 2
        TSpeedButton *SpeedButton1;  //przycisk, umo�liwiaj�cy powr�t do menu
        TSpeedButton *SpeedButton2;  //przycisk, umo�liwiaj�cy przej�cie do rozgrywki 1vs1
        TSpeedButton *SpeedButton3;  //przycisk, umo�liwiaj�cy przej�cie do rogrywki vs CPU
        //funkcja pod�wietla przycisk po najechaniu kursora
        void __fastcall Label2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        //funkcja przywraca poprzednie w�asciwo�ci przycisku
        void __fastcall Label2MouseLeave(TObject *Sender); 
        void __fastcall Label3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Label3MouseLeave(TObject *Sender);
        void __fastcall Label4MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Label4MouseLeave(TObject *Sender);
        //funkcja ko�czy program
        void __fastcall Label4Click(TObject *Sender);
        //funkcja wyswietla menu dla rozgrywki 1vs1
        void __fastcall Label2Click(TObject *Sender);
        //funkcja umo�liwia powr�t do menu
        void __fastcall SpeedButton1Click(TObject *Sender);
        //funkcja wy�wietla menu dla rozgrywki vs CPU
        void __fastcall Label3Click(TObject *Sender);
        //funkcje umo�liwiaj�ca u�ytkownikowi wprowadzanie nazw u�ytkownika
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        //funkcja wy�wietla plansz� dla rozgrywki 1vs1
        void __fastcall SpeedButton2Click(TObject *Sender);
        //funkcja wy�wietla plansz� dla rozgrywki vs CPU
        void __fastcall SpeedButton3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
AnsiString gracz1;//zmienne s�u��ce do przechowywania nazw graczy wprowadzonych
AnsiString gracz2;//przez u�ytkownika

        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
