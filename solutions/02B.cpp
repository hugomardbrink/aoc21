#include <iostream>
#include <fstream>
#include <string>

int main() 
{
  std::ifstream inputFile("../input/02.txt");
  std::string input;
  long h,d,a = 0;

  while(std::getline(inputFile, input))
  {
    input.pop_back();
    int val = input.back() - 48;

    switch(input.front())
    {
      case 'f': d += a * val;
                h += val; break;
      case 'u': a -= val; break;
      case 'd': a += val; break;                    
    }
  }

  inputFile.close();

  std::cout << d*h << std::endl;

  return 0;
}