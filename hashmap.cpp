#include <iostream>
#include <string>

using namespace std;

int division(const std::string &data, const int size) {
  int total = 0;

  for (char word : data) {
    total += static_cast<int>(word);
  }

  return total % size;
}

int midSquare(const std::string &data) {
  int total = 0;

  for (char word : data) {
    total += static_cast<int>(word);
  }

  std::string converted = std::to_string(total);
  int length = converted.length();

  if (length % 2 == 1) {
    converted = "0" + converted;
    length++;
  }

  if (length == 2) return std::stoi(converted);

  std::string result = "";
  int gap = length / 2 - 1, index = gap + 1;

  for (char num : converted) {
    if (gap > 0) {
      gap--;
      continue;
    }
    if (index == 0) break; 

    result = result + num;
    index--;
  }

  cout << result << endl;
  return std::stoi(result);
}

int main() {
  int tableSize = 30;

  std::string str1 = "AJOJING";
  std::string str2 = "CHARLIE";

  int div1 = division(str1, tableSize);
  int div2 = division(str2, tableSize);

  int mid1 = midSquare(str1);
  int mid2 = midSquare(str2);

  cout << "Index division 1 = " << div1 << endl;
  cout << "Index division 2 = " << div2 << endl;
  cout << "===========================" << endl;
  cout << "Index mid 1 = " << mid1 << endl;
  cout << "Index mid 2 = " << mid2 << endl;
}
