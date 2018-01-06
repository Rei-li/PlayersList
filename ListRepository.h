// ---------------------------------------------------------------------------

#ifndef ListRepositoryH
#define ListRepositoryH
// ---------------------------------------------------------------------------
#endif

#include <string>
#include <vector>
#include "PlayerModel.h"
#pragma once

class ListRepository {
	static std::string _fileName;
	static std::vector<Player>_players;

public:

	static void SetFile(std::string fileName);
	static void LoadData();
	static void AddRecord(Player player);
	static void DeleteRecord(int id);
	static Player GetRecord(int id);
	static void UpdateRecord(Player updatedPlayer);
	static std::vector<Player>GetRecords();

private:
	static std::string TrimString(std::string const & str);
};
