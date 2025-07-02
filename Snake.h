#pragma once
#include <queue>

class Snake
{
public:
	Snake(int, int);
	enum class Route {down, left, up, right};//����������� �������� ������
	void addTail(int, int);//���������� ����
	std::pair <int, int> getTail();//�������� �����
	std::pair <int, int> getTailT();
	Route getRoute();//�������� ����������� ������
	void addRoute(Route&);//���������� ����������� ������
	std::pair<int,int> getHead();//������� ���������� ������
	void addHead(int, int);//���������� ���������� ������

private:
	std::queue < std::pair<int, int>> tail;//���� ����
	Route route{};//����������� ������
	std::pair<int, int> head;//�������������� ������ �� ����
};