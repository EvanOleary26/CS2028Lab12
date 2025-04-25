#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "StudentList.h"
#include "SortingAlgorithms.h"
#include "Student.h"

Student createRandomStudent();

template<class T>
T* generateArray(int n);

void runTests(Student *testArr, int size);

typedef std::chrono::high_resolution_clock Clock;

int main() {
    srand(time(0));

    StudentList studentList;
    for (int i{}; i < 50; i++) {
        studentList.AddItem(createRandomStudent());
    }

    int promptChoice;

    std::cout << "How would you like to test?\n" 
              << "1. Arrays of different sizes\n"
              << "2. Linked List of students" << std::endl;
    std::cin >> promptChoice;
    switch(promptChoice) {
        case 1: {
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
        
            // Deallocate memory for all arrays
            for (int i = 0; i < numSizes; ++i) {
                delete[] arrays[i];
            }
            return 0;
        }
        case 2: {
            std::cout << "Created Student List." << std::endl;
            studentList.displayStudents();
            while (true) {
                bool ascending = true;
                std::cout << "Would order would you like to sort in?" << std::endl;
                std::cout << "1. Ascending\n"
                          << "2. Descending" << std::endl;
                std::cin >> promptChoice;
                if (promptChoice == 1) {
                    ascending = true;
                } else {
                    ascending = false;
                }
                std::cout << "What information should be used for sorting the students?" << std::endl;
                std::cout << "1. First Name\n"
                          << "2. Last Name\n"
                          << "3. MNumber" << std::endl;
                std::cin >> promptChoice;
                switch(promptChoice) {
                    case 1: { // Sort by first name
                        studentList.sortUsingFirstName();
                        std::cout << "Now sorting based on students first name using bubble sort." << std::endl;
                        Student* arr = studentList.toArray();
                        bubbleSort(arr, studentList.Size(), ascending);
                        studentList.fromArray(arr);
                        studentList.displayStudents();
                        break;
                    }
                    case 2: { // Sort by last name
                        studentList.sortUsingLastName();
                        std::cout << "Now sorting based on students last name using quick sort." << std::endl;
                        Student* arr = studentList.toArray();
                        quickSort(arr, 0, studentList.Size()-1, ascending);
                        studentList.fromArray(arr);
                        studentList.displayStudents();
                        break;
                    }
                    case 3: { // Sort by MNumber
                        studentList.sortUsingMNumber();
                        std::cout << "Now sorting based on students MNumber using insertion sort." << std::endl;
                        Student* arr = studentList.toArray();
                        insertionSort(arr, studentList.Size(), ascending);
                        studentList.fromArray(arr);
                        studentList.displayStudents();
                        break;
                    }
                }
                std::cout << "Would you like to sort the students again?" << std::endl;
                std::cout << "1. Yes\n"
                          << "2. No" << std::endl;
                std::cin >> promptChoice;
                if (promptChoice == 2) {
                    return 0;
                }
            }
        }
    }
}

Student createRandomStudent() {
    std::string firstNames[] = {"Steve", "Sue", "Mark", "Sarah", "Josh", "Kelly", "Jerry", "Lisa", "Paul", "Rachel"};
    std::string lastNames[] = {"Smith", "Harvey", "North", "Bines", "O'Conner", "Lincoln", "Adams", "Johnson", "Grant", "Trump"};
    std::string majors[] = {"CS", "Biology", "Law", "Art", "Architecture", "Business", "Engineering", "English", "Gamer", "Doctor"};
    
    int randFName = rand() % 10;
    int randLName = rand() % 10;
    int randMNum = (rand() % 1000000) + 10000000;
    int randMaj = rand() % 10;
    
    Student temp(firstNames[randFName], lastNames[randLName], randMNum, majors[randMaj]);
    return temp;
}

template<class T>
T* generateArray(int n) {
    T* arr = new T[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (2 * n + 1);
    } //random number
    return arr;

}

void runTests(Student *testArr, int size) {
        // Create deep copies for each algorithm test
        Student *bubbleArr = new Student[size];
        Student *insertArr = new Student[size];
        Student *mergeArr = new Student[size];
        Student *quickArr = new Student[size];
        Student *countArr = new Student[size];
        Student *radixArr = new Student[size];
        
        // Copy original array to each test array
        for (int i = 0; i < size; i++) {
            bubbleArr[i] = testArr[i];
            insertArr[i] = testArr[i];
            mergeArr[i] = testArr[i];
            quickArr[i] = testArr[i];
            countArr[i] = testArr[i];
            radixArr[i] = testArr[i];
        }

	auto t1 = Clock::now();
	bubbleSort(bubbleArr, size);
	auto t2 = Clock::now();
	std::cout << "Bubble Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000 << " ms" << std::endl;
	
    t1 = Clock::now();
	insertionSort(insertArr, size);
	t2 = Clock::now();
	std::cout << "Insertion Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000 << " ms" << std::endl;
    
    t1 = Clock::now();
    mergeSort(mergeArr, 0, size - 1);
	t2 = Clock::now();
	std::cout << "Merge Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000 << " ms" << std::endl;
	
    t1 = Clock::now();
	quickSort(quickArr, 0, size - 1);
	t2 = Clock::now();
	std::cout << "Quick Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000 << " ms" << std::endl;

    t1 = Clock::now();
	countingSort(countArr, size);
	t2 = Clock::now();
	std::cout << "Counting Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000 << " ms" << std::endl;

    t1 = Clock::now();
	radixSort(radixArr, size);
	t2 = Clock::now();
	std::cout << "Radix Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000 << " ms" << std::endl;

    delete[] bubbleArr;
    delete[] insertArr;
    delete[] mergeArr;
    delete[] quickArr;
    delete[] countArr;
    delete[] radixArr;
}