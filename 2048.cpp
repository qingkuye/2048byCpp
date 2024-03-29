// 2048.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
string str[12] = {
	"    ",
	"   2",
	"   4",
	"   8",
	"  16",
	"  32",
	"  64",
	" 128",
	" 256",
	" 512",
	"1024",
	"2048"
};//Used to display
int data[4][4];//Used to storage;
void show();//To show the result;
void routine();//To move the data;
void refresh();//To add the number in space area;
int check();//To check the game is over or complete;
int main()
{
	//Initialization;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			::data[i][j] = rand() % 100 < 10;
		}
	}
	//Begin the game;
	show();
	cout << "w:up  s:down  a:left  d:right  q:quit"<<endl;
	while (1)
	{
		//Move
		routine();
		//Check;
		if (check() != 0)
			break;
		cout << "w:up  s:down  a:left  d:right  q:quit"<<endl;
	}
	return 0;
}
void show()
{
	//To show the game;
	for (int i = 0; i < 4; i++)
	{
		cout << "|";
		for (int j = 0; j < 4; j++)
		{
			cout << str[::data[i][j]] << "|";
		}
		cout << endl;
		cout << "----------------------" << endl;
	}
}
void routine()
{
	//To move;
	int tmp[4] = { 0,0,0,0 };
	int n = 0;
	char command='/0';
	cin >> command;
	//When going up;
	if (command == 'w')
	{
		for (int i = 0; i < 4; i++)
		{
			n = 0;
			//Move the data to one direct;
			for (int j = 0; j < 4; j++)
			{
				if (::data[j][i] > 0)
				{
					tmp[n]= ::data[j][i];
					n++;
				}
			}
			//Merge same data;
			for (int j = 0; j < 3; j++)
			{
				if (tmp[j]==tmp[j+1]&& tmp[j]!=0)
				{
					tmp[j]++;
					tmp[j + 1] = 0;
				}
			}
			//Move the data to one direct again;
			n = 0;
			for (int j = 0; j < 4; j++)
			{
				if (tmp[j] > 0)
				{
					tmp[n] = tmp[j];
					n++;
				}
				
			}
			for (int m = n; m < 4; m++)
				tmp[m] = 0;
			//Save the result;
			for (int j = 0; j < 4; j++)
			{
				::data[j][i] = tmp[j];
				tmp[j] = 0;
			}
		}
		//Refresh
		refresh();
	}else if (command == 's')//When going down;
	{
		for (int i = 0; i < 4; i++)
		{
			n = 0;
			//Move the data to one direct;
			for (int j = 0; j < 4; j++)
			{
				if (::data[3-j][i] > 0)
				{
					tmp[n] = ::data[3-j][i];
					n++;
				}
			}
			//Merge same data;
			for (int j = 0; j < 3; j++)
			{
				if (tmp[j] == tmp[j + 1] && tmp[j] != 0)
				{
					tmp[j]++;
					tmp[j + 1] = 0;
				}
			}
			//Move the data to one direct again;
			n = 0;
			for (int j = 0; j < 4; j++)
			{
				if (tmp[j] > 0)
				{
					tmp[n] = tmp[j];
					n++;
				}
				
			}
			for (int m = n; m < 4; m++)
				tmp[m] = 0;
			//Save the result;
			for (int j = 0; j < 4; j++)
			{
				::data[j][i] = tmp[3-j];
				tmp[3-j] = 0;
			}
		}
		//Refresh
		refresh();
	}
	else if (command == 'a')
	{
		for (int i = 0; i < 4; i++)
		{
			n = 0;
			//Move the data to one direct;
			for (int j = 0; j < 4; j++)
			{
				if (::data[i][j] > 0)
				{
					tmp[n] = ::data[i][j];
					n++;
				}
			}
			//Merge same data;；
			for (int j = 0; j < 3; j++)
			{
				if (tmp[j] == tmp[j + 1] && tmp[j] != 0)
				{
					tmp[j]++;
					tmp[j + 1] = 0;
				}
			}
			//Move the data to one direct again;
			n = 0;
			for (int j = 0; j < 4; j++)
			{
				if (tmp[j] > 0)
				{
					tmp[n] = tmp[j];
					n++;
				}
				
			}
			for (int m = n; m < 4; m++)
				tmp[m] = 0;
			//Save the result;
			for (int j = 0; j < 4; j++)
			{
				::data[i][j] = tmp[j];
				tmp[j] = 0;
			}
		}
		//Refresh
		refresh();
	}
	else if (command == 'd')
	{
		for (int i = 0; i < 4; i++)
		{
			n = 0;
			//Move the data to one direct;
			for (int j = 0; j < 4; j++)
			{
				if (::data[i][3 - j] > 0)
				{
					tmp[n] = ::data[i][3 - j];
					n++;
				}
			}
			//Merge same data;
			for (int j = 0; j < 3; j++)
			{
				if (tmp[j] == tmp[j + 1] && tmp[j] != 0)
				{
					tmp[j]++;
					tmp[j + 1] = 0;
				}
			}
			//Move the data to one direct again;
			n = 0;
			for (int j = 0; j < 4; j++)
			{
				if (tmp[j] > 0)
				{
					tmp[n] = tmp[j];
					n++;
				}
			}
			for (int m = n; m < 4; m++)
				tmp[m] = 0;
			//Save the result;
			for (int j = 0; j < 4; j++)
			{
				::data[i][j] = tmp[3 - j];
				tmp[3 - j] = 0;
			}
		}
		//Refresh
		refresh();
	}
	else return;
	show();
}
void refresh()//Refresh the data;
{
	int n = 0;
	//Get the space areas number;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (::data[i][j] == 0)
				n++;
		}
	}
	////Add the number in rand space area;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (::data[i][j] == 0)
			::data[i][j] = rand() % n < 2;
		}
	}
}
int check()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//When you win the game;
			if (::data[i][j] == 11)
			{
				cout << "You Win!"<<endl;
				return 1;

			}
			else if (::data[i][j] == 0)
			{
				return 0;
			}
				
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (::data[i][j]!=0&&(::data[i][j] == ::data[i][j+1]|| ::data[j][i] == ::data[j+1][i]))
				return 0;
		}
	}
	//When you lost the game;
	cout << "Game Over!" << endl;
	return 1;

}