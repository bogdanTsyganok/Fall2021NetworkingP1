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
#include <vector>

class cBuffer
{
	//Properties
	int mReadIndex = 0;
	int mWriteIndex = 0;
	std::vector<uint8_t> mBuffer;

public:
	//Constructors and destructors
	cBuffer(std::size_t size);

	//Methods
	uint8_t* GetBuffer();

	size_t GetSize();

	//Ints size = 32
	void WriteIntBE(std::size_t index, int32_t value);
	void WriteIntBE(int32_t value);

	int32_t ReadIntBE(std::size_t index);
	int32_t ReadIntBE();

	//Shorts size = 16
	void WriteShortBE(std::size_t index, int16_t value);
	void WriteShortBE(int16_t value);

	int16_t ReadShortBE(std::size_t index);
	int16_t ReadShortBE();

	//Strings size = 8
	void WriteStringBE(std::size_t index, std::string value);
	void WriteStringBE(std::string value);

	std::string ReadStringBE(std::size_t index, int32_t stringSize);
	std::string ReadStringBE(int32_t stringSize);

};