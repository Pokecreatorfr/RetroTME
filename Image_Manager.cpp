#include "pch.h"
#include "Image_Manager.h"

Image_Manager::Image_Manager(void)
{
}

Image_Manager::~Image_Manager(void)
{
}

void Image_Manager::set_image_path(std::string path)
{
	image_path = path;
}

void Image_Manager::refresh_image_names()
{
	image_names.clear();
	for (auto & p : std::filesystem::directory_iterator(image_path))
	{
		if (p.path().extension() == ".png" || p.path().extension() == ".jpg" || p.path().extension() == ".jpeg" || p.path().extension() == ".bmp") {
			image_names.push_back(p.path().string());
		}
	}
}

std::vector<std::string> Image_Manager::get_image_list()
{
	refresh_image_names();
	return image_names;
}

std::string Image_Manager::get_image_path()
{
	return image_path;
}

