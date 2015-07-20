#include "Startdialog.h"
#include <math.h>
const string Startdialog::SEPERATOR = "---------------------";
const string Startdialog::CHOSE_WISELY = "-> ";
const string Startdialog::OPTION_EXIT = "(0) EXIT";
const string Startdialog::OPTION_QUEUE_DIALOG = "(1) QUEUE DIALOG";
const string Startdialog::OPTION_LISTEN_DIALOG = "(2) LISTEN DIALOG";
const string Startdialog::OPTION_LISTEN_QUEUE_DIALOG = " (3) LISTEN QUEUE (experimental)";
const char* Startdialog::STD_ERROR = "gooby y u do dis";
const int Startdialog::STD_ANSWER_VALUE = -1;
const int Startdialog::ZERO_VALUE = 0;
const int Startdialog::INPUT_ONE = 1;
const int Startdialog::HIGH_VALUE = 1000;

using namespace std;
Startdialog::Startdialog(){}
Startdialog::~Startdialog(){}

void Startdialog::runStartDialog(){
	int answer = STD_ANSWER_VALUE;
	ListenDialog listenDialog;
	QueueDialog queueDialog;
	do{
		cout << SEPERATOR << endl << OPTION_QUEUE_DIALOG << endl << OPTION_LISTEN_DIALOG << endl
			<< OPTION_LISTEN_QUEUE_DIALOG << endl << OPTION_EXIT << endl << SEPERATOR << endl << CHOSE_WISELY;
		answer = readIntegerInput();
		if (answer > 3){
			answer = STD_ANSWER_VALUE;
		}
		switch (answer){
		case EXIT:
			break;
		case QUEUE_DIALOG:
			queueDialog.initDialog();
			break;
		case LISTEN_DIALOG:
			listenDialog.initLanguage();
			break;
		case LIST_QUEUE:
			queueDialog.initListDialog();
			break;
		default:
			cout << STD_ERROR << endl;
			break;
		}
	} while (answer != 0);
}
/**
* @brief readIntegerInput read in int
*/
int Startdialog::readIntegerInput() {
	double number = readDoubleInput();
	if (!(fmod(number, INPUT_ONE) == ZERO_VALUE)) {
		number = STD_ANSWER_VALUE;
	}
	return (int)number;
}
/**
* @brief readIntegerInput read in double
*/
double Startdialog::readDoubleInput() {
	double number;
	if (cin >> number) {
	}
	else {
		number = STD_ANSWER_VALUE;
	}
	clearInput();
	return number;
}
/**
* @brief clearInput Clear Cin
*/
void Startdialog::clearInput() {
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}
