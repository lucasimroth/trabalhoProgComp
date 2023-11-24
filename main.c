#include "./BADT/frame.h"
#include "./Suport/constructors.h"

void updateFrame(Frame *frame, char *buffer){
	frame->inputBuffer[0] = buffer[0];
	frameRefresh(frame);
			
	clear();
	imageShow(&frame->image);
}

void showFrame(Frame *frame){
	clear();
	imageShow(&frame->image);
}	

void resetOcult(Table *table){
	for(int i = 0; i < table->qtdLine-1; i++)
			tableUpdate(table,0,i,"  ");
}

void main(){

	#define height 18
	int state = 0;
	int lastState = 0, stateBuffer = 0;//State buffer sempre atualiza
	char input = '\0';
	
	//Frames
	Frame menuFrames[6];
	Frame frames[6];
	
	setupMainMenu(&menuFrames[0], height);
	setupMovieOptions(&menuFrames[1], height);
	setupMovieFilter(&menuFrames[2], height);
	setupMovieFilterG(&menuFrames[3], height);
	
	//Tabelas
	int movieFilter = 0;
	Table moviesTable[5];
	
	tableSetup(&moviesTable[0], "sdsdsf",",id, nome, ano, genero, duracao", 'n');//TODOS
	txtToTable(&moviesTable[0], "./movies",'n');
	
	tableSetup(&moviesTable[1], "sdsdsf",",id, nome, ano, genero, duracao", 'n');//FILTROS
	txtToTable(&moviesTable[1], "./movies",'n');
	
	// LOOP COM MAQUINA DE ESTADOS
	while(state > -1){
		
		//MAIN MENU
		if(!state){
			updateFrame(&menuFrames[0], &input);
			showFrame(&menuFrames[0]);
			
			if(input == 10){
				switch(menuFrames[0].optionSelect){
					case 0:
						state = 1;
						break;
					case 1:
						//state = 2;
						break;
					case 2:
						//state = 3;
						break;
					default:
						state = -1;
						break;
				}
			}
		}
		
		//FILMES
		else if(state == 1){
			
			if(!lastState){//INICIALIZANDO FRAME
				setupMovieMenu(&frames[0],&moviesTable[movieFilter], height);
				lastState = state;
			}
			frameSetTable(&frames[0], &moviesTable[movieFilter]);
			
			updateFrame(&frames[0], &input);
			showFrame(&frames[0]);
			
			if(input == 'o' || input == 'O'){
				state = 10;
			}
		}
		
		//OPÇÕES COM FILMES
		else if(state == 10){
			
			updateFrame(&menuFrames[1], &input);
			showFrame(&menuFrames[1]);
			
			if(input == 10){
				switch(menuFrames[1].optionSelect){
					case 0:
						lastState = 10;
						state = 11;
						break;
					case 1:
						tableRefresh(&moviesTable[0]);
						movieFilter = 0;
						state = 1;
						break;
					case 2:
						//state = 13;
						break;
					case 3:
						//state = 14;
						break;
					case 4:
						//state = 15;
						break;
					case 5:
						//state = 12;
						break;
					default:
						for(int i = 0; i < 6; i++)
							frameCursorSub(&menuFrames[1]);
						state = 0;
				}
			}
		}
		
		else if(state == 11){//OPÇÕES DE FILTRO
			
			updateFrame(&menuFrames[2], &input);
			showFrame(&menuFrames[2]);
			
			if(input == 10){
				switch(menuFrames[2].optionSelect){
					case 0:
						lastState = 11;
						state = 111;
						break;
					case 1:
						state = 112;
						break;
					case 2:
						lastState = 11;
						state = 113;
						break;
				}
				
			}
		}
		
		else if(state == 111){//Filtrar genero
			movieFilter = 1;
			
			updateFrame(&menuFrames[3], &input);
			showFrame(&menuFrames[3]);
			
			//Genero Escolhido
			char *select = (char *)malloc(moviesTable[0].bigOfCol[3] + 2);
			bufferClean(select, moviesTable[0].bigOfCol[4] + 1);
			//Saida da Tabela
			char *outBuffer = (char *)malloc(moviesTable[0].bigOfCol[3] + 2);
			bufferClean(outBuffer, moviesTable[0].bigOfCol[4] + 1);
			
			if(input == 10 && lastState == 11){
				
				switch(menuFrames[3].optionSelect){
					case 0:
						strCopy(select,"Acao");
						break;
					case 1:
						strCopy(select,"Aventura");
						break;
					case 2:
						strCopy(select,"Comedia");
						break;
					case 3:
						strCopy(select,"Drama");
						break;
					case 4:
						strCopy(select,"Romance");
						break;
					case 5:
						strCopy(select,"Suspense");
						break;
					case 6:
						strCopy(select,"Terror");
						break;
				}
				
				for(int i = 0; i < moviesTable[0].qtdLine-1; i++){
					tableGet(&moviesTable[0], 4, i, outBuffer);
					
					if((strComp(select, outBuffer) == 0)){
						tableGet(&moviesTable[0], 0, i, outBuffer);
						if(outBuffer[0] != ';')
							tableUpdate(&moviesTable[1],0,i,"  ");
					}
					else{
						tableUpdate(&moviesTable[1],0,i,":");
					}
				}
				state = 1;
			}
		}
		
		else if(state == 112){
			movieFilter = 1;
			if(lastState != 112){
				setupMovieFilterL(&frames[1]);
				lastState = 112;
			}
			
			updateFrame(&frames[1], &input);
			showFrame(&frames[1]);
			
			//Saida da Tabela
			char *outBuffer = (char *)malloc(moviesTable[0].bigOfCol[3] + 2);
			bufferClean(outBuffer, moviesTable[0].bigOfCol[4] + 1);
			
			if(input == 10){
				for(int i = 0; i < moviesTable[0].qtdLine-1; i++){
					tableGet(&moviesTable[0], 2, i, outBuffer);
					
					if(strComp(outBuffer, frames[1].inputBuffer) < 3){
						tableGet(&moviesTable[0], 0, i, outBuffer);
						if(outBuffer[0] != ';')
							tableUpdate(&moviesTable[1],0,i,"  ");
					}
					else{
						tableUpdate(&moviesTable[1],0,i,":");
					}
				}
				state = 1;
			}
		}
		
		else if(state == 113){
			movieFilter = 1;
			if(lastState != 113){
				setupMovieFilterY(&frames[1]);
				lastState = 113;
			}
			
			updateFrame(&frames[1], &input);
			showFrame(&frames[1]);
			
			//input
			char *inputBuffer = frameGetInput(&frames[1]);
			//Saida da Tabela
			char *outBuffer = (char *)malloc(moviesTable[0].bigOfCol[3] + 2);
			bufferClean(outBuffer, moviesTable[0].bigOfCol[3] + 1);
			
			if(input == 10){
				for(int i = 0; i < moviesTable[0].qtdLine-1; i++){
					tableGet(&moviesTable[0], 3, i, outBuffer);
					
					if(strComp(outBuffer, inputBuffer) == 0){
						tableGet(&moviesTable[0], 0, i, outBuffer);
						if(outBuffer[0] != ';')
							tableUpdate(&moviesTable[1],0,i,"  ");
					}
					else{
						tableUpdate(&moviesTable[1],0,i,":");
					}
				}
				state = 1;
			}
		}
		
		if(input != 10 && stateBuffer == state){
			input = getch();
		}
		else{
			input = '\0';
			stateBuffer = state;
		}
		
	}
	
	//ENCERRAMENTO
	clear();
	frameFree(&menuFrames[0]);
	
	tableToTxt(&moviesTable[0],"./teste");
	
	for(int i = 0; i < 2; i++){
		tableFree(&moviesTable[i]);
	}
	
	printf("\n====================================\n");
	printf("|                                  |\n");
	printf("| Programa encerrado corretamente! |\n");
	printf("|                                  |\n");
	printf("====================================\n");
}
