	/*Algumas fun��es para utiliza��o na main principal*/
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	#include "funcoes.h"
	#include <stdlib.h>
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
	#define TECLA_PARA_BAIXO
	#define TECLA_PARA_CIMA
	#define TECLA_PARA_DIREITA
	#define TECLA_PARA_ESQUERDA
	
	/*Tecla para mudança da cor do Quadrado*/
	/*#define ESPAÇO Ñ sei seu código ainda*/
	
	/*Tecla para mudança da cor do retângulo*/
	#define TAB 9
	
	/*typedef struct _Cores
	{
		Cores utilizadas para troca do ret�ngulo e quadrado
		
	}CORES;*/
	
	/*Apaga o Quadrado passando a sua última posição que ele tinha*/
	void Apaga_Quadrado(int pos_X, int pos_Y, int linhas)
	{
		int i;
		
		/*"Apaga" o quadrado anterior*/
		for(i = 0; i < linhas - i; i++)
		{
			/*Meio do Quadrado*/
			gotoxy(pos_X, pos_Y - i);
			putchar(32);
					
			/*Acima do meio*/ 
			gotoxy(pos_X, pos_Y + 1 - i);
			putchar(32);
					
			/*Abaixo do meio*/
			gotoxy(pos_X, pos_Y + 2 - i);
			putchar(32);
				
			/*[0][0] ponto esquerdo*/
			gotoxy(pos_X - 1, pos_Y - i);
			putchar(32);
					
			/*direita do meio*/
			gotoxy(pos_X - 1, pos_Y + 1);
			putchar(32);
						
			/*ponta esquerda de baixo do quadrado*/
			gotoxy(pos_X - 1, pos_Y + 2 - i);
			putchar(32);
					
			/**/
			gotoxy(pos_X + 1, pos_Y - i);
			putchar(32);
					
			/**/
			gotoxy(pos_X + 1, pos_Y + 1 - i);
			putchar(32);
					
			/*ponta direita de baixo do quadrado*/
			gotoxy(pos_X + 1, pos_Y + 2 - i);
			putchar(32);
			Sleep(1000/100);
		}	
	}
	
	/*Essa função nao ta pronta e nao interfere no programa*/
	void Aumenta_Retangulo()
	{
		/*Limites
		Menor linha: 1;
		Maior linha: 40;
		Menor coluna: 1;
		Maior coluna: 100;
		Menor largura da �rea: 3 colunas*/
		
		char tecla;
		int cont_linhas_cima = 0;
		int cont_linhas_baixo = 0;
		int cont_coluna_esq = 0;
		int cont_coluna_dir = 0;
		tecla = getch();
		
		switch(tecla)
		{
			/*ESC -> Encerra o programa*/
			case 27:
			{
				exit(0);
				break;
			}
			/*F3 -> Aumenta a �rea esquerda do ret�ngulo*/
			case 114: 
			{
				cont_coluna_esq++;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
				break;
			}
			/*F4 -> Diminui a �rea esquerda do ret�ngulo*/
			case 115:
			{
				cont_coluna_esq--;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
				break;
			}
			/*F5 -> Aumenta a �rea direita do ret�ngulo*/
			case 116:
			{
				cont_coluna_dir++;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_dir);
				break;
			}
			/*F6 -> Diminui a �rea direita do ret�ngulo*/
			case 117:
			{
				cont_coluna_dir--;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_dir);
				break;
			}
			/*F7 -> Aumenta a �rea da borda horizontal superior*/
			case 118:
			{
				cont_linhas_cima++;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
				break;
			}
			/*F8 -> Diminui a �rea da borda horizontal superior*/
			case 119:
			{
				cont_linhas_cima--;
				Cria_Retangulo(cont_linhas_cima, cont_coluna_esq);
				break;
			}
			/*F9 -> Aumenta a �rea da borda horizontal inferior*/
			case 120:
			{
				cont_linhas_baixo++;
				Cria_Retangulo(cont_linhas_baixo, cont_coluna_dir);
				break;
			}
			/*F10 -> Diminui a �rea da borda horizontal inferior*/
			case 121:
			{
				cont_linhas_baixo--;
				Cria_Retangulo(cont_linhas_baixo, cont_coluna_dir);
				break;
			}
			/*Caso o usu�rio digite qualquer outra tecla*/
			default:
			{
				Aumenta_Retangulo();
				break;
			}
		}
	}
	
	/*Cria as bordas do ret�ngulo*/
	void Cria_Retangulo(int linhas, int colunas)
	{
		int i, j, x, y;
		
		/*Tamanho M�ximo da Janela para (x,y)*/
		COORD tamMaxJanela;
		COORD Quadrado;
		
		/*Guarda o tamanho maximo da janela do console*/
		tamMaxJanela = MaxDimensaoJanela();
		Quadrado = MaxDimensaoJanela();
		
		/*Seta a nova Dimensao da Janela do Console*/
		setDimensaoJanela(tamMaxJanela.X, tamMaxJanela.Y);
		
		x = (tamMaxJanela.X - colunas)/2;
		y = (tamMaxJanela.Y - linhas)/2;
		
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
		Cria_Quadrado(Quadrado, linhas);
		system("pause");
		
		/*Posiciona x e y para o final da linha console*/
		gotoxy(tamMaxJanela.X, tamMaxJanela.Y);
	}
		
	void Cria_Quadrado(COORD Quadrado, int linhas)
	{
		int i;
		int pos_X;
		int pos_Y;
		
		/*Troca o fundo da janela do console*/
		textbackground(BLACK);
		
		pos_X = Quadrado.X/2;
		pos_Y = Quadrado.Y/2;
		
		/*Desenha o Quadrado na tela*/
		for(i = 0; i < linhas - i; i++)
		{
			/*Meio do Quadrado*/
			gotoxy(pos_X, pos_Y - i);
			putchar(42);
					
			/*Acima do meio*/ 
			gotoxy(pos_X, pos_Y + 1 - i);
			putchar(42);
					
			/*Abaixo do meio*/
			gotoxy(pos_X, pos_Y + 2 - i);
			putchar(42);
				
			/*[0][0] ponto esquerdo*/
			gotoxy(pos_X - 1, pos_Y - i);
			putchar(42);
					
			/*direita do meio*/
			gotoxy(pos_X - 1, pos_Y + 1);
			putchar(42);
						
			/*ponta esquerda de baixo do quadrado*/
			gotoxy(pos_X - 1, pos_Y + 2 - i);
			putchar(42);
					
			/**/
			gotoxy(pos_X + 1, pos_Y - i);
			putchar(42);
					
			/**/
			gotoxy(pos_X + 1, pos_Y + 1 - i);
			putchar(42);
					
			/*ponta direita de baixo do quadrado*/
			gotoxy(pos_X + 1, pos_Y + 2 - i);
			putchar(42);
			Sleep(1000/10);
			Apaga_Quadrado(pos_X, pos_Y, linhas);
			}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	