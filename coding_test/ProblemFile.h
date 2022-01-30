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

// template class or inline 인 경우 같은 파일에서 정의까지 해야함.

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

			
			// 왜 동시에 compile하지 않느냐 와 같은 질문은 당장은 잘 모르겠음
			// ProgrammerFile templat class compile 당시 parent class가 만들어지지 않았음. => 전역 변수를 찾으려함 => 못찾음 error
			// 따라서 this->를 통해 이 class에는 있다는 것을 알려주자. 또는 ProblemFile<input_T, output_T>::inputs 등 사용

			//this->inputs.push_back(buffer); 
		}
	}
	else
	{
		throw ifs;
	}

	ifs.close();
}