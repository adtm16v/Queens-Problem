#pragma once
class Desk
{
public:
	int d = 8;
	int **desk = new int*[d];
public:
	void start();
	Desk();
	~Desk();
	int setQueen(int a,int b);
	void deleteQueen(int a, int b);
	void showDesk();
};

