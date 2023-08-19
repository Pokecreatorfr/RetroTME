#include "pch.h"
#include "Image_Manager.h"

Image_Manager::Image_Manager(void)
{
}

Image_Manager::~Image_Manager(void)
{
}

void Image_Manager::load_images()
{
	this->image_names.clear();

	// read line by line the image_c.h file
	std::ifstream file(this->image_path);

	std::string line;
	std::string name;
	bool is_image = false;
	while (std::getline(file, line))
	{
		if (is_image == false && line.find("const image_ressource") != std::string::npos )
		{
			is_image = true;
			name = line.substr(line.find("image_ressource") + 16, line.find("=") - 17 - line.find("image_ressource"));
		}
		else if (is_image == true && line.find("};") != std::string::npos)
		{
			is_image = false;
			image_names.push_back(name);
		}
	}

	file.close();
}

void Image_Manager::save_image()
{
	std::string h_file;
	h_file += "#pragma once\n";
	h_file += "#include <iostream>\n";
	h_file += "#include <vector>\n";
	h_file += "\n";
	h_file += "\n";
	h_file += "struct image_ressource\n";
	h_file += "{\n";
	h_file += "\t const int width;\n";
	h_file += "\t const int height;\n";
	h_file += "\t const const uint32_t pixels[];\n";
	h_file += "};\n";
	h_file += "\n";

	std::ifstream file(this->image_path);
	std::string line;
	std::string name;
	int width;
	int height;
	std::vector<uint32_t> pixels;

	std::vector<ImageC> images;

	bool is_image = false;
	int step = 0;
	// read the file line by line and parse it to get the image data . Example :
	//const image_ressource te = {
	//	194,
	//	259,
	//	{ 4278123775, 4278123775, ... 4294967295, 4294967295}
	//};
	while (std::getline(file, line))
	{
		if (is_image == false && line.find("const image_ressource") != std::string::npos)
		{
			is_image = true;
			name = line.substr(line.find("image_ressource") + 16, line.find("=") -17 - line.find("image_ressource"));
			step == 0;
		}
		else if (is_image == true && step == 0)
		{
			width = std::stoi(line.substr(line.find("\t") + 1, line.find(",") - line.find("\t") - 1));
			step++;
		}
		else if (is_image == true && step == 1)
		{
			height = std::stoi(line.substr(line.find("\t") + 1, line.find(",") - line.find("\t") - 1));
			step++;
		}
		else if (is_image == true && step == 2)
		{
			// line to char
			char* cstr = new char[line.length() + 1];
			strcpy_s(cstr, line.length() + 1, line.substr(line.find("{") + 1, line.find("}") - line.find("{") - 1).c_str());

			// split the char

			char* token = strtok(cstr, ",");
			std::vector<std::string> token_processed;
			while (token != NULL)
			{
				token_processed.push_back(token);

				// delete the space 
				while (token_processed[token_processed.size() - 1].find(" ") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find(" "), 1, "");
				}
				// delete the \t
				while (token_processed[token_processed.size() - 1].find("\t") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("\t"), 1, "");
				}
				// delete the \n
				while (token_processed[token_processed.size() - 1].find("\n") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("\n"), 1, "");
				}
				// delete the { and }
				while (token_processed[token_processed.size() - 1].find("{") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("{"), 1, "");
				}
				while (token_processed[token_processed.size() - 1].find("}") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("}"), 1, "");
				}
				pixels.push_back(std::stoll(token_processed[token_processed.size() - 1]));
				token = strtok(NULL, ",");
			}


			step++;
		}
		else if (is_image == true && step == 3)
		{
			is_image = false;
			step = 0;
			images.push_back(ImageC(name, width, height, pixels));
			pixels.clear();
		}
	}
	file.close();

	// if this->image name are in image_names add them to the images vector
	for (int i = 0; i < this->image_names.size(); i++)
	{
		if (this->image->name == this->image_names[i])
		{
			images.push_back(*this->image);
		}
	}

	// if an image name is in images and not in this->image_names remove it from images
	for (int i = 0; i < images.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < this->image_names.size(); j++)
		{
			if (images[i].name == this->image_names[j])
			{
				found = true;
			}
		}
		if (found == false)
		{
			images.erase(images.begin() + i);
		}
	}

	// write the h file
	for (int i = 0; i < images.size(); i++)
	{
		h_file += "const image_ressource " + images[i].name + " = {\n";
		h_file += "\t" + std::to_string(images[i].width) + ",\n";
		h_file += "\t" + std::to_string(images[i].height) + ",\n";
		h_file += "\t{";
		for (int j = 0; j < images[i].pixels.size(); j++)
		{
			h_file += std::to_string(images[i].pixels[j]);
			if (j != images[i].pixels.size() - 1)
			{
				h_file += ", ";
			}
		}
		h_file += "}\n";
		h_file += "};\n";
		h_file += "\n";
	}

	std::ofstream h_file_out(this->image_path);
	h_file_out << h_file;
	h_file_out.close();
	load_images();
}

void Image_Manager::set_image_path(std::string name)
{
	this->image_path = name;
	load_images();
}

void Image_Manager::load_image(std::string name)
{
	delete this->image;
	this->image = nullptr;
	std::ifstream file(this->image_path);
	std::string line;
	std::string namee;
	int width;
	int height;
	std::vector<uint32_t> pixels;
	bool is_image = false;
	int step = 0;

	while (std::getline(file, line))
	{
		if (is_image == false && line.find("const image_ressource") != std::string::npos)
		{
			namee = line.substr(line.find("image_ressource") + 16, line.find("=") - 17 - line.find("image_ressource"));
			step == 0;
			if (name == namee)
			{
				is_image = true;
			}
		}
		else if (is_image == true && step == 0 && name == namee)
		{
			width = std::stoi(line.substr(line.find("\t") + 1, line.find(",") - line.find("\t") - 1));
			step++;
		}
		else if (is_image == true && step == 1)
		{
			height = std::stoi(line.substr(line.find("\t") + 1, line.find(",") - line.find("\t") - 1));
			step++;
		}
		else if (is_image == true && step == 2)
		{
			// line to char
			char* cstr = new char[line.length() + 1];
			strcpy_s(cstr, line.length() + 1, line.substr(line.find("{") + 1, line.find("}") - line.find("{") - 1).c_str());

			// split the char

			char* token = strtok(cstr, ",");
			std::vector<std::string> token_processed;
			while (token != NULL)
			{
				token_processed.push_back(token);

				// delete the space 
				while (token_processed[token_processed.size() - 1].find(" ") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find(" "), 1, "");
				}
				// delete the \t
				while (token_processed[token_processed.size() - 1].find("\t") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("\t"), 1, "");
				}
				// delete the \n
				while (token_processed[token_processed.size() - 1].find("\n") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("\n"), 1, "");
				}
				// delete the { and }
				while (token_processed[token_processed.size() - 1].find("{") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("{"), 1, "");
				}
				while (token_processed[token_processed.size() - 1].find("}") != std::string::npos)
				{
					token_processed[token_processed.size() - 1].replace(token_processed[token_processed.size() - 1].find("}"), 1, "");
				}
				pixels.push_back(std::stoll(token_processed[token_processed.size() - 1]));
				token = strtok(NULL, ",");
			}


			step++;
		}
		else if (is_image == true && step == 3)
		{
			this->image = new ImageC(name, width, height, pixels);
			is_image = false;
			return;
		}
	}
}

void Image_Manager::create_image(System::Drawing::Bitmap^ bmp, std::string name)
{
	// Convert bmp to this->image ( image as array of pixels )

	// Get the width and height of the bitmap
	int width = bmp->Width;
	int height = bmp->Height;

	std::vector<uint32_t> pixels;
	uint32_t pix = 0;
	for (int i = 0; i < width * height; i++)
	{
		System::Drawing::Color pixel = bmp->GetPixel(i % width, i / width);
		pix = pixel.ToArgb();
		// conver ARGB to RGBA
		pix = ((pix & 0xFF000000) >> 24) | ((pix & 0x00FFFFFF) << 8);
		pixels.push_back(pix);
	}
	if (this->image != nullptr)
	{
		delete this->image;
	}
	this->image = new ImageC(name, width, height, pixels);
	this->image_names.push_back(name);
	this->save_image();

	// delete this->image
	delete this->image;
	this->image = nullptr;
}

void Image_Manager::update_image(System::Drawing::Bitmap^ bmp, std::string name)
{
	this->delete_image(name);
	this->create_image(bmp, name);

}

void Image_Manager::delete_image(std::string name)
{
	this->image_names.erase(std::remove(this->image_names.begin(), this->image_names.end(), name), this->image_names.end());
	this->save_image();
}

std::vector<std::string> Image_Manager::get_image_names()
{
	return image_names;
}

System::Drawing::Bitmap^ Image_Manager::get_bitmap(std::string name)
{
	this->load_image(name);
	System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(this->image->width, this->image->height);
	System::Drawing::Color pixel;
	uint32_t pix = 0;
	for (int i = 0; i < this->image->width * this->image->height; i++)
	{
		// conver RGBA to ARGB
		pix = ((this->image->pixels[i] & 0x000000FF) << 24) | ((this->image->pixels[i] & 0xFFFFFF00) >> 8);
		pixel = System::Drawing::Color::FromArgb(pix);
		bmp->SetPixel(i % this->image->width, i / this->image->width, pixel);
	}
	return bmp;
}
