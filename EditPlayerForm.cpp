// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditPlayerForm.h"
#include "PlayersList.h"
#include "Service.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

Player TForm3::player;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::FormShow(TObject *Sender) {
	int selectedRow = Form1->PlayersListGd->Row;
	std::string id(AnsiString(Form1->PlayersListGd->Cells[0][selectedRow])
		.c_str());

	if (id != "") {
		int playerId = stoi(id);

		player = Service::GetRecord(playerId);

		NameInput->Text = player.GetName().c_str();
		ClubInput->Text = player.GetClub().c_str();
		RoleInput->Text = player.GetRole().c_str();
		PointsInput->Text = String(player.GetPoints());
		PenaltyPointsInput->Text = String(player.GetPenaltyPoints());

	}
	else {
		Form3->Close();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::SaveBtnClick(TObject *Sender) {
	std::string name(AnsiString(NameInput->Text).c_str());
	std::string club(AnsiString(ClubInput->Text).c_str());
	std::string role(AnsiString(RoleInput->Text).c_str());
	std::string points(AnsiString(PointsInput->Text).c_str());
	std::string penaltyPoints(AnsiString(PenaltyPointsInput->Text).c_str());

	Service::SavePlayer(std::to_string(player.GetId()), name, club, role, points, penaltyPoints);

	Form1->ReloadGridData();

	Form3->Close();
}
// ---------------------------------------------------------------------------
