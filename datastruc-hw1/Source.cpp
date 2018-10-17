//
//  main.cpp
//  datatstructure-1
//
//  Created by kay liao on 2018/10/5.
//  Copyright © 2018 kay liao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#define row 10
#define column 10
using namespace std;

struct wordinfo
{
	char wordname;
	int r1;
	int c1;
	char up;
	int upr1;
	int upc1;
	char down;
	int downr1;
	int downc1;
	char left;
	int leftr1;
	int leftc1;
	char right;
	int rightr1;
	int rightc1;

};

class wordgame
{
public:
	wordgame() {}
	vector<wordinfo>information;
	vector<wordinfo>answer;
	void wordinit();
	void FindPattern(string patt, string reused);
	bool checkletter(int r, int c, string patt);
	bool checkfalseletter(int r, int c, string patt);
	bool ifused(int r, int c);
	void reset();

};

bool wordgame::ifused(int r, int c)
{
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i].r1 == r && answer[i].c1 == c)
		{
			i = answer.size() + 1;
			return false;
		}
	}
	return true;
}

bool wordgame::checkfalseletter(int r, int c, string patt)
{

	for (int i = 0; i < 4; i++)
	{
		if (answer.size() < patt.length())
		{
			if (i == 0)
			{
				if (information[r * row + c].up == patt[answer.size()] && ifused(information[r * row + c].upr1, information[r * row + c].upc1) == true)
				{
					wordinfo upper;
					upper.r1 = information[r * row + c].upr1;
					upper.c1 = information[r * row + c].upc1;
					answer.push_back(upper);
					checkfalseletter(upper.r1, upper.c1, patt);

				}
			}
			else if (i == 1)
			{
				if (information[r * row + c].right == patt[answer.size()] && ifused(information[r * row + c].rightr1, information[r * row + c].rightc1) == true)
				{
					wordinfo righter;
					righter.r1 = information[r * row + c].rightr1;
					righter.c1 = information[r * row + c].rightc1;
					answer.push_back(righter);
					checkfalseletter(righter.r1, righter.c1, patt);

				}
			}
			else if (i == 2)
			{
				if (information[r * row + c].left == patt[answer.size()] && ifused(information[r * row + c].leftr1, information[r * row + c].leftc1) == true)
				{
					wordinfo lefter;
					lefter.r1 = information[r * row + c].leftr1;
					lefter.c1 = information[r * row + c].leftc1;
					answer.push_back(lefter);
					checkfalseletter(lefter.r1, lefter.c1, patt);

				}
			}
			else if (i == 3)
			{
				if (information[r * row + c].down == patt[answer.size()] && ifused(information[r * row + c].downr1, information[r * row + c].downc1) == true)
				{
					wordinfo downer;
					downer.r1 = information[r * row + c].downr1;
					downer.c1 = information[r * row + c].downc1;
					answer.push_back(downer);
					checkfalseletter(downer.r1, downer.c1, patt);

				}
				else
				{
					answer.pop_back();
					return false;
				}
			}

		}
		else if (answer.size() == patt.length())
		{
			return true;
		}
	}

	return false;
}

bool wordgame::checkletter(int r, int c, string patt)
{

	for (int i = 0; i < 4; i++)
	{
		if (answer.size() < patt.length())
		{
			if (i == 0)
			{
				if (information[r * row + c].up == patt[answer.size()])
				{
					wordinfo upper;
					upper.r1 = information[r * row + c].upr1;
					upper.c1 = information[r * row + c].upc1;
					answer.push_back(upper);
					checkletter(upper.r1, upper.c1, patt);

				}
			}
			else if (i == 1)
			{
				if (information[r * row + c].right == patt[answer.size()])
				{
					wordinfo righter;
					righter.r1 = information[r * row + c].rightr1;
					righter.c1 = information[r * row + c].rightc1;
					answer.push_back(righter);
					checkletter(righter.r1, righter.c1, patt);

				}
			}
			else if (i == 2)
			{
				if (information[r * row + c].left == patt[answer.size()])
				{
					wordinfo lefter;
					lefter.r1 = information[r * row + c].leftr1;
					lefter.c1 = information[r * row + c].leftc1;
					answer.push_back(lefter);
					checkletter(lefter.r1, lefter.c1, patt);

				}
			}
			else if (i == 3)
			{
				if (information[r * row + c].down == patt[answer.size()])
				{
					wordinfo downer;
					downer.r1 = information[r * row + c].downr1;
					downer.c1 = information[r * row + c].downc1;
					answer.push_back(downer);
					checkletter(downer.r1, downer.c1, patt);

				}
				else
				{
					answer.pop_back();
					return false;
				}
			}

		}
		else if (answer.size() == patt.length())
		{
			return true;
		}
	}

	return false;
}


void wordgame::FindPattern(string patt, string reused)
{
	if (reused == "TRUE")
	{
		for (int i = 0; i < information.size(); i++)
		{
			if (information[i].wordname == patt[0])
			{
				wordinfo a;
				a.r1 = information[i].r1;
				a.c1 = information[i].c1;
				answer.push_back(a);
				bool check = checkletter(information[i].r1, information[i].c1, patt);
				if (check == true && answer.size() == patt.length())
				{

					for (int k = 0; k < answer.size(); k++)
					{
						cout << "(" << answer[k].r1 << "," << answer[k].c1 << ")";
					}
					cout << endl;
					i = row * column + 1;
				}
				else
				{
					answer.clear();
				}
			}

		}
		if (answer.size() != patt.length())
		{
			cout << "no match" << endl;
		}
	}
	else if (reused == "FALSE")
	{
		for (int i = 0; i < information.size(); i++)
		{
			if (information[i].wordname == patt[0])
			{
				wordinfo a;
				a.r1 = information[i].r1;
				a.c1 = information[i].c1;
				answer.push_back(a);
				bool check = checkfalseletter(information[i].r1, information[i].c1, patt);
				if (check == true && answer.size() == patt.length())
				{

					for (int k = 0; k < answer.size(); k++)
					{
						cout << "(" << answer[k].r1 << "," << answer[k].c1 << ")";
					}
					cout << endl;
					i = row * column + 1;
				}
				else
				{
					answer.clear();
				}
			}

		}
		if (answer.size() != patt.length())
		{
			cout << "no match" << endl;
		}
	}
	else
	{
		cout << "THE REUSED TYPE IS NOT DEFINED" << endl;
	}
}

void wordgame::reset()
{
	answer.clear();
}

void wordgame::wordinit()
{
	char c;
	cout << "enter characters." << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> c;
			wordinfo a;
			a.wordname = c;
			a.r1 = i;
			a.c1 = j;

			information.push_back(a);
		}
	}



	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{

			if (i > 0)
			{
				information[i * row + j].up = information[i * row + j - row].wordname;
				information[i * row + j].upr1 = information[i * row + j - row].r1;
				information[i * row + j].upc1 = information[i * row + j - row].c1;
			}
			if (i < row - 1)
			{
				information[i * row + j].down = information[i * row + j + row].wordname;
				information[i * row + j].downr1 = information[i * row + j + row].r1;
				information[i * row + j].downc1 = information[i * row + j + row].c1;
			}
			if (j>0)
			{
				information[i *row + j].left = information[i * row + j - 1].wordname;
				information[i *row + j].leftr1 = information[i * row + j - 1].r1;
				information[i * row + j].leftc1 = information[i *row + j - 1].c1;
			}
			if (j< column - 1)
			{
				information[i * row + j].right = information[i *row + j + 1].wordname;
				information[i *row + j].rightr1 = information[i * row + j + 1].r1;
				information[i *row + j].rightc1 = information[i * row + j + 1].c1;
			}
		}
	}
}

int main()
{
	string patt;
	string reused;
	wordgame game;

	game.wordinit();

	while (1)
	{
		cout << "enter pattern" << endl;
		cin >> patt;
		cout << "enter reused type" << endl;
		cin >> reused;
		while (patt.size()>10)
		{
			cout << "THE PATTERN CANNOT MORE THAN 10 LETTERS." << endl;
			cout << "PLEASE RE-ENTER" << endl;
			cin >> patt;
		}

		game.FindPattern(patt, reused);
		game.reset();
	}
	return 0;
}