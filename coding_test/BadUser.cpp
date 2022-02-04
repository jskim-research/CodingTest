#include "BadUser.h"
#include "CommonHeaders.h"

using namespace std;

BadUser::BadUser(FileFormat file_format): ProgrammersProblem(file_format)
{

}

std::vector<std::string> BadUser::Solve(std::vector<std::vector<std::string>>& input)
{
	std::vector<std::string> output;

	map<string, bool> selected;
	vector<string> user_id = input[0];
	vector<string> banned_id = input[1];
	vector<vector<string>> v;
	set<string> s;
	int answer = 0;
		
	for (int i = 0; i < user_id.size(); i++)
		selected[user_id[i]] = false;

	for (int i = 0; i < banned_id.size(); i++)
	{
		vector<string> tmp;
		for (int j = 0; j < user_id.size(); j++)
		{
			if (Matching(user_id[j], banned_id[i]))
			{
				tmp.push_back(user_id[j]);
			}
		}
		v.push_back(tmp);
	}

	GetNumCases(selected, v, 0, s);
	output.push_back(to_string(s.size()));
	
	return output;
}

bool BadUser::Matching(const std::string& s1, const std::string& s2) const
{
	if (s1.size() != s2.size()) return false;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == s2[i] || (s1[i] == '*' || s2[i] == '*')) continue;
		else return false;
	}

	return true;
}

int BadUser::GetNumCases(std::map<std::string, bool>& selected, const std::vector<std::vector<std::string>>& v, int i, set<string>& s)
{
	if (i >= v.size())
	{
		string final_string = "";
		for (map<string, bool>::iterator iter = selected.begin(); iter != selected.end(); iter++)
			if (iter->second)
				final_string += iter->first;

		s.insert(final_string);
		return 1;
	}
	int result = 0;

	for (int j = 0; j < v[i].size(); j++)
	{
		if (!selected[v[i][j]]) // iterator�� �����صΰ� �����ϴ� ���� ���� ��.
		{
			selected[v[i][j]] = true;
			result += GetNumCases(selected, v, i + 1, s);
			selected[v[i][j]] = false;
		}
	}

	return result;
}
