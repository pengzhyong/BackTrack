// 回溯法之骑士巡游.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定nxn方格，按照马走日字的方式，让骑士不重复的走完所有格子，给出可行解总数和解的具体值
//解的形式：每一个方格表示第几步
//左上角为坐标原点
#include <iostream>
#include<stack>
using namespace std;

#define MAXSIZE 10
int chess[MAXSIZE][MAXSIZE];//棋盘格，元素为步数
int n = 5;//棋盘格尺寸
int steps = 0;//步数
int nSolutions = 0;//解个数
double total_bt_times = 0;
bool Place(int x, int y, int direct, int& nextX, int& nextY) {//判断指定方向是否可行
	int x1, y1;
	switch (direct)
	{
	case 1:
		x1 = x + 2;
		y1 = y + 1;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;
	case 2:
		x1 = x + 1;
		y1 = y + 2;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)//chess==0表示尚未走过
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;

	case 3:
		x1 = x - 1;
		y1 = y + 2;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;

	case 4:
		x1 = x - 2;
		y1 = y + 1;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;

	case 5:
		x1 = x - 2;
		y1 = y - 1;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;

	case 6:
		x1 = x - 1;
		y1 = y - 2;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;

	case 7:
		x1 = x + 1;
		y1 = y - 2;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;

	case 8:
		x1 = x + 2;
		y1 = y - 1;
		if (x1 < n&&x1 >= 0 && y1 < n&&y1 >= 0 && chess[x1][y1] == 0)
		{
			nextX = x1;
			nextY = y1;
			return true;
		}
		break;

	default:
		break;
	}
	return false;
}
void BackTrack(int x, int y) {
	if (steps >= n * n){
		cout << "Solution " << nSolutions++ << ": " << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cout << chess[i][j] << "	";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	else {
		for (int d = 1; d <= 8; d++) {
			int nextX, nextY;
			bool OK = Place(x, y, d, nextX, nextY);
			if (OK) {
				steps++;
				chess[nextX][nextY] = steps;
				BackTrack(nextX, nextY);
				chess[nextX][nextY] = 0;
				steps--;
				total_bt_times++;
			}
		}
	}
}

int main() {
	n = 5;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			chess[i][j] = 0;
	int initX = 2;
	int initY = 2;
	chess[initX][initY] = 1;
	steps = 1;
	BackTrack(initX, initY);
	cout << "total_backtrack_times: " << total_bt_times << endl;
	system("pause");
	return 0;
}

