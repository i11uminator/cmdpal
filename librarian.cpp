#include "librarian.h"

Librarian::Librarian()
{
    this->LoadCommands();
    Librarian::topid = this->GetHighestId();   
}

Librarian::Librarian(std::string filepath)
{
    this->filepath = filepath;
    this->LoadCommands();
    Librarian::topid = this->GetHighestId();
}

Command& Librarian::GetCommand(int id)
{
    Command hlpr;
    for (int i = 0; i < this->commands.size(); ++i)
    {
	if (id == this->commands[i].GetId())
	{
	    return &this->commands[i];
	}
    }
    return NULL;
}

Command& Librarian::GetCommand(std::string name)
{
    Command hlpr;
    for (int i = 0; i < this->commands.size(); ++i)
    {
	if (hlpr.ToLower(name) == hlpr.ToLower(this->commands[i].GetName()))
	{
	    return &this->commands[i];
	}
    }
    return NULL;
}

bool Librarian::AddCommand(Command command)
{
    int id = this->Contains(command.getName());
    if (id > 0)
    {
	this->AddDetails(command);	
    }
    else
    {
	command.setId(Librarian::topid + 1);
	this->commands.push_back(command);	
    }
}

void Librarian::AddDetails(Command command)
{
    Command& c = this->GetCommand(command.GetName());
    
    std::stringstream ss(c.GetDescription());
    ss << " " << command.GetDescription(); 
    c.SetDescription(ss.str());

    std::vector<std::string> tags;
    command.GetTags(tags);

    c.SetTags(tags);
}

bool Librarian::AddCommand(std::vector<std::string> tokns)
{
    Command c;
    c.SetId(atoi(tokns[0]));
    c.SetName(tokns[1]);
    for (int i = 2; i < tokns.size(); ++i)
    {
	if(tokns[i][0] == 'd')	
	{
	    c.SetDescription(tokns[i].substring(1, tokns[i].size() - 1);
	}
	else if (tokns[i][0] == 't')
	{
	    c.SetTags(tokns[i].substring(1, tokns[i].size() - 1);
	}
    }
    return this->AddCommand(c);
}

int Librarian::Contains(std::string name)
{
    Command hlpr;
    for (int i = 0; i < this->commands.size(); ++i)
    {
	if (hlpr.ToLower(name) == hlpr.ToLower(this->commands[i].GetName()))
	    return this->commands[i].GetId(); 
    }
    return -1;
}

int Librarian::GetHighestId()
{
    int highest = 0;
    for (int i = 0; i < this->commands.size(); ++i)
    {
	if (this->commands[i].GetId() > highest)
	{
	    highest = this->commands[i].GetId();
	}
    }
    return highest;
}

Command Librarian::CreateCommandFromString(std::string strcmd)
{
    std::vector<std::string> tokns;
    this->SplitToVector(strcmd, '|', tokns); 
    Command c;
    c.SetId(atoi(tokns[0]));
    c.SetName(tokns[1]);
    for (int i = 1; i < tokns.size(); ++i)
    {
	if(tokns[i][0] == 'd')	
	{
	    c.SetDescription(tokns[i].substring(1, tokns[i].size() - 1);
	}
	else if (tokns[i][0] == 't')
	{
	    c.SetTags(tokns[i].substring(1, tokns[i].size() - 1);
	}
    }
    return c;
}

void Librarian::LoadCommands()
{
    std::vector<std::string> filelines;
    this->ImportStrings(filelines);
    for (int i = 0; i < filelines.size(); ++i)
    {
	this->commands.push_back(this->CreateCommandFromString(filelines[i]));
    }
}

void Librarian::WriteCommandToFile(Command command)
{
    std::ofstream o;
    o.open(this->filepath, std::ios::app);
    o << command.printToStorage();
}

std::vector<std::string>& Librarian::SplitToVector(std::string s, const char c, std::vector<std::string>& vs)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, c))
    {
	if (item.empty() != 0)
		vs.push_back(item);
    }
    return vs;
}

void Librarian::ImportStrings(std::vector<std::string>& vs)
{
    if (this->filepath.empty() == 0)
    {
	this->filepath = "/home/brad/Documents/Commands/commands";
    }
    std::ifstream ifl(this->filepath);
    
    if (ifl.is_open())
    {
	std::copy
	    (
		std::istream_iterator<std::string>(ifl),
		std::istream_iterator<std::string>(),
		std::back_inserter(vs)
	    );
    }
}

void Librarian::PrintAll()
{
    for (int i = 0; i < this->commands.size(); ++i)
    {
	std::cout << this->commands.Print() << std::endl;
    }
}
