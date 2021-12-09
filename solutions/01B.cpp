#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::vector<int>& readToInt(const std::string& path);

int main()
{
  std::vector<int> depths = readToInt("../input/01.txt");
      
  int increases{};
  for(auto i = 0; i < depths.size() - 3; i++)
    increases += 1 * (depths[i]+depths[i+1]+depths[i+2] < depths[i+1]+depths[i+2]+depths[i+3]);

  std::cout << increases << std::endl;

  return 0;
}

const std::vector<int>& readToInt(const std::string& path)
{
  std::ifstream inputFile(path);
  static std::vector<int> inputs;
   
  std::string input;
  while(std::getline(inputFile, input))
    inputs.push_back(std::stoi(input));

  inputFile.close();  

  return inputs;
}
