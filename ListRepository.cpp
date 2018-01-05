//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListRepository.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListRepository::ListRepository() {
	_fileName = std::string();
}

ListRepository::ListRepository(std::string fileName) {
	_fileName = fileName;
}

void ListRepository::GetData() {
}

void ListRepository::AddRecord(Player player) {
}

void ListRepository::DeleteRecord(int id) {
}

void ListRepository::UpdateRecord(Player updatedPlayer) {
}

std::vector<Player>ListRepository::GetRecords() {
	return _players;
}

std::string ListRepository::GetFileName() {
	return _fileName;
}

ListRepository::~ListRepository() {
}

std::string ListRepository::TrimString(std::string const& str) {
	return std::string();
}