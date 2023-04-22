﻿	/*Programa: Quadrado Animado
	Descrição: ******************
	Programador: Hugo Josue Lema Das Neves
	RGM: 47159
	Data da última modificação: 12/04/2023*/

	#include <stdlib.h> /* system() */
	#include <string.h> /* strlen() */
	#include <windows.h>
	#include "funcoes.h"
	#include "conio_v3.2.4.h"   /* textbackground(), window(), gotoxy(), getch(), constantes BLACK, BLUE, LIGHTGRAY, RED */
	#include "console_v1.5.4.h"

	int main(int argc, char *argv[])
	{
		int linhas = 40;
		int colunas = 100;
		/*Artifício para silenciar os Warnings*/
		argc = argc;
		argv = argv;

		/*Limpa a tela*/
		clrscr();
		
		/*Muda a cor de fundo do console*/
		textbackground(BLUE);
		
		/*Chamada da função para criação do retângulo e quadrado*/
		Cria_Retangulo(linhas, colunas);
		Cria_Quadrado();
		Aumenta_Retangulo();

		/*Devolve a cor original da janela de console*/
		textbackground(BLACK);
		textcolor(7);
		clrscr();
		system("cls");

		return 0;
	}
