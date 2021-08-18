#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// function prototypes
void printMenu();
void listItemCounts();
void getItemCount();
void createHistogram();

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("pythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"pythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"pythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void main()
{

	int userInput;

	do {

		// print menu options
		printMenu();

		try {
			cin >> userInput;

			if (userInput > 4 || userInput < 1) {
				throw runtime_error("Invalid choice.\nChoice must be between 1 and 4 inclusive");
			}

			switch (userInput) {
			case 1:
				listItemCounts();
				break;
			case 2:
				getItemCount();
				break;
			case 3:
				createHistogram();
				break;
			case 4:
				system("cls");
				cout << "Goodbye!" << endl;
				break;
			}
		}
		catch (runtime_error& excpt) {
			system("cls");
			cout << excpt.what() << endl;
			cout << "Try again" << endl;
			system("pause");
			system("cls");
		}

	} while (userInput != 4);

}

void printMenu() {
	cout << "1. List all items and number of time they were purchased." << endl;
	cout << "2. Get the number of times a particular item was purchased in a given day" << endl;
	cout << "3. Produce a test-based histogram for all items" << endl;
	cout << "4. Quit" << endl;
}

void listItemCounts() {

	string functionArgument = "listItemCounts";

	CallProcedure(functionArgument);

	system("pause");
	system("cls");

}

void getItemCount() {
	
	string item;
	int itemCount;
	string functionName="getItemCount";

	// This program will assume that there are no items made up of numbers.
	// All items are expected to be alphanumeric
	try {
		cout << "Enter item name: ";
		cin >> item;

		for (int x = 0; x < item.size(); x++) {
			if (isdigit(item.at(x))) {
				throw runtime_error("no numbers allowed in input");
			}
		}


		itemCount = callIntFunc(functionName, item);

		cout << itemCount << endl;
		system("pause");
		system("cls");
	}
	catch (runtime_error& excpt) {
		system("cls");
		cout << "ERROR: " << excpt.what() << endl;
		system("pause");
		system("cls");
	}

}

void createHistogram() {

	string functionArgument = "createHistogram";

	CallProcedure(functionArgument);

	ifstream inFS;
	inFS.open("./Release/frequency.dat");

	if (!inFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
		return;
	}

	string name;
	int frequency;

	while (!inFS.eof()) {
		inFS >> name;
		inFS >> frequency;

		cout << setw(15) << name << " ";

		for (int x = 0; x < frequency; x++) {
			cout << "*";
		}

		cout << endl;
	}

	inFS.close();

	cout << endl;
	
	system("pause");
	system("cls");

	
	
}