// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PlayersList.h"
#include "AddPlayerForm.h"
#include "EditPlayerForm.h"
#include "Service.h"
#include <string>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	PlayersListGd->ColWidths[0] = -1;
	PlayersListGd->ColWidths[1] = 160;
	PlayersListGd->ColWidths[2] = 160;
	PlayersListGd->ColWidths[3] = 160;
	PlayersListGd->ColWidths[4] = 160;
	PlayersListGd->ColWidths[5] = 160;

	PlayersListGd->Cells[1][0] = "Имя";
	PlayersListGd->Cells[2][0] = "Клуб";
	PlayersListGd->Cells[3][0] = "Амплуа";
	PlayersListGd->Cells[4][0] = "Количество забитых мячей";
	PlayersListGd->Cells[5][0] = "Количество штрафных очков";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::AddBtnClick(TObject *Sender) {
	Form2->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::SetFileBtnClick(TObject *Sender) {
	TOpenDialog *OpenDialog = new TOpenDialog(Form1);
	if (!OpenDialog->Execute())
		return;
	std::string fileName(AnsiString(OpenDialog->FileName).c_str());
	Service::SetFile(fileName);
	Service::LoadData();
	std::vector<Player>players = Service::GetRecords();
	LoadDataToGrid(players);
	DeleteBtn->Enabled = true;
	EditBtn->Enabled = true;
	AddBtn->Enabled = true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EditBtnClick(TObject *Sender) {
	int selectedRow = Form1->PlayersListGd->Row;
	if (selectedRow > 0) {
		Form3->Show();
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::DeleteBtnClick(TObject *Sender) {
	int selectedRow = PlayersListGd->Row;
	if (selectedRow > 0) {
		std::string id(AnsiString(PlayersListGd->Cells[0][selectedRow])
			.c_str());
		Service::DeleteRecord(id);
		ReloadGridData();
	}
}
// ---------------------------------------------------------------------------

void TForm1::ReloadGridData() {
	std::vector<Player>players = Service::GetRecords();
	LoadDataToGrid(players);
}

void TForm1::ClearGrid() {
	for (int i = 1; i < Form1->PlayersListGd->RowCount; i++) {
		Form1->PlayersListGd->Rows[i]->Clear();
	}
}

void TForm1::LoadDataToGrid(std::vector<Player>players) {
	ClearGrid();
	int size = players.size();
	int rowsCount = size + 1;
	Form1->PlayersListGd->RowCount = rowsCount;
	if (size > 0) {
		for (unsigned int counter = 0; counter < size; counter++) {
			Player player = players[counter];
			int rowIndex = counter + 1;
			Form1->PlayersListGd->Cells[0][rowIndex] = String(player.GetId());
			Form1->PlayersListGd->Cells[1][rowIndex] = player.GetName().c_str();
			Form1->PlayersListGd->Cells[2][rowIndex] = player.GetClub().c_str();
			Form1->PlayersListGd->Cells[3][rowIndex] = player.GetRole().c_str();
			Form1->PlayersListGd->Cells[4][rowIndex] =
				String(player.GetPoints());
			Form1->PlayersListGd->Cells[5][rowIndex] =
				String(player.GetPenaltyPoints());
		}
	}
}

void __fastcall TForm1::SortByPointsBtnClick(TObject *Sender) {
	std::vector<Player>players = Service::GetSortedListByPoints();
	LoadDataToGrid(players);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::PenaltyPlayersBtnClick(TObject *Sender) {
	std::vector<Player>players = Service::GetSortedListByPenaltyPoints();
	LoadDataToGrid(players);
	Form1->PlayersListGd->RowCount = 11;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::BestPlayersBtnClick(TObject *Sender) {
	std::vector<Player>players = Service::GetBestPlayersList();
	LoadDataToGrid(players);
	Form1->PlayersListGd->RowCount = 11;
}
// ---------------------------------------------------------------------------
