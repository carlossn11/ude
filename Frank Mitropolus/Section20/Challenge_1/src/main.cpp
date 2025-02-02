// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string &s)
{
  std::deque<char> cleaned;
  std::copy_if(s.begin(), s.end(), std::back_inserter(cleaned), [](const char &c)
               { return std::isalpha(c); });

  std::deque<char>::const_iterator left = cleaned.begin();
  auto right = cleaned.cend() - 1;

  while (left != cleaned.end())
  {
    if (std::tolower(*left) != std::tolower(*right))
    {
      return false;
    }
    ++left;
    --right;
  }
  return true;
}

int main()
{
  std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

  std::cout << std::boolalpha;
  std::cout << std::setw(8) << std::left << "Result"
            << "String" << std::endl;
  for (const auto &s : test_strings)
  {
    std::cout << std::setw(8) << std::left << is_palindrome(s) << "          " << s << std::endl;
  }
  std::cout << std::endl;
  return 0;
}