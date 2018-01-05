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
	ListRepository _repo;

public:
	Service();
	Service(std::string fileName);
	std::vector<Player>LoadData();
	bool IsFileSet();
};
