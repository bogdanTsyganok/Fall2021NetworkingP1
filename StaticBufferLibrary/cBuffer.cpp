#include "cBuffer.h"

cBuffer::cBuffer(std::size_t size)
{
	mBuffer.resize(size);
}

uint8_t* cBuffer::GetBuffer()
{
	return mBuffer.data();
}

size_t cBuffer::GetSize()
{
	return mBuffer.size();
}

//Ints
void cBuffer::WriteIntBE(std::size_t index, int32_t value)
{
	mBuffer[index] = value >> 24;
	mBuffer[index + 1] = value >> 16;
	mBuffer[index + 2] = value >> 8;
	mBuffer[index + 3] = value;
}

void cBuffer::WriteIntBE(int32_t value)
{
	mBuffer[mWriteIndex] = value >> 24;
	mBuffer[mWriteIndex + 1] = value >> 16;
	mBuffer[mWriteIndex + 2] = value >> 8;
	mBuffer[mWriteIndex + 3] = value;
	mWriteIndex += 4;
}

int32_t cBuffer::ReadIntBE(std::size_t index)
{
	uint32_t value = 0;
	value |= mBuffer[index] << 24;
	value |= mBuffer[index + 1] << 16;
	value |= mBuffer[index + 2] << 8;
	value |= mBuffer[index + 3];
	return value;
}

int32_t cBuffer::ReadIntBE()
{
	uint32_t value = 0;
	value |= mBuffer[mReadIndex] << 24;
	value |= mBuffer[mReadIndex + 1] << 16;
	value |= mBuffer[mReadIndex + 2] << 8;
	value |= mBuffer[mReadIndex + 3];
	mReadIndex += 4;
	return value;
}

//Floats
void cBuffer::WriteShortBE(std::size_t index, int16_t value)
{
	mBuffer[index] = value >> 8;
	mBuffer[index + 1] = value;
}

void cBuffer::WriteShortBE(int16_t value)
{
	mBuffer[mWriteIndex] = value >> 8;
	mBuffer[mWriteIndex + 1] = value;
	mWriteIndex += 2;
}

int16_t cBuffer::ReadShortBE(std::size_t index)
{
	int16_t value = 0;
	value |= mBuffer[index] << 8;
	value |= mBuffer[index + 1];
	return value;
}

int16_t cBuffer::ReadShortBE()
{
	int16_t value = 0;
	value |= mBuffer[mReadIndex] << 8;
	value |= mBuffer[mReadIndex + 1];
	mReadIndex += 2;
	return value;
}

//Strings
void cBuffer::WriteStringBE(std::size_t index, std::string value)
{
	for (char c : value)
	{
		mBuffer[index] = c;
		index++;
	}
}

void cBuffer::WriteStringBE(std::string value)
{
	for (char c : value)
	{
		mBuffer[mWriteIndex] = c;
		mWriteIndex++;
	}
}

std::string cBuffer::ReadStringBE(std::size_t index, int32_t stringSize)
{
	char value;
	std::string outPut;
	for (int i = 0; i < stringSize; i++)
	{
		value |= mBuffer[index++];
		outPut += value;
	}

	return outPut;
}

std::string cBuffer::ReadStringBE(int32_t stringSize)
{
	char value;
	std::string outPut;
	for (int i = 0; i < stringSize; i++)
	{
		value |= mBuffer[mReadIndex++];
		outPut += value;
	}

	return outPut;
}
