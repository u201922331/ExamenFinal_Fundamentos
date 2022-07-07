#pragma once

#ifndef _IO_MANAGER_
#define _IO_MANAGER_

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class IOManager {

public:
	static bool readFileToBuffer(string filePath,
		vector<unsigned char>& buffer);
};

#include "IOManager.inl"
#endif
