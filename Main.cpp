#include <iostream>
#include <chrono>

#include "SortingAlgorithms.h"

template <class T>
void bubbleSort(T *arr);    //Need to pass a pointer for referencing the array

template <class T>
void insertionSort(T *arr); //Need to pass a pointer for referencing the array

template <class T>
void quickSort(T *arr, int low, int high);

template <class T>
T* countingSort(T arr[], int size);

template <class T>
void radixSort(T arr[]);

typedef std::chrono::high_resolution_clock Clock;

int main() {

auto t1 = Clock::now();
auto t2 = Clock::now();
std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

return 0;
}
