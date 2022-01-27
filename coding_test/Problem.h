#pragma once
#include "ProblemFile.h"

class Problem
{
protected:
	ProblemFile *file;
public:
	Problem();
	virtual ~Problem() = 0;
	virtual void Solve() = 0;
};

class ProgrammersProblem : public Problem
{
public:
	ProgrammersProblem();
};