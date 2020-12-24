#include "Player.h"

Player::Player()
{
	win = false;
	name = "unknown";
}

void Player::SetName()
{
	getline(cin, name);
}

string Player::GetName()
{
	return(name);
}

void Player::SetSecret()
{
	int i, j, right;
	int correct = 0; //������������ �����
	string input;

	while (!correct)
	{
		getline(cin, input);
		right = 1;
		if (input.size() == 4)
		{
			for (i = 0; (i < 4) && (right == 1); i++)
			{
				if (input[i] >= '0' && input[i] <= '9')
				{
					secret[i] = input[i] - '0';
					for (j = 0; (j < i)&&(right==1); j++)
					{
						if (secret[i] == secret[j])
						{
							right = 0;
							correct = 0;
							cout << "����� �����������!\n";
						}
						else
						{
							right = 1;
							correct = 1;
						}
					}
				}
				else
				{
					right = 0;
					correct = 0;
					cout << "��� �� �����!\n";
				}
			}
		}
		else
		{

			cout << "����� ������ ���� 4-� �������!\n";
		}
	}

}

void Player::NextPlayer()
{
	system("cls");
	cout << "��������� ��������� " << name;
	cout << "\n������� ����� �������.";
	_getch();
	system("cls");
}

void Player::ShowHistory()
{
	int i, n;
	n = history.size();
	if (n != 0)
	{
		cout << "������� �����:\n";
		for (i = 0; i < n; i++)
		{
			cout << history[i] << endl;
		}
	}
}

void Player::Guess(Player second)
{
	string new_try, log;
	int i, j, bulls, cows, checked;

	bulls = 0;
	cows = 0;
	cout << "����� �������: ";
	getline(cin, new_try);
	if (new_try.size() == 4)
	{
		for (i = 0; i < 4; i++)
		{
			if (new_try[i] >= '0' && new_try[i] <= '9')
			{
				checked = 0;
				for (j = 0; (j < 4) && (checked == 0); j++)
				{
					if (second.secret[j] == (new_try[i] - '0'))
					{
						checked = 1;
						if (i == j) bulls++;
						else cows++;
					}
				}
			}
		}
		log = to_string(bulls);
		new_try = new_try + "   " + log + " � ";
		log = to_string(cows);
		new_try = new_try + " " + log + " �";
		history.push_back(new_try);
		if (bulls == 4) win = true;
		cout << new_try << endl;
		_getch();
	}
	else cout << "������������ ����\n";
}