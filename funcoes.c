	/*Algumas fun��es para utiliza��o na main principal*/
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	#include "funcoes.h"
	#include <stdlib.h>
	#include <time.h>
	#include <windows.h>
	
	/*Tecla sa�da do programa*/
	#define ESC 27
	
	/*Teclas para velocidade do quadrado*/
	#define F1 112
	#define F2 113
	
	/*Teclas para tamanho do ret�ngulo*/
	#define F3 114
	#define F4 115
	#define F5 116
	#define F6 117
	#define F7 118
	#define F8 119
	#define F9 120
	#define F10 121
	
	/*Teclas para o quadrado*/
	#define TECLA_PARA_BAIXO 40
	#define TECLA_PARA_CIMA 38
	#define TECLA_PARA_DIREITA 39
	#define TECLA_PARA_ESQUERDA 37
	
	/*Tecla para mudança da cor do Quadrado*/
	/*#define ESPAÇO Ñ sei seu código ainda*/
	
	/*Tecla para mudança da cor do retângulo*/
	#define TAB 9
	
	/*typedef struct _Cores
	{
		Cores utilizadas para troca do ret�ngulo e quadrado
			
	}CORES;*/
	
	/*Apaga o Quadrado passando a sua última posição que ele tinha*/
	void Apaga_Quadrado(int pos_X, int pos_Y, int direcao)
	{
		int i, j;
		
		/*Apaga a ultima impressão do quadrado em um dos 4 sentidos*/
		if(direcao == 0)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(pos_X - 1 + j, pos_Y - 1 + i + 1);
					putchar(32);
				}
			}
		}
		
		if(direcao == 1)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(pos_X - 1 - j, pos_Y - 1 + i + 1);
					putchar(32);
				}
			}
		}
		if(direcao == 2)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(pos_X - 1 + j, pos_Y - 1 + i + 3);
					putchar(32);
				}
			}
		}
		if(direcao == 3)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(pos_X - 1 + j, pos_Y - 1 + i - 3);
					putchar(32);
				}
			}
		}
	}
	
	/*Cria as bordas do retângulo*/
	void Cria_Retangulo(int linhas, int colunas)
	{
		int i, j, x, y;
		int direcao = 0;
		
		/*Tamanho Máximo da Janela para (x,y)*/
		COORD tamMaxJanela;
		COORD Quadrado;
		
		/*Gerando numeros aleatórios para a direção do quadrado*/
		srand(time(NULL));
		/*direcao = rand() % 4;*/
		
		
		/*Guarda o tamanho maximo da janela do console*/
		tamMaxJanela = MaxDimensaoJanela();
		Quadrado = MaxDimensaoJanela();
		
		/*Seta a nova Dimensao da Janela do Console*/
		setDimensaoJanela(tamMaxJanela.X, tamMaxJanela.Y);
		
		x = (tamMaxJanela.X - colunas)/2;
		y = (tamMaxJanela.Y - linhas)/2;
		
		_setcursortype(_NOCURSOR);
		/*Linha horizontal superior do ret�ngulo*/
		for(j = 0; j < colunas; j++)
		{
			gotoxy(x + j, y);
			putchar(32);
		}
		/*Linha vertical da esquerda do ret�ngulo*/
		for(i = 0; i < linhas - 1; i++)
		{
			gotoxy(x, y + i + 1);
			putchar(32);
		}
		/*Linha horizontal inferior do ret�ngulo*/
		for(j = 0; j < colunas - 1; j++)
		{
			gotoxy(x + j + 1, y + linhas - 1);
			putchar(32);
		}
		/*Linha vertical da direita do ret�ngulo*/
		for(i = 0; i < linhas - 1; i++)
		{
			gotoxy(x + colunas - 1, y + i);
			putchar(32);
		}
		Cria_Quadrado(Quadrado, direcao);
		_setcursortype(_NORMALCURSOR);
		
		/*Posiciona x e y para o final da linha console*/
		gotoxy(tamMaxJanela.X, tamMaxJanela.Y);
	}
		
	/*Função que irá criar o quadrado central a partir das coordenadas passadas na função Cria_Retangulo();*/
	void Cria_Quadrado(COORD Quadrado, int direcao)
	{
		int pos_X, pos_Y;
		
		/*Troca o fundo da janela do console e atribui o meio da janela do console as variaveis*/
		textbackground(BLACK);
		pos_X = Quadrado.X/2;
		pos_Y = Quadrado.Y/2;
		
		/*Chamada da função que cria e movimenta o quadrado para uns dos lados*/
		Movimenta_Quadrado(pos_X, pos_Y, direcao);
	}
	
	void Movimenta_Quadrado(int pos_X, int pos_Y, int direcao)
	{
		int i, j/*, cont = 0*/;
		
		/*Laço infinito*/
		do
		{
			/*Para a esquerda*/
			if(direcao == 0)
			{
				Sleep(100);
				pos_X -= 1;
				if(pos_X > 53)
				{
					for(i = 0; i < 3; i++)
					{
						for(j = 0; j < 3; j++)
						{
							gotoxy(pos_X - 1 - j - 1, pos_Y - 1 + i + 1);
							putchar(42);
						}
					}
					Apaga_Quadrado(pos_X, pos_Y, direcao);
				}
			}
			
			/*para a direita*/
			if(direcao == 1)
			{
				Sleep(100);
				pos_X += 1;
				for(i = 0; i < 3; i++)
				{
					for(j = 0; j < 3; j++)
					{
						gotoxy(pos_X - 1 + j + 1, pos_Y - 1 + i + 1);
						putchar(42);
					}
				}
				Apaga_Quadrado(pos_X, pos_Y, direcao);
			}
			
			/*para cima*/
			if(direcao == 2)
			{
				Sleep(100);
				pos_Y -= 1;
				for(i = 0; i < 3; i++)
				{
					for(j = 0; j < 3; j++)
					{
						gotoxy(pos_X - 1 + j, pos_Y - 1 + i);
						putchar(42);
					}
				}
				Apaga_Quadrado(pos_X, pos_Y, direcao);
			}
			
			/*para baixo*/
				if(direcao == 3)
				{
					Sleep(100);
					pos_Y += 1;
					for(i = 0; i < 3; i++)
					{
						for(j = 0; j < 3; j++)
						{
							gotoxy(pos_X - 1 + j, pos_Y - 1 + i);
							putchar(42);
						}
					}
					Apaga_Quadrado(pos_X, pos_Y, direcao);
				}
		}while(1);
	}

	
	
	
	
	
	
	
	
	
	