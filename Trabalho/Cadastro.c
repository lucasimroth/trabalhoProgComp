#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Cadastro de Cliente
/*
é necessario:
-salvar em TXT o cadastro
-opção de listar todos os clientes
-consultar a partir de CPF
-desativar cliente
-excluir cliente
-fazer o Sort dos cliente


*/

//---------------------------------------------- Structs ------------------------------------------------------

typedef struct{
	char estado[20];
	char cidade[20];
	char rua[60];
	int numero;
}local;

typedef struct{
	char cpf[11];
	char nome[100];
	char email[50];
	char telefone[14]; //(41)99595-7968
	char dataNascimento[8];
	int sexo;//0-Masculino, 1-Feminino, 3-outros
	local endereco;
	int status;//0-Ativo, 1-Desativado
	
}clientes;

typedef struct{
	int id;
	char *nome;
	int ano;
	int genero;//0-Ação, 1-Aventura, 2-Comédia, 3-Drama, 4-Romance, 5-Suspense  6-Terror
	float duracao;//em horas
	
}filmes;

typedef struct{
	int id;
	int idFilme;
	int cpf;
	time_t data;
	int prazo;//5 reais por dia
	float preco;
	int status;//0-Solicitado, 1-Pago, 2-Encerrado;
	
}pedido;


//----------------------------------------------------------  PROTÓTIPOS  -------------------------------------------------------------------


int mainMenu();//retorna stateProgram
//void alocacaoClientes();
//void consultaFilmes();
void consultaClientes();
//void consultaPedidos();

void cadastroClientes();
	int validacaoCPF();
	int validacaoStr();
		int comparaSTR();
	int validacaoEmail();
void listagemClientes();
void consultaCPF();
void excluirClientes();

//----------------------------------------------------------- MAIN ----------------------------------------------------------------------

int main(){

	clientes clientesStruct;

	int stateMain;

	while(stateMain != 0){
		scanf("%d", &stateMain);
		switch(stateMain){
			//STATES PRINCIPAIS

			case 1:
				//consultaFilmes();
				break;
			case 2:
				consultaClientes(&clientesStruct);
				break;
			case 3:
				//consultaPedidos();
				break;
			default:
			break;
		}
	}

    return 1;
}

//1 ---------------------------------------- ABA CLIENTES --------------------------------------------------------------


void consultaClientes(clientes *clientesStruct){
	int stateConsult = -1;

	while (stateConsult != 0)
	{
		scanf("%d", &stateConsult);

		switch (stateConsult)
		{
			case 1:
				cadastroClientes(&clientesStruct);
				break;
			case 2:
				listagemClientes();
				break;
			case 3:
				consultaCPF();
				break;
			case 4:
				excluirClientes();
				break;
		default:
			break;
		}
	}
}

// ----------------------------------------------- CADASTRO --------------------------------------------------------------

void cadastroClientes(clientes *clientesStruct){
	int stateCad = -1;
	int verificacaoCad, marcaVerificacao = -1;

	while (stateCad != 0)
	{
		printf("tem certeza que gostaria de realizar um novo cadastro?\n\n1 - sim\n0 - nao\n");
		scanf("%d", &verificacaoCad);

		if(verificacaoCad == 1){

			while (marcaVerificacao != 1)
			{
				printf("\nDigite o CPF: ");
				scanf("%s", (*clientesStruct).cpf);

				marcaVerificacao =  validacaoCPF(*clientesStruct);

				if(marcaVerificacao == 2){
					break;
				}
			}
			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o nome: ");
				fgets((*clientesStruct).nome, 100, stdin);

				marcaVerificacao = 1; //validacaoStr(&clientesStruct);

				printf("%s", (*clientesStruct).nome);
				
			}
			marcaVerificacao = -1;

			puts("1");

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\ndigite seu e-mail: ");
				scanf("%s", (*clientesStruct).email);

				marcaVerificacao = 1; //validacaoEmail(clientesStruct);

				printf("%s", (*clientesStruct).email);
			}
			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o Telefone: ");
				scanf("%s", (*clientesStruct).telefone);

				marcaVerificacao = 1; //validacaoStr(&clientesStruct);

				printf("%s", (*clientesStruct).telefone);
				
			}
			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite a Data de Nascimento modelo DD/MM/AAAA: ");
				scanf("%s", (*clientesStruct).dataNascimento);

				marcaVerificacao = 1; //validacaoStr(&clientesStruct);

				printf("%s", (*clientesStruct).dataNascimento);
				
			}
			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o Sexo: ");
				scanf("%d", &(*clientesStruct).sexo);

				marcaVerificacao = 1; //validacaoStr(&clientesStruct);

				printf("%d", (*clientesStruct).sexo);
				
			}
			marcaVerificacao = -1;
			

		}else{
			stateCad = 0;
		}
	
	}
stateCad = -1;
}

// VALIDAÇÃO DO CPF -------------------------------------------------------------------------

int validacaoCPF(clientes clientesStruct){

int *p;
int primeiroDigito = 0;
int segundoDigito = 0;
int somaTotal = 0;

printf("chega 1");

	if (clientesStruct.cpf[0] == '0')
	{
		printf("\nOperação Cancelada.\n");
		return 2;
	}else
	{
		printf("chega 2");
		if((comparaSTR(clientesStruct.cpf, "00000000000") == 0) || (comparaSTR(clientesStruct.cpf, "11111111111") == 0) || (comparaSTR(clientesStruct.cpf, "22222222222") == 0) || (comparaSTR(clientesStruct.cpf, "33333333333") == 0)
		|| (comparaSTR(clientesStruct.cpf, "44444444444") == 0) || (comparaSTR(clientesStruct.cpf, "55555555555") == 0) || (comparaSTR(clientesStruct.cpf, "66666666666") == 0) || (comparaSTR(clientesStruct.cpf, "77777777777") == 0)
		|| (comparaSTR(clientesStruct.cpf, "88888888888") == 0) || (comparaSTR(clientesStruct.cpf, "99999999999") == 0))
		{
			printf("\ncpf invalido\n");
			return 0;
		}else
		{
    		p = (int *)malloc(11 * sizeof(int));

    		for(int i = 0; i < 11; i++){
        		p[i] = clientesStruct.cpf[i] - 48;
        		printf("%d", p[i]);
    		}

    		for(int i = 9, j = 2; i > 0; i--, j++){
        		somaTotal += ( p[i] * j );
    		}

    		if(somaTotal % 11 < 2){
        		primeiroDigito = 0;
    		}else{
        		primeiroDigito = 11 - (somaTotal % 11);}
    		somaTotal = 0;

    		for( int i = 10, j = 2; i > 0; i--, j++){
        		somaTotal += ( p[i] * j);
    		}

    		if(somaTotal % 11 < 2){
        		segundoDigito = 0;
    		}else {
        		segundoDigito = 11 - (somaTotal % 11);}

        	printf("\n%d -> %d \n%d - > %d", p[9], primeiroDigito, p[10], segundoDigito);

    		if(primeiroDigito == p[9] && segundoDigito == p[10]){
        		free(p);
        		return 1;
    		}else{
        		printf("\ncpf invalido\n");
        		free(p);
        		return 0;
    		}
		}
	}
}
// comparador de STRING vulgo STRCMP ----------------------------

	int comparaSTR(char *p1, char *p2){
		char *positionOne = p1;
		char *positionTwo = p2;
		char markOne, markTwo;

		printf("chega 3 = %s", p1);

		do{
			markOne = *positionOne++;
			markTwo = *positionTwo++;
			if(markOne == '\0'){
				return markOne-markTwo;
			}
		} while (markOne == markTwo);
		printf("chega 4");

		return markOne - markTwo;
	}

// validação da String ------
	

//2 ------------------------------------------ listagem de clientes ------------------------------------------------------

void listagemClientes(){
/* abre direto todos os clientes
aqui da para consultar todos os clientes ao mesmo tempo, aparecendo somente cpf, nome, telefone, pedidos vigentes e status do cadastro.
para uma consulta mais detalhada é necessario pesquisar por cpf
-- pergunta se gostaria de consultar um cpf especifico, se sim é só digitar o cpf diretamente que ja ira aparecer, se digitar 0 vai para o menu principal
*/

}


//3--------------------------------------- consulta a partir do CPF --------------------------------------------------------

void consultaCPF(){
/*--aqui pede o cpf ou da a opção 0 que volta para o menu principal
com o cpf sera mostrado todos os dados do cadastro.
a cada chamada tem a opção de editar cadastro, desativar cliente, fazer uma nova busca ou sair*/

}


//4------------------------------------------ excluir cliente --------------------------------------------------------------

void excluirClientes(){
	/*-- aqui pede o cpf, todos os dados do cliente são mostrados na tela
a exclusão apaga do registro todos os dados do cliente e reajusta a numeração de cada cliente para encaixar no processo, excluir o 02 faz o 03 virar 02 e assim consecutivamente
-- pergunta se tem certeza que deseja excluir, se quer somente desativar ou sair dessa tela, e confirmar com um sim ou não se clicar em excluir.*/


}