//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;  //napis wyswietlajacy nazwe gracza 1
        TLabel *Label2;  //napis "remis"
        TLabel *Label3;  //napis wyswietlajacy nazwe gracza 2
        TLabel *Label4;  //napis zegara,pokazujacy czas
        TLabel *Label5;  //napis wyswietlajacy ilosc punktów gracza 1
        TLabel *Label6;  //napis wyswietlajacy ilosc remisów
        TLabel *Label7;  //napis wyswietlajacy ilosc punktów gracza 2
        TLabel *Label9;  //napis "tura gracza",nad obrazem tura
        TLabel *Label10; //napis wyswietlajacy nazwe gracza, który wygral
        
        TLabel *Label8;  //przycisk pozwalajacy rozpoczac nowa rozgrywke
        TLabel *Label11; //przycisk pozwalajacy na powrót do menu

        TTimer *Timer1;  //timer sluzacy do odmierzania czasu
        
        TImage *Image1;  //obraz pola w grze
        TImage *Image2;  //obraz pola w grze
        TImage *Image3;  //obraz pola w grze
        TImage *Image4;  //obraz pola w grze
        TImage *Image5;  //obraz pola w grze
        TImage *Image6;  //obraz pola w grze
        TImage *Image7;  //obraz pola w grze
        TImage *Image8;  //obraz pola w grze
        TImage *Image9;  //obraz pola w grze
        
        TImage *Tura;    //obraz, przedstawiajacy czyj jest ruch
        
       
       
        //funcja zamykajaca program
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        //funkcja tworzaca plansze
        void __fastcall FormCreate(TObject *Sender);
        //funkcja odmierzajaca czas
        void __fastcall Timer1Timer(TObject *Sender);
        //funkcje wstawiajace obraz kólka i krzyzyka po kliknieciu w pole
        void __fastcall Image1Click(TObject *Sender); 
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender); 
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
        void __fastcall Image8Click(TObject *Sender);
        void __fastcall Image9Click(TObject *Sender);
        //funkcja podswietlajaca przycisk po najechaniu
        void __fastcall Label8MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        //funkcja przywracajaca wlasciwosci przycisku
        void __fastcall Label8MouseLeave(TObject *Sender); 
        void __fastcall Label11Click(TObject *Sender);
        void __fastcall Label11MouseLeave(TObject *Sender);
        void __fastcall Label11MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);

private:	// User declarations
public:		// User declarations


        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
