#include "StudentList.h"

void StudentList::sortUsingFirstName() {
    if (first == nullptr) return;
    first->data.sortByFirstName();
}

void StudentList::sortUsingLastName() {
    if (first == nullptr) return;
    first->data.sortByLastName();
}

void StudentList::sortUsingMNumber() {
    if (first == nullptr) return;
    first->data.sortByMNumber();
}

void StudentList::displayStudents() const {
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(26) << std::right << "Student List" << std::setw(26) << "" << "|" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    
    Node<Student>* temp = first;  // Direct access to protected 'first' member
    int index = 1;
    
    // Iterate through the list directly
    while (temp != nullptr) {
        // Format output
        std::cout << "| " << std::left << std::setw(2) << index++ << " | ";
        std::cout << std::left << std::setw(15) << temp->data.getFirstName() << " | ";
        std::cout << std::left << std::setw(15) << temp->data.getLastName() << " | ";
        std::cout << "m" << temp->data.getMNumber() << " |" << std::endl;
        
        temp = temp->next;
    }
    
    std::cout << "------------------------------------------------------" << std::endl;
}

// Convert linked list to array for sorting
Student* StudentList::toArray() {
    if (length == 0) return nullptr;
    
    Student* arr = new Student[length];
    Node<Student>* temp = first;
    int i = 0;
    
    while (temp != nullptr) {
        arr[i] = temp->data;
        i++;
        temp = temp->next;
    }
    
    return arr;
}

// Rebuild linked list from sorted array
void StudentList::fromArray(Student* arr) {
    // Clear existing list
    Node<Student>* temp = first;
    while (temp != nullptr) {
        Node<Student>* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    
    first = nullptr;
    last = nullptr;
    
    // Rebuild list from array
    for (int i = 0; i < length; i++) {
        Node<Student>* newNode = new Node<Student>(arr[i]);
        
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }

    delete[] arr;
}
