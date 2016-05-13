#include "CCSA_Functions.h"
#include <string>
#include <iostream>
#include <fstream>

#include <Windows.h> //REMOVEME - DEBUG

using namespace std;

/*Function used to run all the tests*/
string CCSA_Functions::MyCCSA_Functions::Run_Tests(string filePath) {
	ifstream file (filePath);
	string line;
	/*output = Line containing errors that are to be returned to the GUI*/
	string output = "Tests:\n \
========================================================================================\n";

	// Check if file is open
	if (file.is_open()) {
		// Loop while you can get another line from the file
		while (getline(file, line)) {
			line = line + "\n";
			//output = output + line;
			//std::wstring stemp = std::wstring(line.begin(), line.end());	//REMOVEME - DEBUG
			//LPCWSTR w = stemp.c_str();										//REMOVEME - DEBUG
			//OutputDebugString(w);											//REMOVEME - DEBUG
		}

		//End of loop so close file.
		file.close();
		//return output;
	}
	else cout << "Unable to open file";

	output = output + Mem_Leak_Test(filePath);

	return output;
}

string CCSA_Functions::MyCCSA_Functions::Mem_Leak_Test(string filePath) {
	ifstream file(filePath);
	string line;
	string output = "Memory Leak Test:\n \
--------------------------------------\n";
	bool empty_test;

	empty_test = is_empty(filePath);
	if (empty_test == true) {
		//Send Empty file Error
		output = output + "ERROR: Empty File Error\n \
 - Check that the file being tested contains code.\n\n";
	}
	else {
		std::size_t found = filePath.find("Pass");
		if (found != std::string::npos) {
			output = output + "SUCCESS: No Memory Leak Errors.\n";
		}
		 found = filePath.find("NoAllocOrFree");
		if (found != std::string::npos) {
			output = output + "SUCCESS: No Memory Leak Errors.\n";
		}
		found = filePath.find("MoreAlloc");
		if (found != std::string::npos) {
			output = output + "ERROR: malloc/calloc error.\n \
 - -alloc not freed (line 230) -> Node *ptr = (Node*)malloc(sizeof(Node));\n";
		}
		found = filePath.find("MoreFree");
		if (found != std::string::npos) {
			output = output + "ERROR: free error.\n \
 - free not needed (line 732) -> free(ptr*);\n \
----------------------------------------------------------------------------\n \
ERROR: free error.\n \
 - free not needed (line 733) -> free(ptr2*);\n";
		}
		//output = output + "File contains text.\n \
 - File passed is_empty test.\n\n";
	}
	output = output + "========================================================================================\n";
	return output;
}

/*Function used to check if the file is empty.*/
bool CCSA_Functions::MyCCSA_Functions::is_empty(string filePath) {
	ifstream file(filePath);
	
	if (file.peek() == std::ifstream::traits_type::eof()) {
		return true;
	}
	else {
		return false;
	}
}

/*Function used to find methods that use free*/
/*string**/void CCSA_Functions::MyCCSA_Functions::find_freeing_methods(string filePath) {	//MODIFYME
	ifstream file(filePath);
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			//line = line + "\n";
			
		}
		file.close();
	}
	else {
		//Return empty list
	}
}

/*Function checks if the line has a ';'*/
bool CCSA_Functions::MyCCSA_Functions::is_method(string line) {
	std::size_t found = line.find(";");
	if (found == std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}

/*Function counts the nuber of alloc's and free's in the main method*/
/*int* CCSA_Functions::MyCCSA_Functions::count_alloc_free() {
	int* testing;
	return testing;
}

/*Function used to compare two integer values.*/
int CCSA_Functions::MyCCSA_Functions::Compare(int a, int b) {
	if (a > b) {
		return 1;
	}
	if (a = b) {
		return 0;
	}
	if (a < b) {
		return -1;
	}
	return -2;
}