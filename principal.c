	/*Programa: Quadrado Animado
	Descrição: O programa irá criar um retangulo com suas respectivas bordas e um quadrado
	Programador: Hugo Josue Lema Das Neves
	RGM: 47159
	Data da última modificação: 24/04/2023*/

	#include <stdlib.h> /* system() */
	#include <string.h> /* strlen() */
	#include <windows.h> 
	#include "funcoes.h" /*Cria_Retangulo(), Cria_Quadrado()*/
	#include "conio_v3.2.4.h"   /* textbackground(), window(), gotoxy(), getch(), constantes BLACK, BLUE, LIGHTGRAY */
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
		
		/*Devolve a cor original da janela de console*/
		textbackground(BLACK);
		textcolor(7);
		clrscr();
		return 0;
	}