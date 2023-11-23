void setupMainMenu(Frame *frame, int height);
void setupMovieMenu(Frame *frame, Table *table, int height);
void setupMovieFilter(Frame *frame, int height);
void setupMovieFilterG(Frame *frame, int height);

void refreshMovieMenu(Frame *frame);

//-------//

void setupMainMenu(Frame *frame, int height){

	frameSetup(frame, "MENU PRINCIPAL", 50, height, 'n');

	frameInsertCenter(frame, "Seja bem vindo!", 2);

	frameInsertOption(frame, "Consultar Filmes");
	frameInsertOption(frame, "Consultar Clientes");
	frameInsertOption(frame, "Consultar Pedidos");
}

void setupMovieMenu(Frame *frame, Table *table, int height){

	frameSetup(frame, "FILMES", 80, height, 'n');
	
	tableSetup(table, "dsdsf"," id, nome, ano, genero, duracao");
	txtToTable(table, "./movies");
	
	frameSetTable(frame, table);
	frameRefresh(frame);
	
	frameInsertCenter(frame, "F - Filtrar : L - Limpar Filtro : P - Novo Pedido : C - Cadastrar : D - Deletar",19);
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

	frameInsertCenter(frame, "Escolha qual genero deseja:", 2);
	
	frameInsertOption(frame, "Acao");
	frameInsertOption(frame, "Aventura");
	frameInsertOption(frame, "Comedia");
	frameInsertOption(frame, "Drama");
	frameInsertOption(frame, "Roance");
	frameInsertOption(frame, "Suspense");
	frameInsertOption(frame, "Terror");
}


//-------//

void refreshMovieMenu(Frame *frame){

	frameRefresh(frame);
	frameInsertCenter(frame, "F - Filtrar : L - Limpar Filtro : P - Novo Pedido : C - Cadastrar : D - Deletar",19);
}
