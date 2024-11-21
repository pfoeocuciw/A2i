#include "ArrayGenerator.h"

ArrayGenerator::ArrayGenerator() {
  rng.seed(42);

  std::uniform_int_distribution<int> dist(0, 6000);
  baseArray.resize(10000);
  for (int i = 0; i < 10000; ++i) {
    baseArray[i] = dist(rng);
  }
}

std::vector<int> ArrayGenerator::getRandomArray(int size) {
  return std::vector<int>(baseArray.begin(), baseArray.begin() + size);
}

std::vector<int> ArrayGenerator::getReversedArray(int size) {
  std::vector<int> arr = getRandomArray(size);
  std::sort(arr.begin(), arr.end(), std::greater<int>());
  return arr;
}

std::vector<int> ArrayGenerator::getAlmostSortedArray(int size, int swaps) {
  std::vector<int> arr = getRandomArray(size);
  std::sort(arr.begin(), arr.end());
  std::uniform_int_distribution<int> dist(0, size - 1);

  for (int i = 0; i < swaps; ++i) {
    int idx1 = dist(rng);
    int idx2 = dist(rng);
    std::swap(arr[idx1], arr[idx2]);
  }
  return arr;
}
