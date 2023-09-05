#pragma once

#include <windows.h>
#include <iostream>
#include <fstream>
#include <ios>

enum MouseButton
{
	Left = 0,
	Right = 1
};

struct Keybind
{
	unsigned mod{};
	unsigned key{};
};

struct Settings
{
	// Mouse settings
	MouseButton mouseButton{ MouseButton::Left };
	unsigned mouse_frequency{ 1 };
	Keybind mouseKeybind{ MOD_CONTROL | MOD_ALT | MOD_NOREPEAT , 0x51 }; // ALT + Q

	// Keyboard settings
	Keybind keyboardButton{ 0, 0x45 }; // E
	unsigned keyboard_frequency{ 1 };
	Keybind keyboardKeybind{ MOD_CONTROL | MOD_ALT | MOD_NOREPEAT , 0x53 }; // ALT + S

	char const* filepath{ "settings.dat" };
	Settings();
	~Settings();
};
