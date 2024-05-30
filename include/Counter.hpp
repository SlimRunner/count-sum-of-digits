#ifndef COUNTER_H
#define COUNTER_H

#include "Choices.hpp"

#include <iterator>
#include <memory>
#include <vector>

using Transformer = int (*)(std::vector<int> vars);
using Predicate = bool (*)(int result);
using ChoiceVector = std::vector<Choices>;
using IntCases = std::vector<std::vector<int>>;

class Counter {
private:
  /* data */
  ChoiceVector mVars;
  Transformer mTrans;
  Predicate mPred;
  std::vector<int> mX;

  int enumerateChoice(ChoiceVector::iterator caseIt,
                      std::vector<int>::iterator varIt);
  int enumerateChoice(ChoiceVector::iterator caseIt,
                      std::vector<int>::iterator varIt,
                      std::back_insert_iterator<IntCases> out);

public:
  Counter(Transformer transform, Predicate match);
  Counter();

  int countCases();
  int countCases(std::back_insert_iterator<IntCases> out);

  void changeTransformer(Transformer transform);
  void changePredicate(Predicate match);
  void addCase(Choices choices);
};

#endif // COUNTER_H
