#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


using namespace std;
// 글씨 움직여보기
//숙제
#define start_x 8
#define start_y 4
void cout_gotoxy(int x, int y, char*a); //gotoxy 여기서 찾으러옴!
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
	int pan_inner_state[12][12]; //판내부의 정보를 기억하는 2차원 배열 변수
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			pan_inner_state[y][x] = 0;
		}
	}
	//위의 판 내부정보를 기억하는 2차원 배열 변수를 모두 0으로 초기화

	int my_position_x, my_position_y; //내 xy좌표를 기억하는 변수
	my_position_x = 2; my_position_y = 1;//내 초기위치를 처음으로 잡음


	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
	for (int i = 0; i < 26; i = i + 1)
	{

		cout_gotoxy(i, 0, "━");
		cout_gotoxy(i, 13, "━");
	}

	for (int i = 0; i <= 12; i = i + 1)
	{
		cout_gotoxy(0, i, "┃");
		cout_gotoxy(26, i, "┃");

	}
	cout_gotoxy(0, 0, "┏");
	cout_gotoxy(26, 0, "┓");
	cout_gotoxy(0, 13, "┗");
	cout_gotoxy(26, 13, "┛");
	cout_gotoxy(my_position_x, my_position_y, "ㅁ");

	//여까지 테두리그림
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
	int key; // 내가 누른 키보드에 대한 아스키코드 값을 임시 저장하는 변수
	while (1) //내가 키보드 누를 때마다 항상 반복
	{
		key = getch(); //conio.h
		//cout << key << endl;

		if (key == 13)//엔터키 누를 때의 동작
		{
			// my position  x,y  좌표값 바꿔주면 pan inner +1;
			pan_inner_state[my_position_y - 1][(my_position_x / 2) - 1]++;

		}


		if (key == 224)//방향키 눌렀을 때 동작
		{
			key = getch();
			//위 72 왼 75 오른77 아래80

			//cout << key << endl;
			if (key == 77)//오
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
						cout_gotoxy(my_position_x, my_position_y, "●");

					}
					my_position_x = my_position_x + 2;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "ㅁ");


				}
			}

			else if (key == 75)//왼
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
						cout_gotoxy(my_position_x, my_position_y, "●");
					}


					my_position_x = my_position_x - 2;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "ㅁ");
				}
			}
			else if (key == 72)//위
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
						cout_gotoxy(my_position_x, my_position_y, "●");
					}
					my_position_y = my_position_y - 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "ㅁ");
				}
			}
			else if (key == 80) //아래
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
						cout_gotoxy(my_position_x, my_position_y, "●");
					}
					my_position_y = my_position_y + 1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
					cout_gotoxy(my_position_x, my_position_y, "ㅁ");
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
	//위 72 왼 75 오른77 아래80
		
	cout << "                             ■                  ■ " << endl;
	cout << "   ■■■■■       ■■     ■■■     ■■     ■  " << endl;
	cout << "           ■     ■    ■   ■       ■    ■   ■" << endl;	          
	cout << "           ■     ■    ■   ■       ■    ■   ■" << endl;
	cout << "           ■       ■■     ■■■     ■■     ■" << endl;
	cout << "      ■   ■                ■                  ■ " << endl;
	cout << "      ■                ■■                     ■" << endl;
	cout << "■■■■■■■■      ■    ■                   ■ " << endl;
	cout << "                      ■    ■                   ■ " << endl;
	cout << "                        ■■                   " << endl;
	cout << "                                           " << endl;
	cout << "                  ■ ■                  ■        " << endl;
	cout << "                  ■ ■        ■■      ■             " << endl;
	cout << "    ■■■■■    ■ ■      ■    ■    ■                      " << endl;
	cout << "            ■    ■ ■      ■    ■    ■            " << endl;
	cout << "           ■ ■■■ ■        ■■      ■                  " << endl;
	cout << "          ■      ■ ■                  ■         " << endl;
	cout << "        ■        ■ ■                          " << endl;
	cout << "      ■          ■ ■         ■■■■■                 " << endl;
	cout << "                  ■ ■         ■      ■          " << endl;
	cout << "                                ■■■■■               " << endl;

	
	int menulocation_x = 60;
	int menulocation_y = 15;

	cout_gotoxy(menulocation_x, menulocation_y, "");

		cout_gotoxy(menulocation_x, menulocation_y, "게임시작");
	cout_gotoxy(menulocation_x, menulocation_y+1, "게임종료");
	cout_gotoxy(menulocation_x+1, menulocation_y+2, "도움말");
	cout_gotoxy(menulocation_x, menulocation_y + 3, "랭킹보기");

	int cx = menulocation_x - 1, cy = menulocation_y;  //02
	cout_gotoxy(cx, cy, "o");
	cout_gotoxy(cx + 10, cy, "o");

	/////입출력인터페이스////
	//int a;
	//cin >> a; //숫자를 누르고 엔터눌렀을 때 a값 정해짐

	//키보드 눌렀을 때 숫자 고르고 엔터누르면 a정해짐
	
	int key;
	int a;
	while (1)
	{
		key = getch(); //getch는 conio.h 헤더 안에 선언
		if (key == 224)
		{
		

				key = getch();
				if (key == 80) //아래
				{
					if (cy <= menulocation_y+2)
					{
						//원래 커서위치 지움
						cout_gotoxy(cx, cy, " ");
						cout_gotoxy(cx + 10, cy, " ");
						cy++;
						cout_gotoxy(cx, cy, "o");
						cout_gotoxy(cx + 10, cy, "o");
					}
				}
			

			else if (key == 72) //위
			{
				if (cy >= menulocation_y+1)
				{
					cout_gotoxy(cx, cy, " ");
					cout_gotoxy(cx + 10, cy, " ");
					cy--; //y위치 하나 증가
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



	//a값을 내가 입력한 숫자로 받았
	//a값을 나의 위치에 따른 숫자로 정해주면



	///입출력에 따른 동작
	cout_gotoxy(menulocation_x, menulocation_y + 6, "");
	//cout_gotoxy(1, 10, "");
	system("cls");
	if (a == 1)
		{
		//game();
		randomnumber();
		//cout << "게임을 시작하지";
		}
		else if (a == 2)
		{
			cout << "끝!";
		}
		else if (a == 3)
		{
			cout << "도움!!";
		}
		else if (a == 4)
		{
			cout << "누가 제일 잘하나~";
		}
		//cout_gotoxy(menulocation_x, menulocation_y + 4, "어쩌구저쩌구다");
		
	
}

void cout_gotoxy(int x, int y, char*a)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //내 커서 위치 바꿔주고

	cout << a << endl; //바뀐 내 커서위치에 a 출력

}

	
