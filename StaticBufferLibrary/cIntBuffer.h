/*
* Author:		Jarrid Steeper 0883583, Bogdan Tsyganok 0886354
* Class:		INFO6016 Network Programming
* Teacher:		Lukas Gustafson
* Project:		Project01
* Due Date:		Oct 22
* Filename:		cBuffer.h
* Purpose:
*/

#pragma once
#include <string>
#include "cBuffer.h"

class cIntBuffer : public cBuffer
{
private:
	std::vector<int> mBuffer;

public:
	//Constructors and destructors
	cIntBuffer(std::size_t size);

	//Methods
	void writeIntLE(std::size_t index, int value);
	void writeIntLE(int value);

	int readIntLE(std::size_t index);
	int readIntLE();
};