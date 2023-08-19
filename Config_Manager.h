#pragma once
#include <iostream>
#include <fstream>
#include <string>


class Config_Manager
{
	public:
		Config_Manager(void);
		~Config_Manager(void);
		void create_config();
		void load_config();
		void save_config();
		void set_last_oppened_path(std::string path);
		void set_last_oppened_path1(std::string path);
		void set_last_oppened_path2(std::string path);
		std::string get_last_oppened_path();
		std::string get_last_oppened_path1();
		std::string get_last_oppened_path2();
	private:
		std::string last_oppened_path;
		std::string last_oppened_path1;
		std::string last_oppened_path2;

};

