	/*Algumas funções para utilização na main principal*/
	#include "funcoes.h"
	#include "conio_v3.2.4.h"
	#include "console_v1.5.4.h"
	#include <stdlib.h>
	#include <stdio.h>
	
	#define ESC 27
	#define LINHAS 40
	#define COLUNAS 100
	
	/*Cria as bordas do retângulo*/
	void CriaRetangulo()
		{
			/*i é linha e j é Coluna*/
			int j;
			/*Tamanho Maximo da Janela e posicões(x,y) do retangulo*/
			COORD tamMaxJanela;
			/*COORD retangulo;*/
			
			/*Guarda o tamanho maximo da janela do console*/
			tamMaxJanela = MaxDimensaoJanela();

			/*Seta a Posicao da Janela do console*/
			setDimensaoJanela(tamMaxJanela.X, tamMaxJanela.Y);
			setPosicaoJanela(1,1);
			
			
			/*Linha horizontal superior do retangulo*/
			gotoxy((tamMaxJanela.X/2)/2, (tamMaxJanela.Y/2)/2);
			for(j = 1; j < COLUNAS; j++)
			{
				printf(" ");
				Sleep(1000/100);
			}
			
			/*Linha Vertical da esquerda do retangulo*/
			gotoxy((tamMaxJanela.X/2)/2, (tamMaxJanela.Y/2)/2);
			for(j = 1; j < LINHAS; j++)
			{
				printf("  \n");
				Sleep(1000/100);
			}
			
			system("pause");
		}