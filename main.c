#include "./BADT/frame.h"
#include "./Suport/constructors.h"

void main(){

	int height = 18;
	Frame frames[6];
	Table moviesTable;

	setupMainMenu(&frames[0], height);
	frameRefresh(&frames[0]);
	
	//MOVIE
	setupMovieMenu(&frames[0],&moviesTable, height);
	
	imageShow(&frames[0].image);
}
