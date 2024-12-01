
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <string_view>

struct LocationList {
  std::vector<int> left;
  std::vector<int> right;
};

int calculate(LocationList &&locationList) {
  assert(locationList.left.size() == locationList.right.size());
  auto &&left = locationList.left;
  auto &&right = locationList.right;

  return std::accumulate(left.begin(), left.end(), 0, [&](int accumulated, int l) {
    return accumulated + l * std::count(right.begin(), right.end(), l);
  });
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

    locList.left.push_back(left);
    locList.right.push_back(right);
  }

  auto res = calculate(std::move(locList));

  std::cout << "Result = " << res << std::endl;

  return 0;
}
