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

const std::string repo("/home/brad/Documents/Commands/commands");

void import(std::vector<std::string>& vs)
{
    std::ifstream ifl(repo);
    
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

int main(int argc, char** argv)
{
    Librarian libr("/home/brad/Documents/Commands/commands");
    std::vector<std::string> vs;
    for (int i = 1; i < argc; ++i)
    {
	vs.push_back(std::string(argv[i]));
    }
    libr.AddCommand(vs);
    libr.PrintAll();

    return 0;
}
