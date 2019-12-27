#include "../std_lib_facilities.h"
#include <locale>
#include "windows.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream ifs{ "if_file.txt" };
	if (!ifs)
	{
		error("error");
	}

	ofstream ofs{ "ofs_file.txt" };
	if (!ofs)
	{
		error("error");
	}

	string str;
	string temp_str;
	while (!ifs.eof())
	{
		vector <string> vec_str;
		getline(ifs, str);
		stringstream s{ str };
		while (s >> temp_str)
		{
			vec_str.push_back(temp_str);
		}

		for (int i = vec_str.size() - 1; i >= 0; i--)
		{
			ofs << vec_str[i] << " ";
		}
		ofs << "\n";
	}

	cin.get();
	cin.get();
	return 0;
}