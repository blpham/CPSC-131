#include <iostream>
#include <cstdint>
#include <list>
#include <unordered_map>

// The hash table size. This should be a prime number for best performance.
const int TABLE_SIZE = 30;

// The hash function.
// It takes in a hash code and outputs the index in which the data will be stored.
uint64_t hashFunction(uint64_t hashCode) {
  return hashCode % TABLE_SIZE;
}

// The hash table.
std::unordered_map<uint64_t, std::list<int>> table;

int main() {
    // Collision case
    // Array containing values to input into the hashFunction
    int a[] = {11, 15, 6, 12, 22, 8, 4, 13, 17, 9, 20};
    // Loop to print the indices and their values
    for (int i : a) {
        std::cout << "index: " << hashFunction(a[i]) << " value: " << a[i] << std::endl;
    }

    // Non-Collision Case
    // Array containing values to input into the hashFunction
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    // Loop to print the indices and their values
    for (int i : b) {
        std::cout << "index: " << hashFunction(b[i]) << " value: " << b[i] << std::endl;
    }

    return 0;
}
