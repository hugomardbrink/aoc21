#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::vector<std::string>& readToString(const std::string& path);

int main() 
{
  std::vector<std::string> commands = readToString("../input/02.txt");
  long h{},d{};

  for(std::string command : commands)
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

  std::cout << h*d << std::endl;

  return 0;
}

const std::vector<std::string>& readToString(const std::string& path)
{
  std::ifstream inputFile(path);
  std::string input;
  static std::vector<std::string> inputs;

  while(std::getline(inputFile, input))
    inputs.push_back(input);

  inputFile.close();

  return inputs;
}