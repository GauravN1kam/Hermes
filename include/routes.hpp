#pragma once

#include <iostream>
#include <map>
#include <string>

void add_route(std::string path);



void add_route(std::string path, std::string (*ptr)());
