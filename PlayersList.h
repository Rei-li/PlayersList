//---------------------------------------------------------------------------

#ifndef PlayersListH
#define PlayersListH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Service.h"
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *AddBtn;
	TButton *SetFileBtn;
	TStringGrid *PlayersListGd;
	TButton *EditBtn;
	TButton *DeleteBtn;
	TButton *SortByPointsBtn;
	TButton *BestPlayersBtn;
	TButton *PenaltyPlayersBtn;
	void __fastcall AddBtnClick(TObject *Sender);
	void __fastcall SetFileBtnClick(TObject *Sender);
	void __fastcall EditBtnClick(TObject *Sender);
	void __fastcall DeleteBtnClick(TObject *Sender);
	void __fastcall SortByPointsBtnClick(TObject *Sender);
	void __fastcall PenaltyPlayersBtnClick(TObject *Sender);
private:    void LoadDataToGrid(std::vector<Player> players);
            void ClearGrid();
public:		void ReloadGridData();
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
