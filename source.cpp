#include <iostream>
#include <vector>
#include <iterator>
#include <exception>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "librarian.h"

int main(int argc, char** argv)
{
	Librarian libr("/home/brad/Documents/Commands/commands");
	std::vector<std::string> vs;
	for (int i = 1; i < argc; ++i)
	{
		vs.push_back(std::string(argv[i]));
	}
	if (vs.size() > 0)
	{
		libr.AddCommand(vs);
		Command c = libr.GetCommand(Librarian::topid + 1);
		libr.WriteCommandToFile(c);
	}
	libr.PrintAll();

	return 0;
}
