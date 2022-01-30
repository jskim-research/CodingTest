#pragma once
#include "DataStructureLayer.h"
#include "UtilityLayer.h"
#include "StringOperation.h"

class ProblemFile
{
protected:
	size_t num_of_problems;
	std::vector<std::vector<std::string>> arrays;
public:
	ProblemFile();
	virtual ~ProblemFile();
	size_t GetNumOfProblems() const;
	std::vector<std::vector<std::string>> GetArrays() const;
	virtual void ReadFile(std::string file_name, std::vector<std::string> type) {}
};

class ProgrammersFile : public ProblemFile
{
private:

public:
	ProgrammersFile();
	~ProgrammersFile();
	void ReadFile(std::string file_name, std::vector<std::string> type) override;
};

// template class or inline �� ��� ���� ���Ͽ��� ���Ǳ��� �ؾ���.

inline ProblemFile::ProblemFile()
{
	num_of_problems = 0;
}

inline ProblemFile::~ProblemFile()
{
}


inline size_t ProblemFile::GetNumOfProblems() const
{
	return num_of_problems;
}

inline std::vector<std::vector<std::string>> ProblemFile::GetArrays() const
{
	return arrays;
}

inline ProgrammersFile::ProgrammersFile()
{
	
}

inline ProgrammersFile::~ProgrammersFile()
{
}

inline void ProgrammersFile::ReadFile(std::string file_name, std::vector<std::string> type)
{
	std::fstream ifs;
	std::string buffer;

	ifs.open(file_name);

	if (ifs.is_open())
	{
		while (ifs.peek() != EOF)
		{
			std::getline(ifs, buffer);

			std::vector<std::string> split_string = StringOperation::split(buffer, '\t');
			for (int i = 0; i < split_string.size(); i++)
			{
 				std::string s = split_string[i];
				std::vector<std::string> array;
				if (type[i] == "list")
				{
					s = StringOperation::remove_all(StringOperation::remove_all(StringOperation::trim(split_string[i]), ' '), '\"');
				}
				
				array = StringOperation::split(s, ',');
				arrays.push_back(array);
			}

			
			// �� ���ÿ� compile���� �ʴ��� �� ���� ������ ������ �� �𸣰���
			// ProgrammerFile templat class compile ��� parent class�� ��������� �ʾ���. => ���� ������ ã������ => ��ã�� error
			// ���� this->�� ���� �� class���� �ִٴ� ���� �˷�����. �Ǵ� ProblemFile<input_T, output_T>::inputs �� ���

			//this->inputs.push_back(buffer); 
		}
	}
	else
	{
		throw ifs;
	}

	ifs.close();
}