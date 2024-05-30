#include "Counter.hpp"

#include <stdexcept>
#include <utility>

Counter::Counter(Transformer transform, Predicate match)
    : mVars{}, mTrans{transform}, mPred{match}, mX{} {}

Counter::Counter() : mVars{}, mTrans{nullptr}, mPred{nullptr}, mX{} {}

int Counter::enumerateChoice(ChoiceVector::iterator caseIt,
                             std::vector<int>::iterator varIt) {
  const int f = caseIt->getFactor();
  int res = 0;
  // iterate over ranges of a sinle case
  for (auto range = caseIt->cbegin(); range < caseIt->cend(); ++range) {
    // iterate over a single range
    for (int i = range->first; i <= range->second; ++i) {
      *varIt = i * f;
      // if this case is the back of vector call transformer
      if (caseIt + 1 == mVars.end()) {
        res += mPred(mTrans(mX));
      } else {
        res += enumerateChoice(caseIt + 1, varIt + 1);
      }
    }
  }
  return res;
}

int Counter::enumerateChoice(ChoiceVector::iterator caseIt,
                             std::vector<int>::iterator varIt,
                             std::back_insert_iterator<IntCases> out) {
  const int f = caseIt->getFactor();
  int res = 0;
  // iterate over ranges of a sinle case
  for (auto range = caseIt->cbegin(); range < caseIt->cend(); ++range) {
    // iterate over a single range
    for (int i = range->first; i <= range->second; ++i) {
      *varIt = i * f;
      // if this case is the back of vector call transformer
      if (caseIt + 1 == mVars.end()) {
        if (mPred(mTrans(mX))) {
          ++res;
          *out++ = mX;
        }
      } else {
        res += enumerateChoice(caseIt + 1, varIt + 1, out);
      }
    }
  }
  return res;
}

int Counter::countCases() {
  if (!mTrans && !mPred) {
    return -1;
  }
  return enumerateChoice(mVars.begin(), mX.begin());
}

int Counter::countCases(std::back_insert_iterator<IntCases> out) {
  if (!mTrans && !mPred) {
    return -1;
  }
  return enumerateChoice(mVars.begin(), mX.begin(), out);
}

void Counter::changeTransformer(Transformer transform) { mTrans = transform; }

void Counter::changePredicate(Predicate match) { mPred = match; }

void Counter::addCase(Choices choices) {
  mX.push_back(0);
  mVars.push_back(choices);
}
