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

Player Service::GetRecord(int id) {
	return ListRepository::GetRecord(id);
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

std::vector<Player>Service::GetSortedListByPoints() {
	std::vector<Player>players = ListRepository::GetRecords();
	std::vector<Player> *copiedPlayers = new std::vector<Player>();

	for (unsigned int counter = 0; counter < players.size(); counter++) {

		copiedPlayers->push_back(players[counter]);

	}

	QuickSortByPoints(copiedPlayers, 0, copiedPlayers->size() - 1);

	return CopyReversed(copiedPlayers);
}

std::vector<Player>Service::GetSortedListByPenaltyPoints() {
	std::vector<Player>players = ListRepository::GetRecords();
	std::vector<Player> *copiedPlayers = new std::vector<Player>();

	for (unsigned int counter = 0; counter < players.size(); counter++) {

		copiedPlayers->push_back(players[counter]);

	}

	QuickSortByPenaltyPoints(copiedPlayers, 0, copiedPlayers->size() - 1);

	return CopyReversed(copiedPlayers);
}

std::vector<Player>Service::GetBestPlayersList() {
	std::vector<Player>players = ListRepository::GetRecords();
	std::vector<Player> *copiedPlayers = new std::vector<Player>();

	for (unsigned int counter = 0; counter < players.size(); counter++) {

		copiedPlayers->push_back(players[counter]);

	}

	QuickSortByPoints(copiedPlayers, 0, copiedPlayers->size() - 1);

	return CopyReversedAndSortByPenaltyPoints(copiedPlayers);
}

void Service::QuickSortByPoints(std::vector<Player> *players, int left,
	int right) {

	int i = left, j = right;

	Player tmp;

	int pivot = (*players)[(left + right) / 2].GetPoints();

	while (i <= j) {

		while ((*players)[i].GetPoints() < pivot)

			i++;

		while ((*players)[j].GetPoints() > pivot)

			j--;

		if (i <= j) {

			tmp = (*players)[i];

			(*players)[i] = (*players)[j];

			(*players)[j] = tmp;

			i++;

			j--;

		}

	};

	if (left < j)

		QuickSortByPoints(players, left, j);

	if (i < right)

		QuickSortByPoints(players, i, right);

}

void Service::QuickSortByPenaltyPoints(std::vector<Player> *players, int left,
	int right) {

	int i = left, j = right;

	Player tmp;

	int pivot = (*players)[(left + right) / 2].GetPenaltyPoints();

	while (i <= j) {

		while ((*players)[i].GetPenaltyPoints() < pivot)

			i++;

		while ((*players)[j].GetPenaltyPoints() > pivot)

			j--;

		if (i <= j) {

			tmp = (*players)[i];

			(*players)[i] = (*players)[j];

			(*players)[j] = tmp;

			i++;

			j--;

		}

	};

	if (left < j)

		QuickSortByPenaltyPoints(players, left, j);

	if (i < right)

		QuickSortByPenaltyPoints(players, i, right);

}

std::vector<Player>Service::Copy(std::vector<Player> *players) {
	std::vector<Player>resultList;
	for (unsigned int counter = 0; counter < players->size(); counter++) {

		resultList.push_back((*players)[counter]);

	}
	return resultList;
}

std::vector<Player>Service::CopyReversed(std::vector<Player> *players) {
	std::vector<Player>resultList;
	int size = players->size() - 1;
	for (int counter = size; counter >= 0; counter--) {

		resultList.push_back((*players)[counter]);

	}
	return resultList;

}

std::vector<Player>Service::CopyReversedAndSortByPenaltyPoints
	(std::vector<Player> *players) {
	std::vector<Player>resultList;
	std::vector<Player> *equalPlayers = new std::vector<Player>();
	int size = players->size() - 1;
	for (int counter = size; counter >= 0; counter--) {
			  int equalPlayersSize =  equalPlayers->size()           ;
		if (equalPlayersSize == 0) {
			equalPlayers->push_back((*players)[counter]);
		}
		else {
			int points = (*players)[counter].GetPoints();
			int pointsPrevious = equalPlayers->back().GetPoints();
			if (points == pointsPrevious) {
				equalPlayers->push_back((*players)[counter]);
			}
			else {
				if (equalPlayers->size() > 1) {
					QuickSortByPenaltyPoints(equalPlayers, 0,
						equalPlayers->size() - 1);
					for (unsigned int i = 0; i < equalPlayers->size(); i++) {
						resultList.push_back((*equalPlayers)[i]);
					}
				}
				else {
					resultList.push_back((*equalPlayers)[0]);
				}

				equalPlayers->clear();
				equalPlayers->push_back((*players)[counter]);
			}

		}

	}

	if (equalPlayers->size() > 0) {
		if (equalPlayers->size() > 1) {
			QuickSortByPenaltyPoints(equalPlayers, 0, equalPlayers->size() - 1);
			for (unsigned int i = 0; i < equalPlayers->size(); i++) {
				resultList.push_back((*equalPlayers)[i]);
			}
		}
		else {
			resultList.push_back((*equalPlayers)[0]);
		}
	}

	return resultList;

}

// bool Service::IsFileSet() {
// string fileName = ListRepository::GetFileName();
//
// return fileName != "";
// }
