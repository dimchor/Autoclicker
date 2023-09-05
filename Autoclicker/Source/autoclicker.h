#pragma once

#include <thread>

#include "helperfunctions.h"

class AutoClicker
{
public:
	void Enable();
	void Disable();

	bool IsEnabled() const;
	unsigned GetFrequency() const;
	void SetFrequency(unsigned);

	AutoClicker() = default;
	AutoClicker(AutoClicker&) = default;
	AutoClicker& operator=(AutoClicker&) = default;
	AutoClicker(AutoClicker&&) = default;
	AutoClicker& operator=(AutoClicker&&) = default;
	virtual ~AutoClicker() = default;
private:
	std::thread _autoClicker{};
	bool _enabled{ false };
	unsigned _frequency{ 1 };

	virtual void Click() = 0;
};
