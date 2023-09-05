#pragma once

#define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <windows.h>
#include <synchapi.h>

#include "autoclicker.h"
#include "settings.h"

class MouseClicker: public AutoClicker
{
public:
	MouseClicker() = default;

	MouseButton GetMouseButton() const;
	void SetMouseButton(MouseButton);

private:
	MouseButton _mouseButton{ MouseButton::Left };

	void Click() override;
};
