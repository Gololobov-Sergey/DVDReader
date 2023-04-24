#pragma once
#include <iostream>
#include "DVD_Disk.h"

using namespace std;


class IReader abstract
{
public:
	virtual ~IReader() {}
	virtual void open(DVD_Disk* disk = nullptr) = 0;
	virtual bool write(string data) = 0;
	virtual string read() = 0;
};

