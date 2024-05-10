#include "Counter.hpp"

#include <iostream>

int main() {
  constexpr int MATCH = 24;
  Transformer trans = [](std::vector<int> vars) -> int {
    int res = 0;
    for (const & var: vars) {
      res += var;
    }
    return res;
  };
  Predicate pred = [](int result) -> bool {
    return result == MATCH;
  };
  Counter counter(trans, pred);
  counter.addCase(Choices(4, 0, 6));
  counter.addCase(Choices(4, 0, 6));
  counter.addCase(Choices(1, 0, 24));
  counter.addCase(Choices(1, 0, 24));

  std::cout << counter.countCases() << std::endl;
  return 0;
}