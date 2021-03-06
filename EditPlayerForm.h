//---------------------------------------------------------------------------

#ifndef EditPlayerFormH
#define EditPlayerFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "PlayerModel.h"
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *NameInput;
	TEdit *ClubInput;
	TEdit *RoleInput;
	TEdit *PointsInput;
	TEdit *PenaltyPointsInput;
	TButton *SaveBtn;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SaveBtnClick(TObject *Sender);
private:	static Player player;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
