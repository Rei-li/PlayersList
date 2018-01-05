//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PlayersList.h"
#include "AddPlayerForm.h"
#include "Service.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadDataBtnClick(TObject *Sender)
{
	bool isfileSelected = _service.IsFileSet();
	if(!isfileSelected){
            TOpenDialog *OpenDialog = new TOpenDialog(Form1);
			if (!OpenDialog->Execute())
				return;
			String fileName = OpenDialog->FileName;
			AnsiString _astr = fileName;
	}
	 std::vector<Player>records = _service.LoadData();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddBtnClick(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------
