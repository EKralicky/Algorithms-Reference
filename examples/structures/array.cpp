#include <iostream>

//============================
// Fundamental C++ array operations
//============================
void fundamentals() {
    // Create an array of size n. In this example n is 10
    // It is illegal in C++ to intialize an array with a non-const value
    int arr[10];

    // Initialize an array with elements
    int elem[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Get the first/last element
    int first = elem[0];
    int last  = elem[-1];

    // Get array size. Divides the total byte size of the array by the byte size of the array type
    std::size_t  size = sizeof(arr)/sizeof(int);
}



namespace DataStructures {
    
    class Array {
    public:
    private:
    }
}





