#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
using namespace std;
#include "Date.h"
#include "TripSpecifics.h"
#include "Odometer.h"
#include "TripHandling.h"
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK ,__FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif // _DEBUG

//throw exception
#define N 30
void menu();

class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};

void menu() {
	cout << "Welcome" << endl;

}
int main()
{
	try {
		auto_ptr<TripHandling> trip;
		
		/*km.setKm();
		cout << km.getKm() << endl;*/
	}
	catch (Exception e) {
		cout << "Exeption happened: " << e.what() << endl;
		cout << "Managed" << endl;
	}
	_CrtDumpMemoryLeaks;
	//system("Pause");
	return EXIT_SUCCESS;
}