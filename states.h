#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "dataDriver.h"

/* States */
#define ST_END			0
#define ST_ABOUTSYSTEM 	1
#define ST_FINDER	   	2
#define ST_CALCULATOR  	3
#define ST_NOTES	   	4
#define ST_DATETIME    	5
#define ST_CONNECTION  	6
#define ST_CLOSEWINDWS 	7

/* Defines Socket Connection */
#define tmb 1024
#define porta 6666

/* Global Variables by States*/
int state;


void init_states() 
{
    while(1)
    {

    	state = readOptBtnInt();

	    switch(state)
	    {
	    	case ST_ABOUTSYSTEM:

	    		dataAboutSystem();

	    		break;
	    	case ST_FINDER:

	    		dataFinder();

	    		break;
	    	case ST_CALCULATOR:

	    		dataCalculator();

	    		break;
	    	case ST_NOTES:

	    		dataNotes();

	    		break;
	    	case ST_DATETIME:
	    		
	    		dataDateTime();

	    		break;
	    	case ST_CONNECTION:
	    
	    		dataConnection();

	    		break;
	    	case ST_CLOSEWINDWS:

	    		displayCloseWindws();

	    		break;
	    	case ST_END:
	    		system("clear");
	    		exit(EXIT_SUCCESS);

	    		break;
	    	default:
	    		move(46, 10);
        		printw("Invalid Option!!");
        		getch();
        		move(46, 10);
    			printw("                    ");		
	    }
	}
}