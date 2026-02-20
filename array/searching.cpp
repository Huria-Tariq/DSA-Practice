#include <iostream>
using namespace std;

class ArrayList {
    int arr[100];  // static array
    int n;         // current number of elements

public:
    ArrayList() {
        n = 0;
    }

    void insertEnd(int value) {
        if (n >= 100) {
            cout << "List is full!\n";
            return;
        }
        arr[n++] = value;
    }

    void display() {
        if (n == 0) {
            cout << "List is empty!\n";
            return;
        }
        cout << "Array List: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";  
        }
        cout << endl;
    }

    // ---------------- Linear Search using while loop ----------------
    int linearSearch(int key) {
        int i = 0;
        while (i < n) {
            if (arr[i] == key) {
                return i; // found key at index i
            }
            i++;
        }
        return -1; // key not found
    }
};

int main() {
    ArrayList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.display();

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    int result = list.linearSearch(key);
    if (result != -1)
        cout << key << " found at index " << result << endl;
    else
        cout << key << " not found in the list.\n";

    return 0;
}
