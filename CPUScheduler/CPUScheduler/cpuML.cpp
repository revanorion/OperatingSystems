#include "cpuML.h"

void ML::start()
{
	init();
	do {
		/*thread docpu(&MLFQ::do_CPU, this);
		thread doio(&MLFQ::do_IO, this);
		doio.join();
		docpu.join();*/
		do_CPU();
		if (!IO->empty())
			do_IO();
		if (CPUnode != 0 && CPUnode->CPU_burst.back() <= 0)
		{
			CPUnode->CPU_burst.pop_back();
			if (!CPUnode->CPU_burst.empty())
			{
				CPUnode->time_on = 0;
				CPUnode->qu = "";
				IO->insert(CPUnode);
			}
			CPUnode = 0;
		}


	} while (!queue->empty() || !queue->empty() || !queue->empty() || !IO->empty());

}

void ML::init()
{
	shared_ptr<listnode> P1 = make_shared<listnode>(); //{ 18, 41, 16, 52, 19, 31, 14, 33, 17, 43, 19, 66, 14, 39, 17 }
	shared_ptr<listnode> P2 = make_shared<listnode>(); //{ 8, 32, 7, 42, 6, 27, 17, 41, 7, 33, 11, 43, 12, 32, 14 }
	shared_ptr<listnode> P3 = make_shared<listnode>(); //{ 6, 51, 5, 53, 6, 46, 9, 32, 11, 52, 4, 61, 8 }
	shared_ptr<listnode> P4 = make_shared<listnode>(); //{ 25, 35, 19, 41, 21, 45, 18, 51, 12, 61, 24, 54, 23, 61, 21 }
	shared_ptr<listnode> P5 = make_shared<listnode>(); //{ 15, 61, 16, 52, 15, 71, 13, 41, 15, 62, 14, 31, 14, 41, 13, 32, 15 }
	shared_ptr<listnode> P6 = make_shared<listnode>(); //{ 6, 25, 5, 31, 6, 32, 5, 41, 4, 81, 8, 39, 11, 42, 5 }
	shared_ptr<listnode> P7 = make_shared<listnode>(); //{ 16, 38, 17, 41, 15, 29, 14, 26, 9, 32, 5, 34, 8, 26, 6, 39, 5 }
	shared_ptr<listnode> P8 = make_shared<listnode>(); //{5, 52, 4, 42, 6, 31, 7, 21, 4, 43, 5, 31, 7, 32, 6, 32, 7, 41, 4}
	shared_ptr<listnode> P9 = make_shared<listnode>(); //{ 11, 37, 12, 41, 6, 41, 4, 48, 6, 41, 5, 29, 4, 26, 5, 31, 3 }

	P1->CPU_burst = { 17, 14, 19, 17, 14, 19, 16, 18 };
	P1->IO_time = { 39, 66, 43, 33, 31, 52, 41 };
	P2->CPU_burst = { 14, 12, 11, 7, 17, 6, 7, 8 };
	P2->IO_time = { 32, 43, 41, 27, 42, 32 };
	P3->CPU_burst = { 8, 4, 11, 9, 6, 5, 6 };
	P3->IO_time = { 61,52,32,46,53,51 };
	P4->CPU_burst = { 21,23,24,12,18,21,19,25 };
	P4->IO_time = { 61, 54, 61, 51, 45, 41, 35 };
	P5->CPU_burst = { 15,13,14,14,15,13,15,16,15 };
	P5->IO_time = { 32, 41, 31, 62, 41, 71, 52, 61 };
	P6->CPU_burst = { 5, 11, 8, 4, 5, 6, 5, 6 };
	P6->IO_time = { 42, 39, 81, 41, 32, 31, 25 };
	P7->CPU_burst = { 5, 6, 8, 5, 9, 14, 15, 17, 16 };
	P7->IO_time = { 39, 26, 34, 32, 26, 29, 41, 38 };
	P8->CPU_burst = { 4, 7, 6, 7, 5, 4, 7, 6, 4, 5 };
	P8->IO_time = { 41, 32, 32, 31, 43, 21, 31, 42, 52 };
	P9->CPU_burst = { 3, 5, 4, 5, 6, 4, 6, 12, 11 };
	P9->IO_time = { 31, 26, 29, 41, 48, 41, 41, 37 };

	P1->name = "P1";
	P2->name = "P2";
	P3->name = "P3";
	P4->name = "P4";
	P5->name = "P5";
	P6->name = "P6";
	P7->name = "P7";
	P8->name = "P8";
	P9->name = "P9";

	queue->insert(P1);
	queue->insert(P2);
	queue->insert(P3);
	queue->insert(P4);
	queue->insert(P5);
	queue->insert(P6);
	queue->insert(P7);
	queue->insert(P8);
	queue->insert(P9);
	shared_ptr<listnode> newNode = queue->get_front();
	while (newNode != 0)
	{
		cout << "\t\t" << newNode->name << "\t\t" << newNode->CPU_burst.back() << "\t\t" << newNode->qu << endl;
		newNode = newNode->next;
	}
}

void ML::print()
{
	if (counter == 456)
		cout << endl;
	cout << ".................................................." << endl << endl;
	cout << "Ready Queue:\tProcess\t\tBurst\t\tQueue" << endl;
	shared_ptr<listnode> newNode = queue->get_front();
	while (newNode != 0)
	{
		cout << "\t\t" << newNode->name << "\t\t" << newNode->CPU_burst.back() << "\t\t" << newNode->qu << endl;
		newNode = newNode->next;
	}
	cout << ".................................................." << endl << endl;
	cout << "Now in IO:\tProcess\t\tRemaining I/O time\n" << IO;
	cout << endl;
}

void ML::CPU_time_quantom_7()
{
	if (CPUnode == 0 || CPUnode->qu != "Q1") {
		CPU_prempt();
		//CPUnode = queue->get_front();
		CPUnode=queue->remove_front();
		cout << "Current time: " << counter << "\nCurrently Running: " << CPUnode->name << endl;
		print();
	}
	CPUnode->CPU_burst.back()--;
	CPUnode->time_on++;
	if (CPUnode->CPU_burst.back()!=0 && CPUnode->time_on == 7)
	{
		CPUnode->priority++;
		CPUnode->qu = "Q2";
		queue->insert(CPUnode);
		CPUnode->time_on = 0;
		CPUnode = 0;
	}
}

void ML::CPU_fcfs()
{
	if (CPUnode == 0 || CPUnode->qu != "Q3") {
		CPU_prempt();
		CPUnode = queue->get_front();
		queue->remove_front();
		cout << "Current time: " << counter << "\nCurrently Running: " << CPUnode->name << endl;
		print();
	}
	CPUnode->CPU_burst.back()--;
	CPUnode->time_on++;
}

void ML::CPU_prempt()
{
	if (CPUnode != 0) {
		if (CPUnode->CPU_burst.back() <= 0)
		{
			CPUnode->CPU_burst.pop_back();
			CPUnode->time_on = 0;
			CPUnode->qu = "";
			IO->insert(CPUnode);
			CPUnode = 0;
		}

		else if (CPUnode->qu == "Q1")
		{
			CPUnode->time_on = 0;
			queue->insert(CPUnode);
			CPUnode = 0;
		}
		else if (CPUnode->qu == "Q2")
		{
			CPUnode->time_on = 0;
			queue->insert(CPUnode);
			CPUnode = 0;
		}
		else {
			CPUnode->time_on = 0;
			queue->insert(CPUnode);
			CPUnode = 0;
		}
	}
}

void ML::do_IO()
{
	shared_ptr<listnode> node = IO->get_front();
	shared_ptr<listnode> nodeNext;
	while (node != 0)
	{
		if(!node->IO_time.empty())
			node->IO_time.back()--;
		if (node->IO_time.empty() || node->IO_time.back() == 0)
		{
			nodeNext = node->next;
			IO->remove_node(node);
			node->next = 0;
			switch (node->priority)
			{
			case 1:
				node->qu = "Q1";
				queue->insert(node);
				break;
			case 2:
				node->qu = "Q2";
				queue->insert(node);
				break;
			case 3:
				node->qu = "Q3";
				queue->insert(node);
				break;
			default:
				cout << "error\n";
				break;
			}
			if (!node->IO_time.empty())
				node->IO_time.pop_back();
			node = nodeNext;
		}
		else
			node = node->next;
	}
}

void ML::do_CPU()
{
	if ((!queue->empty() && queue->get_front()->qu == "Q1")||(CPUnode != 0 && CPUnode->qu == "Q1"))
	{
		CPU_time_quantom_7();
	}
	else if ((!queue->empty() && queue->get_front()->qu == "Q2")||(CPUnode != 0 && CPUnode->qu == "Q2"))
	{
		CPU_time_quantom_14();
	}
	else if ((!queue->empty() && queue->get_front()->qu == "Q3")||(CPUnode != 0 && CPUnode->qu == "Q3"))
	{
		CPU_fcfs();
	}
	else
		cout << "CPU Idle";
	counter++;
}

void ML::CPU_time_quantom_14()
{

	if (CPUnode == 0 || CPUnode->qu != "Q2")
	{
		CPU_prempt();
		CPUnode = queue->get_front();
		queue->remove_front();
		cout << "Current time: " << counter << "\nCurrently Running: " << CPUnode->name << endl;
		print();
	}
	CPUnode->CPU_burst.back()--;
	CPUnode->time_on++;
	if (CPUnode->CPU_burst.back() != 0 && CPUnode->time_on == 14)
	{
		CPUnode->priority++;
		CPUnode->qu = "Q3";
		queue->insert(CPUnode);
		CPUnode->time_on = 0;
		CPUnode = 0;
	}

}
