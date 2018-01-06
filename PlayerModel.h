//---------------------------------------------------------------------------

#ifndef PlayerModelH
#define PlayerModelH
//---------------------------------------------------------------------------
#endif

#include <string>

#pragma once

class Player
{
	int _id, _points, _penaltyPoints;
	std::string _name, _club, _role;
public:
	Player::Player();
	Player(int id, std::string name, std::string club, std::string role, int points, int penaltyPoints);
	Player(std::string name, std::string club, std::string role, int points, int penaltyPoints);
	int GetId();
	int GetPoints();
	int GetPenaltyPoints();
	std::string GetName();
	std::string GetClub();
	std::string GetRole();
	void SetId(int id);
	std::string ToString();
	~Player();
};