#pragma once
#include "Board.h"
#include "Snake.h"


class Game
{
public:
	Game();//����������� ����
	void run();//����� ����� ���������

private:
	void processInput();//���� � ����������
	void update();//�������������� ����������
	void render();//��������� ����
	void genCoin();//��������� �����

	Board board;//����
	Snake snake;//����
	bool isRunning;//���� ������� ����� ���������
	int delay=300;//�������� ���������
};