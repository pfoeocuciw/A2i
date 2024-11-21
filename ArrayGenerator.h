
#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

class ArrayGenerator {
public:
  ArrayGenerator();

  std::vector<int> getRandomArray(int size);

  std::vector<int> getReversedArray(int size);

  std::vector<int> getAlmostSortedArray(int size, int swaps);

private:
  std::vector<int> baseArray;
  std::mt19937 rng;
};

#endif // ARRAY_GENERATOR_H
