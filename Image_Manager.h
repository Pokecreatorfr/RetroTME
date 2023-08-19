#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



struct ImageC
{
	ImageC(std::string name,  int width, int height, std::vector<uint32_t> pixels)
	{
		this->name = name;
		this->width = width;
		this->height = height;
		this->pixels = pixels;
	}
	std::string name;
	int width;
	int height;
	std::vector<uint32_t> pixels ; // RGBA
};

class Image_Manager
{
	public:
		Image_Manager();
		~Image_Manager(void);
		void load_images();
		void save_image();
		void set_image_path(std::string path);
		void load_image(std::string name);
		void create_image(System::Drawing::Bitmap^ bmp, std::string name);
		void update_image(System::Drawing::Bitmap^ bmp, std::string name);
		void delete_image(std::string name);
		std::vector<std::string> get_image_names();
		System::Drawing::Bitmap^ get_bitmap(std::string name);
	private:
		std::string image_path;
		ImageC* image = nullptr;
		std::vector<std::string> image_names;
};

