// ---------------------------------------------------------------------------

#ifndef ServiceH
#define ServiceH
// ---------------------------------------------------------------------------
#endif

#include <string>
#include <vector>
#include "ListRepository.h"
#include "PlayerModel.h"

#pragma once

class Service {

public:
	static void SetFile(std::string fileName);
	static void LoadData();
	static void DeleteRecord(std::string id);
	static Player GetRecord(int id);
	static std::vector<Player>GetRecords();
	static void SavePlayer(std::string id, std::string name, std::string club,
		std::string role, std::string points, std::string penaltyPoints);
	static std::vector<Player>GetSortedListByPoints();
	static std::vector<Player>GetSortedListByPenaltyPoints();
	static std::vector<Player>GetBestPlayersList();
	// static bool IsFileSet();

private:
	static void QuickSortByPoints(std::vector<Player> *players, int left,
		int right);
	static void QuickSortByPenaltyPoints(std::vector<Player> *players, int left,
		int right);
	static std::vector<Player>Service::Copy(std::vector<Player> *players);
	static std::vector<Player>Service::CopyReversed
		(std::vector<Player> *players);
	static std::vector<Player>CopyReversedAndSortByPenaltyPoints
		(std::vector<Player> *players);
};
