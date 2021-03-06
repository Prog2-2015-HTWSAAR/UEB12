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
#include "ListenQueue.h"
#ifndef QUEUEDIALOG_H_
#define QUEUEDIALOG_H_
enum MainDialogOptions{ EXIT_Q, ENQUEUE, DEQUEUE, LISTOPTIONS };
enum LQDialogOptions{ EXIT_LQ, PUSH_BACK_LQ, PUSH_FRONT_LQ, POP_BACK_LQ, POP_FRONT_LQ, INSERT_POS_LQ, DELETE_POS_LQ};

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
	/**
	* @brief initDialog
	// Rule 120. Nobody likes you.
	*/
	void initDialog();
	// Rule 120.2. Except Pedobear
	/**
	* @brief qDialog Diealog fkt
	* @param q MyQueue<Person>*
	*/
	void qDialog(MyQueue<Person>* q);
	/**
	 * @brief ListenQueue Init
	 */
	void initListDialog();
	/**
	 * @brief ListenQueue Dialog
	 */
	void qDialog(ListenQueue<Person>* q);
	/**
	 * @brieft ListenQueue Dialog
	 */
	void startLQDialog(ListenQueue<Person>* q);

	/**
	 * @brief ListenQueue Auswahlauswertung
	 */
	void chooseLQOption(ListenQueue<Person>* q, int choice);
	/**
	* @brief outputOptions Dialog legende
	*/
	void outputOptions();
	/**
	* @brief fileExists Pruefung auf existierende datei(wird nicht verwendet ist deko)
	*/
	bool fileExists(string fileName);
	/**
	* @brief lesePerson Einlesefkt fuer personen obj
	* @returns new Person(nachname, vorname);
	*/
	Person* lesePerson();
	/**
	* @brief clearInput clears cin buffer
	*/
	void clearInput();
	/**
	* @brief readIntegerInput read in int
	*/
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
