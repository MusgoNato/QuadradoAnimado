	/*Programa: Quadrado Animado
	Descrição: O programa realiza a criação de um retângulo e um quadrado ao meio dele,	onde o usuário terá a possibilidade de 
	locomover o quadrado nas direçôes para cima, para baixo, para a esquerda e para a direita. 
	Além disso, poderá aumentar a velocidade do quadrado, trocar a cor dele e a do retângulo 
	e aumentar e diminuir o retângulo até um limite definido.
	As informaçôes do que ocorre no programa será impresso no canto inferior da janela do console.
	
	Programador: Hugo Josue Lema Das Neves
	RGM: 47159
	Data da última modificação: 01/04/2023*/
	
	#include "funcoes.h" /*Cria_Retangulo(), Cria_Quadrado(), Apaga_Quadrado(), Movimenta_quadrado(), Ler_Teclado()*/
	#include "conio_v3.2.4.h"   /* textbackground(), textcolor(), gotoxy(), constantes BLACK, BLUE */
	#include "console_v1.5.4.h" /*EVENTO(), hit(), MaxDimensaoJanela(), setCursorStatus(), setDimensaojanela(),*/

	int main(int argc, char *argv[])
	{
		int linhas = 40;
		int colunas = 100;
		
		/*Artifício para silenciar os Warnings*/
		argc = argc;
		argv = argv;

		/*Limpa a tela*/
		clrscr();
		
		/*Muda a cor para azul, para impressao do retângulo*/
		textbackground(BLUE);
		
		/*Chamada da função para criação do retângulo e quadrado*/
		Cria_Retangulo(linhas, colunas);
		
		/*Devolve a cor original da janela de console*/
		textbackground(BLACK);
		textcolor(7);
		clrscr();
		return 0;
	}