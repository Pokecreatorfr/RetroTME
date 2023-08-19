#include "pch.h"
#include "Config_Manager.h"

Config_Manager::Config_Manager(void)
{
}

Config_Manager::~Config_Manager(void)
{
}

void Config_Manager::create_config()
{
	// create the config file
	std::ofstream config_file;
	config_file.open("config.ini");
	config_file << "last_oppened_path = '';\n";
	config_file << "last_oppened_path1 = '';\n";
	config_file << "last_oppened_path2 = '';\n";
	config_file.close();
}

void Config_Manager::load_config()
{
	// check if the config file exists
	if (!std::ifstream("config.ini"))
	{
		create_config();
	}
	// read the config file
	std::ifstream config_file;
	config_file.open("config.ini");
	std::string line;
	while (std::getline(config_file, line))
	{
		if (line.find("last_oppened_path1") != std::string::npos)
		{
			last_oppened_path1 = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
		else if (line.find("last_oppened_path2") != std::string::npos)
		{
			last_oppened_path2 = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
		else if (line.rfind("last_oppened_path", 0) != std::string::npos )
		{
			last_oppened_path = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
	}	
	config_file.close();
}

void Config_Manager::save_config()
{
	// save the config file
	std::ofstream config_file;
	config_file.open("config.ini");
	config_file << "last_oppened_path = '" << last_oppened_path << "';\n";
	config_file << "last_oppened_path1 = '" << last_oppened_path1 << "';\n";
	config_file << "last_oppened_path2 = '" << last_oppened_path2 << "';\n";
	config_file.close();
}

void Config_Manager::set_last_oppened_path(std::string path)
{
	last_oppened_path = path;
}

void Config_Manager::set_last_oppened_path1(std::string path)
{
	last_oppened_path1 = path;
}

void Config_Manager::set_last_oppened_path2(std::string path)
{
	last_oppened_path2 = path;
}

std::string Config_Manager::get_last_oppened_path()
{
	return last_oppened_path;
}

std::string Config_Manager::get_last_oppened_path1()
{
	return last_oppened_path1;
}

std::string Config_Manager::get_last_oppened_path2()
{
	return last_oppened_path2;
}
