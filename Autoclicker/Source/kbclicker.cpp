#include "kbclicker.h"

Keybind KbClicker::GetKbButton() const
{
	return _keybind;
}

void KbClicker::SetKbButton(Keybind keybind)
{
	_keybind = keybind;
}

void KbClicker::Click()
{
	INPUT inputs[2];
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = _keybind.key;

	inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = _keybind.key;
	inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

	unsigned uSent{ SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT)) };
	if (not uSent)
	{
		std::cerr << "Missed a click: 0x" << std::hex << HRESULT_FROM_WIN32(GetLastError()) << std::dec << '\n';
	}
}
