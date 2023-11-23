//MOVIE CONSTRUCTOR
void setupMainMenu(Frame *frame, int height);//MENU
void setupMovieMenu(Frame *frame, Table *table, int height);//TABLE
void setupMovieFilter(Frame *frame, int height);//MENU
void setupMovieFilterG(Frame *frame, int height);//MENU
void setupMovieFilterL(Frame *frame);//INPUT LEN 1
void setupMovieFilterY(Frame *frame);//INPUT LEN 4
void setupMovieId(Frame *frame, int state);//INPUT LEN 10

//MOVIE REFRESH
void refreshMovieMenu(Frame *frame);

//-------//

void setupMainMenu(Frame *frame, int height){

	frameSetup(frame, "MENU PRINCIPAL", 52, height, 'n');

	frameInsertCenter(frame, "Seja bem vindo!", 2);

	frameInsertOption(frame, "Consultar Filmes");
	frameInsertOption(frame, "Consultar Clientes");
	frameInsertOption(frame, "Consultar Pedidos");
	
	frameInsert(frame, "NOTA: Comandos no rodape sem atalho sao executados", 2, height - 3);
	frameInsert(frame, "ao pressionar a PRIMEIRA LETRA do mesmo", 2, height - 2);
}

void setupMovieMenu(Frame *frame, Table *table, int height){

	frameSetup(frame, "FILMES", 80, height, 'n');
	
	tableSetup(table, "dsdsf"," id, nome, ano, genero, duracao");
	txtToTable(table, "./movies");
	
	frameSetTable(frame, table);
	frameRefresh(frame);
	
	frameInsertCenter(frame, "Filtrar:Limpar Filtro :Novo Pedido :Cadastrar :Atualizar Filme :Deletar Cadastro",19);
}

void setupMovieFilter(Frame *frame, int height){

	frameSetup(frame, "FILTRAR FILME", 50, height, 'n');

	frameInsertCenter(frame, "Escolha como deseja filtrar:", 2);
	
	frameInsertOption(frame, "Filtrar por genero");
	frameInsertOption(frame, "Filtrar por letra");
	frameInsertOption(frame, "Filtrar por ano");
}

void setupMovieFilterG(Frame *frame, int height){

	frameSetup(frame, "FILTRAR POR GENERO", 50, height, 'n');

	frameInsertCenter(frame, "Selecione um genero deseja:", 2);
	
	frameInsertOption(frame, "Acao");
	frameInsertOption(frame, "Aventura");
	frameInsertOption(frame, "Comedia");
	frameInsertOption(frame, "Drama");
	frameInsertOption(frame, "Roance");
	frameInsertOption(frame, "Suspense");
	frameInsertOption(frame, "Terror");
}

void setupMovieFilterL(Frame *frame){

	frameSetup(frame, "==FILTRAR POR LETRA===", 50, 5, 'n');
	frameSetInput(frame, "Digite a letra:",1);
}

void setupMovieFilterY(Frame *frame){

	frameSetup(frame, "FILTRAR POR ANO", 50, 5, 'n');
	frameSetInput(frame, "Digite o ano: ",4);
}

void setupMovieId(Frame *frame, int state){

	if(state == 12)
		frameSetup(frame, "INICIAR NOVO PEDIDO", 50, 5, 'n');
		
	else if(state == 14)
		frameSetup(frame, "ATUALIZAR FILME", 50, 5, 'n');
		
	else if(state == 15)
		frameSetup(frame, "DELETAR FILME", 50, 5, 'n');

	frameSetInput(frame, "Digite o id do filme: ",10);
}

void setupMovieRegister(Frame *frame, int state){

	frameSetup(frame, "CADASTRAR NOVO FILME", 50, 5, 'n');

	if(state == 13)
		frameSetInput(frame, "Digite o nome: ",40);
	if(state == 131)
		frameSetInput(frame, "Digite o ano: ",4);
	if(state == 132)
		frameSetInput(frame, "Digite a duracao em horas: ",3);
}

//-------//

void refreshMovieMenu(Frame *frame){

	frameRefresh(frame);
	frameInsertCenter(frame, "F-Filtrar :L-Limpar Filtro :P-Novo Pedido :C-Cadastrar :A-Atualizar Filme :D-Deletar",19);
}
