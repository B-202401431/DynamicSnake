#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "snake.h"
#include "food.h"
#include "cord.h"

using namespace std;

int score = 0;
cord snake_pos(width / 2, height / 2);
cord food_pos;
Snake snake(snake_pos, 1);
Food food;
bool gameover = false;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

// Color definitions
#define WHITE 15
#define GREEN 10
#define RED 12
#define YELLOW 14
#define BLUE 9

// Function to set cursor position (removes blinking effect)
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

// Function to set text color
void setColor(int color)
{
    SetConsoleTextAttribute(console, color);
}

// Function to draw the game board
void board()
{
    gotoxy(0, 0); // Reset cursor position to avoid screen flickering
    snake_pos = snake.get_pos();
    food_pos = food.get_food_pos();
    
    setColor(YELLOW); // Set color for score
    cout << " Score : " << score << "  |  Level: " << (score / 5) + 1 << endl;
    
    vector<cord> snake_body = snake.snake_body();
    for (int i = 0; i < height; i++)
    {
        setColor(GREEN); // Set color for borders
        cout << "\t\t\t\t\t#";
        for (int j = 0; j < width - 2; j++)
        {
            if (i == 0 || i == height - 1)
            {
                setColor(GREEN);
                cout << "#";
            }
            else if (i == snake_pos.y && j + 1 == snake_pos.x)
            {
                setColor(RED); // Set color for snake head
                cout << "O"; // Snake head
            }
            else if (i == food_pos.y && j + 1 == food_pos.x)
            {
                setColor(BLUE); // Set color for food
                cout << "*"; // Food
            }
            else
            {
                bool isbodypart = false;
                for (cord part : snake_body)
                {
                    if (i == part.y && j + 1 == part.x)
                    {
                        setColor(RED); // Set color for snake body
                        cout << "o"; // Snake body
                        isbodypart = true;
                        break;
                    }
                }
                if (!isbodypart)
                {
                    setColor(WHITE); // Set color for empty space
                    cout << " ";
                }
            }
        }
        setColor(GREEN);
        cout << "#" << endl;
    }
}

// Main game loop
int main()
{
    srand(time(NULL));
    food.food_gen();
    int speed = 100; // Initial speed

    cout << "Welcome to the Snake Game!" << endl;
    cout << "Use 'WASD' or Arrow Keys to move." << endl;
    cout << "Press 'ESC' to exit the game." << endl;
    Sleep(2000);
    system("cls");

    while (!gameover)
    {
        board();

        // Capture user input
        if (kbhit())
        {
            char input = getch();
            if (input == 'w' || input == 72) snake.change_dir('u');
            else if (input == 's' || input == 80) snake.change_dir('d');
            else if (input == 'd' || input == 77) snake.change_dir('r');
            else if (input == 'a' || input == 75) snake.change_dir('l');
            else if (input == 27) gameover = true; // ESC key to exit
        }

        // Move the snake
        snake.move();

        // Check if the snake eats food
        if (snake.food_eaten(food.get_food_pos()))
        {
            food.food_gen();
            snake.length_inc();
            score++;

            // Increase speed as score increases
            speed = max(30, 100 - (score * 5));
        }

        // Check if snake collides with border
        if (snake.snake_collide_border())
        {
            gameover = true;
        }

        Sleep(speed);
    }

    // Game Over screen
    system("cls");
    setColor(RED); // Set color for game over message
    cout << "\n\n\t\tGAME OVER!\n";
    setColor(YELLOW); // Set color for final score
    cout << "\t\tFinal Score: " << score << endl;
    cout << "\t\tPress any key to exit...";
    getch();
    return 0;
}
