/**
* compile: g++ -c -Wall -pedantic *.cpp
* compile: g++ -o ueb08 *.o
* @file  ListenDialog.h
* @author Andreas Schreiner & Simon Bastian
* Changelog: https://onedrive.live.com/redir?page=view&resid=A24EC16A1F3E72AA!4270&authkey=!AFE0aRW5WKEHg3Q
*
* @date 14.06.2015
*/
#include "LinList.h"
#include <iostream>
#include <sstream>      
#include "Person.h"
#include "MyQueue.h"
#ifndef QUEUEDIALOG_H_
#define QUEUEDIALOG_H_
enum LanguageDialogOption{ CLOSEPROGRAM, GERMAN, ENGLISH, HODOR, START_MAINDIALOG, runAgain };
enum MainDialogOption{ EXIT, ENQUEUE, DEQUEUE };


class QueueDialog {
public:
	//Konstanten 
	//Seperators
	static const char* SPACER;
	static const string PARSE_COPY;

	//Errorphrasses
	// LanguageDialog
	static const string STD_LANG_NOT_FOUND;
	static const string DE_DE_LANG_NOT_FOUND;
	static const string EN_US_LANG_NOT_FOUND;
	static const string HODOR_WESTEROS_LANG_NOT_FOUND;
	static const string PARSE_LANGUAGEDIALOG;
	static const string LANGUAGE_GERMAN;
	static const string LANGUAGE_ENGLISH;
	static const string LANGUAGE_HODOR;
	static const string LANGUAGE_STD;
	static const string STD_INP_PHRASE;
	// Maindialog
	static const string PARSE_SEPERATOR_LINLIST_BLOCK;
	static const string PARSE_MAINDIALOG;

	// Allgemein
	static const string PARSE_INPUT_ERROR;
	static const string PARSE_STD_ERROR;

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
