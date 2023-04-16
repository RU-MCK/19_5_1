#include <iostream>
#include <fstream>
#include <vector>

int findWord(std::vector<std::string> &buffer, std::string &word) {
  int count = 0;
  for (int i = 0; (i < buffer.size()); ++i) {
    if (word == buffer[i])
      count++;
  }
  return count;
}

int main() {
  std::vector<std::string> buffer;
  std::ifstream word;
  word.open("D:\\SkillboxProject\\FilesTXT\\word.txt");
  int count = 0;
  while (!word.eof()) {
    std::string str;
    word >> str;
    count++;
    buffer.push_back(str);
  }
  std::cout << "Input search word: ";
  std::string searchWord;
  std::cin >> searchWord;
  const std::string quote = "\"";
  std::cout << "All words: " << count << std::endl
            << "Found words " + quote << searchWord << quote + ": "
            << findWord(buffer, searchWord) << std::endl;
  word.close();
  return 0;
}
