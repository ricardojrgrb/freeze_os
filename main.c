#include <stdio.h>
#include <curses.h>
#include "states.h"

int main() 
{    
    initscr(); 		/* lib cursers */
    desenha_tela();
    menu();
    init_states();
    endwin();		/* lib cursers */
}
