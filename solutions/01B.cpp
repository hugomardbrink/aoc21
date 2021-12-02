#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
  std::ifstream inputFile("../input/01.txt");
  std::string input;
  std::vector<int> values;
      
  while(std::getline(inputFile, input))
  {
    values.push_back(std::stoi(input));
  }

  inputFile.close();

  int increases = 0;
  for(auto i = 0; i < values.size() - 3; i++)
  {
    increases += 1 * (values[i]+values[i+1]+values[i+2] < values[i+1]+values[i+2]+values[i+3]);
  }

  std::cout << increases << std::endl;

  return 0;
}

