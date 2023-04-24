	/*Algumas funções para utilização na main principal*/
	#include "funcoes.h"
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	#include <windows.h>
	#include <stdlib.h>
	
	/*Tecla saída do programa*/
	#define ESC 27
	
	/*Teclas para velocidade do quadrado*/
	#define F1 112
	#define F2 113
	
	/*Teclas para tamanho do retângulo*/
	#define F3 114
	#define F4 115
	#define F5 116
	#define F6 117
	#define F7 118
	#define F8 119
	#define F9 120
	#define F10 121
	
	/*Teclas para o quadrado*/
	#define TECLA_PARA_CIMA
	#define TECLA_PARA_BAIXO
	#define TECLA_PARA_DIREITA
	#define TECLA_PARA_ESQUERDA
	
	/*typedef struct _Cores
	{
		Cores utilizadas para troca do retângulo e quadrado
		
	}CORES;*/
	
	void Aumenta_Retangulo()
	{
		/*Limites
		Menor linha: 1;
		Maior linha: 40;
		Menor coluna: 1;
		Maior coluna: 100;
		Menor largura da área: 3 colunas*/
		
		char tecla;
		int cont_linhas_cima = 0;
		int cont_linhas_baixo = 0;
		int cont_coluna_esq = 0;
		int cont_coluna_dir = 0;
		scanf("%c", &tecla);
		
		switch(tecla)
		{
			/*ESC -> Encerra o programa*/
			case 27: 
			{
				exit(0);
			}
			/*F3 -> Aumenta a área esquerda do retãngulo*/
			case 114: 
			{
				cont_coluna_esq++;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
			}
			/*F4 -> Diminui a área esquerda do retângulo*/
			case 115:
			{
				cont_coluna_esq--;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
			}
			/*F5 -> Aumenta a área direita do retângulo*/
			case 116:
			{
				cont_coluna_dir++;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_dir);
			}
			/*F6 -> Diminui a área direita do retângulo*/
			case 117:
			{
				cont_coluna_dir--;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_dir);
			}
			/*F7 -> Aumenta a área da borda horizontal superior*/
			case 118:
			{
				cont_linhas_cima++;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
			}
			/*F8 -> Diminui a área da borda horizontal superior*/
			case 119:
			{
				cont_linhas_cima--;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
			}
			/*F9 -> Aumenta a área da borda horizontal inferior*/
			case 120:
			{
				cont_linhas_baixo++;
				Cria_Retangulo(cont_linhas_baixo, cont_coluna_dir);
			}
			/*F -> Diminui a área da borda horizontal inferior*/
			case 121:
			{
				cont_linhas_baixo--;
				Cria_Retangulo(cont_linhas_baixo, cont_coluna_dir);
			}
			/*Caso o usuário digite qualquer outra tecla*/
			default:
			{
				Aumenta_Retangulo();
			}
		}
	}
	
	/*Cria as bordas do retângulo*/
	void Cria_Retangulo(int linhas, int colunas)
	{
		int i, j, x, y;
		
		/*Tamanho Máximo da Janela para (x,y)*/
		COORD tamMaxJanela;
			
		/*Guarda o tamanho maximo da janela do console*/
		tamMaxJanela = MaxDimensaoJanela();
			
		/*Seta a nova Dimensao da Janela do Console*/
		setDimensaoJanela(tamMaxJanela.X, tamMaxJanela.Y);
		
		x = (tamMaxJanela.X - colunas)/2;
		y = (tamMaxJanela.Y - linhas)/2;
		
		/*Linha horizontal superior do retângulo*/
		for(j = 0; j < colunas; j++)
		{
			gotoxy(x + j, y);
			putchar(32);
		}
		/*Linha vertical da esquerda do retângulo*/
		for(i = 0; i < linhas - 1; i++)
		{
			gotoxy(x, y + i + 1);
			putchar(32);
		}
		/*Linha horizontal inferior do retângulo*/
		for(j = 0; j < colunas - 1; j++)
		{
			gotoxy(x + j + 1, y + linhas - 1);
			putchar(32);
		}
		/*Linha vertical da direita do retângulo*/
		for(i = 0; i < linhas - 1; i++)
		{
			gotoxy(x + colunas - 1, y + i);
			putchar(32);
		}
		Cria_Quadrado();
	}
		
	void Cria_Quadrado()
	{
		/*Posições do Quadrado*/
		int pos_X, pos_Y;
		int tecla;
		COORD Quadrado;
		
		/*Centraliza o quadrado no meio da tela e muda a cor do fundo para preto*/
		textbackground(BLACK);
		Quadrado = MaxDimensaoJanela();
		
		pos_X = Quadrado.X/2;
		pos_Y = Quadrado.Y/2;
		gotoxy(pos_X, pos_Y);
		
		/*Desenha o Quadrado na tela*/
		while(tecla != ESC)
		{
			putchar(18);
			tecla = getch();
		}
	}	