#include <iostream>
#include <list>

class HashTable {
    // number of buckets (indices)
	int NUM_BUCKETS;

	// pointer to a linked list of buckets and values
	std::list<int> *table;
public:
    // constructor
	HashTable(int V);

	// inserts key (x) into hash table
	void insert(int x);

	// hash function
	int hashFunction(int x) {
		return (x % NUM_BUCKETS);
	}

    // prints contents of the hash table
	void printTable();
};

HashTable::HashTable(int b) {
	this->NUM_BUCKETS = b;
	table = new std::list<int>[NUM_BUCKETS];
}

void HashTable::insert(int key) {
	int i = hashFunction(key);
	table[i].push_back(key);
}

void HashTable::printTable() {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        std::cout << "key: " << i << " - value(s): ";
        for (auto x : table[i]) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    /* Collision Case */
    // array with keys to be intputted into hash table
    int a[] = {11, 34, 23, 45, 6, 12, 10, 4, 14, 7, 18};
    int n1 = sizeof(a)/sizeof(a[0]);

    // insert keys into the hash table
    HashTable h1(5);
    for (int i = 0; i < n1; i++) {
        h1.insert(a[i]);
    }

    std::cout << "Collision Case Output:" << std::endl;
    // print contents of table
    h1.printTable();
    std::cout << std::endl;

    /* Non-Collision Case */
    // array with values to be intputted into hash table
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n2 = sizeof(b)/sizeof(b[0]);

    // insert the keys into the hash table
    HashTable h2(11);
    for (int i = 0; i < n2; i++) {
        h2.insert(b[i]);
    }

    std::cout << "Non-Collision Case Output:" << std::endl;
    // print contents of hash table
    h2.printTable();
    std::cout << std::endl;

    return 0;
}