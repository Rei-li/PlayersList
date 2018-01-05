//---------------------------------------------------------------------------

#ifndef ListRepositoryH
#define ListRepositoryH
//---------------------------------------------------------------------------
#endif

#include <string>
#include <vector>
#include "PlayerModel.h"
#pragma once

class ListRepository {
	std::string _fileName;
	std::vector<Player>_players;

public:
	ListRepository();
	ListRepository(std::string fileName);
	void GetData();
	void AddRecord(Player player);
	void DeleteRecord(int id);
	void UpdateRecord(Player updatedPlayer);
	std::vector<Player>GetRecords();
	std::string GetFileName();
	~ListRepository();

private:
	std::string TrimString(std::string const& str);
};