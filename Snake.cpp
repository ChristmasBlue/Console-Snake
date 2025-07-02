#include "Snake.h"

Snake::Snake(int x, int y)
{
	head.first = x;
	head.second = y;
}

void Snake::addTail(int x, int y)
{
	tail.push(std::pair<int, int> {x, y});
}

Snake::Route Snake::getRoute()
{
	return route;
}

void Snake::addRoute(Snake::Route& t)
{
	route = t;
}

std::pair<int,int> Snake::getHead()
{
	return head;
}

void Snake::addHead(int x, int y)
{
	head.first = x;
	head.second = y;
}

std::pair <int, int> Snake:: getTail()
{
	std::pair <int, int> tailt = tail.front();
	tail.pop();
	return tailt;
}

std::pair <int, int> Snake :: getTailT()
{
	return tail.front();
}