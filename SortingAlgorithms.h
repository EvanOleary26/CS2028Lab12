#include "Student.h"
#include <iostream>
#include <array>

//Bubble Sort
template <class T>
void bubbleSort(T *arr, int arrSize) {
    for (int k{}; k < arrSize; k++) {
        std::cout << arr[k] << " ";
    }
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

//QuickSort
template <class T>
int partition(T *arr, int low, int high) {
	int pivot = arr[high];
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
T* countingSort(T arr[], int size) { //may need to be changed to a pointer depending on data size
    T c[] = new T[size];
    for (int i = 0; i < arr.length(); i++) { //gives us our count for each value 
        c[arr[i]]++;
    }
    for(int i=1; i<c.length; i++){ //calculating our running sum
        c[i] += c[i-1];
    }
    T* result = new T[sizeof(arr)];
    for(int i=0; i<arr.length(); i++){
        int index = c[arr[i]];
        index--;
        c[arr[i]] = index;
        result[index] = arr[i]; //places the value in the result array
    }
    return result;
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
            countingSort(arr);
        }
    }


    
