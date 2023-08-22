/*Estruturas e prototipos de funções*/
#include "console_v1.5.4.h"
#include "conio_v3.2.4.h"

/*Estrutura Retangulo*/
typedef struct _retangulo
{
	/*Coordenadas do Retangulo*/
	COORD Ponto_A;
	COORD Ponto_B;

	/*Cor do Retangulo*/
	COLORS Cor_Retangulo;

	int linhas;
	int colunas;

}RETANGULO;

/*Estrutura Quadrado*/
typedef struct _quadrado
{
	/*Coordenadas do Quadrado*/
	COORD Quadrado;
	/*Cor do Quadrado*/
	COLORS Cor_Quadrado;

	/*Direcao e velocidade do Quadrado*/
	int direcao;
	int velocidade;
	
}QUADRADO;

/*Estrutura Leitura do Teclado*/
typedef struct ler_teclado
{
	/*Armazena a leitura do teclado*/
	EVENTO leitura_teclado;
}LE_TECLADO;

typedef struct _janela
{
	/*Armazena as coordenadas para maximização da janela do Console*/
	COORD Tam_Max;

}JANELA;

/*Estrutura para setar as coordenadas das informações*/
typedef struct _informacoes
{
	COORD Inf;
	char Inf_Retangulo_Cor[50];
	char Inf_Quadrado_Cor[50];
	char Inf_direcao[50];
	char Inf_Velocidade[50];

}INFORMACOES;

/*Prototipo da funcao que ira atribuir os valores do Retangulo e Quadrado*/
void Atribui_Valores_Q_R(RETANGULO *, QUADRADO *);

/*Prototipo da funcao que apaga o curso visivel da tela*/
void Apaga_Cursor();

/*Protoripo da funcao que apaga o Quadrado no meio do Retangulo*/
void Apaga_Quadrado(QUADRADO *);

/*Prototipo da funcao que armazena coordenadas do Retangulo na tela*/
void Coord_Retangulo(RETANGULO *);

/*Prototipo da funcao que armazena as coordenadas do Retangulo na tela*/
void Cria_Quadrado(QUADRADO *);

/*Prototipo da funcao que desenha o retangulo na tela*/
void Cria_Retangulo(RETANGULO *);

/*Prototipo da funcao que desenha o quadrado na tela*/
void Desenha_Quadrado(QUADRADO *);

/*Prototipo da Função que Maximiza o tamanho da Janela do Console*/
void Janela_Full(JANELA *);

/*Prototipo da função que ira ler as teclas do teclado*/
void Le_Teclado(LE_TECLADO *, RETANGULO *, QUADRADO *, INFORMACOES *);

/*Prototipo da função que ira movimentar o quadrado na tela*/
void Movimenta_Quadrado(QUADRADO *, RETANGULO *);