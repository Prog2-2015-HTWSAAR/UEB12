#ifndef STARTDIALOG_H_
#define STARTDIALOG_H_
#include "ListenDialog.h"
#include "QueueDialog.h"
class Startdialog
{
public:
	enum startDial{ EXIT, QUEUE_DIALOG, LISTEN_DIALOG, LIST_QUEUE };
	static const string SEPERATOR;
	static const string CHOSE_WISELY;
	static const string OPTION_EXIT ;
	static const string OPTION_QUEUE_DIALOG;
	static const string OPTION_LISTEN_DIALOG;
	static const string OPTION_LISTEN_QUEUE_DIALOG;
	static const char* STD_ERROR;
	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_ONE;
	static const int HIGH_VALUE;
	void runStartDialog();
	/**
	* @brief readIntegerInput read in int
	*/
	int readIntegerInput();
	/**
	* @brief readIntegerInput read in double
	*/
	double readDoubleInput();
	/**
	* @brief clearInput Clear Cin
	*/
	void clearInput();
	Startdialog();
	~Startdialog();
};

#endif
