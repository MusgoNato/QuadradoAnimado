	/*Chamadas de fun��es e declara��o de estruturas*/
	#include <locale.h>
	#include <stdlib.h>
	#include <windows.h>
	
	/*Chamada da fun��o que  ir� criar o nosso ret�ngulo*/
	/*void Aumenta_Retangulo();*/
	void Cria_Retangulo(int linhas, int colunas);
	void Cria_Quadrado(COORD Quadrado, int linhas);
	void Apaga_Quadrado(int pos_X, int pos_Y, int linhas, int direcao);
	void Quadrado_Invertido(int pos_X, int pos_Y, int linhas, int direcao);