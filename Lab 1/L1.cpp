#include "iostream"
#include "string"
#include <fstream>

using namespace std;

bool isEqual(char func) {
	char operations[] = { '+', '-', '*', '/' };
	for (char op : operations) {
		if (func == op) {
			return true;
		}
	}
	return false;
}


int main(void) {
	setlocale(LC_ALL, "Russian");
	string type1, type2;
	char func;
	cout << "Input types: ";
	cin >> type1;
	cin >> type2;
	cout << "Input operation: ";
	cin >> func;
	if (!isEqual(func))
		do
		{
			cout << "Incorrect operation. Try again:";
			cin >> func;
		} while (!isEqual(func));

	cout << "Result: " << type1 << ' ' << func << ' ' << type2 << endl;

	ofstream fout("func_1.cpp");
	fout << "#include <iostream>" << endl;
	fout << "int f(void) {" << endl;
	fout << type1 << " var1;" << endl;
	fout << type2 << " var2;" << endl;
	fout << "std::cout << \"Input var1 & var2:\";" << endl;
	fout << "std::cin >> var1 >> var2;" << endl;
	fout << "std::cout << var1 " << func << " var2 << std::endl; " << endl;
	fout << "return 0;" << endl;
	fout << "}" << endl;


	fout.close();

	ofstream fout1("smain.cpp");

	fout1 << "#include <iostream>" << endl;
	fout1 << "int f(void);" << endl;
	fout1 << "using namespace std;" << endl;
	fout1 << "int main(int argc, char *argv[]) {" << endl;
	fout1 << "int i = (argc > 1) ? atoi(argv[1]) : 0;" << endl;
	fout1 << "int c = 1;" << endl;
	fout1 << "while (i != 0) {" << endl;
	fout1 << "cout << c << ' ';" << endl;
	fout1 << "f();" << endl;
	fout1 << "cout << endl; i--; c++;" << endl;
	fout1 << "}" << endl;
	fout1 << "return 0;" << endl;
	fout1 << "}" << endl;

	fout1.close();

	return 0;
}
