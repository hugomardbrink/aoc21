#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> readToString(const std::string& path);

int main() 
{
  std::vector<std::string> commands = readToString("../input/02.txt");
  long h{},d{},a{};

  for(auto& command : commands)
  {
    command.pop_back();
    int val = command.back() - 48;

    switch(command.front())
    {
      case 'f': d += a * val;
                h += val; break;
      case 'u': a -= val; break;
      case 'd': a += val; break;                    
    }
  }

  std::cout << d*h << std::endl;

  return 0;
}

std::vector<std::string> readToString(const std::string& path)
{
  std::ifstream inputFile(path);
  std::string input;
  std::vector<std::string> inputs;
   
  while(std::getline(inputFile, input))
    inputs.push_back(input);

  inputFile.close();

  return inputs;
}