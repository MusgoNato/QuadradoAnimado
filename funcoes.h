#include "conio_v3.2.4.h" /*COLORS*/
#include "console_v1.5.4.h" /*COORD, EVENTO*/

/*Estrutura para maximização da janela do prompt*/
typedef struct _janela
{
	/*Armazena as dimensoes x e y da janela*/
	COORD janela_inicial;
	COORD janela_final;
	
}JANELA;

/*Estrutura referente ao retangulo que sera criado na tela*/
typedef struct _retangulo
{
	/*Coordenadas do retangulo*/
	COORD retangulo;
	COORD ponto_final;
	COORD ponto_A;
	COORD ponto_B;

	/*Cor do retangulo*/
	COLORS cor_retangulo;
	
	/*Contador de retangulos, linhas e colunas*/
	int cont_retangulos;
	int linhas;
	int colunas;
	
}RETANGULO;

/*Estrutura para o quadrado ao meio do retangulo*/
typedef struct _quadrado
{
	/*Coordenadas do Quadrado*/
	COORD Ponto_1;
	COORD Ponto_2;
	
	/*Contador de quadrados criados*/
	int cont_quadrados;

	/*Muda a cor do quadrado*/
	COLORS cor_quadrado;

	/*Sentido que irá o quadrado*/
	int sentido;
	
}QUADRADO;

/*Estrutura para os eventos do teclado, pressionamento das teclas*/
typedef struct _teclado
{
	/*Armazena o evento que sera lido posteriormente*/
	EVENTO leitura_teclado;

}LEITURA_TECLADO;


/*Chamada da maximizacao da janela do console*/
void Maximiza_Janela(JANELA *);

/*Criacao dos Retangulos*/
void Cria_Retangulos(RETANGULO [], QUADRADO []);

/*Cria o quadrado dentro do retangulo*/
void Cria_Quadrados(QUADRADO [], RETANGULO [], int indice_retangulo);

/*Le o teclado e faz as alteracoes necessarias*/
void Le_Teclado(RETANGULO [], LEITURA_TECLADO *, QUADRADO []);

