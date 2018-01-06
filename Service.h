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
    static std::vector<Player>GetRecords();
	static void SavePlayer(std::string id, std::string name, std::string club, std::string role, std::string points, std::string penaltyPoints);
//	static bool IsFileSet();
};
