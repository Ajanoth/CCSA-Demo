// CCSA_Functions.h
#include <string>

using namespace std;

namespace CCSA_Functions {
	class MyCCSA_Functions {
	public:
		/*Function used to run all the tests*/
		static string Run_Tests(string filePath);

		static string Mem_Leak_Test(string filePath);

		static bool is_empty(string filePath);

		/*Function used to find methods that use free*/
		static /*string**/void find_freeing_methods(string filePath);	//MODIFYME

		/*Function checks if the line has a ';'*/
		static bool is_method(string line);

		/*Function counts the nuber of alloc's and free's in the main method*/
		/*int**/ static int* count_alloc_free(string filePath);

		/*Function used to compare two integer values.*/
		static int Compare(int a, int b);

		static string get_Results(int result);
	};
}