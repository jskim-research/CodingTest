#include "Problem.h"

using namespace std;

Problem::Problem(FileFormat _file_format): file(nullptr), file_format(_file_format)
{}

Problem::~Problem()
{
	delete file;
}

void Problem::Prepare()
{
	cout << "Read from " << file_format.GetFileName() << endl;
	file->ReadFile(file_format.GetFileName(), file_format.GetTypes());
}

void Problem::Score(const std::vector<std::string>& output, const std::vector<std::string>& right_answer)
{
	for (int i = 0; i < output.size(); i++)
		cout << output[i] << ' ';
	cout << "// ";
	for (int i = 0; i < right_answer.size(); i++)
		cout << right_answer[i] << ' ';
	cout << endl;
}

void Problem::Run()
{
	vector<vector<string>> inputs;
	vector<string> output;
	vector<string> right_answer;
	int num_problems = 0;

	Prepare();
	inputs = file->GetArrays();
	num_problems = file->GetNumOfProblems();

	for (int test_case = 0; test_case < inputs.size(); test_case += inputs.size() / num_problems)
	{
		vector<vector<string>> input;
		for (int i = test_case; i < test_case + inputs.size() / num_problems; i++)
		{
			input.push_back(inputs[i]);
		}
		right_answer = inputs[test_case + inputs.size() / num_problems - 1];
		output = Solve(input);
		Score(output, right_answer);
	}

}

ProgrammersProblem::ProgrammersProblem(FileFormat _file_format): Problem(_file_format)
{
	file = new ProgrammersFile();
}
