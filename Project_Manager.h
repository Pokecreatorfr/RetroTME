#pragma once
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string>

#include "Map_Manager.h"
#include "Tileset_Manager.h"
#include "Image_Manager.h"


class Project_Manager
{
	public:
		Project_Manager(void);
		~Project_Manager(void);
		void create_project(std::string path);
		void load_project(std::string path);
		void save_project(std::string path);
		Map_Manager* get_map_manager();
		Tileset_Manager* get_tileset_manager();
		Image_Manager* get_image_manager();
	private:
		int tile_size;
		std::string world_path;
		std::string map_path;
		std::string tileset_path;
		std::string tileset_header_path;
		std::string project_path;
		std::string image_path;
		Map_Manager map_manager;
		Tileset_Manager tileset_manager;
		Image_Manager image_manager;
};

