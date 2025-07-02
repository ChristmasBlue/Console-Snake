#pragma once
#include "Board.h"
#include "Snake.h"


class Game
{
public:
	Game();//конструктор игры
	void run();//время жизни программы

private:
	void processInput();//ввод с клавиатуры
	void update();//обновлениевсех параметров
	void render();//отрисовка игры
	void genCoin();//генерация коина

	Board board;//поле
	Snake snake;//змея
	bool isRunning;//флаг времени жизни программы
	int delay=300;//задержка отрисовки
};