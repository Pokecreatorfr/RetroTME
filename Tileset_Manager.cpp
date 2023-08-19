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
	// Open the tileset header file

}

void Tileset_Manager::save_tileset()
{
}

void Tileset_Manager::set_tileset_path(std::string path)
{
	this->tileset_path = path;
}

void Tileset_Manager::set_tileset_header_path(std::string path)
{
	this->tileset_header_path = path;
}
