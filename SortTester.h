// SortTester.h

#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <vector>
#include <string>

class SortTester {
public:

  void testMergeSort(const std::vector<int>& sizes, int numRuns);
  void testHybridSort(const std::vector<int>& sizes, const std::vector<int>& thresholds, int numRuns);

private:
  void logResults(const std::string& filename, const std::vector<int>& sizes, const std::vector<double>& times);
};

#endif // SORT_TESTER_H
