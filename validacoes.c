#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validacaoCPF(char *string);
char *stringChar(const char *palavra, char caracter);
int leituraStr(char *string);
int comparaSTR(char *p1, char *p2);
int validacaoStr(char *string);
int validacaoEmail(char *string);
int validacaoTel(char *string);
int validacaoData(char *string);

//  --------------------------ValidaçãoCPF-----------------------------------------------------------

int validacaoCPF(char *string)
	{

	int *p;
	int primeiroDigito = 0;
	int segundoDigito = 0;
	int tamanho = strlen(string);
	FILE *arquivo;

	arquivo = fopen("texte.txt", "r"); // MODIFICAR PARA O CODIGO EM VIGENCIA

	if(arquivo != NULL)
    {
		char linha[300];
		fflush(stdin);
			//TOMAR CUIDADO COM ESPAÇOS NO ARQUIVO, ELE BUGA A BUSCA, NAO ALTERAR ARQUIVO MANUALMENTE
		while(fgets(linha, sizeof(linha), arquivo) != NULL)
        {
			linha[strcspn(linha, "\n")] = '\0';

			char *token = strtok(linha, "|");

			if(strcmp(token, string) == 0){
				fclose(arquivo);
				return 0; // AVISO CPF JA CADASTRADO ++++++++++++++++++++++++++++++++++++
			}
		}
		}else
        {
			printf("\narquivo nao foi aberto em validação CPF\n");
		}
		
			if((comparaSTR(string, "00000000000") == 0) || (comparaSTR(string, "11111111111") == 0) || (comparaSTR(string, "22222222222") == 0) || (comparaSTR(string, "33333333333") == 0)
			|| (comparaSTR(string, "44444444444") == 0) || (comparaSTR(string, "55555555555") == 0) || (comparaSTR(string, "66666666666") == 0) || (comparaSTR(string, "77777777777") == 0)
			|| (comparaSTR(string, "88888888888") == 0) || (comparaSTR(string, "99999999999") == 0))
			{
				return 0; //AVISO SOBRE CPF ser invalido+++++++++++++++++++++
			}else
			{
	    		p = (int *)malloc(11 * sizeof(int));

	    		for(int i = 0; i < 11; i++)
                {
	        		p[i] = string[i] - 48;
	        		printf("%d", p[i]);
	    		}

 	   		for(int i = 0, j = 10; i < tamanho - 2; i++, j--)
            {
	        	primeiroDigito += ( p[i] * j );
	    	}
			primeiroDigito %= 11;
	    	if(primeiroDigito < 2)
            {
	        	primeiroDigito = 0;
	    	}else{ primeiroDigito = 11 - primeiroDigito;}

	    	for( int i = 0, j = 11; i < tamanho - 1; i++, j--)
            {
	        	segundoDigito += ( p[i] * j);
	    	}
			segundoDigito %= 11;
	    	if(segundoDigito < 2)
            {
	        	segundoDigito = 0;
	    	}else { segundoDigito = 11 - segundoDigito;}

			printf("\n%d -> %d \n%d - > %d", p[9], primeiroDigito, p[10], segundoDigito);
	    	if(primeiroDigito == p[9] && segundoDigito == p[10]){
	        	free(p);
	        	return 1;
	    	}else{
	        	free(p);
	        	return 0; // AVISO SOBRE CPF SER INVALIDO ++++++++++++++++++++++++++++++
	    	}
		}		
	fclose(arquivo);
}

//---------------------------------------- Função StringChar -----------------------------------

char *stringChar(const char *palavra, char caracter){
	char caracter1 = tolower(caracter);
	do{
		if(*palavra == caracter1) return (char *) palavra;
		palavra++;
	}while(*palavra != '\0');
	return 0;
}

//--------------------------------------- Leitura de String ------------------------------------

int leituraStr(char *string){
	int qtde = 0;
	while(*string != '\0'){
		qtde++;
		string++;
	}
	return qtde;
}

//------------------------------------- COMPARA STRING -----------------------------------------

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

//-------------------------------------- Validação de Strings -----------------------------------

int validacaoStr(char *string){
	char *ponteiroStr = string;
	char letra;
	letra = *ponteiroStr++;
	while(letra != '\0')
    {
		if(!(isalpha(letra) || isspace(letra)))
        {
			return 0;
		}
		letra = *ponteiroStr++;
	};
	return 1;
};

//-------------------------------------------------Validação email -----------------------------------------------

int validacaoEmail(char *string){
	int arrobaMarca = 0;
	int i;

	for( i = 0; i < leituraStr(string); i++){
		if (string[i] == '@')
		{
			arrobaMarca++;
		}
		if(string[i] == ' ' || string[i] == '/' || string[i] == ':' || string[i] == ';' 
		|| string[i] == '<' || string[i] == '>' || string[i] == ',' || string[i] == '='
		|| string[i] == '[' || string[i] == ']' || string[i] == '{' || string[i] == '}')
		{
			return 0;
		}
	}
	if(arrobaMarca == 1){
		if(string[0] != '@'){
			char *ponto = stringChar(string, '.');
			if(ponto != 0 && ponto > stringChar(string, '@')){
				return 1;
			}
		}
	}
	return 0;
}

//---------------------------Validação telefone OBS: 27022001 sem as barras!!!---------------------------------------------------

int validacaoTel(char *string)
{
	if((comparaSTR(string, "00000000000") == 0) || (comparaSTR(string, "11111111111") == 0) || (comparaSTR(string, "22222222222") == 0) || (comparaSTR(string, "33333333333") == 0)
	|| (comparaSTR(string, "44444444444") == 0) || (comparaSTR(string, "55555555555") == 0) || (comparaSTR(string, "66666666666") == 0) || (comparaSTR(string, "77777777777") == 0)
	|| (comparaSTR(string, "88888888888") == 0) || (comparaSTR(string, "99999999999") == 0))
	{
		return 0; //AVISO DE NUMERO INVALIDO
	}else
    {
	    for(int i = 0; i < leituraStr(string); i++)
        {
			if(string[i] < '0' || string[i] > '9')
            {
				return 0; //AVISO DE NUMERO INVALIDO
			}
		}
	}
	return 1;
}

//--------------------------------------- VALIDACAO DATA -------------------------------------------------

int validacaoData(char *string)
{
	int dia = -1, mes = -1, ano = 0, i, cont = 0;

    printf("debug1");

	for(i = 0; i < leituraStr(string); i++){
        printf("debug2");
		if(!isdigit(string[i])){
            printf("debug3");
			return 0;
		}
	}
	i = 0;
	while (string[i] != '\0')
	{
		
		if(cont == 0)
		{
			if(dia == -1)
			{
				dia = (int)string[i] - 48;
				dia *= 10;
			}else
			{
				if(i == 2 && string[i] != '/' && string[i+1] != '/')
                {
					cont++;
					i--;
				}else
                {
					dia += (int)string[i]- 48;
				}
			}
		}else if(cont == 1)
        {
			if(mes == -1)
            {
				mes = (int)string[i]- 48;
				mes *= 10;		
			}else
            {
				if(i == 4 && string[i] != '/' && string[i+1] != '/')
                {
					cont++;
					i--;
				}else
                {
					mes += (int)string[i]- 48;
						
				}
			}
		}else if(cont == 2){
			ano += (int)string[i]- 48;
			ano *= 10;
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

// EXTRA ++++++++++++++++REmover quebra de linha -------------------------------------------------------------------

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
