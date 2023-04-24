// DVDReader.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DVDReader.h"

using namespace std;

int main()
{
	DVD_Disk* disk1 = new DVD_Disk("disk1.txt", 20);

	IReader* reader = new DVDReader();

	reader->open(disk1);

	reader->write("Hello C++ ");
	
	//reader->write("Hello C++ DVDReader DVD");


}

