#include "pch.h"
#include "Project_Manager.h"

Project_Manager::Project_Manager(void)
{
}

Project_Manager::~Project_Manager(void)
{
}

void Project_Manager::create_project(std::string path)
{
	// create the project.ini file
	std::ofstream project_file;
	project_file.open(path + "\\project.ini");
	project_file << "tile_size = 16;\n";
	project_file << "world_path = '\\data\\world.h';\n";
	project_file << "map_path = '\\data\\map.h';\n";
	project_file << "tileset_path = '\\data\\tileset';\n";
	project_file << "image_path = '\\graphics';\n";
	project_file.close();
	this->project_path = path;
}

void Project_Manager::load_project(std::string path)
{
	// read the project.ini file
	std::ifstream project_file;
	project_file.open(path + "\\project.ini");
	std::string line;
	while (std::getline(project_file, line))
	{
		if (line.find("tile_size") != std::string::npos)
		{
			tile_size = std::stoi(line.substr(line.find("=") + 1, line.find_last_of(";") - line.find("=") - 1));
		}
		else if (line.find("world_path") != std::string::npos)
		{
			world_path = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
		else if (line.find("map_path") != std::string::npos)
		{
			map_path = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
		else if (line.find("tileset_path") != std::string::npos)
		{
			tileset_path = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
		else if (line.find("tileset_header_path") != std::string::npos)
		{
			tileset_header_path = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
		else if (line.find("image_path") != std::string::npos)
		{
			image_path = line.substr(line.find("'") + 1, line.find_last_of("'") - line.find("'") - 1);
		}
	}
	project_file.close();
	this->project_path = path;
	this->map_manager.set_map_path(path + map_path);
	this->tileset_manager.set_tileset_path(path + tileset_path);
	this->image_manager.set_image_path(path + image_path);

}

void Project_Manager::save_project(std::string path)
{
	// save the project.ini file
	std::ofstream project_file;
	project_file.open(path + "\\project.ini");
	project_file << "tile_size = " << tile_size << ";\n";
	project_file.close();
}

Map_Manager* Project_Manager::get_map_manager()
{
	return &map_manager;
}

Tileset_Manager* Project_Manager::get_tileset_manager()
{
	return &tileset_manager;
}

Image_Manager* Project_Manager::get_image_manager()
{
	return &image_manager;
}
