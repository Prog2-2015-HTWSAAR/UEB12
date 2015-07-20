/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb12 *.o
* @file ueb12.cpp
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @date 19.07.2015
*
* Main Funktion
*/
#include <iostream>
#include "Startdialog.h"
using namespace std;

/**
* @brief Main Function
*/
int main(){
	Startdialog startDial;
	startDial.runStartDialog();
	return 0;
}
 
