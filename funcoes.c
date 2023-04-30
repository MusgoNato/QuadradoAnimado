	/*Algumas fun��es para utiliza��o na main principal*/
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	#include "funcoes.h"
	#include <stdlib.h>
	#include <time.h> /*rand()*/
	#include <windows.h>
	
	/*Tecla sa�da do programa*/
	#define ESC 27
	#define ENTER 13
	#define BACKSPACE 8
	#define ESPACO 32
	#define TAB 9
	
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
	#define SETA_PARA_ESQUERDA 37
	#define SETA_PARA_CIMA 38
	#define SETA_PARA_DIREITA 39
	#define SETA_PARA_BAIXO 40
	
	/*Tecla para mudança da cor do Quadrado*/
	#define ESPACO 32
	
	/*Tecla para mudança da cor do retângulo*/
	#define TAB 9
	
	/*Apaga o Quadrado passando a sua última posição que ele tinha*/
	void Apaga_Quadrado(COORD *Quadrado, DIRECAO *direcao)
	{
		int i, j;
		
		/*Apaga a ultima impressão do quadrado em um dos 4 sentidos*/
		/*Esquerda*/
		if(direcao->sentido == 0)
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
		if(direcao->sentido == 1)
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
		if(direcao->sentido == 2)
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
		if(direcao->sentido == 3)
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
		
		/*Tamanho Máximo da Janela para (x,y)*/
		COORD tamMaxJanela;
		COORD Quadrado;
		DIRECAO *direcao;
		
		/*Gerando numeros aleatórios para a direção do quadrado*/
		srand(time(NULL));
		direcao->sentido = rand() % 3;
		
		
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
			Ler_Teclado(&Quadrado, direcao);
			/*Limites para as bordas da direira e esquerda*/
			/*Direita*/
			if(Quadrado.X < x + 4)
			{
				direcao->sentido = 1;
			}
			/*Esquerda*/
			if(Quadrado.X > x + colunas - 3)
			{
				direcao->sentido = 0;
			}
			
			/*Limites para as bordas de cima e de baixo do retângulo*/
			/*Baixo*/
			if(Quadrado.Y < y + 3)
			{
				direcao->sentido = 3;
			}
			/*Cima*/
			if(Quadrado.Y > y + linhas - y)
			{
				direcao->sentido = 2;
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
	void Movimenta_Quadrado(COORD *Quadrado, DIRECAO *direcao)
	{
		int i, j;
		
		/*Movimenta Quadrado para esquerda*/
		if(direcao->sentido == 0)
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
		if(direcao->sentido == 1)
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
		if(direcao->sentido == 2)
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
		if(direcao->sentido == 3)
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
	
	/*Função que realiza as leituras das teclas lidas do teclado*/
	void Ler_Teclado(COORD *Quadrado, DIRECAO *direcao)
	{
		/*Criacao de uma variavel que armazenara as teclas lidas do teclado do tipo Evento*/
		EVENTO leitura_teclado;
		
		/*Verifica se houve um evento ocorrido do teclado*/
		do
		{
		if(hit(KEYBOARD_HIT))
		{
			leitura_teclado = Evento();
			
			if(leitura_teclado.tipo_evento & KEY_EVENT)
			{
				if(leitura_teclado.teclado.status_tecla == LIBERADA)
				{
					switch(leitura_teclado.teclado.codigo_tecla)
					{
						/*Verificações que irão movimentar o quadrado de acordo com as teclas que o usuário pressionar*/
						case SETA_PARA_ESQUERDA:
						{
							direcao->sentido = 0;
							Quadrado->X -= 1;
							break;
						}	
						
						case SETA_PARA_DIREITA:
						{
							direcao->sentido = 1;
							Quadrado->X += 1;
							break;
						}
						case SETA_PARA_CIMA:
						{
							direcao->sentido = 2;
							Quadrado->Y -= 1;
							break;
						}
						case SETA_PARA_BAIXO:
						{
							direcao->sentido = 3;
							Quadrado->Y += 1;
							break;
						}
						
					}
				}
			}
		}
		}while(leitura_teclado.teclado.codigo_tecla == ESC);
	}
	

	
	
	
	
	
	
	
	
	
	