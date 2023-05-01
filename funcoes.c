	/*Algumas funções para utiliza��o na main principal*/
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	#include "funcoes.h"
	#include <stdlib.h>
	#include <time.h> /*rand()*/
	#include <windows.h>
	
	#define LINHAS 40
	#define COLUNAS 100
	
	/*Tecla saída do programa*/
	#define ESC 27
	
	/**/
	#define ENTER 13
	
	/*Teclas para mudança de cor do quadrado e retângulo*/
	#define ESPACO 32
	
	
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
	
	
	/*Tecla para mudança da cor do retângulo*/
	#define TAB 9
	
	/*Valores para realizar a saida do programa*/
	#define TRUE 1
	#define FALSE 0
	
	/*Apaga o Quadrado passando a sua última posição que ele tinha*/
	void Apaga_Quadrado(COORD *Quadrado, int sentido)
	{
		int i, j;
		
		/*Apaga a ultima impressão do quadrado em um dos 4 sentidos*/
		/*Esquerda*/
		if(sentido == 0)
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
		if(sentido == 1)
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
		if(sentido == 2)
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
		if(sentido == 3)
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
		/*i e j são variáveis contadoras para a impressão do retângulo
		x e y são variáveis responsáveis por armazenar os calculos para o retângulo e para este ser impresso*/
		int i, j, x, y;
		int sentido;
		
		/*Tamanho Máximo da Janela para (x,y)*/
		COORD tamMaxJanela;
		COORD Quadrado;
		
		/*Gerando numeros aleatórios para a direção do quadrado*/
		srand(time(NULL));
		sentido = rand() % 4;
		
		/*Guarda o tamanho maximo da janela do console*/
		tamMaxJanela = MaxDimensaoJanela();
		Quadrado = MaxDimensaoJanela();
		
		/*Seta a nova Dimensao da Janela do Console*/
		setDimensaoJanela(tamMaxJanela.X, tamMaxJanela.Y);
		
		x = (tamMaxJanela.X - colunas)/2;
		y = (tamMaxJanela.Y - linhas)/2;
		
		/*Apaga o cursor*/
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
		
		/*Laço infinito*/
		do
		{
			Ler_Teclado(&Quadrado, &sentido, x, y);
			/*Limites para as bordas da direira e esquerda*/
			/*Direita*/
			if(Quadrado.X < x + 4)
			{
				sentido = 1;
			}
			/*Esquerda*/
			if(Quadrado.X > x + colunas - 3)
			{
				sentido = 0;
			}
			
			/*Limites para as bordas de cima e de baixo do retângulo*/
			/*Baixo*/
			if(Quadrado.Y < y + 3)
			{
				sentido = 3;
			}
			/*Cima*/
			if(Quadrado.Y >= y + linhas - 4)
			{
				sentido = 2;
			}

			/*Chamada da função que cria e movimenta o quadrado para uns dos lados*/
			Movimenta_Quadrado(&Quadrado, sentido);
		}while(1);
		
		/*Devolve o cursor ao seu estado normal*/
		_setcursortype(_NORMALCURSOR);
		/*Posiciona x e y para o final da linha console*/
		gotoxy(tamMaxJanela.X, tamMaxJanela.Y);
	}
		
	/*Função que irá calcular o meio do Quadrado para X e Y que sao da estrutura COORD*/
	void Cria_Quadrado(COORD *Quadrado)
	{
		/*Troca o fundo da janela do console e posiciona no meio o Quadrado que ainda sera criado*/
		textbackground(BLACK);
		Quadrado->X = Quadrado->X/2;
		Quadrado->Y = Quadrado->Y/2;
	}
	
	/*Cria e movimenta para um dos 4 sentidos possíveis o quadrado*/
	void Movimenta_Quadrado(COORD *Quadrado, int sentido)
	{
		int i, j;
		
		/*Movimenta Quadrado para esquerda*/
		if(sentido == 0)
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
			Sleep(1000);
			Apaga_Quadrado(Quadrado, sentido);
		}
			
		/*para a direita*/
		if(sentido == 1)
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
			Sleep(1000);
			Apaga_Quadrado(Quadrado, sentido);
		}
			
		/*para cima*/
		if(sentido == 2)
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
			Sleep(1000);
			Apaga_Quadrado(Quadrado, sentido);
		}
			
		/*para baixo*/		
		if(sentido == 3)
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
			Sleep(1000);
			Apaga_Quadrado(Quadrado, sentido);
		}
	}
	
	/*Função que realiza as leituras das teclas lidas do teclado*/
	void Ler_Teclado(COORD *Quadrado, int *sentido, int x, int y)
	{
		int saida = TRUE;
		int velocidade_Quadrado = 250;
		/*Criacao de uma variavel que armazenara as teclas lidas do teclado do tipo Evento*/
		EVENTO leitura_teclado;
		COLORS cores;
		
		/*Verifica se houve um evento ocorrido do teclado*/
		do
		{
			/*Verifica se há algum pressionamento de tecla do teclado*/
			if(hit(KEYBOARD_HIT))
			{
				leitura_teclado = Evento();
				
				if(leitura_teclado.tipo_evento & KEY_EVENT)
				{
					if(leitura_teclado.teclado.status_tecla == LIBERADA)
					{
						/*O switch case ira agir de acordo com a tecla pressionada anterior*/
						switch(leitura_teclado.teclado.codigo_tecla)
						{
							/*Muda a cor do quadrado*/
							case ESPACO:
							{
								cores = rand() % 15 + 1;
								textcolor(cores);
								break;
							}
							
							/*Saida do loop e encerra o programa*/
							case ESC:
							{
								saida = FALSE;
								cores = LIGHTGRAY;
								exit(0);
								break;
							}
							
							/*velocidade para o quadrado*/
							/*Aumenta*/
							case F1:
							{
								Sleep(1000-velocidade_Quadrado);
								break;
							}
							/*Diminui*/
							case F2:
							{
								Sleep(1000+velocidade_Quadrado);
								break;
							}
							
							/*Aumenta a área para a esquerda*/
							case F3:
							{
								x++;
								break;
							}
							/*Diminui a partir da borda para a esquerda*/
							case F4:
							{
								x++;
								break;
							}
							/*Aumenta a área para a direita*/
							case F5:
							{
								x++;
								break;
							}
							/*Diminui a área a partir da borda da direita*/
							case F6:
							{
								y++;
								break;
							}
							/*Aumenta a área para cima*/
							case F7:
							{
								y++;
								break;;
							}
							/*Diminui a área a partir da borda de cima*/
							case F8:
							{
								y++;
								break;
							}
							/*Aumenta a área para baixo*/
							case F9:
							{
								y++;
								break;
							}
							/*Diminui a área a partir da borda de baixo*/
							case F10:
							{
								y++;
								break;
							}
							
							/*Verificações que irão movimentar o quadrado de acordo com as teclas que o usuário pressionar*/
							case SETA_PARA_ESQUERDA:
							{
								*sentido = 0;
								Quadrado->X -= 1;
								break;
							}	
							case SETA_PARA_DIREITA:
							{
								*sentido = 1;
								Quadrado->X += 1;
								break;
							}
							case SETA_PARA_BAIXO:
							{
								*sentido = 3;
								Quadrado->Y += 1;
								break;
							}
							case SETA_PARA_CIMA:
							{
								*sentido = 2;
								Quadrado->Y -= 1;
								break;
							}
							
							/*Muda a cor do retângulo nao funciona
							case TAB:
							{
								cores = rand() % 15 + 1;
								Cria_Retangulo(linhas, colunas);
								break;
							}*/
							
							
						}
					}
				}
			}
		}while(saida != TRUE);
	}
	

	
	
	
	
	
	
	
	
	
	