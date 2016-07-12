#include"lib.h"

int Getch(){
	fflush(stdin);
	int ch;
	struct termios oldattr, newattr;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

void Gotoxy(int x,int y){
        printf("%c[%d;%df",0x1B,y,x);
}

void Textcolor(int color, int BG_color){
        //El primer valor es del color de texto y el segundo del color del fondo
        printf("%c[%d;%d;%dm", 0x1B, 1,color,BG_color);
}