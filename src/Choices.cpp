#include "Choices.hpp"

#include <cstdarg>
#include <stdexcept>

Choices::Choices(int factor, int start, int end)
    : mRanges{{start, end}}, mFactor{factor} {}

Choices::Choices() : mRanges{}, mFactor{1} {}

VecPair::iterator Choices::begin() {
  return mRanges.begin();
}

VecPair::iterator Choices::end() {
  return mRanges.end();
}

VecPair::const_iterator Choices::cbegin() {
  return mRanges.cbegin();
}

VecPair::const_iterator Choices::cend() {
  return mRanges.cend();
}

int Choices::getFactor() { return mFactor; }
