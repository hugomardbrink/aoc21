#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>

constexpr std::size_t bSize = 12;

const std::vector<std::string>& readToString(const std::string& path);
const void getGammaEpsilon(std::bitset<bSize>& g, 
                           std::bitset<bSize>& e, 
                           const std::vector<std::string>& v);

int main() 
{

  std::vector<std::string> inputs = readToString("../input/03.txt");
  std::bitset<bSize> g, e;

  getGammaEpsilon(g, e, inputs);

  std::cout << (g.to_ulong() * e.to_ulong()) << std::endl;

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

const void getGammaEpsilon(std::bitset<bSize>& g, 
                           std::bitset<bSize>& e, 
                           const std::vector<std::string>& v)
{
  int bitOccurence [bSize]{};

  for(const auto& el : v)
    for(int b = 0; b < bSize; b++)
      bitOccurence[b] += el[b] - 48;

  for(int b = 0; b < bSize; b++)
    g.set(bSize-b-1, bitOccurence[b] > v.size()/2);

  e = ~g;  
}
