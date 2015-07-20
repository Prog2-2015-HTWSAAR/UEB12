/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file QueueDialog.cpp
* @author Andreas Schreiner & Simon Bastian
*
* @date 14.06.2015
*/
#include "QueueDialog.h"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <math.h>
#include <stdexcept>

//Konstanten
//Seperators
const char* QueueDialog::STD_ERROR = "Fehler: ";
const string QueueDialog::LAST_NAME = "Nachname: ";
const string QueueDialog::SUR_NAME = "Vorname: ";
const string QueueDialog::DEQUEUED = " dequeued";
const string QueueDialog::EMPTY_STRING = "";
const string QueueDialog::SEPERATOR = "---------------------";
const string QueueDialog::SEPERATOR_Q = "--------Queue--------";
const string QueueDialog::EN_QUEUE_OPTION = "(1) Enqueue Person";
const string QueueDialog::DE_QUEUE_OPTION = "(2) Dequeue Person";
const string QueueDialog::EXIT_OPTION = "(0) Exit";
const string QueueDialog::CHOSE_WISELY = "-> ";

//const Int
const int QueueDialog::STD_ANSWER_VALUE = -1;
const int QueueDialog::ZERO_VALUE = 0;
const int QueueDialog::INPUT_ONE = 1;
const int QueueDialog::INPUT_VALUE = 2;
const int QueueDialog::ARRAY_OPERATOR_TEST_VALUE = 3;
const int QueueDialog::MAX_RUNS_FILE_READ = 4;
const int QueueDialog::HIGH_VALUE = 1000;
const int QueueDialog::TEST_QUANTITY = 21;
const int QueueDialog::A_REGULAR_OUTPUT_STOPER = 13;

QueueDialog::QueueDialog() {}
QueueDialog::~QueueDialog() {}
/**
* @brief QueueDialog::mainDialog()
* @details HauptDialog Auswahl Auto Manuell Exit
*/
void QueueDialog::initDialog(){
	MyQueue<Person>* q = new MyQueue<Person>();
	qDialog(q);
	
}
void QueueDialog::qDialog(MyQueue<Person>* q) {
	int answer;
	Person* personpointer = NULL;
		do {
			try {
				cout << SEPERATOR_Q << endl;
				cout << *q << endl;

				outputOptions();
				answer = readIntegerInput();
				switch (answer) {
				case EXIT_Q:
					break;
				case ENQUEUE:
					personpointer = lesePerson();
					q->enQueue(*personpointer);
					break;
				case DEQUEUE:
					cout << q->deQueue() << DEQUEUED << endl;
					break;
				default:
					cout << STD_ERROR << endl;
					break;
				}
			} catch (logic_error& e) {
				cout << STD_ERROR  << e.what() << endl;
			}
		} while (answer != EXIT_Q);

}

void QueueDialog::outputOptions(){
	cout << SEPERATOR << endl << EN_QUEUE_OPTION << endl << DE_QUEUE_OPTION 
		<< endl << EXIT_OPTION << endl << CHOSE_WISELY;
}

Person* QueueDialog::lesePerson(){
	string nachname = EMPTY_STRING;
	string vorname = EMPTY_STRING;
	cout << LAST_NAME;
	nachname = readStringInput();
	cout << SUR_NAME;
	vorname = readStringInput();
	return new Person(nachname, vorname);
}
void QueueDialog::clearInput() {
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}

int QueueDialog::readIntegerInput() {
	double number = readDoubleInput();
	if (!(fmod(number, INPUT_ONE) == ZERO_VALUE)) {
		number = STD_ANSWER_VALUE;
	}
	return (int)number;
}

double QueueDialog::readDoubleInput() {
	double number;
	if (cin >> number) {
	}
	else {
		number = STD_ANSWER_VALUE;
	}
	clearInput();
	return number;
}

string QueueDialog::readStringInput() {
	string input;
	cin >> input;
	clearInput();
	return input;
}

