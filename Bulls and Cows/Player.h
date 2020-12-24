#pragma once

#include <iostream>
#include <locale.h>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

class Player
{
private:
	string name;
	vector<string> history;
	int secret[4];
public:
	bool win; //0 - не выиграл

	Player();
	void SetName();
	string GetName();
	void SetSecret();
	void NextPlayer();
	void ShowHistory();
	void Guess(Player second);
};