#include "command.h"

Command::Command()
{}

Command::Command(int id)
    : id(id)
{
}

Command::Command(int id, std::string name)
    : id(id), name(name)
{
}

Command::Command(int id, std::string name, std::string description)
    : id(id), name(name), description(description)
{
}

void Command::SetId(int id)
{
    this->id = id;
}

int Command::GetId()
{
    return this->id;
}

std::string Command::PrintToStorage()
{
    std::stringstream ss;
    ss << this->id << "|" << this->name << "|" << "d" << this->description;
    for (int i = 0; i < this->tags.size(); ++i)
    {
	ss << "|" << "t" << this->tags[i];
    }
    return ss.str();
}

std::string Command::Print()
{
    std::stringstream ss;
    ss << "Id: " << this->id << " Name: " << this->name << " Description: " << this->description;
    ss << " Tags: \n";
    for (int i = 0; i < this->tags.size(); ++i)
    {
	ss << i + 1 << ": " << this->tags[i] << "\n";
    }
    return ss.str();
}

std::string Command::GetName()
{
    return this->name;
}

std::string Command::ToLower(std::string s)
{
    return std::transform(s.begin(), s.end(), s.begin(), ::tolower); 
}

bool Command::VectorContains(std::vector<std::string>& vs, std::string s)
{
    for (int i = 0; i < vs.size(); ++i)
    {
	if (toLower(vs[i]) == toLower(s))
	    return true;
    }
    return false;
}

void Command::SetTags(std::string tag)
{
    if (
	    std::find
		(
		    this->tags.begin(), 
		    this->tags.end(), 
		    std::transform(tag.begin(), tag.end(), tag.begin(), ::tolower)
		) 
		!= this->tags.end()
       )
    {
	this->tags.push_back(tag);
    }
}

void Command::SetTags(std::vector<std::string> vs)
{
    this->tags.insert(this->tags.end(), vs.begin(), vs.end());
    std::sort(this->tags.begin(), this->tags.end());
    this->tags.erase(std::unique(this->tags.begin(), this->tags.end()), this->tags.end());
}

void Command::SetDescription(std::string s)
{
    this->description = s;
}

std::string Command::GetDescription()
{
    return this->description;
}

std::vector<std::string>& Command::GetTags()
{
    return this->tags;
}
