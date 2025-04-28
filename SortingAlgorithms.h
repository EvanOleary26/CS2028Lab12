#ifndef __SORTINGALGORITHMS__H
#define __SORTINGALGORITHMS__H

#include "Student.h"
#include <iostream>
#include <array>

//Bubble Sort
template <class T>
void bubbleSort(T *arr, int arrSize, bool ascending = true) {
    bool swapped;
    for (int i{}; i < arrSize - 1; i++) {
        swapped = false;
        for (int j{}; j < arrSize - i - 1; j++) {
            // For descending order, reverse the comparison
            if ((ascending && arr[j] > arr[j+1]) || 
                (!ascending && arr[j] < arr[j+1])) {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

//Insertion Sort
template <class T>
void insertionSort(T *arr, int arrSize, bool ascending = true) {
    for (int i = 1; i < arrSize; ++i) {
        T key = arr[i];
        int j = i - 1;
        
        // Modify comparison for ascending/descending
        while(j >= 0 && ((ascending && arr[j] > key) || 
                         (!ascending && arr[j] < key))) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

//Merge Sort
template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] < R[j] || L[i] == R[j]) {
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

    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

//Quick Sort
template <class T>
int partition(T *arr, int low, int high, bool ascending = true) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        // For descending order, reverse the comparison
        if ((ascending && arr[j] < pivot) || 
            (!ascending && arr[j] > pivot)) {
            i++;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    T temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

template <class T>
void quickSort(T *arr, int low, int high, bool ascending = true) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);

        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

//Counting Sort
template <class T>
T* countingSort(T* arr, int arrSize) {
    int N = arrSize;

    // Finding the maximum element of array arr[].
    int M = 0;
    for (int i = 0; i < N; i++) {
		if (int(arr[i]) > M) {
			M = int(arr[i]);
        }
	}
    
    // Initializing countArray[] with 0
    int* countArray = new int[M+1]();

    // Mapping each element of arr[] as an index
    // of countArray[] array
    for (int i = 0; i < N; i++) {
        countArray[arr[i]]++;
	}

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++) {
        countArray[i] += countArray[i - 1];
	}

    // Creating outputArray[] from countArray[] array
    T* outputArray = new T[N];

    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }
    return outputArray;
}

    
//Radix Sort
template <class T>
void radixSort(T arr[], int arrSize) {
    // Find maximum element
    int max = int(arr[0]);
    for (int i = 1; i < arrSize; i++) {
        if (int(arr[i]) > max) {
            max = int(arr[i]);
        }
    }
    
    // Count number of digits in max
    int digits = 0;
    int temp = max;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    // Do counting sort for every digit position
    int exp = 1; // 1, 10, 100, etc.
    T* output = new T[arrSize];
    
    for (int d = 0; d < digits; d++) {
        // Initialize count array
        int count[10] = {0};
        
        // Count occurrences of each digit
        for (int i = 0; i < arrSize; i++) {
            count[(int(arr[i]) / exp) % 10]++;
        }
        
        // Change count[i] so that it contains the actual
        // position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build the output array
        for (int i = arrSize - 1; i >= 0; i--) {
            output[count[(int(arr[i]) / exp) % 10] - 1] = arr[i];
            count[(int(arr[i]) / exp) % 10]--;
        }
        
        // Copy the output array to arr[]
        for (int i = 0; i < arrSize; i++) {
            arr[i] = output[i];
        }
        
        exp *= 10;
    }
    
    delete[] output; // Free memory
}


#endif
