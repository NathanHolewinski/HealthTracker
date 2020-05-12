#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class Date {
private:
	string month;
	int day;
public:
	Date() {}
	Date(string m, int d) {
		month = m;
		day = d;
	}
	string getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
};

int main() {

	double weight;
	string month;
	int day;
	string fileName;
	char cont;

	fileName = "Weight.txt";
	ofstream outFile(fileName.c_str(), ios::app);
	if (!outFile) {
		cout << "Could not open file." << endl;
		exit(1);
	}
	do {
		cout << "Enter Month: ";
		cin >> month;
		cout << "Enter Day: ";
		cin >> day;
		Date date(month, day);
		cout << "Enter Weight: ";
		cin >> weight;
		outFile << date.getMonth() << " " << date.getDay() << " : " << weight << endl;
		cout << "Enter another weight? (y/n): ";
		cin >> cont;
	} while (cont == 'y');
	outFile.close();

	return 0;
}