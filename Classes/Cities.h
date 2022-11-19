#pragma once
#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;
class Cities
{
	set<string> name_city;
public:
	Cities();
	~Cities();
	void add_city();
	void print_cities();
	void delete_city();
	set<string> GetCities();
};

