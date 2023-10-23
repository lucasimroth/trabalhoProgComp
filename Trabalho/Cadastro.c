#include <stdio.h>

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

int main(){

/*1 ---- a parte de cadastro quando entra na função pede os dados do usuario
sendo eles:
CPF - NOME - Email - Telefone - DATA de Nascimento - Sexo - endereço - pedidos - status do cadastro
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












    return 1;
}