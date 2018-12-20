void desenha_linha(int x, int y, int qtd, char simb)
{
    int i;
    for (i =0; i < qtd; i++) 
    {
        move(x, y);
        printw("%c", simb);
        y = y + 1;
    }
}

void desenha_coluna(int x, int y, int qtd, char simb)
{
    int i;
    for (i=0; i < qtd; i++) 
    {
        move(x, y);
        printw("%c", simb);
        x = x + 1;
    }
}

void desenha_tela ()
{    
    desenha_linha(1, 2, 207, '=');
    desenha_linha(3, 2, 207, '=');
    desenha_linha(47, 2, 207, '=');
    desenha_coluna(1, 209, 47, ']');
    desenha_coluna(1, 1, 47, '[');
}

void menu()
{
    move(2, 4);
    printw("( 1 ) - About System");
    move(2, 27);
    printw("( 2 ) - Finder");
    move(2, 44);
    printw("( 3 ) - Calculator");
    move(2, 65);
    printw("( 4 ) - Notes");
    move(2, 81);
    printw("( 5 ) - Date and Time");
    move(2, 105);
    printw("( 6 ) - Connection");
    move(2, 124);
    printw("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    move(2, 185);
    printw("( 0 ) - TurnOff System");
}