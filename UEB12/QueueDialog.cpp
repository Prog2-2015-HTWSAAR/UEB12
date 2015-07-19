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
const char* QueueDialog::SPACER = " ";
const string QueueDialog::LANGUAGE_GERMAN = "de_DE.xml";
const string QueueDialog::LANGUAGE_ENGLISH = "en_US.xml";
const string QueueDialog::LANGUAGE_HODOR = "hodor_WESTEROS.xml";
const string QueueDialog::LANGUAGE_STD = "std.xml";
const string QueueDialog::STD_INP_PHRASE = "STD_INP_PHRASE";
// const strings
// Languagedialog
const string QueueDialog::STD_LANG_NOT_FOUND = "Language std NOT Found";
const string QueueDialog::DE_DE_LANG_NOT_FOUND = "DE_DE_LANG_NOT_FOUND";
const string QueueDialog::EN_US_LANG_NOT_FOUND = "EN_US_LANG_NOT_FOUND";
const string QueueDialog::HODOR_WESTEROS_LANG_NOT_FOUND ="HODOR_WESTEROS_LANG_NOT_FOUND";
const string QueueDialog::PARSE_LANGUAGEDIALOG = "LANGUAGE_DIALOGE";
// Maindialog
const string QueueDialog::PARSE_SEPERATOR_LINLIST_BLOCK =
"SEPERATOR_LINLIST_BLOCK";
const string QueueDialog::PARSE_MAINDIALOG = "MAINDIALOG";
//ManuellDialog

// Allgemein
const string QueueDialog::PARSE_INPUT_ERROR = "INPUT_E";
const string QueueDialog::PARSE_STD_ERROR = "STD_E";

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
	Queue<Person>* q = NULL;
	qDialog(q);
	
}
void QueueDialog::qDialog(Queue<Person>* q) {
	int answer;
	Person person = Person("Last","First");
	do {
		cout << "seperator_LinListe" << endl << "main_dialog";
		answer = readIntegerInput();
		switch (answer) {
		case EXIT:
			break;
		case ENQUEUE:
				q->enqueue(person);
			break;
		case DEQUEUE:
			q->dequeue();
			break;
		default:
			cout << "error_input" << endl;
			break;
		}
	} while (answer != EXIT);
}

void QueueDialog::enqueue(Person &Pers){

}
void QueueDialog::dequeue(){

}

string QueueDialog::parsePhrases(string fileName, string begin) {
	fstream file;
	string anfang = "<" + begin + ">";
	string ende = "</" + begin + ">";
	string cache;
	string line;
	string ausgabe;
	bool found = false;
	bool firstRun = true;
	bool stop = false;
	bool streamWritten = false;
	const char* constName = fileName.c_str();
	file.open(constName);
	while (getline(file, line)) {
		trim(line);
		if (!stop && found) {
			if (!firstRun) {
				ausgabe = ausgabe + cache;
				streamWritten = true;
			}
			if (firstRun) {
				firstRun = false;
			}
		}
		if (found && !stop) {
			if (strcmp(ende.c_str(), line.c_str()) == 0) {
				stop = true;
			}
			else {
				cache = line;
				if (streamWritten) {
					ausgabe = ausgabe + '\n';
				}
			}
		}
		if (strcmp(anfang.c_str(), line.c_str()) == 0 && !found) {
			found = true;
		}
	}
	file.close();
	return ausgabe;
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

bool QueueDialog::fileExists(string fileName) {
	const char* constName = fileName.c_str();
	ifstream infile(constName);
	return infile.good();
}

void QueueDialog::trim(string& str) {
	string trim_chars = " \t";
	string::size_type pos = str.find_last_not_of(trim_chars);
	if (pos != std::string::npos) {
		str.erase(pos + 1);
		pos = str.find_first_not_of(trim_chars);
		if (pos != std::string::npos)
			str.erase(0, pos);
	}
	else
		str.erase(str.begin(), str.end());
}
