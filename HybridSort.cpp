// HybridSort.cpp

#include "HybridSort.h"

void HybridSort::sort(std::vector<int>& arr, int threshold) {
  hybridSort(arr, 0, arr.size() - 1, threshold);
}

void HybridSort::hybridSort(std::vector<int>& arr, int left, int right, int threshold) {
  if (right - left + 1 <= threshold) {
    insertionSort(arr, left, right);
    return;
  }
  int mid = left + (right - left) / 2;
  hybridSort(arr, left, mid, threshold);
  hybridSort(arr, mid + 1, right, threshold);
  merge(arr, left, mid, right);
}

void HybridSort::merge(std::vector<int>& arr, int left, int mid, int right) {
  // Аналогично MergeSort::merge
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
  std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void HybridSort::insertionSort(std::vector<int>& arr, int left, int right) {
  for (int i = left + 1; i <= right; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}
