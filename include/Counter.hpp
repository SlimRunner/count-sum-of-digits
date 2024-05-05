#ifndef COUNTER_H
#define COUNTER_H

#include "Choices.hpp"

#include <memory>
#include <vector>

using Transformer = int (*)(std::vector<int> vars);
using Predicate = bool (*)(int result);
using ChoiceVector = std::vector<Choices>;

class Counter {
private:
  /* data */
  ChoiceVector mVars;
  Transformer mTrans;
  Predicate mPred;
  std::vector<int> mX;

  int enumerateChoice(ChoiceVector::iterator caseIt,
                      std::vector<int>::iterator varIt);

public:
  Counter(Transformer transform, Predicate match);
  Counter();

  int countCases();

  void changeTransformer(Transformer transform);
  void changePredicate(Predicate match);
  void addCase(Choices choices);
};

#endif // COUNTER_H
