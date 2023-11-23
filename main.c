#include "./BADT/frame.h"
#include "constructors.h"

void main(){

	int height = 18;
	Frame frames[6];
	Table moviesTable;

	setupMainMenu(&frames[0], height);
	
	//MOVIE
	setupMovieMenu(&frames[1], &moviesTable, height);
	setupMovieFilter(&frames[2], height);
	setupMovieFilterG(&frames[3], height);
	
	frameRefresh(&frames[3]);
	
	imageShow(&frames[1].image);
}


