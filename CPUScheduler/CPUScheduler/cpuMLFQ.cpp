#include "cpuMLFQ.h"

void MLFQ::start()
{
	init();
	do {
		/*thread docpu(&MLFQ::do_CPU, this);
		thread doio(&MLFQ::do_IO, this);
		doio.join();
		docpu.join();*/
		if (!IO->empty())
			do_IO();
		do_CPU();
		
		
	} while (!queue1->empty() || !queue2->empty() || !fcfs->empty() || !IO->empty());

}

void MLFQ::init()
{
	shared_ptr<qnode> P1 = make_shared<qnode>(); //{ 18, 41, 16, 52, 19, 31, 14, 33, 17, 43, 19, 66, 14, 39, 17 }
	shared_ptr<qnode> P2 = make_shared<qnode>(); //{ 8, 32, 7, 42, 6, 27, 17, 41, 7, 33, 11, 43, 12, 32, 14 }
	shared_ptr<qnode> P3 = make_shared<qnode>(); //{ 6, 51, 5, 53, 6, 46, 9, 32, 11, 52, 4, 61, 8 }
	shared_ptr<qnode> P4 = make_shared<qnode>(); //{ 25, 35, 19, 41, 21, 45, 18, 51, 12, 61, 24, 54, 23, 61, 21 }
	shared_ptr<qnode> P5 = make_shared<qnode>(); //{ 15, 61, 16, 52, 15, 71, 13, 41, 15, 62, 14, 31, 14, 41, 13, 32, 15 }
	shared_ptr<qnode> P6 = make_shared<qnode>(); //{ 6, 25, 5, 31, 6, 32, 5, 41, 4, 81, 8, 39, 11, 42, 5 }
	shared_ptr<qnode> P7 = make_shared<qnode>(); //{ 16, 38, 17, 41, 15, 29, 14, 26, 9, 32, 5, 34, 8, 26, 6, 39, 5 }
	shared_ptr<qnode> P8 = make_shared<qnode>(); //{5, 52, 4, 42, 6, 31, 7, 21, 4, 43, 5, 31, 7, 32, 6, 32, 7, 41, 4}
	shared_ptr<qnode> P9 = make_shared<qnode>(); //{ 11, 37, 12, 41, 6, 41, 4, 48, 6, 41, 5, 29, 4, 26, 5, 31, 3 }

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
	
	queue1->Enqueue(P1);
	queue1->Enqueue(P2);
	queue1->Enqueue(P3);
	queue1->Enqueue(P4);
	queue1->Enqueue(P5);
	queue1->Enqueue(P6);
	queue1->Enqueue(P7);
	queue1->Enqueue(P8);
	queue1->Enqueue(P9);
}

void MLFQ::print()
{
	cout << ".................................................." << endl << endl;
	cout << "Ready Queue:\tProcess\t\tBurst\t\tQueue" << endl;
	shared_ptr<qnode> newNode = queue1->get_front();
	while (newNode != 0)
	{
		cout << "\t\t" << newNode->name << "\t\t" << newNode->CPU_burst.back()<< "\t\t" <<newNode->qu << endl;
		newNode = newNode->next;
	}
	newNode = queue2->get_front();
	while (newNode != 0)
	{
		cout << "\t\t" << newNode->name << "\t\t" << newNode->CPU_burst.back() << "\t\t" << newNode->qu << endl;
		newNode = newNode->next;
	}
	newNode = fcfs->get_front();
	while (newNode != 0)
	{
		cout << "\t\t" << newNode->name << "\t\t" << newNode->CPU_burst.back() << "\t\t" << newNode->qu << endl;
		newNode = newNode->next;
	}
	cout << ".................................................." << endl<<endl;
	cout << "Now in IO:\tProcess\t\tRemaining I/O time\n" << IO << endl;
}

void MLFQ::CPU_time_quantom_7()
{
	shared_ptr<qnode> node = queue1->get_front();
	if (node->time_on == 0)
	{
	cout << "Current time: " << counter << "\nCurrently Running: " << node->name << endl;
	print();
	}
	node->CPU_burst.back()--;
	node->time_on++;
	if (node->CPU_burst.back() == 0)
	{
		node->CPU_burst.pop_back();
		node->time_on = 0;
		node->qu = "";
		queue1->Dequeue();
		IO->Enqueue(node);
	}
	else if (node->time_on == 7)
	{
		node->priority++;
		node->qu = "Q2";
		queue1->Dequeue();
		queue2->Enqueue(node);
		node->time_on = 0;
	}

}

void MLFQ::CPU_fcfs()
{
	shared_ptr<qnode> node = fcfs->get_front();
	if (node->time_on == 0)
	{
		cout << "Current time: " << counter << "\nCurrently Running: " << node->name << endl;
		print();
	}
	node->CPU_burst.back()--;
	node->time_on++;
	if (node->CPU_burst.back() == 0)
	{
		node->CPU_burst.pop_back();
		node->time_on = 0;
		node->qu = "";
		fcfs->Dequeue();
		IO->Enqueue(node);
	}
}

void MLFQ::do_IO()
{
	shared_ptr<qnode> nodeParent = 0;
	shared_ptr<qnode> node = IO->get_front();
	
	while (node != 0)
	{
		
		node->IO_time.back()--;
		if (node->IO_time.back() == 0)
		{
			IO->remove_node(node);
			switch (node->priority)
			{
			case 1:
				node->qu = "Q1";
				queue1->Enqueue(node);
				break;
			case 2:
				node->qu = "Q2";
				queue2->Enqueue(node);
				break;
			case 3:
				node->qu = "FCFS";
				fcfs->Enqueue(node);
				break;
			default:
				cout << "error\n";
				break;
			}
			node->IO_time.pop_back();
		}
		node = node->next;
	}
}

void MLFQ::do_CPU()
{
	if (!queue1->empty())
	{
		CPU_time_quantom_7();
	}
	else if (!queue2->empty())
	{
		CPU_time_quantom_14();
	}
	else if (!fcfs->empty())
	{
		CPU_fcfs();
	}
	else
		cout << "CPU Idle";
	counter++;
}

void MLFQ::CPU_time_quantom_14()
{
	shared_ptr<qnode> node = queue2->get_front();
	node->CPU_burst.back()--;
	node->time_on++;
	if (node->CPU_burst.back() == 0)
	{
		node->CPU_burst.pop_back();
		node->time_on = 0;
		queue2->Dequeue();
		IO->Enqueue(node);
	}
	else if (node->time_on > 14)
	{
		node->priority++;
		queue2->Dequeue();
		fcfs->Enqueue(node);
		node->time_on = 0;
	}

}
