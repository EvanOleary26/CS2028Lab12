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
T* countingSort(T arr[]);

template <class T>
void radixSort(T arr[], int arrSize);

Student createRandomStudent();

typedef std::chrono::high_resolution_clock Clock;

int main() {

    auto t1 = Clock::now();
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

    //test
    Student testArr[] = { Student(2),Student(5),Student(7),Student(1),Student(3)};
    int arrSize = sizeof(testArr)/sizeof(testArr[0]);

    Student bubbleTest[5] = { Student(2),Student(5),Student(7),Student(1),Student(3) };
    auto bs1 = Clock::now();
    bubbleSort(bubbleTest, arrSize);
    auto bs2 = Clock::now();
    std::cout << "Bubble Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(bs2 - bs1).count() << " nanoseconds" << std::endl;

    Student InsertTest[5] = {Student(2),Student(5),Student(7),Student(1),Student(3)};
    auto is1 = Clock::now();
    insertionSort(InsertTest, arrSize);
    auto is2 = Clock::now();
    std::cout << "Insertion Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(is2 - is1).count() << " nanoseconds" << std::endl;

    Student CountTest[5] = {Student(2),Student(5),Student(7),Student(1),Student(3)};
    auto cs1 = Clock::now();
    countingSort(CountTest, arrSize);
    auto cs2 = Clock::now();
    std::cout << "Counting sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(cs2 - cs1).count() << " nanoseconds" << std::endl;


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