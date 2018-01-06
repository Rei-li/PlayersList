// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddPlayerForm.h"
#include "PlayersList.h"
#include "Service.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::SaveBtnClick(TObject *Sender) {

	std::string name(AnsiString(NameInput->Text).c_str());
	std::string club(AnsiString(ClubInput->Text).c_str());
	std::string role(AnsiString(RoleInput->Text).c_str());
	std::string points(AnsiString(PointsInput->Text).c_str());
	std::string penaltyPoints(AnsiString(PenaltyPointsInput->Text).c_str());

	Service::SavePlayer(std::string(), name, club, role, points, penaltyPoints);

	Form1->ReloadGridData();

	Form2->Close();

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action) {
	NameInput->Text = "";
	ClubInput->Text = "";
	RoleInput->Text = "";
	PointsInput->Text = "";
	PenaltyPointsInput->Text = "";
}
// ---------------------------------------------------------------------------
