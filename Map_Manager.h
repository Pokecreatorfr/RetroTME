#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Tileset_Manager.h"

struct Map
{
		Map(std::string map_name, std::string name, int height, int width, std::vector<std::vector<int>> tilemaps, std::vector<int> collision)
		{
			this->map_name = map_name;
			this->name = name;
			this->height = height;
			this->width = width;
			this->tilemaps = tilemaps;
			this->collision = collision;
		}
		std::string map_name;
		std::string name;
		int height;
		int width;
		std::vector<std::vector<int>> tilemaps;
		std::vector<int> collision;
		Tileset* tileset;
};

class Map_Manager
{
	public:
		Map_Manager(void);
		~Map_Manager(void);
		void set_map_path(std::string path);
		void save_maps();
		void load_maps();
	private:
		std::string map_path;
		std::vector<Map*> maps;
};


