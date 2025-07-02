#include "Board.h"
#include "Snake.h"
#include <iostream>
#include <queue>


Board::Board() : grid(HEIGHT, std::vector<int>(WIDTH, 0)) 
{
	for (int ny{}; ny < Board::HEIGHT; ny++)
		for (int nx{};nx < Board::WIDTH;nx++)
			slot.insert(std::pair<int, int>(nx, ny));
	slot.erase(std::pair <int, int>(Board::WIDTH / 2, Board::HEIGHT / 2 - 1));
	slot.erase(std::pair <int, int>(Board::WIDTH / 2, Board::HEIGHT / 2));
}

void Board::draw()
{
	for (int ty{}; ty < HEIGHT; ty++)
	{
		for (int tx{}; tx < WIDTH; tx++)
		{
			if (grid[ty][tx] == 0)//свободная клетка
				std::cout << " ";
			if (grid[ty][tx] == 1)//коин
				std::cout << "@";
			if (grid[ty][tx] == 2|| grid[ty][tx] == 3)//тело змеи
					std::cout << "#";
		}
		std::cout << "|" << std::endl;
	}
	for (int i{}; i < WIDTH; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void Board::addGrid(std::pair<int, int> p, int element)
{
	grid[p.second][p.first] = element;
}

void Board::movement(Snake& snake)
{
	std::pair<int, int> tailt{snake.getTailT()};
	std::pair<int, int> head{snake.getHead()};
	switch (snake.getRoute())
	{
	case Snake::Route:: down:
		snake.addTail(head.first, head.second);
		grid[head.second][head.first] += 2;
		if (grid[head.second][head.first] != 3)
		{
			grid[tailt.second][tailt.first] = 0;
			clearSlot(snake);
		}
		else
		{
			slot.erase(head);
			givCoin = true;
			addScore();
		}
		break;
	case Snake::Route:: left:
		snake.addTail(head.first, head.second);
		grid[head.second][head.first] += 2;
		if (grid[head.second][head.first] != 3)
		{
			grid[tailt.second][tailt.first] = 0;
			clearSlot(snake);
		}
		else
		{
			slot.erase(head);
			givCoin = true;
			addScore();
		}
		break;
	case Snake::Route:: up:
		snake.addTail(head.first, head.second);
		grid[head.second][head.first] += 2;
		if (grid[head.second][head.first] != 3)
		{
			grid[tailt.second][tailt.first] = 0;
			clearSlot(snake);
		}
		else
		{
			slot.erase(head);
			givCoin = true;
			addScore();
		}
		break;
	case Snake::Route:: right:
		snake.addTail(head.first, head.second);
		grid[head.second][head.first] += 2;
		if (grid[head.second][head.first] != 3)
		{
			grid[tailt.second][tailt.first] = 0;
			clearSlot(snake);
		}
		else
		{
			slot.erase(head);
			givCoin=true;
			addScore();
		}
		break;
	}
}

bool Board::isCollision(Snake& snake)
{
	std::pair<int, int> head{ snake.getHead() };
	if ((grid[head.second][head.first] + 2 ) >= 4)
		return false;
	return true;
}

bool Board::outBorders(Snake& snake)
{
	std::pair<int, int> head = snake.getHead();
	if (head.first >= WIDTH || head.first < 0 || head.second < 0 || head.second >= HEIGHT)
		return false;
	return true;
}

void Board::updateHead(Snake& snake)
{
	std::pair<int, int> head{ snake.getHead() };
	switch (snake.getRoute())
	{
	case Snake::Route::down:
		snake.addHead(head.first, head.second+1);
		break;
	case Snake::Route::left:
		snake.addHead(head.first-1, head.second);
		break;
	case Snake::Route::up:
		snake.addHead(head.first, head.second-1);
		break;
	case Snake::Route::right:
		snake.addHead(head.first+1, head.second);
		break;
	}
}

void Board::clearSlot(Snake& snake)
{
	slot.insert(snake.getTail());
	slot.erase(snake.getHead());
}

int Board::sizeSlot()
{
	return slot.size();
}

std::pair <int, int> Board::backSlot(int el)
{
	std::set<std::pair <int, int>>::iterator it = slot.begin();
	for (int i{}; i < el;i++)
		it++;
	return *it;
}

bool Board::getCheckCoin()
{
	return givCoin;
}

void Board::addCheckCoin()
{
	givCoin = false;
}

void Board::addScore()
{
	score++;
}

int Board::getScore()
{
	return score;
}