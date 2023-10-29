#include <stdio.h>
#include <time.h>
#include <ctype.h>

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
	int estado;
	char *cidade;
	char *rua;
	int *numero;
}local;

typedef struct{
	int cpf;
	char *nome;
	char *email;
	char *telefone;
	char *dataNascimento;
	int sexo;//0-Masculino, 1-Feminino, 3-Não Binário
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
void consultaFilmes();
void consultaClientes();
void consultaPedidos();

void cadastroClientes();
	int validacaoCPF();
	int verificaLeStr();
void listagemClientes();
void consultaCPF();
void excluirClientes();

//----------------------------------------------------------- MAIN ----------------------------------------------------------------------

int main(){

	clientes clientesStruct[1];

	FILE *arquivoClientes;

	int stateMain;

	//MÁQUINA DE ESTADOS
	while(stateMain != 0){
		scanf("%d", &stateMain);
		switch(stateMain){
			//STATES PRINCIPAIS

			case 1:
				consultaFilmes();
				break;
			case 2:
				consultaClientes(clientesStruct, &arquivoClientes);
				break;
			case 3:
				consultaPedidos();
				break;
			default:
			break;
		}
	}

    return 1;
}


//1 ---------------------------------------- CADASTRO --------------------------------------------------------------


void consultaClientes(clientes *clientesStruct, FILE *arquivoClientes){
	int stateConsult = -1;

	while (stateConsult != 0)
	{
		scanf("%d", &stateConsult);

		switch (stateConsult)
		{
			case 1:
				cadastroClientes(clientesStruct);
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

/*a parte de cadastro quando entra na função pede os dados do usuario
sendo eles:
CPF - NOME - Email - Telefone - DATA de Nascimento - Sexo - endereço - status do cadastro
-- cada cliente novo realiza um sort para deixar sempre ordenado os cadastros.(a ser definido o tipo de sort)*/

void cadastroClientes(clientes *clientesStruct){
	int stateCad = -1;
	int verificacaoCad, marcaVerificacao = -1;

	while (stateCad != 0)
	{
		printf("tem certeza que gostaria de realizar um novo cadastro?\n 1 - sim\n0 - não");
		scanf("%d", &verificacaoCad);

		if(verificacaoCad != 1){

			while (marcaVerificacao != 1)
			{
				printf("\nDigite o CPF: ");
				scanf("%d", &clientesStruct[0].cpf);

				marcaVerificacao =  validacaoCPF(clientesStruct->cpf);
			}
			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				printf("\nDigite o nome: ");
				scanf("%s", clientesStruct[0].nome);

				marcaVerificacao = verificaLeStr(clientesStruct->nome);
				
			}
			

		}else{
			stateCad = 0;
		}
	
	}
stateCad = -1;
}

// VALIDAÇÃO DO CPF ----
	int validacaoCPF(clientes *CPF){
		int verificaCPF = CPF, verificaAux, verificaSoma = 0, primeiroDigito = 0, segundoDigito = 0;

		segundoDigito = verificaCPF % 10;
		verificaCPF / 10;

		primeiroDigito = verificaCPF % 10;
		verificaCPF / 10;

		verificaAux = verificaCPF;

		for(int i = 2; i < 11; i++){
			verificaSoma += ((verificaCPF % 10) * i);
			verificaCPF / 10;
		}

		if(verificaSoma % 11 < 2){
			primeiroDigito = 0;
		}else{
		primeiroDigito = 11 - (verificaSoma % 11);
		}

		verificaAux = verificaAux * 10 + primeiroDigito;
		verificaCPF = verificaAux;
		verificaSoma = 0;

		for(int i = 2; i < 12; i++){
			verificaSoma += ((verificaAux % 10) * i);
			verificaAux / 10;
		}

		if(verificaSoma % 11 < 2){
			segundoDigito = 0;
		}else{
		segundoDigito = 11 - (verificaSoma % 11);
		}
		verificaCPF = verificaCPF * 10 + segundoDigito;

		if(verificaCPF == CPF->cpf){
			return 1;
		}else{
			printf("\nCPF Inválido!\n");
			return 0;
		}

	}

// leitura da String ------
	int verificaLeStr(clientes *nome){
		int contador = 0;
		int *memoria = &nome;

		
		while (*memoria != '\0')
		{
			if(*memoria > 'a' && *memoria < 'z'){
				*memoria = toupper(*memoria);
			}
			if(*memoria < 'A' || *memoria > 'Z'){
				printf("\nnome invalido.\n");
				return 0;
			}else{
			memoria++;
			}
		}
		
		return contador;
	} 


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