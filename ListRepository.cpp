// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ListRepository.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

std::string ListRepository::_fileName = "test.txt";
std::vector<Player>ListRepository::_players;

void ListRepository::SetFile(std::string fileName) {
	_fileName = fileName;
}

void ListRepository::LoadData() {
	string line;
	string text;
	int counter = 0;
	ifstream myfile(_fileName);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			text = text + line + ";";
			counter++;
		}
		myfile.close();
	}

	std::vector<Player>timetableData;
	counter = 0;

	std::stringstream fullData(text);
    _players.clear();
	while (getline(fullData, line, ';')) {
		string subString;
		std::stringstream busStringfullData(line);
		string* playerFields = new string[6];
		int i = 0;
		while (getline(busStringfullData, subString, ',')) {
			string subStringTrimmed = TrimString(subString);
			playerFields[i] = subStringTrimmed;
			i++;
		}

		std::string id = playerFields[0];
		std::string name = playerFields[1];
		std::string club = playerFields[2];
		std::string role = playerFields[3];
		std::string points = playerFields[4];
		std::string penaltyPoints = playerFields[5];

		Player player(stoi(id), name, club, role, stoi(points),
			stoi(penaltyPoints));
		_players.push_back(player);
	}
}

void ListRepository::AddRecord(Player player) {
	if (!_players.empty()) {
		Player lastPlayer = _players.back();
		int lastPlayerId = lastPlayer.GetId();
		player.SetId(lastPlayerId + 1);
	}
	else {
		player.SetId(1);
	}

	_players.push_back(player);

	std::string pl = player.ToString();

	std::ofstream out;
	out.open(_fileName, std::ios::app);
	out << player.ToString() << endl;
	out.close();
}

void ListRepository::DeleteRecord(int id) {
}

void ListRepository::UpdateRecord(Player updatedPlayer) {

	vector<Player>updatedPlayersList;
	std::ofstream ofs;
	ofs.open(_fileName, std::ofstream::out | std::ofstream::trunc);
	for (unsigned int counter = 0; counter < _players.size(); counter++) {
		if (_players[counter].GetId() != updatedPlayer.GetId()) {
			updatedPlayersList.push_back(_players[counter]);
			ofs << _players[counter].ToString() << endl;
		}
		else {
			updatedPlayersList.push_back(updatedPlayer);
			ofs << updatedPlayer.ToString() << endl;
		}
	}
	ofs.close();
	_players.swap(updatedPlayersList);

}

std::vector<Player>ListRepository::GetRecords() {
	return ListRepository::_players;
}

std::string ListRepository::TrimString(std::string const & str) {
	if (str.empty())
		return str;

	std::size_t firstScan = str.find_first_not_of(' ');
	std::size_t first = firstScan == std::string::npos ? str.length() :
		firstScan;
	std::size_t last = str.find_last_not_of(' ');
	return str.substr(first, last - first + 1);
}
