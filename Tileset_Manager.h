#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Anim
{
	int id; // id of the animation
	int anim_speed; // number of frames per step
	std::vector<int> anim_frames; // frames of the animation
};;

struct Tileset
{
	Tileset(std::string tileset_name, std::string image_pointer, std::vector<int> tile_properties , std::vector<int> tile_properties2)
	{
		this->tileset_name = tileset_name;
		this->image_pointer = image_pointer;
		this->tile_properties = tile_properties;
		this->tile_properties2 = tile_properties2;
	}
	std::string tileset_name;
	std::string image_pointer;
	std::vector<int> tile_properties;
	std::vector<int> tile_properties2;
	std::vector<int> tile_const;
	std::vector<int> tile_const2;
	std::vector<Anim> anims;
};

class Tileset_Manager
{
	public:
		Tileset_Manager(void);
		~Tileset_Manager(void);
		void set_tileset_path(std::string path);
		void refresh_tilesets();
		std::vector<std::string> get_tileset_list();
		std::string get_tileset_path();
		void load_tileset(std::string tileset_name);
		Tileset* get_tileset();
		void save_tileset();
		void new_tileset(std::string tileset_name);
	private:
		std::string tileset_path;
		std::vector<std::string> tilesets_names;
		Tileset* tileset;
};

