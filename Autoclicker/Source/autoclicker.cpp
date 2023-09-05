#include "autoclicker.h"

void AutoClicker::Enable()
{
	if (_enabled)
	{
		return;
	}
	_enabled = true;
	_autoClicker = std::thread(
		[this]( unsigned const& frequency, bool const& enabled)
		{
			while (enabled)
			{
				Click();
				SleepFor(Frequency(frequency));
			}
		},
		std::cref(_frequency), std::cref(_enabled));
}

void AutoClicker::Disable()
{
	if (not _enabled)
	{
		return;
	}
	_enabled = false;
	_autoClicker.join();
}

bool AutoClicker::IsEnabled() const
{
	return _enabled;
}

unsigned AutoClicker::GetFrequency() const
{
	return _frequency;
}

void AutoClicker::SetFrequency(unsigned frequency)
{
	_frequency = frequency;
}
