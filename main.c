/*Main principal*/
/*Programa: Multiplos Quadrados Animados
Descrição: O programa realiza a criação de um retângulo e um quadrado ao meio dele,	onde o usuário terá a possibilidade de 
locomover o quadrado nas direçôes para cima, para baixo, para a esquerda e para a direita. 
Além disso, poderá aumentar a velocidade do quadrado, trocar a cor dele e a do retângulo 
e aumentar e diminuir o retângulo até um limite definido. O usuário tera também a opção de criar mais de um retangulo na tela
onde os quadrados ao meio dele estarao se movimentando em velocidades diferentes.
Alem disso, o usuario podera modificar cada retangulo com seu respectivo quadrado no meio e havera destaque de cor ao retangulo em qual ele estiver mexendo.


Programador: Hugo Josue Lema Das Neves
RGM: 47159
Data da última modificação: 11/06/2023*/

/*gcc main.c -o main.exe conio_v3.2.4.c console_v1.5.4.c funcoes.c -Wall -pedantic -Wextra -Werror*/
/*main.exe*/

#include <stdio.h>
#include "funcoes.h" /*Maximixa_Janela(), Criacao_Retangulos(), Le_Teclado()*/
#include "conio_v3.2.4.h" /*clrscr()*/
#include "console_v1.5.4.h"

int main(int argc, char *argv[])
{
	/*Armazena a dimensao da janela*/
	JANELA Janela;

	/*Estrutura da leitura de teclas*/
	LEITURA_TECLADO Leitura;

	/*Vetor de estrutura para os retangulos*/
	RETANGULO Retangulos[9];
	
	/*Quadrados criados dentro do retangulo*/
	QUADRADO Quadrados[9];

	/*Artificio para silenciar os Warnings*/
	argc = argc;
	argv = argv;
	
	/*Limpa a tela*/
	clrscr();

	/*Primeiro retangulo e quadraodos inicializados nos seus respectivos contadores*/
	Retangulos->cont_retangulos = 0;
	Retangulos->cor_retangulo = 1;
	Quadrados->cont_quadrados = 0;
	Retangulos[Retangulos->cont_retangulos].ponto_A.X = 1;
	Retangulos[Retangulos->cont_retangulos].ponto_A.Y = 1; 
	Retangulos[Retangulos->cont_retangulos].ponto_B.X = 1;
	Retangulos[Retangulos->cont_retangulos].ponto_B.Y = 1;

	/*Chamada da função para maximizar a janela do prompt*/
	Maximiza_Janela(&Janela);

	/*Loop infinito*/
	do
	{
		/*Chamada da função para criação dos Retângulos*/
		Cria_Retangulos(Retangulos, Quadrados);

		/*Chamada da função para ler as teclas do teclado*/
		Le_Teclado(Retangulos, &Leitura, Quadrados);
		
	}while(1);
	return 0;
}