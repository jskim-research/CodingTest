#include "Problem.h"

Problem::Problem(): file(nullptr)
{}

Problem::~Problem()
{
	delete file;
}

ProgrammersProblem::ProgrammersProblem()
{
	file = new ProgrammersFile();
}
