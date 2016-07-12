#ifndef _DRAW_H_
#define _DRAW_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "lib.h"

//teclas
#define  ARRIBA 			119
#define  PRINT_ARRIBA		87
#define  ABAJO				115
#define  PRINT_ABAJO		83
#define  IZQUIERDA			97
#define  PRINT_IZQUIERDA	65
#define  DERECHA			100
#define  PRINT_DERECHA		68
#define  PRINT 				32
#define  EXIT				24
#define  RESET				18
#define  TEXTO				20
#define  ENTER				10
#define  DELETE				127
#define	 CARACTERES			5

void Dibujo();

#endif
