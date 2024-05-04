#include <iostream>

int main() {
  constexpr int MIN = 1;
  constexpr int MAX = 6;
  int total = 0, temp_sum;
  
  for (int x1 = MIN; x1 <= MAX; ++x1) {
    for (int x2 = MIN; x2 <= MAX; ++x2) {
      for (int x3 = MIN; x3 <= MAX; ++x3) {
        temp_sum = x1 + x2 + x3;
        if (
          // x5 <= 1 &&
          // 0 <= x0 && x1 <= 9 &&
          // x0 > 9 &&
          temp_sum == 12
        ) {
          ++total;
        }
        // if (
        //   0 <= x1 && x1 <= 5 &&
        //   1 <= x2 && x2 <= 6 &&
        //   1 <= x3 && x3 <= 6 &&
        //   1 <= x4 && x4 <= 6 &&
        //   0 <= x5 && x5 <= 5 &&
        //   x1 + x2 + x3 + x4 + x5 == 8
        // ) {
        //   ++total;
        // }
      }
    }
  }

  std::cout << total << std::endl;
  return 0;
}