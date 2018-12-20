#include "desenha_tela.h"

void displayAboutSystem()
{
	desenha_linha(4, 4, 25, '=');
	desenha_linha(6, 4, 25, '=');
	desenha_linha(13, 4, 25, '=');
	desenha_coluna(4, 3, 10, '[');
	desenha_coluna(4, 29, 10, ']');
	move(5, 6);
	printw(" -> About System");
	move(8, 6);
	printw("Freeze OS");
	move(9, 6);
	printw("Version Beta 0.0.1");
	move(10, 6);
	printw("by Fats Corporation");
	move(12, 6);
	printw("( x ) - Close");
}

void displayFinder()
{
	desenha_linha(4, 33, 35, '=');
	desenha_linha(6, 33, 35, '=');
	desenha_linha(28, 33, 35, '=');
	desenha_coluna(4, 32, 25, '[');
	desenha_coluna(4, 68, 25, ']');
	move(5, 35);
	printw(" -> Finder");
	move(7, 35);
	printw("( n ) - New File");
	move(8, 35);
	printw("( w ) - Write File");
	move(9, 35);
	printw("( r ) - Read File");
	move(10, 35);
	printw("( x ) - Close");
	move(12, 35);
	printw("Name File: ");
	move(14, 35);
	printw("Write: ");
	move(15, 35);
	printw("Read: ");
}

void displayCalculator()
{
	desenha_linha(4, 99, 69, '=');
	desenha_linha(6, 99, 69, '=');
	desenha_linha(28, 99, 69, '=');
	desenha_coluna(4, 98, 25, '[');
	desenha_coluna(4, 167, 25, ']');
	move(5, 101);
	printw(" -> Calculator");
	move(8, 100);
	printw("Basic Operations Math:");
	move(9, 100);
	printw("( a ) - Addition");
	move(10, 100);
	printw("( s ) - Subtraction");
	move(11, 100);
	printw("( m ) - Multiplication");
	move(12, 100);
	printw("( d ) - Division");
	move(14, 100);
	printw("Results:");
	move(15, 100);
	printw("..by Addition: ");
	move(16, 100);
	printw("..by Subtraction: ");
	move(17, 100);
	printw("..by Multiplication: ");
	move(18, 100);
	printw("..by Division: ");
	move(20, 100);
	printw("After performing one of the operations, press x to start over.");
}

void displayNotes()
{
	desenha_linha(29, 4, 80, '=');
	desenha_linha(31, 4, 80, '=');
	desenha_linha(44, 4, 80, '=');
	desenha_coluna(29, 3, 16, '[');
	desenha_coluna(29, 84, 16, ']');
	move(30, 6);
	printw(" -> Notes");
	move(33, 6);
	printw("( n ) - New Note");
	move(34, 6);
	printw("( x ) Close");
}

void displayDateTime()
{
	desenha_linha(15, 71, 25, '=');
	desenha_linha(17, 71, 25, '=');
	desenha_linha(28, 71, 25, '=');
	desenha_coluna(15, 70, 14, '[');
	desenha_coluna(15, 96, 14, ']');
	move(16, 73);
	printw(" -> Date and Time");
	move(27, 73);
	printw("( x ) - Close");
}

void displayConnection()
{
	desenha_linha(29, 87, 80, '=');
	desenha_linha(31, 87, 80, '=');
	desenha_linha(44, 87, 80, '=');
	desenha_coluna(29, 86, 16, '[');
	desenha_coluna(29, 167, 16, ']');
	move(30, 89);
	printw(" -> Connection");
	move(32, 89);
	printw("( c ) - Connect");
	move(33, 89);
	printw("( x ) - Close");
}

void displayCloseWindws()
{
	clear();
	desenha_tela();
	menu();
}