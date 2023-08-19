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
	project_file << "image_path = '\\data\\image_c.h';\n";
	project_file.close();
	this->project_path = path;

	// create the data folder with the world.h, map.h, tileset.h and image_c.h files
	std::string data_path = path + "\\data";
	_wmkdir(std::wstring(data_path.begin(), data_path.end()).c_str());
	std::string world_path = data_path + "\\world.h";
	std::string map_path = data_path + "\\map.h";
	std::string tileset_path = data_path + "\\tileset.h";
	std::string image_path = data_path + "\\image_c.h";
	std::ofstream world_file;
	world_file.open(world_path);
	world_file.close();
	std::ofstream map_file;
	map_file.open(map_path);
	map_file.close();
	std::ofstream tileset_file;
	tileset_file.open(tileset_path);
	tileset_file.close();
	std::ofstream image_file;
	image_file.open(image_path);
	image_file.close();
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
	this->tileset_manager.set_tileset_header_path(path + tileset_header_path);
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
