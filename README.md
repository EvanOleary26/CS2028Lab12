# CS2028Lab12

4/25/25 - EO 2:24PM
- Some Fixes to testing all algorithms
    - Made seperate arrays so we arent trying to sort a sorted array
- Added the ability to sort in ascending or descending order for bubble, quick, and insertion sorts
- Changes to Student to allow for sorting based on different things in student
- Added StudentList.cpp and StudentList.h. These are derived classes of List to allow for ease of creating arrays sorting values then turning it back into a linked list
- Added menu for choosing what the user to make choices
    - Sort using ints and different size arrays (Task 2)
    - Sort using Linked List of students (Task 3)
        - When sorting using students user can choose ascending or descending order
            - User then chooses what they want to sort using first name, last name, or MNumber
                - First name sorts using bubble sort
                - Last name sorts using quick sort
                - MNumber sorts using insertion sort
        - User can then choose to sort using linked list again or end program
