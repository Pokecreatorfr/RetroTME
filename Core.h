#pragma once
#include <iostream>
#include "Config_Manager.h"
#include "Project_Manager.h"
#include "Image_Manager.h"

struct Core
{
	Config_Manager config_manager;
	Project_Manager project_manager;
	std::string openned_project_path;
	
};

