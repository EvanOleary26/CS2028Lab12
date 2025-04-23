#include "List.h"

template <class T>
List<T>::~List() {
    while (first != nullptr) {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void List<T>::AddItem(T inVal) {
    Reset();        //Reset curLocation if the list is changed
    Node<T>* newNode = new Node<T>(inVal);
    if (first == nullptr) {
        first = newNode;
        last = newNode;
    }
    else {
        Node<T>* temp = first;
        while (temp != nullptr) {
            if (inVal < temp->data) {
                newNode->next = temp;
                newNode->prev = temp->prev;
                if (temp->prev != nullptr) {
                    temp->prev->next = newNode;
                }
                else {
                    first = newNode;
                }
                temp->prev = newNode;
                break;
            }
            else if (temp->next == nullptr) {
                temp->next = newNode;
                newNode->prev = temp;
                last = newNode;
                break;
            }
            temp = temp->next;
        }
    }
    length++;
}


template <class T>
T List<T>::GetItem(T target) {
    Reset();       //Reset curLocation if the list is changed
    Node<T>* temp = first;

    if (first == nullptr) {
        //Check if list is empty
        throw Exception(1, "List is empty");
    }

    if (first->data == target) {
        //Check if the first item in the list is the one that should be removed
        length--;
        if (first->next == nullptr) {
            //If there is only one item in the list
            first = nullptr;
            last = nullptr;
        } else {
            //If there is more than one item in the list
            first = first->next;
            first->prev = nullptr;
        }
        T data = temp->data;
        delete temp;
        return data;
    }

    while (temp != nullptr && temp->data != target) {
        //Move through the list while not at the item to remove or at the end
        temp = temp->next;
    }

    if (temp == nullptr) {
        //Check if the loop got to the end of the list without finding the item
        throw Exception(1, "Item not found");
    }

    if (temp->next != nullptr) {
        //Check if the last item in the list is the target
        temp->next->prev = temp->prev;
    } else {
        //If the last item in the list is the target
        last = temp->prev;
    }
    
    if (temp->prev != nullptr) {
        //Check if the first item in the list is the target
        temp->prev->next = temp->next;
    } else {
        //If the first item in the list is the target
        first = temp->next;
    }
    

    //Connect previous to next and next to previous then return the value of the item removed
    T data = temp->data;
    delete temp;
    length--;
    return data;
}

template <class T>
bool List<T>::IsInList(T target) {
    Node<T>* temp = first;
    if (first == nullptr) {
        //Return false if no items in the list
        return false;
    }

    if (temp->data == target) {
        //Check if the first item is the target
        return true;
    }

    while (temp->next != nullptr) {
        //Continue while not at the end
        temp = temp->next;
        if (temp->data == target) {
            //Stop when the item is found
            return true;
        }
    }
    //Return false if item is not found in loop
    return false;

}

template <class T>
bool List<T>::IsEmpty() {
    return first == nullptr;
}

template <class T>
int List<T>::Size() {
    return length;
}

template <class T>
T List<T>::SeeNext() {
    if (first == nullptr) {
        throw Exception(1, "List is empty");
    }
    if (curLocation == nullptr) {
        curLocation = first;
    }
    else {
        curLocation = curLocation->next;
    }
    if (curLocation == nullptr) {
        throw Exception(1, "Index out of bounds");
    }
    return curLocation->data;
}

template <class T>
T List<T>::SeePrev() {
    if (last == nullptr) {
        throw Exception(1, "List is empty");
    }

    if (curLocation == nullptr) {
        curLocation = last;
    }
    else {
        curLocation = curLocation->prev;
    }

    if (curLocation == nullptr) {
        throw Exception(1, "Index out of bounds");
    }

    return curLocation->data;
}

template <class T>
T List<T>::SeeAt(int target) {
    Node<T>* temp = first;
    for (int i = 0; i < target; i++) {
        temp = temp->next;
        if (temp == nullptr) {
            throw Exception(1, "Index out of bounds");
        }
    }
    curLocation = temp;
    return temp->data;
}
/*
template <class T>
void List<T>::DisplayList() {
    Node<T>* temp = first;
	while (temp != nullptr) {
        temp->data.display();
        temp = temp->next;
        if (temp != nullptr) {
            std::cout << "         |  |" << std::endl;
        }
	}        
}
*/
template <class T>
void List<T>::Reset() {
    curLocation = nullptr;
}

template <class T>
bool List<T>::operator==(const List<T>& right) const {
    return this->first->data == right.first->data;
}

template <class T>
bool List<T>::operator>(const List<T>& right) const {
    return this->first->data > right.first->data;
}

template <class T>
bool List<T>::operator<(const List<T>& right) const {
    return this->first->data < right.first->data;
}


//template class List<Student>;
