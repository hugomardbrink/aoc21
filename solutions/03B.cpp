#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>

constexpr std::size_t bSize = 12;

const std::vector<std::string>& readToString(const std::string& path);
const void getGammaEpsilon(std::bitset<bSize>& g, 
                           std::bitset<bSize>& e, 
                           const std::vector<std::string>& v);
const void filterCommonBit(int bit, const std::bitset<bSize>& f, std::vector<std::string>& v);
std::string filterCommonBinary(bool common, std::vector<std::string> v);

int main() 
{
  std::vector<std::string> rates = readToString("../input/03.txt");
  
  std::bitset<bSize> o{filterCommonBinary(true, rates)};
  std::bitset<bSize> c{filterCommonBinary(false, rates)};
  
  std::cout << o.to_ulong() * c.to_ulong() << std::endl;
  
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
    for(auto b = 0; b < bSize; b++)
      bitOccurence[b] += el[b] - 48;

  for(auto b = 0; b < bSize; b++)
    g.set(bSize-b-1, bitOccurence[b] >= round((float) v.size()/2));
  
  e = ~g;  
}

const void filterCommonBit(int bit, const std::bitset<bSize>& f, std::vector<std::string>& v)
{
  std::vector<std::string> nv;
  
  for(auto i = 0; i < v.size(); i++) 
    if(f[bSize-bit-1] == v[i][bit] - 48)
      nv.push_back(v[i]);

  v.clear();
  for(const auto& e : nv)
    v.push_back(e);
}

std::string filterCommonBinary(bool common, std::vector<std::string> v)
{
  std::bitset<bSize> g, e;

  for(auto b = 0; b < bSize; b++)
  {
    getGammaEpsilon(g, e, v);
    filterCommonBit(b, common ? g : e, v);

    if(v.size() == 1)
      return v[0];
  }

  return "";
}