#pragma once

#define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <windows.h>
#include <synchapi.h>

#include "autoclicker.h"
#include "settings.h"

class KbClicker: public AutoClicker
{
public:
	KbClicker() = default;

	Keybind GetKbButton() const;
	void SetKbButton(Keybind);

private:
	Keybind _keybind{ 0, 'E' };

	void Click() override;
};
