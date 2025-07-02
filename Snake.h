#pragma once
#include <queue>

class Snake
{
public:
	Snake(int, int);
	enum class Route {down, left, up, right};//направление движения головы
	void addTail(int, int);//добавление тела
	std::pair <int, int> getTail();//получить хвост
	std::pair <int, int> getTailT();
	Route getRoute();//получить направление головы
	void addRoute(Route&);//установить направление головы
	std::pair<int,int> getHead();//полчить координаты головы
	void addHead(int, int);//установить координаты головы

private:
	std::queue < std::pair<int, int>> tail;//тело змеи
	Route route{};//напрваление головы
	std::pair<int, int> head;//местоположение головы на поле
};