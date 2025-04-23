#ifndef __SORTINGALGORITHMS__
#define __SORTINGALGORITHMS__

#include "Student.h"
#include <iostream>
#include <array>

//Bubble Sort
template <class T>
void bubbleSort(T *arr, int arrSize) {

    std::cout << "\n";
	for (int i{}; i < arrSize -1;i++){
		for (int j{}; j < arrSize -i-1;j++){
			if (arr[j] > arr[j+1]){
				T temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
        /* Watch sorting process!!
        for (int k{}; k < arrSize; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << "\n";*/
    }
}

//Insertion Sort
template <class T>
void insertionSort(T *arr, int arrSize){
	for (int i=1; i< arrSize; ++i){
		T key = arr[i];
		int j=i-1;
		while(j>= 0 && arr[j] > key){
			arr[j+1]=arr[j];
			j = j-1;
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
int partition(T *arr, int low, int high) {
	T pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high -1; j++) {
		if (arr[j] < pivot) {
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
void quickSort(T *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//Counting Sort
template <class T>
T* countingSort(T inputArray[], int arrSize) {
    int N = arrSize;

    // Finding the maximum element of array inputArray[].
    int M = 0;

    for (int i = 0; i < N; i++) {
		if (inputArray[i] > M) {
			M = inputArray[i];
        }
	}
    
    // Initializing countArray[] with 0
    T* countArray = new T[M+1];

    // Mapping each element of inputArray[] as an index
    // of countArray[] array
    for (int i = 0; i < N; i++) {
        countArray[inputArray[i]]++;
	}

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++) {
        countArray[i] += countArray[i - 1];
	}

    // Creating outputArray[] from countArray[] array
    T* outputArray = new T[N];

    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];

        countArray[inputArray[i]]--;
    }
    return outputArray;
}

    
//Radix Sort
template <class T>
void radixSort(T arr[], int arrSize) {
    //find amount of decimal places
    T greatest = T[0]; //rather than make a new T object we’re just gonna have temp be the first T
    for (int i{}; i < arrSize; i++) {
        if (greatest > T[i]) {
            greatest = T[i];
        }
    } // close find-greatest
    //find amount of decimal places
        int decPlaces = 0;
        T decFinder = greatest;
        while (true) {
            if (decFinder / 10 < 10) {
                decFinder++;
                decFinder / 10;
            }
            else {
                break;
            }
        }//close find-dec

        //actual piece of radixSort
        for (int i{}; i < decPlaces; i++) {
            countingSort(arr, arrSize);
        }
    }


#endif
