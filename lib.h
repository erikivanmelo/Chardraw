#ifndef _LIB_H_
#define _LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

//Colores de texto
#define Black 30
#define Red 31
#define Green 32
#define Yellow 33
#define Blue 34
#define Magenta 35
#define Cyan 36
#define White 37
//colores de fondo
#define BG_Black 40
#define BG_Red 41
#define BG_Green 42
#define BG_Yellow 43
#define BG_Blue 44
#define BG_Magenta 45
#define BG_Cyan 46
#define BG_White 47

#define none 0

void Gotoxy(int x,int y);
int Getch();
void Textcolor(int color, int BG_color);


#endif


