#include "settings.h"

Settings::Settings()
{
	std::ifstream ifs(filepath, std::ios::binary);
	if (ifs.bad())
	{
		std::cerr << "Couldn't open file, sticking to defaults...\n";
		return;
	}

	// Read mouse settings
	ifs.read((char*)&this->mouseButton, sizeof(int));
	ifs.read((char*)&this->mouse_frequency, sizeof(unsigned));
	ifs.read((char*)&this->mouseKeybind.mod, sizeof(unsigned));
	ifs.read((char*)&this->mouseKeybind.key, sizeof(unsigned));
	// Read keyboard settings
	ifs.read((char*)&this->keyboardButton.mod, sizeof(unsigned));
	ifs.read((char*)&this->keyboardButton.key, sizeof(unsigned));
	ifs.read((char*)&this->keyboard_frequency, sizeof(unsigned));
	ifs.read((char*)&this->keyboardKeybind.mod, sizeof(unsigned));
	ifs.read((char*)&this->keyboardKeybind.key, sizeof(unsigned));

	ifs.close();
	if (ifs.bad())
	{
		std::cerr << "Couldn't read file.\n";
	}
}

Settings::~Settings()
{
	std::ofstream ofs(filepath, std::ios::binary);
	if (ofs.bad())
	{
		std::cerr << "Couldn't open file, sticking to defaults...\n";
		return;
	}

	// Write mouse settings
	ofs.write((char*)&this->mouseButton, sizeof(int));
	ofs.write((char*)&this->mouse_frequency, sizeof(unsigned));
	ofs.write((char*)&this->mouseKeybind.mod, sizeof(unsigned));
	ofs.write((char*)&this->mouseKeybind.key, sizeof(unsigned));
	// Write keyboard settings
	ofs.write((char*)&this->keyboardButton.mod, sizeof(unsigned));
	ofs.write((char*)&this->keyboardButton.key, sizeof(unsigned));
	ofs.write((char*)&this->keyboard_frequency, sizeof(unsigned));
	ofs.write((char*)&this->keyboardKeybind.mod, sizeof(unsigned));
	ofs.write((char*)&this->keyboardKeybind.key, sizeof(unsigned));

	ofs.close();
	if (ofs.bad())
	{
		std::cerr << "Couldn't write file.\n";
	}
}
