	/*Chamadas de fun��es e declara��o de estruturas*/
	#include <locale.h>
	#include <stdlib.h>
	#include <windows.h>
	
	/*Chamada da fun��o que  ir� criar o nosso ret�ngulo*/
	/*void Aumenta_Retangulo();*/
	void Cria_Retangulo(int linhas, int colunas);
	void Cria_Quadrado(COORD *Quadrado);
	void Apaga_Quadrado(COORD *Quadrado, int direcao);
	void Movimenta_Quadrado(COORD *Quadrado, int direcao);