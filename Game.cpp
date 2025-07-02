#include "Game.h"
#include "Board.h"
#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <random>
#include <thread>
#include <chrono>
//#include <cstdlib>

Game::Game() : snake(Board::WIDTH / 2, Board::HEIGHT / 2), isRunning (true)//создание змейки в центре
{
	board.addGrid(std::pair<int, int> (Board::WIDTH / 2, Board::HEIGHT / 2 - 1), 2);
	snake.addTail(Board::WIDTH / 2, Board::HEIGHT / 2 - 1);
	board.addGrid(std::pair<int, int>(Board::WIDTH / 2, Board::HEIGHT / 2), 2);
	snake.addTail(Board::WIDTH / 2, Board::HEIGHT / 2);
}

void Game::processInput()
{
    if (_kbhit())
    {
        char key = _getch(); //чтение лавиши с клаватуры
        Snake::Route direction = snake.getRoute();
        switch (key)
        {
        case 'a':
            if (direction != Snake::Route::right)
            {
                direction = Snake::Route::left;
                snake.addRoute(direction);
            }
        break;
        case 'd':
            if (direction != Snake::Route::left)
            {
                direction = Snake::Route::right;
                snake.addRoute(direction);
            }
        break;
        case 's':
            if (direction != Snake::Route::up)
            {
                direction = Snake::Route::down;
                snake.addRoute(direction);
            }
        break;
        case 'w':
            if (direction != Snake::Route::down)
            {
                direction = Snake::Route::up;
                snake.addRoute(direction);
            }
        break;
        case 'q': 
            isRunning = false;
            break;
        }
    }
}

void Game::update()
{
    board.updateHead(snake);
    if (board.outBorders(snake) && board.isCollision(snake))
    {
        board.movement(snake);
        if (board.getCheckCoin())
            genCoin();
    }
    else
        isRunning = false;
}

void Game::render()
{
    system("cls");
    board.draw();
    std::cout << std::endl;
    std::cout <<"Score: "<<board.getScore() << std::endl;
    std::cout << "Press 'W', 'A', 'S', 'D' for snake control." << std::endl;
    std::cout << "Press 'Q' for exit.";
}

void Game::run()
{
    char v;
    bool ok = false;
    while (!ok)
    {
        std::cout << "Select snake speed:\n";
        std::cout << "Enter '1' for normal snake speed.\n";
        std::cout << "Enter '2' for average snake speed.\n";
        std::cout << "Enter '3' for fast snake speed.\n";
        std::cout << "Enter 'q' for exit game.\n";
        std::cout << "Enter difficulty level: ";
        std::cin >> v;
        switch (v)
        {
        case '1':
            ok = true;
            break;
        case '2':
            delay -= 100;
            ok = true;
            break;
        case '3':
            delay -= 200;
            ok = true;
            break;
        case 'q':
            isRunning = false;
            ok = true;
            break;
        default:
            std::cout << "The command entered was not recognized.\n";
            std::cout << "Please re-enter.\n";
            system("pause");
            break;
        }
        system("cls");
    }
    while (isRunning)
    {
        processInput();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // «адержка
    }
}

void Game::genCoin()
{
    int m;
    std::random_device rd;//создание источника энтропии
    std::mt19937 gen(rd());//инициализаци€ генератора случайных чисел
    std::uniform_int_distribution<> dist(0, board.sizeSlot()-1);//равномерное распределение от 0 до 6
    m = dist(gen);
    board.addGrid(board.backSlot(m),1);
    board.addCheckCoin();
}

