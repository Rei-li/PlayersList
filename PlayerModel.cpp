//---------------------------------------------------------------------------

#pragma hdrstop

#include "PlayerModel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



Player::Player()
{
}

Player::Player(int id, std::string name, std::string club, std::string role, int points, int penaltyPoints)
{
	_id = id;
	_name = name;
	_club = club;
	_role = role;
	_points = points;
	_penaltyPoints = penaltyPoints;
}

Player::Player(std::string name, std::string club, std::string role, int points, int penaltyPoints)
{
	_name = name;
	_club = club;
	_role = role;
	_points = points;
	_penaltyPoints = penaltyPoints;
}

int Player::GetId()
{
	return _id;
}

void Player::SetId(int id)
{
	_id = id;
}

std::string Player::ToString()
{
	return std::string(std::to_string(_id) + ", " + _name + ", " + _club + ", " + _role + ", " + std::to_string( _points ) + ", " + std::to_string(_penaltyPoints));
}

Player::~Player()
{
}
