/*Bibliotecas utilizadas durante o programa*/
#include "funcoes.h" 
#include "conio_v3.2.4.h" /*clrscr(), gotoxy(), textbackground(), textcolor(), setcursortype()*/
#include "console_v1.5.4.h" /*MaxDimensaoJanela(), setPosicaoJanela(), setDimensaoJanela(), hit(), Evento() */
#include <windows.h>

/*Teclas para mudanca de cor do quadrado e retangulo*/
#define ESPACO 32

/*Tecla cricao de um retangulo novo*/
#define CTRL 17

/*Teclas para tamanho do retangulo*/
#define F3 114 /*Aumenta e diminui borda direita*/
#define F4 115

#define F5 116
#define F6 117
#define F7 118
#define F8 119
#define F9 120
#define F10 121


/*Tecla para mudança da cor do retangulo*/
#define TAB 9

/*Apaga a borda do Retangulo atual da area de cima"*/
void Apaga_Borda_Retangulo_Cima(RETANGULO Retangulos[])
{
	int i;
	textbackground(BLACK);
	for(i = 0; i < Retangulos->colunas; i++)
	{
		gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.X + i, Retangulos[Retangulos->cont_retangulos].ponto_A.Y);
		putchar(32);
	}
}

/*Apaga a borda atual de baixo do retangulo*/
void Apaga_Borda_Retangulo_Baixo(RETANGULO Retangulos[])
{
	int i;
	textbackground(BLACK);
	for(i = 0; i < Retangulos->colunas; i++)
	{
		gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.X + i, Retangulos[Retangulos->cont_retangulos].ponto_B.Y);
		putchar(32);
	}
}

/*Apaga a borda do Retangulo atual "pra direita somente"*/
void Apaga_Borda_Retangulo_Direito(RETANGULO Retangulos[])
{
	int i;
	textbackground(BLACK);

	for(i = 0; i < Retangulos->linhas; i++)
	{
		gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_B.X - 1, Retangulos[Retangulos->cont_retangulos].ponto_A.Y + i + 1);
		putchar(32);
	}
}

/*Apaga a borda atual esquerda*/
void Apaga_Borda_Retangulo_Esquerdo(RETANGULO Retangulos[])
{
	int i;
	textbackground(BLACK);

	for(i = 0; i < Retangulos->linhas; i++)
	{
		gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.X, Retangulos[Retangulos->cont_retangulos].ponto_A.Y + i);
		putchar(32);
	}
}

/* Função para criação dos quadrados dentro do retângulo */
void Cria_Quadrados(QUADRADO Quadrados[], RETANGULO Retangulos[], int indice_retangulo)
{
    /* Cor padrao do quadrado */
	int i, j;
    
    int centro_x;
	int centro_y;
	int canto_x;
	int canto_y;

    /* Calcula as coordenadas do quadrado pequeno no centro do retângulo */
    centro_x = (Retangulos[indice_retangulo].ponto_A.X + Retangulos[indice_retangulo].ponto_B.X)/2;
    centro_y = (Retangulos[indice_retangulo].ponto_A.Y + Retangulos[indice_retangulo].ponto_B.Y)/2;
    
    /* Calcula as coordenadas do canto superior esquerdo do quadrado */
    canto_x = centro_x - 3/2;
    canto_y = centro_y - 3/2;
    
    /* Desenha o quadrado pequeno */
	textbackground(BLACK);
	textcolor(Quadrados[Quadrados->cont_quadrados].cor_quadrado);
    for (i = canto_y; i < canto_y + 3; i++)
    {
        gotoxy(canto_x, i);
        for (j = 0; j < 3; j++)
        {
            putchar(42);
        }
    }
}

/*Maximiza a Janela do prompt de comando*/
void Maximiza_Janela(JANELA *Janela)
{
	/*Maximizacao da janela do prompt de comando*/
	Janela->janela_final = MaxDimensaoJanela();

	setDimensaoJanela(Janela->janela_final.X, Janela->janela_final.Y);
	setPosicaoJanela(0,0);
	
	/*Desliga o Cursor*/
	_setcursortype(_NOCURSOR);
}

/*Função para criação dos retangulos na tela*/
void Cria_Retangulos(RETANGULO Retangulos[], QUADRADO Quadrados[])
{
	int i, j, k;
	int linhas = 20;
	int colunas = 38;

	/*Loop para contar ate os retangulos definidos*/
	for(i = 0; i <= Retangulos->cont_retangulos/* && i <= Quadrados->cont_quadrados*/; i++)
	{
		textbackground(Retangulos->cor_retangulo);

		/*Atribui os respectivos valores para as linhas e colunas*/
		Retangulos[i].linhas = linhas;
		Retangulos[i].colunas = colunas;
		
		/*Verificação do primeiro retangulo para atribuicao das coordenadas*/
		Retangulos[i].ponto_A.X = Retangulos[Retangulos->cont_retangulos].ponto_A.X;
		Retangulos[i].ponto_B.Y = Retangulos[Retangulos->cont_retangulos].ponto_A.Y;

		/*Inicializa a COORD ponto B para utilizacao dela durante a criacao do retangulo*/
		Retangulos[i].ponto_B.X = Retangulos[i].ponto_A.X + Retangulos[i].colunas;
		Retangulos[i].ponto_B.Y = Retangulos[i].ponto_A.Y + Retangulos[i].linhas;

		/*Loops para as bordas do retangulo*/
		for (j = 0; j < Retangulos[i].colunas; j++)
		{
			/*Borda de cima*/
			gotoxy(Retangulos[i].ponto_A.X + j, Retangulos[i].ponto_A.Y);
			putchar(32);  
			
			/*Borda de baixo*/
			gotoxy(Retangulos[i].ponto_A.X + j, Retangulos[i].ponto_B.Y);
			putchar(32);
		}
		
		for (k = 0; k < Retangulos[i].linhas; k++)
		{
			/*Borda esquerda*/
			gotoxy(Retangulos[i].ponto_A.X, Retangulos[i].ponto_A.Y + k);  
			putchar(32);

			/*Borda direita*/
			gotoxy(Retangulos[i].ponto_B.X - 1, Retangulos[i].ponto_A.Y + k);
			putchar(32);
		}
		/*Quadrados[i].Quadrado_Pequeno.X = (Retangulos[i].ponto_A.X + Retangulos[i].colunas)/2;
		Quadrados[i].Quadrado_Pequeno.Y = (Retangulos[i].ponto_B.X + Retangulos[i].linhas)/2;*/

		Cria_Quadrados(Quadrados, Retangulos, i);
		/*printf("(%d) (%d)\n", i, Retangulos->cont_retangulos);*/
	}
	
}

/*Leitura do teclado*/
void Le_Teclado(RETANGULO Retangulos[], LEITURA_TECLADO *leitura, QUADRADO Quadrados[])
{
	int i, cont_bordas = 0;
	if(hit(KEYBOARD_HIT))
	{
		leitura->leitura_teclado = Evento();
		
		if(leitura->leitura_teclado.tipo_evento & KEY_EVENT)
		{
			if(leitura->leitura_teclado.teclado.status_tecla == LIBERADA)
			{
				/*O switch case ira agir de acordo com a tecla pressionada anterior*/
				switch(leitura->leitura_teclado.teclado.codigo_tecla)
				{
					/*Criacao de um novo retangulo*/
					case CTRL:
					{
						/*if(Retangulos->cont_retangulos < 10)
						{
							Retangulos[Retangulos->cont_retangulos].cor_retangulo = BLUE;
							Retangulos[Retangulos->cont_retangulos - 1].cor_retangulo = LIGHTGRAY;
							Retangulos->cont_retangulos += 1;
							Quadrados->cont_quadrados += 1;
							testes
							printf("(%d | %d)", Retangulos[Retangulos->cont_retangulos].ponto_A.X, Retangulos[Retangulos->cont_retangulos].ponto_A.Y);
							printf("(%d | %d)", Retangulos[Retangulos->cont_retangulos].ponto_B.X, Retangulos[Retangulos->cont_retangulos].ponto_B.Y);
						}*/
						break;
					}

					/*Troca a cor do quadrado do meio*/
					case ESPACO:
					{
						Quadrados[Quadrados->cont_quadrados].cor_quadrado = rand() % 15 + 1;
						break;
					}

					/*Aumenta a area para a esquerda*/
					case F3:
					{
						cont_bordas = 0;
					
						Apaga_Borda_Retangulo_Esquerdo(Retangulos);
						textbackground(Retangulos[Retangulos->cont_retangulos].cor_retangulo);
						Retangulos[Retangulos->cont_retangulos].ponto_A.X -= cont_bordas + 1;
						for(i = 0; i < Retangulos->colunas; i++)
						{
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.X, Retangulos[Retangulos->cont_retangulos].ponto_A.Y - i - cont_bordas);
							putchar(32);
						}	
						break;
					}

					/*Diminui a area da esquerda*/
					case F4:
					{
						cont_bordas = 0;
						/*Apaga a borda atual esquerda para desenhar a nova borda com a posicao nova*/
						
						Apaga_Borda_Retangulo_Esquerdo(Retangulos);
						textbackground(Retangulos[Retangulos->cont_retangulos].cor_retangulo);
						Retangulos[Retangulos->cont_retangulos].ponto_A.X += cont_bordas + 1;
						for(i = 0; i < Retangulos->linhas; i++)
						{
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.X, Retangulos[Retangulos->cont_retangulos].ponto_A.Y + i + cont_bordas);
							putchar(32);
						}	
						break;
					}

					/*Aumenta a borda da direita*/
					case F5:
					{
						cont_bordas = 0;
						/*Apaga a borda atual direita para desenhar a nova borda com a posicao nova*/
					
						Apaga_Borda_Retangulo_Direito(Retangulos);

						/*Desenha a nova borda*/
						textbackground(Retangulos[Retangulos->cont_retangulos].cor_retangulo);
						Retangulos[Retangulos->cont_retangulos].ponto_A.X += cont_bordas + 1;
						for(i = 0; i < Retangulos->linhas; i++)
						{
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_B.X + cont_bordas, Retangulos[Retangulos->cont_retangulos].ponto_A.Y + i);
							putchar(32);
						}
						break;
					}

					/*Diminui a borda da direita*/
					case F6:
					{
						cont_bordas = 0;
						/*Apaga a borda atual direita para desenhar a nova borda com a posicao nova*/
				
						Apaga_Borda_Retangulo_Direito(Retangulos);

						Retangulos[Retangulos->cont_retangulos].ponto_A.X -= cont_bordas + 1;
						for(i = 0; i < Retangulos->linhas; i++)
						{
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_B.X - cont_bordas, Retangulos[Retangulos->cont_retangulos].ponto_A.Y - i);
							putchar(32);
						}
						break;
					}

					/*Aumenta a area para cima*/
					case F7:
					{
						cont_bordas = 0;
						/*Apaga a borda de cima atual para criacao de uma nova*/
					
						Apaga_Borda_Retangulo_Cima(Retangulos);
						Retangulos[Retangulos->cont_retangulos].ponto_A.Y -= cont_bordas + 1;
						for(i = 0; i < Retangulos->colunas; i++)
						{
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.X, Retangulos[Retangulos->cont_retangulos].ponto_A.Y + cont_bordas);
							putchar(32);
						}
						break;
					}

					/*Diminui a area de cima*/
					case F8:
					{
						cont_bordas = 0;

						Apaga_Borda_Retangulo_Cima(Retangulos);
						Retangulos[Retangulos->cont_retangulos].ponto_A.Y += cont_bordas + 1;
						for(i = 0; i < Retangulos->colunas; i++)
						{
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.X, Retangulos[Retangulos->cont_retangulos].ponto_A.Y - cont_bordas);
							putchar(32);
						}
						break;
					}

					/*Aumenta a area para baixo*/
					case F9:
					{
						cont_bordas = 0;

						/*Apaga a posicao atual da borda de baixo do retangulo*/
						Apaga_Borda_Retangulo_Baixo(Retangulos);
						Retangulos[Retangulos->cont_retangulos].ponto_B.Y += cont_bordas + 1;
						Retangulos[Retangulos->cont_retangulos].ponto_A.Y += cont_bordas + 1;
						printf("%d", Retangulos[Retangulos->cont_retangulos].ponto_B.Y);
						Sleep(100);
						for(i = 0; i < Retangulos->colunas; i++)
						{
							
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.Y + cont_bordas, Retangulos[Retangulos->cont_retangulos].ponto_B.Y - cont_bordas);
							putchar(32);
						}
						/*printf("%d %d", Retangulos[Retangulos->cont_retangulos].ponto_A.X, Retangulos[Retangulos->cont_retangulos].ponto_B.Y);*/
						break;
					}

					/*Diminui a area de baixo*/
					case F10:
					{
						cont_bordas = 0;
						/*Apaaga a posicao atual da borda de baixo pra diminuir seu tamanho*/
						Apaga_Borda_Retangulo_Baixo(Retangulos);
						Retangulos[Retangulos->cont_retangulos].ponto_B.Y -= cont_bordas + 1;
						Retangulos[Retangulos->cont_retangulos].ponto_A.Y -= cont_bordas + 1;

						
						for(i = 0; i < Retangulos->colunas; i++)
						{
							gotoxy(Retangulos[Retangulos->cont_retangulos].ponto_A.Y - cont_bordas, Retangulos[Retangulos->cont_retangulos].ponto_B.Y + cont_bordas);
							putchar(32);
						}
						break;
					}

					/*Troca a cor do Retangulo*/
					case TAB:
					{				
						Retangulos[Retangulos->cont_retangulos].cor_retangulo = rand() % 15 + 1;
						break;
					}

					
					/*Encerra o programa*/
					case ESC:
					{
						/*Seta a caixa de texto do prompt no canto superior esquerdo*/
						Retangulos->ponto_final.X = 1;
						Retangulos->ponto_final.Y = 1;
						gotoxy(Retangulos->ponto_final.X, Retangulos->ponto_final.Y);

						/*Devolve a cor original*/
						textbackground(BLACK);
						textcolor(LIGHTGRAY);

						/*Limpa a tela*/
						clrscr();

						/*Retorna o Cursor*/
						_setcursortype(_NORMALCURSOR);
						exit(0);
						break;
					}
				}
			}
		}
	}
}




