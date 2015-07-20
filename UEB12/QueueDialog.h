/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file  ListenDialog.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @date 14.06.2015
*/
#include <iostream>
#include <sstream>      
#include "Person.h"
#include "MyQueue.h"
#ifndef QUEUEDIALOG_H_
#define QUEUEDIALOG_H_
enum MainDialogOptions{ EXIT_Q, ENQUEUE, DEQUEUE };


class QueueDialog {
public:
	//Konstanten 
	//Seperators
	static const char* STD_ERROR;
	static const string SEPERATOR;
	static const string SEPERATOR_Q;
	static const string EN_QUEUE_OPTION;
	static const string DE_QUEUE_OPTION;
	static const string EXIT_OPTION;
	static const string CHOSE_WISELY;
	static const string LAST_NAME;
	static const string SUR_NAME;
	static const string DEQUEUED;
	static const string EMPTY_STRING;
	//const Int
	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_ONE;
	static const int INPUT_VALUE;
	static const int HIGH_VALUE;
	static const int TEST_QUANTITY;
	static const int MAX_RUNS_FILE_READ;
	static const int A_REGULAR_OUTPUT_STOPER;
	static const int ARRAY_OPERATOR_TEST_VALUE;

	//FKT
	/**
	* @brief Konstruktor
	*/
	QueueDialog();
	/**
	* @brief Dekonstruktor
	*/
	virtual ~QueueDialog();
	void initDialog();
	void qDialog(MyQueue<Person>* q);
	void outputOptions();
	bool fileExists(string fileName);

	Person* lesePerson();
	/**
	* @brief readIntegerInput read in int
	*/
	void clearInput();
	int readIntegerInput();
	/**
	* @brief readIntegerInput read in double
	*/
	double readDoubleInput();
	/**
	* @brief readIntegerInput read in string
	*/
	string readStringInput();
	/**
	* @brief parsePhrases Xml Parser
	* @param fileName Xml Datei die genutzt werden soll
	* @param begin String in Xml Datei der als start und endpunkt gennommen werden soll
	*/
	string parsePhrases(string fileName, string begin);
	/**
	* @brief trim string trimmer
	* @param str String Referenz
	*/
	void trim(std::string& str);

};

#endif /* LINLIST_LISTENDIALOG_H_ */
