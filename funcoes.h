	/*Bibliotecas que serão utilizadas*/
	#include <windows.h> /*COORD*/
	#include "conio_v3.2.4.h"  /* textbackground(), gotoxy(), constantes BLACK, BLUE, LIGHTGRAY */
	#include "console_v1.5.4.h" /*EVENTO(), hit(), MaxDimensaoJanela(), setCursorStatus(), setDimensaojanela(),*/
	
	/*Chamada da funções*/
	/*Apaga os rastros do Quadrado, em quaisquer direções que ele estiver indo*/
	void Apaga_Quadrado(COORD *Quadrado, int sentido);
	
	/*Cria o Retangulo e chama as outras funçoes, Cria_Quadrado(), Ler_Teclado() e Movimenta_Quadrado()*/
	void Cria_Retangulo(int linhas, int colunas);
	
	/*Seta o meio da janela para que posteriormente seja usado para imprimir o quadrado na tela*/
	void Cria_Quadrado(COORD *Quadrado);
	
	
	/*Movimenta o Quadrado para uma das 4 direções possíveis*/
	void Movimenta_Quadrado(COORD *Quadrado, int sentido, int velocidade);
	
	/*Faz a leitura do teclado, onde as teclas pressionadas irão modificar o quadrado ou retangulo de acordo com o que o usuário irá querer fazer*/
	void Ler_Teclado(COORD *Quadrado, int *sentido, int *x, int *y, int *velocidade, COLORS *cores, EVENTO *leitura_teclado);