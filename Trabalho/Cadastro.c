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
	char cpf[12];
	char nome[100];
	char email[50];
	char telefone[12]; //41995957968
	char dataNascimento[10];//27/02/2001
	int genero;//1-Masculino, 2-Feminino, 3-outros
	char estado[20];
	char cidade[20];
	char rua[50];
	int numero;
	int status;//0-Ativo, 1-Desativado
	
}clientes;

typedef struct{
	char cpf[12];
	char nome[100];
	char email[50];
	char telefone[12]; //41995957968
	char dataNascimento[10];//27/02/2001
	int genero;//1-Masculino, 2-Feminino, 3-outros
	char estado[20];
	char cidade[20];
	char rua[50];
	int numero;
	int status;//0-Ativo, 1-Desativado
	
}clientesT;

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
		int comparaSTR(); // Strcmp
		int leituraStr(); //Strlen
		char *stringChar(const char *palavra, char caracter); 
		void removerQuebraLinha(char *string);
	int validacaoEmail();
	int validacaoTel();
	int validacaoData();
	int validacaoGenero();
		void passagemArquivoCode(clientesT *clientesGeral);
void listagemClientes();
void consultaCPF();
void excluirClientes();

//----------------------------------------------------------- MAIN ----------------------------------------------------------------------

int main(){

	clientes clientesStruct;
	clientesT *clientesGeral = malloc (1 * sizeof(clientesT));

	int stateMain;

	while(stateMain != 0){
		scanf("%d", &stateMain);
		switch(stateMain){
			//STATES PRINCIPAIS

			case 1:
				//consultaFilmes();
				break;
			case 2:
				consultaClientes(&clientesStruct, clientesGeral);
				break;
			case 3:
				//consultaPedidos();
				break;
			default:
			break;
		}
	}
	
	free(clientesGeral);

    return 1;
}

//1 ---------------------------------------- ABA CLIENTES --------------------------------------------------------------


void consultaClientes(clientes *clientesStruct, clientesT *clientesGeral){
	int stateConsult = -1;

	while (stateConsult != 0)
	{
		scanf("%d", &stateConsult);

		switch (stateConsult)
		{
			case 1:
				cadastroClientes(&clientesStruct, clientesGeral);
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

void cadastroClientes(clientes *clientesStruct, clientesT *clientesGeral){
	int stateCad = -1;
	int verificacaoCad, marcaVerificacao = -1;

	while (stateCad != 0)
	{
		printf("tem certeza que gostaria de realizar um novo cadastro?\n\n1 - sim\n0 - nao\n");
		scanf("%d", &verificacaoCad);

		if(verificacaoCad == 1){
			
			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o CPF (somente numeros): ");
				fgets((*clientesStruct).cpf, 12, stdin);
				//strcpy((*clientesStruct).cpf, "11879956900");

				marcaVerificacao = validacaoCPF(*clientesStruct);

				removerQuebraLinha((*clientesStruct).cpf);
			}
			
			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o nome: ");
				fgets((*clientesStruct).nome, 100, stdin);
				
				//strcpy((*clientesStruct).nome, "lucas de oliveira");

				marcaVerificacao = validacaoStr((*clientesStruct).nome);
				
				for(int i = 0; (*clientesStruct).nome[i] != '\0'; i++){
					(*clientesStruct).nome[i] = toupper((*clientesStruct).nome[i]);
				}

				removerQuebraLinha((*clientesStruct).nome);
				printf("%s", (*clientesStruct).nome);
				
			}

			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\ndigite seu e-mail: ");
				fgets((*clientesStruct).email, 50, stdin);
				//strcpy((*clientesStruct).email, "lucas@eu.com");

				marcaVerificacao = validacaoEmail(*clientesStruct);

				for(int i = 0; (*clientesStruct).email[i] != '\0'; i++){
					(*clientesStruct).email[i] = toupper((*clientesStruct).email[i]);
				}

				removerQuebraLinha((*clientesStruct).email);

				printf("%s", (*clientesStruct).email);
			}

			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o Telefone (somente Numero com DDD): ");
				fgets((*clientesStruct).telefone, 12, stdin);
				//strcpy((*clientesStruct).telefone, "41995957968");

				marcaVerificacao = validacaoTel(*clientesStruct);

				removerQuebraLinha((*clientesStruct).telefone);

				printf("%s", (*clientesStruct).telefone);
				
			}

			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite a Data de Nascimento modelo DD/MM/AAAA: ");
				scanf("%s", (*clientesStruct).dataNascimento);
				//strcpy((*clientesStruct).dataNascimento, "27022001");
				fflush(stdin);
				marcaVerificacao = validacaoData(*clientesStruct);

				removerQuebraLinha((*clientesStruct).dataNascimento);

				printf("%s", (*clientesStruct).dataNascimento);
				
			}

			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o Genero: \n\n1 - Feminino\n2 - Masculino\n3 - outros\n");
				scanf("%d", &(*clientesStruct).genero);
				//clientesStruct->genero = 2;
				fflush(stdin);
				marcaVerificacao = validacaoGenero(*clientesStruct);

				printf("%d", (*clientesStruct).genero);
				
			}

			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o Estado: ");
				fgets((*clientesStruct).estado, 20, stdin);
				//strcpy((*clientesStruct).estado, "Parana");

				marcaVerificacao = validacaoStr((*clientesStruct).estado);
				
				for(int i = 0; (*clientesStruct).estado[i] != '\0'; i++){
					(*clientesStruct).estado[i] = toupper((*clientesStruct).estado[i]);
				}

				removerQuebraLinha((*clientesStruct).estado);

				printf("%s", (*clientesStruct).estado);
				
			}


			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite a Cidade: ");
				fgets((*clientesStruct).cidade, 20, stdin);
				//strcpy((*clientesStruct).cidade, "Curitiba");

				marcaVerificacao = validacaoStr((*clientesStruct).cidade);
				
				for(int i = 0; (*clientesStruct).cidade[i] != '\0'; i++){
					(*clientesStruct).cidade[i] = toupper((*clientesStruct).cidade[i]);
				}

				removerQuebraLinha((*clientesStruct).cidade);

				printf("%s", (*clientesStruct).cidade);
				
			}

			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite a Rua: ");
				fgets((*clientesStruct).rua, 50, stdin);
				//strcpy((*clientesStruct).rua, "Rua Subtenente jose makahin");

				marcaVerificacao = validacaoStr((*clientesStruct).rua);
				
				for(int i = 0; (*clientesStruct).rua[i] != '\0'; i++){
					(*clientesStruct).rua[i] = toupper((*clientesStruct).rua[i]);
				}

				removerQuebraLinha((*clientesStruct).rua);

				printf("%s", (*clientesStruct).rua);
				
			}

			marcaVerificacao = -1;

			while (marcaVerificacao != 1)
			{
				fflush(stdin);
				printf("\nDigite o numero: ");
				scanf("%d", &(*clientesStruct).numero);
				//(*clientesStruct).numero = 163;
				fflush(stdin);

				if((*clientesStruct).numero > 0 || (*clientesStruct).numero <= 10000){
					marcaVerificacao = 1;
				}else{
					marcaVerificacao = -1;
				}

				printf("%d", (*clientesStruct).numero);
				
			}

			(*clientesStruct).status = 1; 

		FILE *arquivo;
		arquivo = fopen("listaClientes.txt", "r+");
			int qtdeClientes;
			fscanf(arquivo, "%d", &qtdeClientes);
			qtdeClientes ++;
			rewind(arquivo);
			fprintf(arquivo, "%d", qtdeClientes);
		fclose(arquivo);

		arquivo = fopen("listaClientes.txt", "a");

		if(arquivo != NULL){
			printf("\n\narquivo foi aberto corretamente no final do cadastro\n\n");
		}else{
			printf("\n\narquivo nao foi aberto no final do cadastro\n\n");
		}

		fprintf(arquivo, "%s|%s|%s|%s|%s|%d|%s|%s|%s|%d|%d\n", (*clientesStruct).cpf, (*clientesStruct).nome, (*clientesStruct).email,
		(*clientesStruct).telefone, (*clientesStruct).dataNascimento, (*clientesStruct).genero, (*clientesStruct).estado, (*clientesStruct).cidade,
		(*clientesStruct).rua, (*clientesStruct).numero, (*clientesStruct).status);

		fclose(arquivo);
		}else{
			stateCad = 0;
		}
	passagemArquivoCode(clientesGeral);
	}
stateCad = -1;
}

// VALIDAÇÃO DO CPF -------------------------------------------------------------------------

	int validacaoCPF(clientes clientesStruct)
	{

		int *p;
		int primeiroDigito = 0;
		int segundoDigito = 0;
		int tamanho = strlen(clientesStruct.cpf);
		FILE *arquivo;

		arquivo = fopen("listaClientes.txt", "r");

		if(arquivo != NULL){
			printf("\narquivo foi aberto corretamente em validação CPF\n");
		}else{
			printf("\narquivo nao foi aberto em validação CPF\n");
		}

		char linha[300];

		fflush(stdin);

		//TOMAR CUIDADO COM ESPAÇO  NO ARQUIVO, ELE BUGA A BUSCA, NAO ALTERAR ARQUIVO MANUALMENTE
		while(fgets(linha, sizeof(linha), arquivo) != NULL){
			linha[strcspn(linha, "\n")] = '\0';

			char *token = strtok(linha, "|");

			if(comparaSTR(token, clientesStruct.cpf) == 0){
				fclose(arquivo);
				printf("\ncpf já cadastrado.\n");
				return 0;
			}

		}

		
		
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

 	   		for(int i = 0, j = 10; i < tamanho - 2; i++, j--){
	        		primeiroDigito += ( p[i] * j );
	    		}
				primeiroDigito %= 11;
	    		if(primeiroDigito < 2){
	        		primeiroDigito = 0;
	    		}else{
	        		primeiroDigito = 11 - primeiroDigito;}

	    		for( int i = 0, j = 11; i < tamanho - 1; i++, j--){
	        		segundoDigito += ( p[i] * j);
	    		}
				segundoDigito %= 11;
	    		if(segundoDigito < 2){
	        		segundoDigito = 0;
	    		}else {
	        		segundoDigito = 11 - segundoDigito;}

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
		
		fclose(arquivo);
	}
// comparador de STRING vulgo STRCMP --------------------------------------------------------

	int comparaSTR(char *p1, char *p2){
		char *positionOne = p1;
		char *positionTwo = p2;
		char markOne, markTwo;
		do{
			markOne = *positionOne++;
			markTwo = *positionTwo++;
			if(markOne == '\0'){
				return markOne-markTwo;
			}
		} while (markOne == markTwo);

		return markOne - markTwo;
	}

// Leitura String ---------------------------------------------------------------------------

	int leituraStr(char *string){
		int qtde = 0;
		while(*string != '\0'){
			qtde++;
			string++;
		}
		return qtde;
	}

// STRING CHAR que busca a posição de memoria do caracter especificado ----------------------

	char *stringChar(const char *palavra, char caracter){
		char caracter1 = tolower(caracter);
		do{
			if(*palavra == caracter1) return (char *) palavra;
			palavra++;
		}while(*palavra != '\0');
		return 0;
	}

// validação da String ----------------------------------------------------------------------

	int validacaoStr(char *string){
		char *ponteiroStr = string; 
		char letra;
		letra = *ponteiroStr++;
		while(letra != '\0'){
			if(!(isalpha(letra) || isspace(letra))){
				return 0;
			}
			letra = *ponteiroStr++;
		};
		return 1;
	};

// validação Email ---------------------------------------------------------------------------

	int validacaoEmail(clientes clientesStruct){
		int arrobaMarca = 0;
		int i;

		for( i = 0; i < leituraStr(clientesStruct.email); i++){
			if (clientesStruct.email[i] == '@')
			{
				arrobaMarca++;
			}
			if(clientesStruct.email[i] == ' ' || clientesStruct.email[i] == '/' || clientesStruct.email[i] == ':' || clientesStruct.email[i] == ';' 
			|| clientesStruct.email[i] == '<' || clientesStruct.email[i] == '>' || clientesStruct.email[i] == ',' || clientesStruct.email[i] == '='
			|| clientesStruct.email[i] == '[' || clientesStruct.email[i] == ']' || clientesStruct.email[i] == '{' || clientesStruct.email[i] == '}')
			{
				return 0;
			}
		}
		if(arrobaMarca == 1){
			if(clientesStruct.email[0] != '@'){
				char *ponto = stringChar(clientesStruct.email, '.');

				if(ponto != 0 && ponto > stringChar(clientesStruct.email, '@')){
					return 1;
				}
			}
		}
		return 0;
	}

// validação do Telefone ---------------------------------------------------------------------

	int validacaoTel(clientes clientesStruct){
		if((comparaSTR(clientesStruct.telefone, "00000000000") == 0) || (comparaSTR(clientesStruct.telefone, "11111111111") == 0) || (comparaSTR(clientesStruct.telefone, "22222222222") == 0) || (comparaSTR(clientesStruct.telefone, "33333333333") == 0)
		|| (comparaSTR(clientesStruct.telefone, "44444444444") == 0) || (comparaSTR(clientesStruct.telefone, "55555555555") == 0) || (comparaSTR(clientesStruct.telefone, "66666666666") == 0) || (comparaSTR(clientesStruct.telefone, "77777777777") == 0)
		|| (comparaSTR(clientesStruct.telefone, "88888888888") == 0) || (comparaSTR(clientesStruct.telefone, "99999999999") == 0))
		{
			printf("\nNumero invalido\n");
			return 0;
		}else{
		for(int i = 0; i < 11; i++){
			
				if(clientesStruct.telefone[i] < '0' || clientesStruct.telefone[i] > '9'){
					printf("\n\nNumero invalido\n\n");
					return 0;
				}
			}
		}
		return 1;
	}

// validação da Data -------------------------------------------------------------------------

	int validacaoData(clientes clientesStruct){
		int dia = -1, mes = -1, ano = 0, i, cont = 0;

		for(i = 0; i < leituraStr(clientesStruct.dataNascimento); i++){
			if(clientesStruct.dataNascimento[i] != '/' && !isdigit(clientesStruct.dataNascimento[i])){
				return 0;
			}
		}
		i = 0;
		while (clientesStruct.dataNascimento[i] != '\0')
		{
			if(isdigit(clientesStruct.dataNascimento[i]))
			{
				if(cont == 0)
				{
					if(dia == -1)
					{
						dia = (int)clientesStruct.dataNascimento[i] - 48;
						dia *= 10;
					}else
					{
						if(i == 2 && clientesStruct.dataNascimento[i] != '/' && clientesStruct.dataNascimento[i+1] != '/'){
							cont++;
							i--;
						}else{
							dia += (int)clientesStruct.dataNascimento[i]- 48;
						}
					}
				}else if(cont == 1){
					if(mes == -1){
						mes = (int)clientesStruct.dataNascimento[i]- 48;
						mes *= 10;
						
					}else{
						if(i == 4 && clientesStruct.dataNascimento[i] != '/' && clientesStruct.dataNascimento[i+1] != '/'){
							cont++;
							i--;
						}else{
							mes += (int)clientesStruct.dataNascimento[i]- 48;
							
						}
					}
					

				}else if(cont == 2){
					ano += (int)clientesStruct.dataNascimento[i]- 48;
					ano *= 10;
				}
			}else{
				cont++;
			}
			i++;
		}
		ano = ano / 10;

		if(dia < 0 || dia > 31){
			printf("dia invalida %d\n", dia);
			return 0;
		}else if( mes < 1 || mes > 12){
			printf("mes invalida %d\n", mes);
			return 0;
		}else if( ano < 1900 || ano > 2023){
			printf("ano invalida %d\n", ano);
			return 0;
		}else if((2023 - ano) < 18){
			printf("cliente menor que 18 anos %d", ano - 2023);
			return 0;
		}
		return 1;
	}

// validacao Genero --------------------------------------------------------------------------

	int validacaoGenero(clientes clientesStruct){
		if(clientesStruct.genero == 1 || clientesStruct.genero == 2 || clientesStruct.genero == 3 ){
			return 1;
		}else{
			return 0;
		}
	}

// REmover quebra de linha -------------------------------------------------------------------

	void removerQuebraLinha(char *string)
	{
    	if(string != NULL && strlen(string) > 0)
    	{
    	    short tamanho = strlen(string);
    	    if(string[tamanho-1] == '\n')
    	    {
   	            string[tamanho-1] = '\0';
    	    }
    	}
	}

//PASSAGEM ARQUIVO --------------------------------------------------------------------------

	void passagemArquivoCode(clientesT *clientesGeral){
		FILE *arquivo;
		int qtdeClientes;

		arquivo = fopen("listaClientes.txt", "r");

		if(arquivo != NULL){
			printf("\narquivo foi aberto corretamente em passagemArquivo\n");
		}else{
			printf("\narquivo nao foi aberto em passagemArquivo\n");
		}
		fscanf(arquivo, "%d", &qtdeClientes);

		clientesT *p = realloc(clientesGeral, qtdeClientes * sizeof(clientesGeral));

		if(clientesGeral != NULL){
			printf("\ndeu boa no realloc\n");
			clientesGeral = p;
		}else{
			printf("\nfudeu deu ruim no realloc\n");
		}

		//teste a partir daqui -----
		char linha[sizeof(clientesT)];
		char *pt;
		clientesT *marca;

		for (int i = 0; i < qtdeClientes; i++)
		{
			puts("debug 3");
			fgets(linha, sizeof(linha), arquivo);

			pt = strtok(linha, "|");

			for(marca = &clientesGeral[0]; marca < &clientesGeral[qtdeClientes - 1]; marca++)
			{
				puts("debug 4");
				strcpy(marca->cpf, pt);
				printf("%s", marca->cpf);
				pt = strtok(NULL, "|");
				strcpy(marca->nome, pt);
				printf("%s", marca->nome);
				pt = strtok(NULL, "|");
				strcpy(marca->email, pt);
				pt = strtok(NULL, "|");
				strcpy(marca->telefone, pt);
				pt = strtok(NULL, "|");
				strcpy(marca->dataNascimento, pt);
				pt = strtok(NULL, "|");
				marca->genero = ((int)*pt) - 48; 
				pt = strtok(NULL, "|");
				strcpy(marca->estado, pt);
				pt = strtok(NULL, "|");
				strcpy(marca->cidade, pt);
				pt = strtok(NULL, "|");
				strcpy(marca->rua, pt);
				pt = strtok(NULL, "|");
				for (int i = 0, j = strlen(pt); i < j; i++)
				{
					puts("debug 5");
					marca->numero = pt[i] = 48;
					marca->numero *= 10;
				}
				marca->numero /= 10;
				pt = strtok(NULL, "\n");
				marca->status = ((int)*pt) - 48;
				puts("debug 6");
			}
		}
		for(marca = &clientesGeral[0]; marca < &clientesGeral[qtdeClientes - 1]; marca++){
			printf("%s|%s|%s|%s|%s|%d|%s|%s|%s|%d|%d\n", marca->cpf, marca->nome, marca->email,
		marca->telefone, marca->dataNascimento, marca->genero, marca->estado, marca->cidade,
		marca->rua, marca->numero, marca->status);
		}
		puts("debug 7");

		fclose(arquivo);
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