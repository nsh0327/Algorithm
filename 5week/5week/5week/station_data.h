#pragma once

#ifndef STATION_DATA_H
#define STATION_DATA_H

#include <string>
#include <vector>
#include <map> 
#include <utility>

using namespace std;

vector<string> get_all_station_names();

vector<pair<string, string>> get_line_connections();

#endif 