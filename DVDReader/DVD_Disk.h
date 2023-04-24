#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class DVD_Disk
{
	string data;
	int space;
	bool broken;

	string path;

public:
	DVD_Disk(string path, int space) : path(path), space(space)
	{
		ifstream in(path);
		getline(in, data);
		in.close();
		broken = (space < data.length()) ? false : !(rand() % 5);
	}

	int getFreeSpace()
	{
		return this->space - this->data.length();
	}

	bool isBroken()
	{
		return this->broken;
	}

	string getData()
	{
		return this->data;
	}

	void setData(string data)
	{
		this->data = data;

		ofstream out(path);
		out << data << endl;
		out.close();
	}
};

