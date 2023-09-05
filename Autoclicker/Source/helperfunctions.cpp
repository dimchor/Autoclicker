#include "helperfunctions.h"

unsigned Frequency(unsigned frequency)
{
	return 1000 / frequency;
}

void SleepFor(unsigned ms)
{
	DWORD s{ timeGetTime() };
	DWORD elapsedTime{};
	while (elapsedTime < ms)
	{
		elapsedTime = timeGetTime() - s;
	}
}
