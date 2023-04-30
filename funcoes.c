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
	void Apaga_Quadrado(COORD *Quadrado, int direcao)
	{
		int i, j;
		
		/*Apaga a ultima impressão do quadrado em um dos 4 sentidos*/
		/*Esquerda*/
		if(direcao == 0)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 + j - 1, Quadrado->Y - 1 + i + 1);
					putchar(32);
				}
			}
		}
		
		/*Direita*/
		if(direcao == 1)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 - j + 1, Quadrado->Y - 1 + i + 1);
					putchar(32);
				}
			}
		}
		
		/*Cima*/
		if(direcao == 2)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 + j, Quadrado->Y - 1 + i + 2);
					putchar(32);
				}
			}
		}
		
		/*Baixo*/
		if(direcao == 3)
		{
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 + j, Quadrado->Y - 1 + i - 1);
					putchar(32);
				}
			}
		}
	}
	
	/*Cria as bordas do retângulo*/
	void Cria_Retangulo(int linhas, int colunas)
	{
		int i, j, x, y;
		int direcao;
		
		/*Tamanho Máximo da Janela para (x,y)*/
		COORD tamMaxJanela;
		COORD Quadrado;
		
		/*Gerando numeros aleatórios para a direção do quadrado*/
		srand(time(NULL));
		direcao = rand() % 4;
		
		
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

		Cria_Quadrado(&Quadrado);
		_setcursortype(_NORMALCURSOR);
		
		/*Laço infinito*/
		do
		{
			/*Limites para as bordas da direira e esquerda*/
			/*Direita*/
			if(Quadrado.X < x + 4)
			{
				direcao = 1;
			}
			/*Esquerda*/
			if(Quadrado.X > x + colunas - 3)
			{
				direcao = 0;
			}
			/*Limites para as bordas de cima e de baixo do retângulo*/
			/*Baixo*/
			if(Quadrado.Y < y + 3)
			{
				direcao = 3;
			}
			/*Cima*/
			if(Quadrado.Y > y + linhas - y)
			{
				direcao = 2;
			}
			/*Chamada da função que cria e movimenta o quadrado para uns dos lados*/
			Movimenta_Quadrado(&Quadrado, direcao);
			
		}while(1);
		/*Posiciona x e y para o final da linha console*/
		gotoxy(tamMaxJanela.X, tamMaxJanela.Y);
	}
		
	/*Função que irá criar o quadrado central a partir das coordenadas passadas na função Cria_Retangulo();*/
	void Cria_Quadrado(COORD *Quadrado)
	{
		/*Troca o fundo da janela do console e posiciona no meio do Quadrado à ser criado*/
		textbackground(BLACK);
		Quadrado->X = Quadrado->X/2;
		Quadrado->Y = Quadrado->Y/2;
	}
	
	/*Cria e movimenta para um dos 4 sentidos possíveis o quadrado*/
	void Movimenta_Quadrado(COORD *Quadrado, int direcao)
	{
		int i, j;
		
		/*Movimenta Quadrado para esquerda*/
		if(direcao == 0)
		{
			Quadrado->X -= 1;
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 - j + 1, Quadrado->Y - 1 + i + 1);
					putchar(42);
				}
			}
			Sleep(100);
			Apaga_Quadrado(Quadrado, direcao);
		}
			
		/*para a direita*/
		if(direcao == 1)
		{
			Quadrado->X += 1;
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 + j - 1, Quadrado->Y - 1 + i + 1);
					putchar(42);
				}
			}
			Sleep(100);
			Apaga_Quadrado(Quadrado, direcao);
		}
			
		/*para cima*/
		if(direcao == 2)
		{
			Quadrado->Y -= 1;
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 + j, Quadrado->Y - 1 + i + 2);
					putchar(42);
				}
			}
			Sleep(100);
			Apaga_Quadrado(Quadrado, direcao);
		}
			
		/*para baixo*/		
		if(direcao == 3)
		{
			Quadrado->Y += 1;
			for(i = 0; i < 3; i++)
			{
				for(j = 0; j < 3; j++)
				{
					gotoxy(Quadrado->X - 1 + j, Quadrado->Y - 1 + i - 1);
					putchar(42);
				}
			}
			Sleep(100);
			Apaga_Quadrado(Quadrado, direcao);
		}
	}

	
	
	
	
	
	
	
	
	
	