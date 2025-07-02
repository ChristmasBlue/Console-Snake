#pragma once
#include "Snake.h"
#include <vector>
#include <set>

class Board
{
public:
	static const int WIDTH = 20;//ширина
	static const int HEIGHT = 10;//высота
	Board();//конструктор поля
	void draw();//отрисовка поля
	void movement(Snake&);//движение змеи(через очередь)
	bool isCollision(Snake&);//проверка на столкновение
	bool outBorders(Snake&);//проверка выхода за границы
	void updateHead(Snake&);//обновление координат головы для проверки
	void clearSlot(Snake&);//добавление координат змеи(очистка координаты хвоста, добавление координаты головы), для создания коина
	int sizeSlot();//количество свободных клеток для создания коина
	std::pair <int, int> backSlot(int);//возвращение клетки для создания в ней коина
	void addCheckCoin();//изменение флага существования коина
	bool getCheckCoin();//получение флага о существовании коина
	void addGrid(std::pair<int, int>, int);//добавление в поле координат(свободных и занятых)
	int getScore();//вывод счёта
	void addScore();//увеличение счёта

private:
	bool givCoin{ true };//флаг существования коина
	int score{};//счёт
	std::set < std::pair<int, int>> slot;//свободные клетки для создания коина
	std::vector <std::vector<int>> grid;//0-свободная клетка, 1-коин для схедения, 2-тело змеи
};