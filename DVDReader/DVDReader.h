#pragma once
#include <iostream>
#include "IReader.h"
#include "DVD_Disk.h"

using namespace std;


class DVDReader: public IReader
{
	DVD_Disk* disk;

public:
	DVDReader(DVD_Disk* disk = nullptr) : disk(disk)
	{

	}

	virtual void open(DVD_Disk* disk)
	{
		this->disk = disk;
	}

	virtual bool write(string data) override
	{
		if (disk != nullptr)
		{
			if (!disk->isBroken())
			{
				int freeSpace = disk->getFreeSpace();
				if (data.length() <= freeSpace)
				{
					disk->setData(data);

					string dataRead = disk->getData();

					if (data == dataRead)
					{
						cout << "Disk saved" << endl;
						return true;
					}
					else
					{
						cout << "Disk not verification" << endl;
						return false;
					}
				}
				else
				{
					cout << "No free space" << endl;
				}
			}
			else
			{
				cout << "Disk error" << endl;
			}
		}
		else
		{
			cout << "No disk" << endl;
		}
	}

	virtual string read() override
	{
		return "";
	}
};

