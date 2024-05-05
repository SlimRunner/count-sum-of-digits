#include "Choices.hpp"

#include <cstdarg>
#include <stdexcept>

Choices::Choices(int factor, int start, int end, int rest...)
    : mRanges{{start, end}}, mFactor{factor} {
  std::va_list args;
  va_start(args, rest);
  if (rest % 2) {
    throw std::invalid_argument("Ranges go in pairs");
  }
  for (size_t i = 0; i < static_cast<size_t>(rest); i += 2) {
    start = va_arg(args, int);
    end = va_arg(args, int);
    mRanges.push_back({start, end});
  }
}

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
