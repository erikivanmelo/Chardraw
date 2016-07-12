#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "lib.h"
#include "draw.h"

struct winsize w;

#ifndef _MAIN_C_
#define _MAIN_C_
void Marco();
void Herramientas();
void HText(short x,short y,char control[2],char explicacion[20]);
void Barra();

int main(){
	system("clear");

		Barra();
        Marco();
        Herramientas();
		Dibujo();

	Gotoxy(1,1);
	system("clear");
}

void Herramientas(){

    //Para saber el tamaño de la terminal
    ioctl(0, TIOCGWINSZ, &w);

    //Coordenadas 00
    const short x = 1;
    const short y = w.ws_row-1;

    //Como usar las distintas funciones
    HText(x		,y,		"^X",	" Salir"				);
    HText(x		,y+1,	"^R" ,	" Reset"				);
	HText(x+19	,y+1,	"^T" ,	" Texto"				);
	HText(x+19	,y,		"SpB",	" Imprimir caracter"	);
}

void Marco(){
	//Para saber el tamaño de la terminal
	ioctl(0, TIOCGWINSZ, &w);

	//Coordenadas
	short x,y;

	//Ancho y largo del marco
	const short AnchoMarco = w.ws_col;
	const short AltoMarco = w.ws_row-2;

	//Imprecion del marco
	for(x = 1;x<AnchoMarco;x++){
		for(y = 2;y<AltoMarco;y++){
			//Imprecion de arista
			if(x==1 && y!=(2 && AltoMarco)){	Gotoxy(x,y); printf("║");	}
		}
	}


	//Imprecion de esquinas
    Gotoxy(1,2);												printf("╔");
    for (x = 2; x < AnchoMarco; x++){							printf("═"); }
    Gotoxy(1,AltoMarco);										printf("╚");
	for (x = 2; x < AnchoMarco; x++){							printf("═"); }
    Gotoxy(AnchoMarco,2);										printf("╗");
	for (y = 3; x < AltoMarco; x++){	Gotoxy(AnchoMarco,y);	printf("║"); }	
    Gotoxy(AnchoMarco,AltoMarco);								printf("╝");
}

void HText(short x,short y,char control[2],char explicacion[20]){
        Gotoxy(x,y);
        Textcolor(Black,BG_White);
        printf("%s",control);
        Textcolor(White,none);
        printf("%s",explicacion);
}

void Barra(){
	ioctl(0, TIOCGWINSZ, &w);
	const short AnchoBarra = w.ws_col+1;

	Textcolor(Black,BG_White);
	for (short i = 0; i < AnchoBarra; ++i)
	{
		Gotoxy(i,1);
		Textcolor(Black,BG_White);
		printf(" ");

	}
	Gotoxy((AnchoBarra/2)-4,1);
	printf("Chardraw");
	Gotoxy(AnchoBarra,1);
	Textcolor(White,none);


}

#endif
