#include "JewelShopping.h"
#include "CommonHeaders.h"
using namespace std;

template <class T>
void Print(const T& data)
{
	cout << data << ' ';
}


int JewelShopping::GetCatNum(const vector<string>& gems)
{
	set<string> s;

	for (int i = 0; i < gems.size(); i++)
		s.insert(gems[i]);

	return s.size();
}

JewelShopping::JewelShopping(FileFormat file_format): ProgrammersProblem(file_format)
{
}

std::vector<std::string> JewelShopping::Solve(std::vector<std::vector<std::string>>& input)
{
	std::vector<std::string> output;

	vector<string> gems = input[0];
	int start = 0, end = 0, min_start = 1, min_end = gems.size(), min_len = gems.size(), cat_num = GetCatNum(gems);
	set<string> s;
	map<string, int> m;

	while (start <= end && end <= gems.size())
	{
		if (s.size() == cat_num) // 조건 만족시 start++
		{
			if (end - start < min_len)
			{
				min_len = end - start;
				min_start = start + 1;
				min_end = end;
			}

			m[gems[start]]--;
			if (m[gems[start]] == 0)
				s.erase(gems[start]);
			start++;
		}
		else // 조건 불만족시 조건 만족시까지 end++
		{
			if (end >= gems.size()) break;
			if (m.find(gems[end]) == m.end())
				m[gems[end]] = 1;
			else
				m[gems[end]]++;

			s.insert(gems[end]);
			end++;
		}

	}

	output.push_back(to_string(min_start));
	output.push_back(to_string(min_end));
	
	return output;
}


