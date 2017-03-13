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
        TLabel *Label1;  //napis wyœwietlaj¹cy nazwê gracza 1
        TLabel *Label2;  //napis "remis"
        TLabel *Label3;  //napis wyœwietlaj¹cy nazwê gracza 2
        TLabel *Label4;  //napis zegara,pokazuj¹cy czas
        TLabel *Label5;  //napis wyœwietlaj¹cy iloœæ punktów gracza 1
        TLabel *Label6;  //napis wyœwietlaj¹cy iloœæ remisów
        TLabel *Label7;  //napis wyœwietlaj¹cy iloœæ punktów gracza 2
        TLabel *Label9;  //napis "tura gracza",nad obrazem tura
        TLabel *Label10; //napis wyœwietlaj¹cy nazwê gracza, który wygra³
        
        TLabel *Label8;  //przycisk pozwalaj¹cy rozpocz¹æ now¹ rozgrywkê
        TLabel *Label11; //przycisk pozwalaj¹cy powrót do menu

        TTimer *Timer1;  //timer s³u¿¹cy do odmierzania czasu
        
        TImage *Image1;  //obraz pola w grze
        TImage *Image2;  //obraz pola w grze
        TImage *Image3;  //obraz pola w grze
        TImage *Image4;  //obraz pola w grze
        TImage *Image5;  //obraz pola w grze
        TImage *Image6;  //obraz pola w grze
        TImage *Image7;  //obraz pola w grze
        TImage *Image8;  //obraz pola w grze
        TImage *Image9;  //obraz pola w grze
        
        TImage *Tura;    //obraz, przedstawiaj¹cy czyj jest ruch
        
       
       
        //funcja zamykaj¹ca program
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        //funkcja tworz¹ca planszê
        void __fastcall FormCreate(TObject *Sender);
        //funkcja odmierzaj¹ca czas
        void __fastcall Timer1Timer(TObject *Sender);
        //funkcje wstawiaj¹ce obraz kó³ka i krzy¿yka po klikniêciu w pole
        void __fastcall Image1Click(TObject *Sender); 
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender); 
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
        void __fastcall Image7Click(TObject *Sender);
        void __fastcall Image8Click(TObject *Sender);
        void __fastcall Image9Click(TObject *Sender);
        //funkcja podœwietlaj¹ca przycisk po najechaniu
        void __fastcall Label8MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        //funkcja przywracaj¹ca w³aœciwoœci przycisku
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
