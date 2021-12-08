#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::vector<std::string>& readToString(const std::string& path);

int main() 
{
  std::vector<std::string> commands = readToString("../input/02.txt");
  long h,d = 0;

  for(auto& command : commands)
  {
    command.pop_back();
    int val = command.back() - 48;

    switch(command.front())
    {
      case 'f': h += val; break;
      case 'u': d -= val; break;
      case 'd': d += val; break;                    
    }
  }

  std::cout << d*h << std::endl;

  return 0;
}

const std::vector<std::string>& readToString(const std::string& path)
{
  std::ifstream inputFile(path);
  std::string input;
  static std::vector<std::string> inputs;
   
  while(std::getline(inputFile, input))
    inputs.push_back(input);

  return inputs;
}