#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


using namespace std;
// �۾� ����������
//����
#define start_x 8
#define start_y 4
void cout_gotoxy(int x, int y, char*a); //gotoxy ���⼭ ã������!
void delete_cursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);




}
void game()
{
	system("mode con:lines=20 cols=28");
	int pan_inner_state[12][12]; //�ǳ����� ������ ����ϴ� 2���� �迭 ����
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			pan_inner_state[y][x] = 0;
		}
	}
	//���� �� ���������� ����ϴ� 2���� �迭 ������ ��� 0���� �ʱ�ȭ

	int my_position_x, my_position_y; //�� xy��ǥ�� ����ϴ� ����
	my_position_x = 2; my_position_y = 1;//�� �ʱ���ġ�� ó������ ����


	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
	for (int i = 0; i < 26; i = i + 1)
	{

		cout_gotoxy(i, 0, "��");
		cout_gotoxy(i, 13, "��");
	}

	for (int i = 0; i <= 12; i = i + 1)
	{
		cout_gotoxy(0, i, "��");
		cout_gotoxy(26, i, "��");

	}
	cout_gotoxy(0, 0, "��");
	cout_gotoxy(26, 0, "��");
	cout_gotoxy(0, 13, "��");
	cout_gotoxy(26, 13, "��");
	cout_gotoxy(my_position_x, my_position_y, "��");

	//������ �׵θ��׸�
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	int key; // ���� ���� Ű���忡 ���� �ƽ�Ű�ڵ� ���� �ӽ� �����ϴ� ����
	while (1) //���� Ű���� ���� ������ �׻� �ݺ�
	{
		key = getch(); //conio.h
		//cout << key << endl;

		if (key == 13)//����Ű ���� ���� ����
		{
			// my position  x,y  ��ǥ�� �ٲ��ָ� pan inner +1;
			pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1]++;

		}


		if (key == 224)//����Ű ������ �� ����
		{
			key = getch();
			//�� 72 �� 75 ����77 �Ʒ�80

			//cout << key << endl;
			if (key == 77)//��
			{

				if (my_position_x <= 22)
				{

					if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 0)

					{
						cout_gotoxy(my_position_x, my_position_y, "  ");
					}
					else if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 1)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
						cout_gotoxy(my_position_x, my_position_y, "��");

					}
					my_position_x = my_position_x + 2;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "��");


				}
			}

			else if (key == 75)//��
			{
				if (my_position_x >= 4)
				{

					if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 0)

					{
						cout_gotoxy(my_position_x, my_position_y, "  ");
					}
					else if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 1)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
						cout_gotoxy(my_position_x, my_position_y, "��");
					}


					my_position_x = my_position_x - 2;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "��");
				}
			}
			else if (key == 72)//��
			{
				if (my_position_y >= 2)
				{

					if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 0)

					{
						cout_gotoxy(my_position_x, my_position_y, "  ");
					}
					else if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 1)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
						cout_gotoxy(my_position_x, my_position_y, "��");
					}
					my_position_y = my_position_y - 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "��");
				}
			}
			else if (key == 80) //�Ʒ�
			{
				if (my_position_y < 12)
				{

					if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 0)

					{
						cout_gotoxy(my_position_x, my_position_y, "  ");
					}
					else if (pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1] == 1)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
						cout_gotoxy(my_position_x, my_position_y, "��");
					}
					my_position_y = my_position_y + 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "��");
				}
			}





		}
	}
}
void randomnumber()
{
	srand(time(NULL));
	int rannum = rand() % 4 + 1;
	cout << rannum << endl;

}

void main()
{
	delete_cursor();
	//�� 72 �� 75 ����77 �Ʒ�80
		
	cout << "                             ��                  �� " << endl;
	cout << "   ������       ���     ����     ���     ��  " << endl;
	cout << "           ��     ��    ��   ��       ��    ��   ��" << endl;	          
	cout << "           ��     ��    ��   ��       ��    ��   ��" << endl;
	cout << "           ��       ���     ����     ���     ��" << endl;
	cout << "      ��   ��                ��                  �� " << endl;
	cout << "      ��                ���                     ��" << endl;
	cout << "���������      ��    ��                   �� " << endl;
	cout << "                      ��    ��                   �� " << endl;
	cout << "                        ���                   " << endl;
	cout << "                                           " << endl;
	cout << "                  �� ��                  ��        " << endl;
	cout << "                  �� ��        ���      ��             " << endl;
	cout << "    ������    �� ��      ��    ��    ��                      " << endl;
	cout << "            ��    �� ��      ��    ��    ��            " << endl;
	cout << "           �� ���� ��        ���      ��                  " << endl;
	cout << "          ��      �� ��                  ��         " << endl;
	cout << "        ��        �� ��                          " << endl;
	cout << "      ��          �� ��         ������                 " << endl;
	cout << "                  �� ��         ��      ��          " << endl;
	cout << "                                ������               " << endl;

	
	int menulocation_x = 60;
	int menulocation_y = 15;

	cout_gotoxy(menulocation_x, menulocation_y, "");

		cout_gotoxy(menulocation_x, menulocation_y, "���ӽ���");
	cout_gotoxy(menulocation_x, menulocation_y+1, "��������");
	cout_gotoxy(menulocation_x+1, menulocation_y+2, "����");
	cout_gotoxy(menulocation_x, menulocation_y + 3, "��ŷ����");

	int cx = menulocation_x - 1, cy = menulocation_y;  //02
	cout_gotoxy(cx, cy, "o");
	cout_gotoxy(cx + 10, cy, "o");

	/////������������̽�////
	//int a;
	//cin >> a; //���ڸ� ������ ���ʹ����� �� a�� ������

	//Ű���� ������ �� ���� ���� ���ʹ����� a������
	
	int key;
	int a;
	while (1)
	{
		key = getch(); //getch�� conio.h ��� �ȿ� ����
		if (key == 224)
		{
		

				key = getch();
				if (key == 80) //�Ʒ�
				{
					if (cy <= menulocation_y+2)
					{
						//���� Ŀ����ġ ����
						cout_gotoxy(cx, cy, " ");
						cout_gotoxy(cx + 10, cy, " ");
						cy++;
						cout_gotoxy(cx, cy, "o");
						cout_gotoxy(cx + 10, cy, "o");
					}
				}
			

			else if (key == 72) //��
			{
				if (cy >= menulocation_y+1)
				{
					cout_gotoxy(cx, cy, " ");
					cout_gotoxy(cx + 10, cy, " ");
					cy--; //y��ġ �ϳ� ����
					cout_gotoxy(cx, cy, "o");
					cout_gotoxy(cx + 10, cy, "o");
				}
			}

		}

		else if (key == 13)
		{
			a = cy-14;
			break;
		}

	}



	//a���� ���� �Է��� ���ڷ� �޾�
	//a���� ���� ��ġ�� ���� ���ڷ� �����ָ�



	///����¿� ���� ����
	cout_gotoxy(menulocation_x, menulocation_y + 6, "");
	//cout_gotoxy(1, 10, "");
	system("cls");
	if (a == 1)
		{
		//game();
		randomnumber();
		//cout << "������ ��������";
		}
		else if (a == 2)
		{
			cout << "��!";
		}
		else if (a == 3)
		{
			cout << "����!!";
		}
		else if (a == 4)
		{
			cout << "���� ���� ���ϳ�~";
		}
		//cout_gotoxy(menulocation_x, menulocation_y + 4, "��¼����¼����");
		
	
}

void cout_gotoxy(int x, int y, char*a)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //�� Ŀ�� ��ġ �ٲ��ְ�

	cout << a << endl; //�ٲ� �� Ŀ����ġ�� a ���

}

	
