#include<iostream>
#include<windows.h>
using namespace std;
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
int main() {
    int i;
    for (i=0; i<256; i++) {
        textcolor(i);
        cout << i << " : mau" << endl ;
    }

}
