#include "RepByN.h"
#include "CommonHeaders.h"

using namespace std;

int Plus(const int& lhs, const int& rhs)
{
	return lhs + rhs;
}

int Minus(const int& lhs, const int& rhs)
{
	return lhs - rhs;
}

int Divide(const int& lhs, const int& rhs)
{
	if (rhs == 0) throw "0���� ���� �� �����ϴ�.";
	return lhs / rhs;
}

int Multiply(const int& lhs, const int& rhs)
{
	return lhs * rhs;
}


void RepN::PushAll(std::vector<int>& memo, const std::vector<int>& tmp)
{
	for (std::vector<int>::size_type i = 0; i < tmp.size(); i++)
		memo.push_back(tmp[i]);
}

int RepN::MakeNs(int N, int i)
{
	if (i <= 0) return 0;
	return N * pow(10, i - 1) + MakeNs(N, i - 1);
}


std::vector<int> RepN::calculate(const std::vector<int>& lhs, const std::vector<int>& rhs, int (*func)(const int&, const int&), int number, bool& found)
{
	std::vector<int> result;
	int tmp = 0;

	for (std::vector<int>::size_type i = 0; i < lhs.size(); i++)
	{
		for (std::vector<int>::size_type j = 0; j < rhs.size(); j++)
		{
			try {
				tmp = func(lhs[i], rhs[j]);
			}
			catch (...)
			{
				continue;
			}
			if (tmp == number)
				found = true;
			result.push_back(tmp);
		}
	}

	return result;
}


RepN::RepN(FileFormat file_format): ProgrammersProblem(file_format)
{
}

std::vector<std::string> RepN::Solve(std::vector<std::vector<std::string>>& input)
{
	std::vector<std::string> output;

	
	int answer = -1;
	int N = stoi(input[0][0]), number = stoi(input[1][0]);
	vector<vector<int>> memo;
	vector<int> tmp;
	bool bFound = false;

	for (int i = 1; i <= 7; i++)
	{
		vector<int> v;
		int n = MakeNs(N, i);
		if (n == number)
		{
			answer = i;
		}
		v.push_back(n);
		memo.push_back(v);
	}

	for (int i = 2; i <= 7; i++)
	{
		if (answer != -1) break;
		for (int j = 1; j < i; j++)
		{
			tmp = calculate(memo[j - 1], memo[i - j - 1], Plus, number, bFound);
			PushAll(memo[i - 1], tmp);
			tmp = calculate(memo[j - 1], memo[i - j - 1], Minus, number, bFound);
			PushAll(memo[i - 1], tmp);
			tmp = calculate(memo[j - 1], memo[i - j - 1], Divide, number, bFound);
			PushAll(memo[i - 1], tmp);
			tmp = calculate(memo[j - 1], memo[i - j - 1], Multiply, number, bFound);
			PushAll(memo[i - 1], tmp);
		}
		if (bFound)
		{
			answer = i;
			break;
		}
	}

	output.push_back(to_string(answer));
	
	return output;
}