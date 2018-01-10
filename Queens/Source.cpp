#include <iostream>
using namespace std;
#include<conio.h>
#include<ctime>
#include<fstream>
class Desk {
private:
	int n = 1;
	int d = 8;
	int desk[8][8] = {
		{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}
	};
public:
Desk()
{
}
void start() {
	showDesk();
	solve();
}
void showDesk() {
	system("cls");
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			cout << '[' << desk[i][j] << ']';
		}
		cout << endl;
	}
}

int setQueen(int a, int b) {
	if (desk[a][b] == 0) {
		for (int i = 0; i < d; i++) {
				desk[a][i] = n;
		}
		for (int i = 0; i < d; i++) {
				desk[i][b] = n;
		}
		for (int i = a, j = b; i < d&j < d; i++, j++) {
			desk[i][ j] = n;
		}
		for (int i = a, j = b; i >= 0&j < d; i--, j++) {
			desk[i][j] = n;
		}
		for (int i = a, j = b; i >= 0&j >= 0; i--, j--) {
			desk[i][j] = n;
		}
		for (int i = a, j = b; i < d&j >= 0; i++, j--) {
			desk[i][j] = n;
		}
		desk[a][b] = 8;
	}
	
	else {
		return -1;
	
	}	showDesk();
}
~Desk()
{
}
void solve() {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			desk[i][j] = 0;
		}
	}
	int a, b;
	bool ch = false;
	srand(time(0));
	while (!ch) {
		a = rand() % (d - 1);
		b = rand() % (d - 1);
		ch = true;
		if (desk[a][b] == 0) {
			setQueen(a, b);
			ch = false;
		} 
		if (ch) {
			for (int i = 0; i < d; i++) {
				for (int j = 0; j < d; j++) {
					if (desk[i][j] == 0) {
						setQueen(i, j);
						ch = false;
						break;
					}
				}
				if (!ch)
					break;
			}
		}
	}

	cout << "Solved. Again? 1 - Yes // 2 - No(Exit) ";
	exportSolution();
	int ch1 = _getch();
	switch (ch1) {
	case 49:
		solve();
		break;
	case 50	:
		return;
		break;
	}
}
void solveNew() {
	while (true) {
		int a, b;
		a =(int) rand() % 7;
		b =(int) rand() % 7;
		cout << endl << a << ' ' << b;
		_getch();
		setQueen(a, b);
		_getch();
		
	}
}
void exportSolution() {
	ofstream fout("solution.txt");
	fout << d << '\n';
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			fout << desk[i][j] << ' ';
		}
		fout << '\n';
	}
}
};


int main() {
	srand(time(0));
	Desk desk;
	desk.start();
	return 0;
}