#include "SortTester.h"
#include "ArrayGenerator.h"
#include "MergeSort.h"
#include "HybridSort.h"
#include <chrono>
#include <fstream>
#include <iostream>

void SortTester::testMergeSort(const std::vector<int>& sizes, int numRuns) {
  ArrayGenerator generator;
  std::vector<double> avgTimesRandom, avgTimesReversed, avgTimesAlmostSorted;

  for (int size : sizes) {
    double totalTimeRandom = 0, totalTimeReversed = 0, totalTimeAlmostSorted = 0;

    for (int run = 0; run < numRuns; ++run) {

      auto arrRandom = generator.getRandomArray(size);
      auto start = std::chrono::high_resolution_clock::now();
      MergeSort::sort(arrRandom);
      auto end = std::chrono::high_resolution_clock::now();
      totalTimeRandom += std::chrono::duration<double, std::milli>(end - start).count();

      auto arrReversed = generator.getReversedArray(size);
      start = std::chrono::high_resolution_clock::now();
      MergeSort::sort(arrReversed);
      end = std::chrono::high_resolution_clock::now();
      totalTimeReversed += std::chrono::duration<double, std::milli>(end - start).count();

      auto arrAlmostSorted = generator.getAlmostSortedArray(size, size / 10);
      start = std::chrono::high_resolution_clock::now();
      MergeSort::sort(arrAlmostSorted);
      end = std::chrono::high_resolution_clock::now();
      totalTimeAlmostSorted += std::chrono::duration<double, std::milli>(end - start).count();
    }

    avgTimesRandom.push_back(totalTimeRandom / numRuns);
    avgTimesReversed.push_back(totalTimeReversed / numRuns);
    avgTimesAlmostSorted.push_back(totalTimeAlmostSorted / numRuns);
  }

  logResults("merge_sort_random.csv", sizes, avgTimesRandom);
  logResults("merge_sort_reversed.csv", sizes, avgTimesReversed);
  logResults("merge_sort_almost_sorted.csv", sizes, avgTimesAlmostSorted);
}

void SortTester::testHybridSort(const std::vector<int>& sizes, const std::vector<int>& thresholds, int numRuns) {
  ArrayGenerator generator;

  for (int threshold : thresholds) {
    std::vector<double> avgTimesRandom, avgTimesReversed, avgTimesAlmostSorted;

    for (int size : sizes) {
      double totalTimeRandom = 0, totalTimeReversed = 0, totalTimeAlmostSorted = 0;

      for (int run = 0; run < numRuns; ++run) {

        auto arrRandom = generator.getRandomArray(size);
        auto start = std::chrono::high_resolution_clock::now();
        HybridSort::sort(arrRandom, threshold);
        auto end = std::chrono::high_resolution_clock::now();
        totalTimeRandom += std::chrono::duration<double, std::milli>(end - start).count();

        auto arrReversed = generator.getReversedArray(size);
        start = std::chrono::high_resolution_clock::now();
        HybridSort::sort(arrReversed, threshold);
        end = std::chrono::high_resolution_clock::now();
        totalTimeReversed += std::chrono::duration<double, std::milli>(end - start).count();

        auto arrAlmostSorted = generator.getAlmostSortedArray(size, size / 10);
        start = std::chrono::high_resolution_clock::now();
        HybridSort::sort(arrAlmostSorted, threshold);
        end = std::chrono::high_resolution_clock::now();
        totalTimeAlmostSorted += std::chrono::duration<double, std::milli>(end - start).count();
      }

      avgTimesRandom.push_back(totalTimeRandom / numRuns);
      avgTimesReversed.push_back(totalTimeReversed / numRuns);
      avgTimesAlmostSorted.push_back(totalTimeAlmostSorted / numRuns);
    }

    logResults("hybrid_sort_random_threshold_" + std::to_string(threshold) + ".csv", sizes, avgTimesRandom);
    logResults("hybrid_sort_reversed_threshold_" + std::to_string(threshold) + ".csv", sizes, avgTimesReversed);
    logResults("hybrid_sort_almost_sorted_threshold_" + std::to_string(threshold) + ".csv", sizes, avgTimesAlmostSorted);
  }
}

void SortTester::logResults(const std::string& filename, const std::vector<int>& sizes, const std::vector<double>& times) {
  std::ofstream file(filename);
  file << "Size,Time(ms)\n";
  for (size_t i = 0; i < sizes.size(); ++i) {
    file << sizes[i] << "," << times[i] << "\n";
  }
  file.close();
}
