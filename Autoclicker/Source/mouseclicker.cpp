#include "mouseclicker.h"

MouseButton MouseClicker::GetMouseButton() const
{
	return _mouseButton;
}

void MouseClicker::SetMouseButton(MouseButton mouseButton)
{
	_mouseButton = mouseButton;
}

void MouseClicker::Click()
{
	unsigned buttonDown, buttonUp;
	if (_mouseButton == MouseButton::Left)
	{
		buttonDown = MOUSEEVENTF_LEFTDOWN;
		buttonUp = MOUSEEVENTF_LEFTUP;
	}
	else if (_mouseButton == MouseButton::Right)
	{
		buttonDown = MOUSEEVENTF_RIGHTDOWN;
		buttonUp = MOUSEEVENTF_RIGHTUP;
	}
	else
	{
		return;
	}

	INPUT inputs[2];
	ZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_MOUSE;
	inputs[0].mi.dwFlags = buttonDown;

	inputs[1].type = INPUT_MOUSE;
	inputs[1].mi.dwFlags = buttonUp;

	unsigned uSent{ SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT)) };
	if (not uSent)
	{
		std::cerr << "Missed a click: 0x" << std::hex << HRESULT_FROM_WIN32(GetLastError()) << std::dec << '\n';
	}
}
