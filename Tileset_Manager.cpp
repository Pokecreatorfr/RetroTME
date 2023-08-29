#include "pch.h"
#include "Tileset_Manager.h"

Tileset_Manager::Tileset_Manager(void)
{
}

Tileset_Manager::~Tileset_Manager(void)
{
}

void Tileset_Manager::load_tileset()
{
}

void Tileset_Manager::save_tileset()
{
	std::ofstream tileset_file;
	tileset_file.open(this->tileset_path);

	// header
	tileset_file << "#pragma once" << std::endl;
	tileset_file << "#include <iostream>" << std::endl;
	tileset_file << "#include <string>" << std::endl;
	tileset_file << "#include <vector>" << std::endl;

	// tileset struct 

	tileset_file << "struct Tileset" << std::endl;
	tileset_file << "{" << std::endl;
	tileset_file << "\tTileset(std::string tileset_name, std::string image_pointer, std::vector<int> tile_properties)" << std::endl;
}

void Tileset_Manager::set_tileset_path(std::string path)
{
	this->tileset_path = path;
}
