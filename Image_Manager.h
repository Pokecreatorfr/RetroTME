#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>


class Image_Manager
{
	public:
		Image_Manager();
		~Image_Manager(void);
		void set_image_path(std::string path);
		void refresh_image_names();
		std::vector<std::string> get_image_list();
		std::string get_image_path();
	private:
		std::string image_path;
		std::vector<std::string> image_names;
};

