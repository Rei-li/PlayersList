//---------------------------------------------------------------------------

#pragma hdrstop

#include "Service.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Service::Service() {
	_repo = ListRepository();
}

Service::Service(std::string fileName) {
	_repo = ListRepository(fileName);
}

vector<Player>Service::LoadData() {
	vector<Player>players;

	return players;
}

bool Service::IsFileSet() {
	string fileName = _repo.GetFileName();

	return fileName != "";
}