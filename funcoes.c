	/*Algumas funções para utiliza��o na main principal*/
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	#include "funcoes.h"
	#include <string.h>
	#include <time.h> 
	#include <windows.h>
	
	/*Tecla saída do programa*/
	#define ESC 27
	
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

	/*Funcao para atribuicao de aleatoriedade inicial e cores*/
	void Atribui_Valores_Q_R(RETANGULO *Retangulo, QUADRADO *Quadrado)
	{
		/*Definindo cor inicial e informações do Retangulo e Quadrado*/
		Retangulo->Cor_Retangulo = BLUE;
		Quadrado->Cor_Quadrado = LIGHTGRAY;

		/*Geração da primeira direcao do Quadrado e atribuicao de sua velocidade*/
		Quadrado->direcao = rand() % 4;
		Quadrado->velocidade = 1000;
	}

	/*Função que apaga o Cursor da tela*/
	void Apaga_Cursor()
	{
		_setcursortype(_NOCURSOR);
	}

	/*Apaga o Quadrado do meio do Retangulo*/
	void Apaga_Quadrado(QUADRADO *Quadrado_P)
	{
		textcolor(Quadrado_P->Cor_Quadrado);
		/*Esquerda*/
		if(Quadrado_P->direcao == 0)
		{
			gotoxy(Quadrado_P->Quadrado.X + 3, Quadrado_P->Quadrado.Y);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X + 3, Quadrado_P->Quadrado.Y + 1);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X + 3, Quadrado_P->Quadrado.Y - 1);
			printf("   ");
		}

		/*Direita*/
		if(Quadrado_P->direcao == 1)
		{
			gotoxy(Quadrado_P->Quadrado.X - 3, Quadrado_P->Quadrado.Y);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X - 3, Quadrado_P->Quadrado.Y + 1);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X - 3, Quadrado_P->Quadrado.Y - 1);
			printf("   ");
		}

		/*Cima*/
		if(Quadrado_P->direcao == 2)
		{
			gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y + 2);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y + 2);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y - 3);
			printf("   ");
		}

		/*Baixo*/
		if(Quadrado_P->direcao == 3)
		{
			gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y - 2);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y - 2);
			printf("   ");
			gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y + 3);
			printf("   ");
		}
	}

	/*Funcao que seta as coordenadas do Quadrado_P (P = Pequeno)*/
	void Cria_Quadrado(QUADRADO *Quadrado_P)
	{
		/*Setando as coordenadas do Quadrado menor ao meio do retangulo*/
		Quadrado_P->Quadrado = MaxDimensaoJanela();
		Quadrado_P->Quadrado.X = Quadrado_P->Quadrado.X/2;
		Quadrado_P->Quadrado.Y = Quadrado_P->Quadrado.Y/2;
	}

	/*Desenha o Quadrado do meio na tela*/
	void Desenha_Quadrado(QUADRADO *Quadrado_P)
	{
		textbackground(BLACK);
		textcolor(Quadrado_P->Cor_Quadrado);
		gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y);
		printf("***");
		gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y + 1);
		printf("***");
		gotoxy(Quadrado_P->Quadrado.X, Quadrado_P->Quadrado.Y - 1);
		printf("***");
		Apaga_Quadrado(Quadrado_P);

		/*Controle de velocidade do quadrado*/
		Sleep(Quadrado_P->velocidade);
	}

	/*Função que movimenta o Quadrado em uma das direcoes*/
	void Movimenta_Quadrado(QUADRADO *Quadrado_P, RETANGULO *Retangulo)
	{
		/*Verificação da movimentação esquerda e colisão com o Retangulo borda esquerda*/
		if(Quadrado_P->direcao == 0)
		{
			Quadrado_P->Quadrado.X -= 1;

			/*Verifica e inverte para direita o quadrado*/
			if(Quadrado_P->Quadrado.X == Retangulo->Ponto_A.X + 1)
			{
				Quadrado_P->direcao = 1;
			}
		}

		/*Verificação da movimentação direita e colisão com o Retangulo borda direita*/
		if(Quadrado_P->direcao == 1)
		{
			Quadrado_P->Quadrado.X += 1;
			
			/*Verifica e inverte para esquerda o quadrado*/
			if(Quadrado_P->Quadrado.X == Retangulo->Ponto_B.X - 3)
			{
				Quadrado_P->direcao = 0;
			}
		}

		/*Verificação da movimentação cima e colisão com o Retangulo borda de cima*/
		if(Quadrado_P->direcao == 2)
		{
			Quadrado_P->Quadrado.Y -= 1;

			/*Verifica e inverte para baixo o quadrado*/
			if(Quadrado_P->Quadrado.Y == Retangulo->Ponto_A.Y + 2)
			{
				Quadrado_P->direcao = 3;
			}
		}

		/*Verificação da movimentação baixo e colisão com o Retangulo borda de baixo*/
		if(Quadrado_P->direcao == 3)
		{
			Quadrado_P->Quadrado.Y += 1;

			/*Verfica e inverte para cima o quadrado*/
			if(Quadrado_P->Quadrado.Y == Retangulo->Ponto_B.Y - 3)
			{
				Quadrado_P->direcao = 2;
			}
		}

		Desenha_Quadrado(Quadrado_P);
	}

	/*Função que seta as coordenadas para a criação posterior do retangulo*/
	void Coord_Retangulo(RETANGULO *Retangulo)
	{
		/*Linhas e Colunas do Retangulo setadas*/
		Retangulo->linhas = 40;
		Retangulo->colunas = 100;

		Retangulo->Ponto_A = MaxDimensaoJanela();
		Retangulo->Ponto_A.X = Retangulo->Ponto_A.X/2/2;
		Retangulo->Ponto_A.Y = Retangulo->Ponto_A.Y/2/2;
		Retangulo->Ponto_B.X = Retangulo->Ponto_A.X + Retangulo->colunas;
		Retangulo->Ponto_B.Y = Retangulo->Ponto_A.Y + Retangulo->linhas;
	}

	/*Desenha o Retangulo na tela*/
	void Cria_Retangulo(RETANGULO *Retangulo)
	{
		int i;
		/*Jogando o clear aqui da certo o quadrado mas zoa todo o retangulo, manter comentado
		clrscr();
		*/
		
		textbackground(Retangulo->Cor_Retangulo);
		
		for(i = 0; i < Retangulo->colunas; i++)
		{
			/*Borda de cima*/
			gotoxy(Retangulo->Ponto_A.X + i, Retangulo->Ponto_A.Y);
			putchar(32);

			/*Borda de baixo*/
			gotoxy(Retangulo->Ponto_A.X + i, Retangulo->Ponto_B.Y - 1); /*Ele decrementa uma vez so*/
			putchar(32);
		}

		for(i = 0; i < Retangulo->linhas; i++)
		{
			/*Borda esquerda*/
			gotoxy(Retangulo->Ponto_A.X, Retangulo->Ponto_B.Y - i - 1);
			putchar(32);

			/*Borda direita*/
			gotoxy(Retangulo->Ponto_B.X, Retangulo->Ponto_A.Y + i);
			putchar(32);
		}

	}

	/*Função que ira maximizar o tamanho da janela do Console*/
	void Janela_Full(JANELA *Janela)
	{
		Janela->Tam_Max = MaxDimensaoJanela();
		setPosicaoJanela(1,1);
		setDimensaoJanela(Janela->Tam_Max.X, Janela->Tam_Max.Y);
	}

	/*Funcao que ira ler as teclas que o usuario pressionar*/
	void Le_Teclado(LE_TECLADO *Leitura, RETANGULO *Retangulo, QUADRADO *Quadrado_P, INFORMACOES *Informacoes)
	{
		/*Verifica se há algum pressionamento de tecla do teclado*/
		if(hit(KEYBOARD_HIT))
		{
			Leitura->leitura_teclado = Evento();
			
			if(Leitura->leitura_teclado.tipo_evento & KEY_EVENT)
			{
				if(Leitura->leitura_teclado.teclado.status_tecla == LIBERADA)
				{
					/*O switch case ira agir de acordo com a tecla pressionada anterior*/
					switch(Leitura->leitura_teclado.teclado.codigo_tecla)
					{
						case ESC:
						{
							/*Sai do programa pondo em ordem as configurações iniciais antes da partida*/
							textbackground(BLACK);
							textcolor(LIGHTGRAY);
							_setcursortype(_NORMALCURSOR);
							clrscr();
							gotoxy(1,1);
							exit(0);
							break;
						}

						case ESPACO:
						{
							/*Muda o cor do Quadrado*/
							Quadrado_P->Cor_Quadrado = rand() % 15 + 1;
							break;
						}
						
						/*Aumenta a velocidade do Quadrado*/
						case F1:
						{
							if(Quadrado_P->velocidade >= 100)
							{
								Quadrado_P->velocidade -= 100;
							}
							break;
						}
			
						/*Diminui a velocidade do Quadrado*/
						case F2:
						{
							if(Quadrado_P->velocidade <= 1000)
							{
								Quadrado_P->velocidade += 100;
							}
							break;
						}

						/*Aumenta a partir da esquerda*/
						case F3:
						{
							/*Verificacao da borda quando bate na janela*/
							if(Retangulo->Ponto_A.X > 1)
							{
								/*Soma as colunas para nao deixar o lado direito parado num canto*/
								Retangulo->colunas += 1;
								Retangulo->Ponto_A.X -= 1;

								/*Da um clear pra apagar a ultima posicao da linha do retangulo*/
								clrscr();
								Cria_Retangulo(Retangulo);
							}
							break;
						}

						/*Diminui a partir da esquerda*/
						case F4:
						{
							/*Verificação para nao passar da outra borda do Retangulo*/
							if(Retangulo->Ponto_A.X < Retangulo->Ponto_B.X - 6)
							{
								/*Decrementa as colunas para nao ultrapassar e arruinar as bordas do retangulo
								***É o processo inverso do anterior*/
								Retangulo->colunas -= 1;
								Retangulo->Ponto_A.X += 1;
								clrscr();
								Cria_Retangulo(Retangulo);
							}
							break;
						}

						/*Aumenta a area para direita*/
						case F5:
						{
							/*Aumenta as colunas e incrementa a coordenada B.X que esta no final da coordenada A.X*/
							Retangulo->colunas += 1;
							Retangulo->Ponto_B.X += 1;
							clrscr();
							Cria_Retangulo(Retangulo);
							break;
						}

						/*Diminui a area da direita*/
						case F6:
						{
							/*Verificação para para a borda direita nao encostar na borda esquerda*/
							if(Retangulo->Ponto_B.X > Retangulo->Ponto_A.X + 6)
							{
								/*Processo inverso do anterior*/
								Retangulo->colunas -= 1;
								Retangulo->Ponto_B.X -= 1;
								clrscr();
								Cria_Retangulo(Retangulo);
							}
							break;
						}

						/*Aumenta a borda de cima*/
						case F7:
						{
							if(Retangulo->Ponto_A.Y > 1)
							{
								/*Incrementa as linhas para nao arruinar a criacao das outras linhas do retangulo*/
								Retangulo->linhas += 1;
								Retangulo->Ponto_A.Y -= 1;
								clrscr();
								Cria_Retangulo(Retangulo);
							}
							break;
						}

						/*Diminui a borda de cima*/
						case F8:
						{
							if(Retangulo->Ponto_A.Y < Retangulo->Ponto_B.Y - 6)
							{
								/*Processo inverso ao anterior*/
								Retangulo->linhas -= 1;
								Retangulo->Ponto_A.Y += 1;
								clrscr();
								Cria_Retangulo(Retangulo);
							}
							break;
						}

						/*Aumenta a borda de baixo*/
						case F9:
						{
							/*Decrementa as linhas e a posicao do B.Y que esta na coordenada (A.Y + linhas)*/
							Retangulo->linhas += 1;
							Retangulo->Ponto_B.Y += 1;
							clrscr();
							Cria_Retangulo(Retangulo);
							break;
						}

						/*Diminui a borda de baixo*/
						case F10:
						{
							if(Retangulo->Ponto_B.Y > Retangulo->Ponto_A.Y + 6)
							{
								/*Processo inverso ao anterior*/
								Retangulo->linhas -= 1;
								Retangulo->Ponto_B.Y -= 1;
								clrscr();
								Cria_Retangulo(Retangulo);
							}
							break;

						}

						/*Seta para esquerda*/
						case SETA_PARA_ESQUERDA:
						{
							Quadrado_P->direcao = 0;
							gotoxy(1,1);
							textcolor(LIGHTGRAY);
							strcpy(Informacoes->Inf_direcao, "Direcao do Quadrado: Esquerda\n");
							printf(Informacoes->Inf_direcao);
							break;
						}

						/*Seta para direita*/
						case SETA_PARA_DIREITA:
						{
							Quadrado_P->direcao = 1;
							
							gotoxy(1,1);
							clreol();
							textcolor(LIGHTGRAY);
							strcpy(Informacoes->Inf_direcao, "Direcao do Quadrado: Direita\n");
							printf(Informacoes->Inf_direcao);
							break;
						}

						/*Seta para cima*/
						case SETA_PARA_CIMA:
						{
							Quadrado_P->direcao = 2;
							gotoxy(1,1);
							clreol();
							textcolor(LIGHTGRAY);
							strcpy(Informacoes->Inf_direcao, "Direcao do Quadrado: Cima\n");
							printf(Informacoes->Inf_direcao);
							break;
						}

						/*seta para baixo*/
						case SETA_PARA_BAIXO:
						{
							Quadrado_P->direcao = 3;
							gotoxy(1,1);
							clreol();
							textcolor(LIGHTGRAY);
							strcpy(Informacoes->Inf_direcao, "Direcao do Quadrado: Baixo\n");
							printf(Informacoes->Inf_direcao);
							break;
						}

						/*Muda a cor do Retangulo*/
						case TAB:
						{
							Retangulo->Cor_Retangulo = rand() % 15 + 1;
							break;
						}
					}
				}
			}
		}
	}

/*Outro jeito seria mudar o decremento do quadrado(Quando ele bate na borda) 
dentro da funcao que movimenta o quadrado, seria na funcao que desenha ele*/