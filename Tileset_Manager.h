#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Tileset
{
	Tileset(std::string tileset_name, std::string image_pointer, std::vector<int> tile_properties)
	{
		this->tileset_name = tileset_name;
		this->image_pointer = image_pointer;
		this->tile_properties = tile_properties;
	}
	std::string tileset_name;
	std::string image_pointer;
	std::vector<int> tile_properties;
};

class Tileset_Manager
{
	public:
		Tileset_Manager(void);
		~Tileset_Manager(void);
		void load_tileset();
		void save_tileset();
		void set_tileset_path(std::string path);
	private:
		std::vector<Tileset> tilesets;
		std::string tileset_path;
};

