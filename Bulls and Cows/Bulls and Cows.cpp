#include "Player.h"

using namespace std;

void BullsAndCows();

int main()
{
    setlocale(LC_ALL, "Russian");

    string main;
    do
    {

        cout << "БЫКИ И КОРОВЫ\n";
        cout << "[1] - Новая игра.\n";
        cout << "[2] - Выход.\n";
        getline(cin, main);
        if ((main == "1")||(main=="start")||(main=="replay")||(main=="new"))
        {
            system("cls");
            BullsAndCows();
        }
        else if ((main == "2")||(main=="exit")||(main=="quit"))
        {
            cout << "Выход.\n";
        }
        else
        {
            system("cls");
            cout << "Неправильный ввод\n";
        }
    } while ((main != "2") && (main != "exit") && (main != "quit"));

    return 0;
}

void BullsAndCows()
{
    int d;
    Player player1, player2;

    cout << "Игрок 1, введите имя: ";
    player1.SetName();
    system("cls");
    cout << "Игрок 2, введите имя: ";
    player2.SetName();
    player1.NextPlayer();
    cout << player1.GetName() << "\n";
    cout << "Введите 4-х значное число с неповторяющимися цифрами\n";
    player1.SetSecret();
    player2.NextPlayer();
    cout << player2.GetName() << "\n";
    cout << "Введите 4-х значное число с неповторяющимися цифрами\n";
    player2.SetSecret();
    system("cls");
    
    while (!player1.win && !player2.win)
    {
        player1.NextPlayer();
        cout << player1.GetName() << endl;
        player1.ShowHistory();
        player1.Guess(player2);
        if (player1.win)
        {
            cout << "Правильно!\n";
            _getch();
        }
        player2.NextPlayer();
        cout << player2.GetName() << endl;
        player2.ShowHistory();
        player2.Guess(player1);
        if (player2.win)
        {
            cout << "Правильно!\n";
            _getch();
        }
    }
    system("cls");
    if (player1.win && player2.win)
    {
        cout << "Ничья.\n";
    }
    else if (player1.win)
    {
        cout << player1.GetName() << " выиграл!\n";
    }
    else if (player2.win)
    {
        cout << player2.GetName() << " выиграл!\n";
    }
    _getch();
}