#ifndef CHOICES_H
#define CHOICES_H

#include <tuple>
#include <vector>

using VecPair = std::vector<std::pair<int, int>>;

class Choices {
private:
  /* data */
  VecPair mRanges;
  int mFactor;

public:
  Choices(int factor, int start, int end, int rest...);
  Choices(int factor, int start, int end);
  Choices();

  VecPair::iterator begin();
  VecPair::iterator end();

  VecPair::const_iterator cbegin();
  VecPair::const_iterator cend();

  int getFactor();
};

#endif // CHOICES_H
