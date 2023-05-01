	/*Bibliotecas que serão utilizadas*/
	#include <locale.h>
	#include <stdlib.h>
	#include <windows.h>
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	
	/*Chamada da funções*/
	void Cria_Retangulo(int linhas, int colunas);
	void Cria_Quadrado(COORD *Quadrado);
	void Apaga_Quadrado(COORD *Quadrado, int sentido);
	void Movimenta_Quadrado(COORD *Quadrado, int sentido, int velocidade);
	void Ler_Teclado(COORD *Quadrado, int *sentido, int *x, int *y, int *velocidade, COLORS *cores, EVENTO *leitura_teclado);