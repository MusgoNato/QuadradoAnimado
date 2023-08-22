	/*Programa: Quadrado Animado
	Descrição: O programa realiza a criação de um retângulo e um quadrado ao meio dele,	onde o usuário terá a possibilidade de 
	locomover o quadrado nas direçôes para cima, para baixo, para a esquerda e para a direita. 
	Além disso, poderá aumentar a velocidade do quadrado, trocar a cor dele e a do retângulo 
	e aumentar e diminuir o retângulo até um limite definido.
	As informaçôes do que ocorre no programa será impresso no canto inferior da janela do console.
	
	Programador: Hugo Josue Lema Das Neves
	RGM: 47159
	Data da última modificação: 19/07/2023*/
	
	#include "funcoes.h" /*Cria_Retangulo(), Cria_Quadrado(), Apaga_Quadrado(), Movimenta_quadrado(), Ler_Teclado()*/
	#include "conio_v3.2.4.h"   /* textbackground(), textcolor(), gotoxy(), constantes BLACK, BLUE */
	#include "console_v1.5.4.h" /*EVENTO(), hit(), MaxDimensaoJanela(), setCursorStatus(), setDimensaojanela(),*/
	#include <time.h>
	
	/*Compilação
	CTRL+C ->gcc principal.c -o principal.exe conio_v3.2.4.c console_v1.5.4.c funcoes.c -Wall -pedantic -Wextra -Werror
	Execução -> principal.exe 
	*/
	
	int main(int argc, char *argv[])
	{
		/*Declaracao das Estruturas*/
		RETANGULO Retangulo;
		QUADRADO Quadrado;
		LE_TECLADO Leitura;
		JANELA Janela;
		INFORMACOES Informacoes;

		/*Artificio para silenciar os warnings*/
		argc = argc;
		argv = argv;
		
		/*Colocando a semente de aleatoriedade*/
		srand(time(NULL));

		/*Chamada das Funções para atribuições em geral*/
		Apaga_Cursor();
		Atribui_Valores_Q_R(&Retangulo, &Quadrado);
		Janela_Full(&Janela);
		Coord_Retangulo(&Retangulo);
		Cria_Quadrado(&Quadrado);

		/*Limpa a tela*/
		clrscr();

		/*Loop infinito*/
		do
		{
			Cria_Retangulo(&Retangulo);
			Movimenta_Quadrado(&Quadrado, &Retangulo);
			Le_Teclado(&Leitura, &Retangulo, &Quadrado, &Informacoes);

		}while(1);

		return 0;
	}