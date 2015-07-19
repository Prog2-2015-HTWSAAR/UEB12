/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file ueb08.cpp
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @date 14.06.2015
*
* Main Funktion
*/
#include <iostream>
#include "QueueDialog.h"
using namespace std;

/**
* @brief Main Function
*/
int main(){
//	ListenDialog listenDialog;
//	listenDialog.initLanguage();
	QueueDialog queueDialog;
	queueDialog.initDialog();
	return 0;
}
 
