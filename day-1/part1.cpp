#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <ranges>
#include <string>
#include <string_view>

struct LocationList {
  std::priority_queue<int> left;
  std::priority_queue<int> right;
};

int calculate(LocationList &&locationList) {
  assert(locationList.left.size() == locationList.right.size());
  int size = locationList.left.size();
  int res = 0;

  for (int i = 0; i < size; ++i) {
    int left = locationList.left.top();
    int right = locationList.right.top();

    res += std::abs(left - right);

    locationList.left.pop();
    locationList.right.pop();
  }

  return res;
}

int main() {
  std::ifstream file("input");
  if (!file)
    return 1;

  LocationList locList{};

  std::string line;
  while (std::getline(file, line)) {
    using std::operator""sv;
    constexpr auto delim{"   "sv};

    std::vector<std::string_view> words;
    for (const auto word : std::views::split(line, delim)) {
      words.push_back(std::string_view(word));
    }

    assert(words.size() == 2);
    int left = std::stoi(std::string(words[0]));
    int right = std::stoi(std::string(words[1]));

    locList.left.push(left);
    locList.right.push(right);
  }

  auto res = calculate(std::move(locList));

  std::cout << "Result = " << res << std::endl;

  return 0;
}
