// main.cpp

#include "SortTester.h"
#include <vector>

int main() {
  SortTester tester;
  std::vector<int> sizes;
  for (int size = 500; size <= 10000; size += 100) {
    sizes.push_back(size);
  }

  int numRuns = 5; // Количество запусков для усреднения

  // Этап 2: Тестирование стандартного MERGE SORT
  tester.testMergeSort(sizes, numRuns);

  // Этап 3: Тестирование гибридного MERGE+INSERTION SORT
  std::vector<int> thresholds = {5, 10, 20, 30, 50};
  tester.testHybridSort(sizes, thresholds, numRuns);

  return 0;
}
