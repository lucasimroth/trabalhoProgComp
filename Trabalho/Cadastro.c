#include <stdio.h>
#include <time.h>

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

typedef struct{
	int estado;
	char *cidade;
	char *rua;
	int *numero;
}local

typedef struct{
	int cpf;
	char *nome;
	char *email;
	char *telefone;
	time_t dataNascimento;
	int sexo;//0-Masculino, 1-Feminino, 3-Não Binário
	local endereco;
	int status;//0-Ativo, 1-Desativado
	
}cliente;

typedef struct{
	int id;
	char *nome;
	int ano;
	int genero;//0-Ação, 1-Aventura, 2-Comédia, 3-Drama, 4-Romance, 5-Suspense  6-Terror
	float duracao;//em horas
	
}filme;

typedef struct{
	int id;
	int idFilme;
	int cpf;
	time_t data;
	int prazo;//5 reais por dia
	float preco;
	int status;//0-Solicitado, 1-Pago, 2-Encerrado;
	
}pedido;

/****************/
/*  PROTÓTIPOS  */
/****************/

int mainMenu();//retorna stateProgram
void consultaFilmes();
void consultaClientes();
void consultaPedidos();

int main(){

/*1 ---- a parte de cadastro quando entra na função pede os dados do usuario
sendo eles:
CPF - NOME - Email - Telefone - DATA de Nascimento - Sexo - endereço - status do cadastro
-- cada cliente novo realiza um sort para deixar sempre ordenado os cadastros.(a ser definido o tipo de sort)
*/


/*
2 ----listagem de clientes:
-- abre direto todos os clientes
aqui da para consultar todos os clientes ao mesmo tempo, aparecendo somente cpf, nome, telefone, pedidos vigentes e status do cadastro.
para uma consulta mais detalhada é necessario pesquisar por cpf
-- pergunta se gostaria de consultar um cpf especifico, se sim é só digitar o cpf diretamente que ja ira aparecer, se digitar 0 vai para o menu principal
*/

/*
3---- consulta a partir do CPF:
--aqui pede o cpf ou da a opção 0 que volta para o menu principal
com o cpf sera mostrado todos os dados do cadastro.
-- a cada chamada tem a opção de editar cadastro, desativar cliente, fazer uma nova busca ou sair
*/

/*
4---- excluir cliente
-- aqui pede o cpf, todos os dados do cliente são mostrados na tela
a exclusão apaga do registro todos os dados do cliente e reajusta a numeração de cada cliente para encaixar no processo, excluir o 02 faz o 03 virar 02 e assim consecutivamente
-- pergunta se tem certeza que deseja excluir, se quer somente desativar ou sair dessa tela, e confirmar com um sim ou não se clicar em excluir.
*/ 
	int stateProgram = 0
	
	//MÁQUINA DE ESTADOS
	while(stateProgram > -1){
		switch(stateProgram){
			//STATES PRINCIPAIS
			case 0:
				mainMenu();
				break;
			case 1:
				consultaFilmes();
				break;
			case 2:
				consultaClientes();
				break;
			case 3:
				consultaPedidos();
				break;
		}
	}

    return 1;
}
