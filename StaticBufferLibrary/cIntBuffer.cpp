#include "cIntBuffer.h"
cIntBuffer::cIntBuffer(std::size_t size)
{
	mBuffer.resize(size);
}

void cIntBuffer::writeIntLE(std::size_t index, int value)
{
	mBuffer[index] = value;
	mBuffer[index + 1] = value >> 8;
	mBuffer[index + 2] = value >> 16;
	mBuffer[index + 3] = value >> 24;
}

void cIntBuffer::writeIntLE(int value)
{
	mBuffer[mWriteIndex] = value;
	mBuffer[mWriteIndex + 1] = value >> 8;
	mBuffer[mWriteIndex + 2] = value >> 16;
	mBuffer[mWriteIndex + 3] = value >> 24;
	mWriteIndex += 4;
}

int cIntBuffer::readIntLE(std::size_t index)
{
	int value = 0;
	value |= mBuffer[index];
	value |= mBuffer[index + 1] << 8;
	value |= mBuffer[index + 2] << 16;
	value |= mBuffer[index + 3] << 24;
	return value;
}

int cIntBuffer::readIntLE()
{
	uint32_t value = 0;
	value |= mBuffer[mReadIndex];
	value |= mBuffer[mReadIndex + 1] << 8;
	value |= mBuffer[mReadIndex + 2] << 16;
	value |= mBuffer[mReadIndex + 3] << 24;
	mReadIndex += 4;
	return value;
}
