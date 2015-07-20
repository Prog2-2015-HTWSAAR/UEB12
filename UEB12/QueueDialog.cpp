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

void QueueDialog::initListDialog(){
	ListenQueue<Person>* q = new ListenQueue<Person>();
	qDialog(q);

}
void QueueDialog::qDialog(ListenQueue<Person>* q) {
	int answer;
	Person* personpointer = NULL;
		do {
			try {
				cout << SEPERATOR_Q << endl;
				cout << *q << endl;
				cout << SEPERATOR << endl << EN_QUEUE_OPTION << endl << DE_QUEUE_OPTION
					<< endl << "(3) Listenoptionen "<< endl << EXIT_OPTION
					<< 	endl << CHOSE_WISELY;
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
				case LISTOPTIONS:
					startLQDialog(q);
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

void QueueDialog::startLQDialog(ListenQueue<Person> *q){
	int answer = -1;
	do{
		cout << *q << endl;
		cout << "(1 )  Push back" << endl;
		cout << "(2 )  Push front" << endl;
		cout << "(3 )  Pop back" << endl;
		cout << "(4 )  Pop front" << endl;
		cout << "(5 )  Vor Position Einfuegen" << endl;
		cout << "(6 )  Position Loeschen" << endl;
		cout << "(0 )  Zurueck" << endl;
		cout << endl << "Ihre Wahl: ";
		answer = readIntegerInput();
		chooseLQOption(q, answer);
	}while (answer != 0);
}

void QueueDialog::chooseLQOption(ListenQueue<Person>* q, int choice){
	int answer = -1;
	try {
		switch (choice) {
			case EXIT_LQ:
				answer = 0;
				break;
			case PUSH_BACK_LQ:
				q->push_back(*lesePerson());
				break;
			case PUSH_FRONT_LQ:
				q->push_front(*lesePerson());
				break;
			case POP_BACK_LQ:
				cout << q->pop_back() << " gepopt!" << endl;
				break;
			case POP_FRONT_LQ:
				cout << q->pop_front() << " gepopt!" << endl;
				break;
			case INSERT_POS_LQ:
				cout << "Position: ";
				answer = readIntegerInput();
				cout << "Person:" << endl;
				q->insert(answer, *lesePerson());
				break;
			case DELETE_POS_LQ:
				cout << "Position: ";
				answer = readIntegerInput();
				cout << "Position " << answer << " gelöscht" << endl;
				break;
			default:
				cout << "Fehlerhafte Eingabe!" << endl;
				break;
		}
	} catch (logic_error& e) {
		cout << "Fehler: " << e.what() << endl;
	}
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

