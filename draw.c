#include "draw.h"
struct winsize ww;
void Texto(int AnchoPlano,int AltoPlano);
void Caracter(short AnchoPlano,short AltoPlano);

typedef struct{
	short Xcursor;
	short Ycursor;
}Coordenada;

Coordenada draw;
Coordenada caracteres;

//Bucles
short l,i,j;

//Tecla
char  T;

//Matriz del dibujo
char plano[1000][1000];

//Id del caracter igual al caracter inicial (#)
short C = 0;

//Caracteres
char Caracteres[]="# a b c d e f g h i j k m n l o p q r s t u v w x y z A B C D E F G H I J K M N L O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9 @ : ; ¿ ? ¡ ! / \\ ( ) [ ] { } < > « » ═ ║ ╔ ╗ ╚ ╝ ╠ ╣ ╦ ╩ ╬ ╭ ╮ ╰ ╯ ╳ ▁ ▂ ▃ ▄ ▅ ▆ ▇ ▉ ▒ ░ ▚ ▞ ■ □ ▢ ▤ ▥ ▦ ▧ ▨ ▩";

//Variable auxiliar
short aux;

//Para saber en que caracter empezar a imprimir la paleta de caracteres
short Contador;

void Dibujo(){

	//Ubicacion inicial del cursor
	draw.Xcursor = 2;
	draw.Ycursor = 3;

	ioctl(0, TIOCGWINSZ, &ww);


	//Ancho y largo dentro del marco
	const short  AnchoPlano   = ww.ws_col;
	const short  AltoPlano    = ww.ws_row-2;
	Gotoxy(draw.Xcursor,draw.Ycursor);

	do{
		//Actualizacion de dibujo en pantalla
		for(i=2;i<AnchoPlano;i++){for(j=3;j<AltoPlano;j++){if(plano[i][j]!='\0'){Gotoxy(i,j); printf("%c", plano[i][j] );}}}
		//Actualizacion de cursor
		Gotoxy(draw.Xcursor,draw.Ycursor);
		//Pidiendo tecla por... teclado :V
		T = Getch();

		//Controles
		switch(T){

			case ARRIBA				:draw.Ycursor--;													break;
			case PRINT_ARRIBA		:plano[draw.Xcursor][draw.Ycursor]=Caracteres[C]; draw.Ycursor--;	break;
			case ABAJO				:draw.Ycursor++;													break;
			case PRINT_ABAJO		:plano[draw.Xcursor][draw.Ycursor]=Caracteres[C]; draw.Ycursor++;	break;
			case IZQUIERDA			:draw.Xcursor--; 													break;
			case PRINT_IZQUIERDA	:plano[draw.Xcursor][draw.Ycursor]=Caracteres[C]; draw.Xcursor--; 	break;
			case DERECHA			:draw.Xcursor++; 													break;
			case PRINT_DERECHA		:plano[draw.Xcursor][draw.Ycursor]=Caracteres[C]; draw.Xcursor++; 	break;
			case PRINT				:plano[draw.Xcursor][draw.Ycursor]=Caracteres[C]; 					break;
			case RESET				:for(i=1;i<AnchoPlano;i++){
										for(j=1;j<AltoPlano;j++){
											if (plano[i][j]){ Gotoxy(i,j); printf(" "); }
											plano[i][j] = '\0';
										}
									}break;
			case TEXTO				:Texto(AnchoPlano,AltoPlano);										break;
			case DELETE				:plano[draw.Xcursor][draw.Ycursor]='\0';
									 Gotoxy(draw.Xcursor,draw.Ycursor);printf(" ");						break;
			case CARACTERES			:Caracter(AnchoPlano,AltoPlano);
		}

		//Teletransportacion de cursor :V
		if(draw.Ycursor < 3			 	)	{	draw.Ycursor=AltoPlano-1;	}
		if(draw.Xcursor < 2			 	)	{	draw.Xcursor=AnchoPlano-1; 	}
		if(draw.Ycursor > AltoPlano-1 	)	{	draw.Ycursor=3;	    		}
		if(draw.Xcursor > AnchoPlano-1 	)	{	draw.Xcursor=2;	    		}


	}while(T !=EXIT);




}

void Texto(int AnchoPlano,int AltoPlano){
	//Ubiacion inicial del cursor al abrir el mapa de caracteres
	caracteres.Xcursor = 3;
	caracteres.Ycursor = 1;

	draw.Xcursor--;
	char T;
	int Xinicio = draw.Xcursor-1;
	int Yinicio = draw.Ycursor-1;
	Gotoxy(draw.Xcursor+1,draw.Ycursor);
	do {
		T=Getch();
		plano[draw.Xcursor+1][draw.Ycursor]=T;
		
		/*if   	  (T==9)  {printf("\t");		}
		else*/ if (T==-61){printf("%s","ñ"); 	}
		else 			  	{printf("%c",T);		}

		//Permite borrar caracteres
		if		(T == DELETE && draw.Ycursor != AltoPlano-1){ 
					plano[draw.Xcursor][draw.Ycursor]='\0'; 
					
					Gotoxy(draw.Xcursor,draw.Ycursor); 
					printf(" "); 
					
					if 		(draw.Xcursor != Xinicio+1) 	draw.Xcursor--;
					//else if (draw.Ycursor >=)				draw.Ycursor--
				}

		//else if (T == DELETE && draw.Ycursor >= AltoPlano-1){		 draw.Ycursor=3; draw.Xcursor=Xinicio;}

		//Permite los saltos de linea
		if		(T == ENTER && draw.Ycursor != AltoPlano-1){		draw.Ycursor++; draw.Xcursor=Xinicio;}
		else if (T == ENTER && draw.Ycursor >= AltoPlano-1){		draw.Ycursor=3; draw.Xcursor=Xinicio;}

		//Permite que no se baya del marco
		if 		(draw.Xcursor >= AnchoPlano-2 && draw.Ycursor != AltoPlano-1){draw.Xcursor=Xinicio; draw.Ycursor++;}
		else if (draw.Xcursor >= AnchoPlano-2 && draw.Ycursor >= AltoPlano-1){draw.Xcursor=Xinicio; draw.Ycursor=3;}

		
		if(T!=DELETE)draw.Xcursor++;
		Gotoxy(draw.Xcursor+1,draw.Ycursor);

	}while(T!=EXIT);

}

void Caracter(short AnchoPlano,short AltoPlano){

	if ( Contador == '\0' ){	Contador = 0; }

	Gotoxy(1,1);

	Textcolor(Black,BG_White);
	printf("< ");
	for (i = Contador; i < AnchoPlano-2; i++)
	{
		printf("%c", Caracteres[i]);
	}
	Gotoxy(AnchoPlano,1);
	printf(">");

	if 		(caracteres.Xcursor == '\0'){	caracteres.Xcursor = 3; }
	Gotoxy(caracteres.Xcursor,1);
	do{

		T = Getch();

		if 		(T == DERECHA 	&& caracteres.Xcursor <= AnchoPlano-6 ){ 	caracteres.Xcursor+=2; }
		else if	(T == IZQUIERDA && caracteres.Xcursor >= 2 			  ){ 	caracteres.Xcursor-=2; }

		//Permite el moviomiento 
		if 		(T == DERECHA 	&& caracteres.Xcursor == AnchoPlano-4 && Contador <= 230){
			Contador+=2;
			Gotoxy(3,1);
			for (i = Contador; i < AnchoPlano-2; i++)
			{
				printf("%c", Caracteres[i]);
			}
		}

		if		(T == ENTER){ C = caracteres.Xcursor-1+Contador;}

		Gotoxy(caracteres.Xcursor+2,caracteres.Ycursor);
	}while(T != ENTER);


	//Imprecion de la barra original
	ioctl(0, TIOCGWINSZ, &ww);
	const short AnchoBarra = ww.ws_col+1;

	for (short i = 1; i < AnchoBarra; i++)
	{
		Gotoxy(i,1);
		Textcolor(Black,BG_White);
		printf(" ");;

	}
	Gotoxy((AnchoBarra/2)-4,1);
	printf("Chardraw");
	Gotoxy(AnchoBarra,1);
	Textcolor(White,none);

}