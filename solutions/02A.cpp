#include <iostream>
#include <fstream>
#include <string>

int main() 
{
  std::ifstream inputFile("../input/02.txt");
  std::string input;
  long h,d = 0;

  while(std::getline(inputFile, input))
  {
    input.pop_back();
    int val = input.back() - 48;

    switch(input.front())
    {
      case 'f': h += val; break;
      case 'u': d -= val; break;
      case 'd': d += val; break;                    
    }
  }

  inputFile.close();

  std::cout << d*h << std::endl;

  return 0;
}