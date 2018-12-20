#include "display.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>

#define porta 6666
#define tmb 1024

char buffer[tmb], bufaux[tmb], *loc;
char comandos[] = "/x /mem /disc /time /pros /port /help";
int pontarq, tbuf, skt, tskt, escolha;
struct sockaddr_in serv;

char optAbtSys;
char optFinder;
char optCalculator;
char optNote;
char optDateTime;
char optConnection;

int readOptBtnInt()
{
	int index;
	move(46, 3);
   	printw("Option: ");
    move(46, 10);
   	scanw("%d", &index);
    move(46, 10);
    printw("                    ");
    return index;
}

int readOptBtnFloat()
{
	float index;
	move(46, 3);
   	printw("Option: ");
    move(46, 10);
   	scanw("%f", &index);
    move(46, 10);
    printw("                    ");
    return index;
}

char readOptBtnChar()
{
	char index;
	move(46, 3);
   	printw("Option: ");
    move(46, 10);
   	scanw("%c", &index);
    move(46, 10);
    printw("                    ");
    return index;
}

void dataAboutSystem()
{
	displayAboutSystem();
	optAbtSys = readOptBtnChar();

	if (optAbtSys == 'x')
	{
	    displayCloseWindws();
	}
}

void dataFinder()
{
	displayFinder();

	while(1)
	{
	    char nameFile[10];
		char *result;
		char wLines[100];
		char rLines[100];
		int i;
		FILE *arq;

		optFinder = readOptBtnChar();

		if (optFinder == 'x')
		{
		    displayCloseWindws();
		    break;
		}
		else if(optFinder == 'n')
		{
	    	move(12, 46);
	   		scanw("%s", &nameFile);
		    strcat(nameFile, ".txt");

		    arq = fopen(nameFile, "wt");

		    move(13, 35);
		    printw("Created File: %s", nameFile);
		}
		else if(optFinder == 'w')
		{
	    	move(14, 42);
	   		scanw("%s", &wLines);
		    result = fputs(wLines, arq);
		    fclose(arq);
		}
		else if(optFinder == 'r')
		{
		    arq = fopen(nameFile, "rt");
		    while(!feof(arq))
		    {
		    	result = fgets(rLines, 100, arq);
		    	if(result)
		    	{
		    	move(15, 41);
		    	printw("%s", rLines);
		    	}
			}
		fclose(arq);
		}
	}	
}

void dataCalculator()
{
	displayCalculator();

	while(1)
	{
		optCalculator = readOptBtnChar();
		
		if (optCalculator == 'x')
		{
		    displayCloseWindws();
		    break;
		}
		if (optCalculator == 'a')
		{
			int valueA = 0, valueB = 0, valueResult = 0;

			valueA = readOptBtnInt();
			valueB = readOptBtnInt();

			valueResult = valueA + valueB;

			move(15, 115);
	       	printw("%d", valueResult);
	       	break;
		}
		else if (optCalculator == 's')
		{
			int valueA = 0, valueB = 0, valueResult = 0;

			valueA = readOptBtnInt();
			valueB = readOptBtnInt();

			valueResult = valueA - valueB;

			move(16, 118);
	       	printw("%d", valueResult);
	       	break;
	    }
		else if (optCalculator == 'm')
		{
			int valueA = 0, valueB = 0, valueResult = 0;

			valueA = readOptBtnInt();
			valueB = readOptBtnInt();

			valueResult = valueA * valueB;

			move(17, 121);
	       	printw("%d", valueResult);
	       	break;
	    }
		else if (optCalculator == 'd')
		{
			float valueA = 0.0, valueB = 0.0, valueResult = 0.0;

			valueA = readOptBtnFloat();
			valueB = readOptBtnFloat();

			valueResult = valueA / valueB;

			move(18, 115);
	       	printw("%0.2f", valueResult);
	       	break;
	    }
	}
}

void dataNotes()
{
	displayNotes();

	while(1)
	{
		optNote = readOptBtnChar();

		if (optNote == 'x')
		{
		    displayCloseWindws();
		    break;
		}
		if (optNote == 'n')
		{
			char newNote[100];
			move(36, 6);
		   	printw("New Note: ");
		    move(36, 16);
		   	scanw("%s", &newNote);
			move(38, 6);
		   	printw("-> %s", newNote);
		    move(36, 16);
		   	printw("                                             ");  	
		}		
	}
}

void dataDateTime()
{
	displayDateTime();
	move(19, 73);
	printw("Data :%s ", __DATE__);
	move(20, 73);
	printw("Hora:%s",__TIME__);

	optDateTime = readOptBtnChar();

	while(1)
	{
		if (optDateTime == 'x')
		{
		    displayCloseWindws();
		    break;
		}
	}
}

void dataConnection()
{
   displayConnection();

   while(1)
   {
   		optConnection = readOptBtnChar();
   		
		if (optConnection == 'x')
		{
		    displayCloseWindws();
		    break;
		}
		else if (optConnection == 'c')
		{	
    		skt = socket(AF_INET, SOCK_STREAM, 0);
    		serv.sin_family = AF_INET;
    		serv.sin_addr.s_addr = INADDR_ANY;
    		serv.sin_port = htons (porta);
    		memset(&(serv.sin_zero),0x00,sizeof(serv.sin_zero));
    		tskt = sizeof(struct sockaddr_in);
    
    		move(34, 89);
    		printw("Welcome Freeze Server");

    		bind(skt,(struct sockaddr *)&serv,sizeof(struct sockaddr));
    		listen(skt,1);

    		move(35, 89);
    		printw("Server work in port: %d",porta);
    		skt = accept(skt,(struct sockaddr *)&serv,&tskt);

    		move(36, 89);
    		printw("The connection with adress %s is estabilished!",inet_ntoa(serv.sin_addr));
    		strcpy(buffer,"Server OK!!!");
    		strcpy(bufaux,buffer);
    		send(skt,buffer,strlen(buffer), 0);

    		tbuf = recv(skt, buffer,tmb, 0);
	    	buffer[tbuf]=0x00;
	    	move(37, 89);
       		printw(">: %s\n",buffer); 

    		while(strcmp(bufaux,buffer) != 0)
    		{
    			move(37, 89);
       			printw(">: %s\n",buffer);     
   				strcpy(bufaux,buffer);
   			}
		}
   }
}