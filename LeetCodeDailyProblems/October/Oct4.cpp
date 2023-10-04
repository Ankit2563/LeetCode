
// 706. Design HashMap

    // Design a HashMap without using any built-in hash table libraries.

    // Implement the MyHashMap class:

    // MyHashMap() initializes the object with an empty map.
    // void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
    // int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    // void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
public:
    int arr[100];//Taken size small now bt in question takes 100001 size
    MyHashMap()
    {
        fill(arr, arr + 100, -1); //fill function used to fill the array
    }
    void put(int key, int val)
    {
        arr[key] = val;
    }
    int get(int key)
    {
        return arr[key];
    }
    void remove(int key)
    {
        arr[key] = -1;
    }
};

int main()
{
    
    MyHashMap m;
    cout << m.get(43) << endl;
    m.put(10, 3);
    m.put(4, 6);
    cout << m.get(10)<<endl;
    m.put(10, 9);
    cout << m.get(10)<<endl;
    m.put(3, 35);
    cout << m.get(3) << endl;
    m.put(10, 4);

    return 0;
}
