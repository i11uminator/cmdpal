#ifndef LIBRARIAN
#define LIBRARIAN

#include "command.h"

class Librarian
{
    public:
	Librarian();
	Librarian(std::string filepath);
	bool AddCommand(Command command);
	bool AddCommand(std::vector<std::string> args);
	Command CreateCommandFromString(std::string strcmd);
	Command& GetCommand(int id);
	Command& GetCommand(std::string name);
	void LoadCommands();
	void ImportStrings(std::vector<std::string>& vs);
	std::vector<std::string>& SplitToVector(std::string s, const char c, std::vector<std::string>& vs);
	bool Contains(std::string name);
	void AddDetails(Command command);
	void WriteCommandToFile(Command command);
	void PrintAll();
    private:
	std::vector<Command> commands;
	static int topid; 
	std::string filepath;
	int GetHighestId();
};

#endif//LIBRARIAN
