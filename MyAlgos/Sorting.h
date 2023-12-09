#pragma once

#include <iostream>
#include <vector>

// A global function for insertion sort.
template<typename T>
void MA_insertionNSort(T* arr, size_t size) {
	for (size_t i = 1; i < size; i++) {
		auto key = arr[i];
		// Insert arr[i] into the sorted subarray Arr[1:j-1]
		size_t j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

template<typename T>
void MA_merge(T* arr, int p, int q, int r) {
    int len_LeftArr = q - p + 1;
    int len_RightArr = r - q;

    T* leftArr = new T[len_LeftArr];
    T* rightArr = new T[len_RightArr];

    // Copy data to temporary arrays leftArr and rightArr
    for (int i = 0; i < len_LeftArr; i++) {
        leftArr[i] = arr[p + i];
    }

    for (int i = 0; i < len_RightArr; i++) {
        rightArr[i] = arr[q + i + 1];
    }

    int i = 0, j = 0, k = p;

    // Merge the temporary arrays back into arr[p..r]
    while (i < len_LeftArr && j < len_RightArr) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr and rightArr if any
    while (i < len_LeftArr) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len_RightArr) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}


template<typename T>
void MA_MergeNSort(T* arr, int startingIndex, int endingIndex) {
	if (startingIndex >= endingIndex) return;
	int middlePoint = (startingIndex + endingIndex) / 2;
	MA_MergeNSort(arr, startingIndex, middlePoint);
	MA_MergeNSort(arr, middlePoint+1,endingIndex);
	MA_merge(arr, startingIndex, middlePoint, endingIndex);
}