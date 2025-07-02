#pragma once
#include "Snake.h"
#include <vector>
#include <set>

class Board
{
public:
	static const int WIDTH = 20;//������
	static const int HEIGHT = 10;//������
	Board();//����������� ����
	void draw();//��������� ����
	void movement(Snake&);//�������� ����(����� �������)
	bool isCollision(Snake&);//�������� �� ������������
	bool outBorders(Snake&);//�������� ������ �� �������
	void updateHead(Snake&);//���������� ��������� ������ ��� ��������
	void clearSlot(Snake&);//���������� ��������� ����(������� ���������� ������, ���������� ���������� ������), ��� �������� �����
	int sizeSlot();//���������� ��������� ������ ��� �������� �����
	std::pair <int, int> backSlot(int);//����������� ������ ��� �������� � ��� �����
	void addCheckCoin();//��������� ����� ������������� �����
	bool getCheckCoin();//��������� ����� � ������������� �����
	void addGrid(std::pair<int, int>, int);//���������� � ���� ���������(��������� � �������)
	int getScore();//����� �����
	void addScore();//���������� �����

private:
	bool givCoin{ true };//���� ������������� �����
	int score{};//����
	std::set < std::pair<int, int>> slot;//��������� ������ ��� �������� �����
	std::vector <std::vector<int>> grid;//0-��������� ������, 1-���� ��� ��������, 2-���� ����
};