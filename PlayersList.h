//---------------------------------------------------------------------------

#ifndef PlayersListH
#define PlayersListH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Service.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *LoadDataBtn;
	TButton *AddBtn;
	void __fastcall LoadDataBtnClick(TObject *Sender);
	void __fastcall AddBtnClick(TObject *Sender);
private:		Service _service;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
