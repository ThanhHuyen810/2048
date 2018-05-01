#include<iostream>
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
using namespace std;

//Array game 2048

int map[4][4] = {0, 0, 0, 0,
				 0, 0, 0, 0,
				 0, 0, 0, 0,
				 0, 0, 0, 0};
//Score
int score = 0;

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}


void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm di chuyên con tro den vi tri x, y
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void modau()
{
     cout << "\n\n\n\n\n\n\n\n\n"
         << "\t\t       -----CHAO MUNG BAN DEN VOI-----\n"
         << "\n\n"
         << "\t\t\t222222  000000  4    4  888888 \n"
         << "\t\t\t     2  0    0  4    4  8    8 \n"
         << "\t\t\t222222  0    0  444444  888888 \n"
         << "\t\t\t2       0    0       4  8    8 \n"
         << "\t\t\t222222  000000       4  888888 \n"
         << "\n\n\n\n"
         << "LUAT CHOI: "
         << "\n\n"
         << "2048 choi tren mot bang co kich thuoc 4x4."
         << "Nguoi choi su dung cac phim mui ten va cac khoi vuong se truot theo mot trong bon huong (len, xuong, trai, phai)."
         << "     Moi luot co mot khoi co gia tri 2 hoac 4 xuat hien ngau nhien o mot o trong tren bang."
         << "   Cac khoi vuong truot theo huong chi dinh cho den khi cham den bien cua bang hoac cham vao khoi vuong khac."
         << " Neu hai khoi vuong co cung gia tri cham vao nhau, chung se ket hop thanh mot khoi vuong co gia tri bang tong gia tri cua hai khoi vuong do."
         << "  Khoi vuong ket qua khong the ket hop voi khoi vuong khac trong mot luot di chuyen."
         << " Khi nguoi choi tao duoc khoi vuong co gia tri 2048 thi thang cuoc."
         << " Khi khong con o trong va cac o ke nhau deu khac gia tri thi tro choi ket thuc!\n\n\n";
         system ("pause");
}


int color_of_data(int x){

	switch(x){
		case 2: return 160;
		case 4: return 63;
		case 8: return 47;
		case 16: return 31;
		case 32: return 79;
		case 64: return 95;
		case 128: return 111;
		case 256: return 159;
		case 512: return 176;
		case 1024: return 207;
		case 2048: return 223;
	}

}


int color_of_block(int x){

	switch(x){
		case 0: return 119;
		case 2: return 170;
		case 4: return 51;
		case 8: return 34;
		case 16: return 17;
		case 32: return 68;
		case 64: return 85;
		case 128: return 102;
		case 256: return 153;
		case 512: return 187;
		case 1024: return 204;
		case 2048: return 221;
	}

}


//draw background game


void draw_background(){
	int a = 0, b = 0;
	for(int i = 0; i <= 16; i++){
		for(int j = 0; j <= 16; j++){

			if(i == 0 || i == 4 || i ==  8 || i == 12 || i == 16){
				textcolor(136);
				cout << 33;
			}
			else if(j == 0 || j == 4 || j ==  8 || j == 12 || j == 16){
				textcolor(136);
				cout << 33;
			}
			else {

				textcolor(0);
				cout << 33;

			}

		}
		textcolor(0);
		cout << endl;

	}

}


//Processes arr and score
void processer(int array[4]){
	for(int i = 0; i < 3; i++){
		for(int j = i + 1; j < 4; j++){
			if(array[i] == 0){
				if(array[j] != 0) swap(array[i], array[j]);
			}
			else {
				if(array[i] == array[j]) {
					array[i] = 2 * array[i];

					// Compuleting score
					if(array[i] >= 4) score = score + array[i];

					array[j] = 0;
					j = 5;
				}
				else if(array[j] == 0) continue;
				else j = 5;
			}
		}
	}
}


//draw data game in background
void draw_game(){
	int y = 3;
	for(int i = 0; i < 4; i++){
		int x = 4;
		for(int j = 0; j < 4; j++){

			textcolor(color_of_block(map[i][j]));
			gotoxy(x-1, y-1);
			cout << "333333";
			gotoxy(x-1, y);
			cout << "333333";
			gotoxy(x-1, y+1);
			cout << "333333";
			textcolor(color_of_data(map[i][j]));

			if(map[i][j] != 0){
				gotoxy(x, y);
				cout << map[i][j];
			}

			x = x + 8;
		}
		y = y + 4;
	}

//Puts your score
	gotoxy(40, 1);
	textcolor(15);
	cout << "Score: " << score
         << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int check_arr_empty(){
	int check;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(map[i][j] == 0) return 1;
		}
	}
	return 0;
}

//make data game
void make_game(){
	int i, j;
	//tao so ngau nhien
	if (check_arr_empty()){
		do{
			i = rand()%4;
			j = rand()%4;
		}while (map[i][j]);
		map[i][j] = 2;
	}
}


//move in game
void move_game(){
	int arr[4], key;
	bool check = false;

	if(GetAsyncKeyState(VK_DOWN)) key = 1;
	else if(GetAsyncKeyState(VK_UP)) key = 2;
	else if(GetAsyncKeyState(VK_LEFT)) key = 3;
	else if(GetAsyncKeyState(VK_RIGHT)) key = 4;

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			switch(key){
				case 1:{
					arr[j] = map[3-j][i];
					break;
				}
				case 2:{
					arr[j] = map[j][i];
					break;
				}
				case 3:{
					arr[j] = map[i][j];
					break;
				}
				case 4:{
					arr[j] = map[i][3-j];
					break;
				}
			}
		}

		processer(arr);

		for(int k = 0; k < 4; k++){
			switch(key){
				case 1:{
					if(arr[k] != map[3-k][i]) check = true;
					break;
				}
				case 2:{
					if(arr[k] != map[k][i]) check = true;
					break;
				}
				case 3:{
					if(arr[k] != map[i][k]) check = true;
					break;
				}
				case 4:{
					if(arr[k] != map[i][3-k]) check = true;
					break;
				}
			}
		}

		for(int k = 0; k < 4; k++){
			switch(key){
				case 1:{
					map[3-k][i] = arr[k];
					break;
				}
				case 2:{
					map[k][i] = arr[k];
					break;
				}
				case 3:{
					map[i][k] = arr[k];
					break;
				}
				case 4:{
					map[i][3-k] = arr[k];
					break;
				}
			}
		}
	}

	if(check) make_game();
}



void game_end(){
	//win
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(map[i][j] == 2048) {
				gotoxy(40, 3);
				textcolor(12);
				cout << "You win !!";
				gotoxy(1, 20);
				system("pause");
				exit(1);
			}
		}
	}

	//lose
	bool check = false;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			if(map[i][j] == map[i][j+1] || map[j][i] == map[j][i+1])
				check = true;
		}
	}

	if(check == false && check_arr_empty() == 0){
		gotoxy(40, 3);
		textcolor(12);
		cout << "You lose !!";
		gotoxy(1, 20);
		system("pause");
		exit(1);
	}
}


void clrscr()
{
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
HANDLE hConsoleOut;
COORD Home = {0,0};
DWORD dummy;

hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
csbiInfo.dwCursorPosition.X = 0;
csbiInfo.dwCursorPosition.Y = 0;
}

int main(){
    modau();
    clrscr();
    gotoxy(1,1);
	srand(time(NULL));
	int x = rand() % 4,
		y = rand() % 4;
	map[x][y] = 2;

	resizeConsole(550, 460);
	draw_background();

	do{
		draw_game();
		game_end();
		if(kbhit() == 0) system("pause");
		move_game();
	}
	while(true);
}
