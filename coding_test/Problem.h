#pragma once
#include "ProblemFile.h"
#include "FileFormat.h"

class Problem
{
protected:
	ProblemFile *file;
	FileFormat file_format;
public:
	Problem(FileFormat _file_format);
	virtual ~Problem() = 0;
	virtual std::vector<std::string> Solve(std::vector<std::vector<std::string>>& input) = 0;
	void Prepare();
	void Score(const std::vector<std::string>& output, const std::vector<std::string>& right_answer);
	void Run();
};

class ProgrammersProblem : public Problem
{
public:
	ProgrammersProblem(FileFormat _file_format);
};