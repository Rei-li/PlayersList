// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Service.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void Service::SetFile(std::string fileName) {
	ListRepository::SetFile(fileName);
}

void Service::LoadData() {
	ListRepository::LoadData();
}

std::vector<Player>Service::GetRecords() {
	return ListRepository::GetRecords();
}

void Service::DeleteRecord(std::string id) {
	if (id != "") {
		int playerId = stoi(id);
		ListRepository::DeleteRecord(playerId);
	}
}

Player Service::GetRecord(int id){
	   return  ListRepository::GetRecord(id);
}

void Service::SavePlayer(std::string id, std::string name, std::string club,
	std::string role, std::string points, std::string penaltyPoints) {

	int playerId;
	int playerPoints;
	int playerPenaltyPoints;

	if (id != "") {
		playerId = stoi(id);
	}
	else {
		playerId = 0;
	}

	if (points != "") {
		playerPoints = stoi(points);
	}
	else {
		playerPoints = 0;
	}

	if (penaltyPoints != "") {
		playerPenaltyPoints = stoi(penaltyPoints);
	}
	else {
		playerPenaltyPoints = 0;
	}

	Player player(playerId, name, club, role, playerPoints,
		playerPenaltyPoints);

	if (playerId == 0) {
		ListRepository::AddRecord(player);
	}
	else {
		ListRepository::UpdateRecord(player);
	}

}

// bool Service::IsFileSet() {
// string fileName = ListRepository::GetFileName();
//
// return fileName != "";
// }
