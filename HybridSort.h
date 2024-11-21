// HybridSort.h

#ifndef HYBRID_SORT_H
#define HYBRID_SORT_H

#include <vector>

class HybridSort {
public:
  static void sort(std::vector<int>& arr, int threshold);
private:
  static void hybridSort(std::vector<int>& arr, int left, int right, int threshold);
  static void merge(std::vector<int>& arr, int left, int mid, int right);
  static void insertionSort(std::vector<int>& arr, int left, int right);
};

#endif // HYBRID_SORT_H
