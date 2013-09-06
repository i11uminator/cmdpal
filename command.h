#ifndef COMMAND
#define COMMAND

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

class Command
{
    public:
	Command();
	Command(int id);
	Command(int id, std::string name);
	Command(int id, std::string name, std::string description);
	void SetId(int id);
	int GetId();
	void SetName(std::string name);
	std::string GetName();
	void SetTags(std::vector<std::string> vs);
	void SetTags(std::string tag);
	std::vector<std::string>& GetTags();
	std::string GetDescription();
	void SetDescription(std::string s);
	bool VectorContains(std::vector<std::string>& vs, std::string s);
	std::string ToLower(std::string s);
	std::string PrintToStorage();
	std::string Print();
    private:
	int id;
	std::string name;
	std::string description;
	std::vector<std::string> tags;
};

#endif//COMMAND
