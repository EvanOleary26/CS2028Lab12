#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "SortingAlgorithms.h"
#include "Student.h"

template <class T>
void bubbleSort(T *arr, int arrSize);    //Need to pass a pointer for referencing the array

template <class T>
void insertionSort(T *arr, int arrSize); //Need to pass a pointer for referencing the array

template <class T>
void mergeSort(T arr[], int left, int right);

template <class T>
void quickSort(T *arr, int low, int high);

template <class T>
T* countingSort(T arr[], int arrSize);

template <class T>
void radixSort(T arr[], int arrSize);

Student createRandomStudent();

typedef std::chrono::high_resolution_clock Clock;

template<class T>
T* generateArray(int n) {
    T* arr = new T[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (2 * n + 1);
    } //random number
    return arr;

}

void runTests(Student *testArr, int size) {
	auto bubble1 = Clock::now();
	bubbleSort(testArr, size);
	auto bubble2 = Clock::now();
	std::cout << "Bubble Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(bubble2 - bubble1).count() << " nanoseconds" << std::endl;
	auto insert1 = Clock::now();
	insertionSort(testArr, size);
	auto insert2 = Clock::now();
	std::cout << "Insertion Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(insert2 - insert1).count() << " nanoseconds" << std::endl;
	auto merge1 = Clock::now();
	mergeSort(testArr, 0, size - 1);
	auto merge2 = Clock::now();
	std::cout << "Merge Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(merge2 - merge1).count() << " nanoseconds" << std::endl;
	auto quick1 = Clock::now();
	quickSort(testArr, 0, size - 1);
	auto quick2 = Clock::now();
	std::cout << "Quick Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(quick2 - quick1).count() << " nanoseconds" << std::endl;
	/*
	auto counting1 = Clock::now();
	countingSort(testArr, size);
	auto counting2 = Clock::now();
	std::cout << "Counting Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(counting2 - counting1).count() << " nanoseconds" << std::endl;
	auto radix1 = Clock::now();
	radixSort(testArr, size);
	auto radix2 = Clock::now();
	std::cout << "Radix Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(radix2 - radix1).count() << " nanoseconds" << std::endl;
	*/
}

int main() {
    srand(time(0));

    int sizes[6] = {10, 100, 500, 5000, 25000, 100000};
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    Student* arrays[numSizes];

    for (int i = 0; i < numSizes; ++i) {
        int size = sizes[i];
        arrays[i] = generateArray<Student>(size);
        std::cout << arrays[i][9] << " ";
    }
    std::cout << "\n";

	for (int i{}; i < numSizes; ++i) {
		int size = sizes[i];
		std::cout << "\nFor an array of size " << size << ":\n";
		runTests(arrays[i], size);
	}

    return 0;
}

Student createRandomStudent() {
    std::string firstNames[] = {"Steve", "Sue", "Mark", "Sarah", "Josh", "Kelly", "Jerry", "Lisa", "Paul", "Rachel"};
    std::string lastNames[] = {"Smith", "Harvey", "North", "Bines", "O'Conner", "Lincoln", "Adams", "Johnson", "Grant", "Trump"};
    std::string majors[] = {"CS", "Biology", "Law", "Art", "Architecture", "Business", "Engineering", "English", "Gamer", "Doctor"};
    
    int randFName = rand() % 10;
    int randLName = rand() % 10;
    int randMNum = (rand() % 1000000) +10000000;
    int randMaj = rand() % 10;
    
    Student temp(firstNames[randFName], lastNames[randLName], randMNum, majors[randMaj]);
    return temp;
}