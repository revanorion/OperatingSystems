#include "cpuML.h"
#include "cpuSJF.h"
#include "cpuFCFS.h"

int main() {

	ML a;
	SJF b;
	FCFS c;
	cout << "Execution Order: MLFQ -> SJF -> FCFS\n";
	cout << "To Start the program press space then follow prompts\n";
	system("pause");
	cout << endl<<"MLFQ start\n";
	a.start();
	cout << endl << "MLFQ end\n";
	system("pause");
	cout << "SJF start\n";
	b.start();
	cout << endl << "SJF end\n";
	system("pause");
	cout << endl << "FCFS start\n";
	c.start();
	cout << endl << "FCFS end\n";
	system("pause");
	return 0;
} 
