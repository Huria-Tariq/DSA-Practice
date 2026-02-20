#include <iostream>
using namespace std;

class ArrayList {
    int* arr;     
    int n;        
    int capacity; 

public:
    ArrayList() {
        capacity = 2;        
        arr = new int[capacity];
        n = 0;
    }

    
    void resize() {
        capacity *= 2;                  
        int* newArr = new int[capacity];
        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];      
        }
        delete[] arr;                  
        arr = newArr;
    }

    // 1. Insert at end
    void insertEnd(int value) {
        if (n == capacity) resize();
        arr[n] = value;
        n++;
    }

    // 2. Insert at start
    void insertStart(int value) {
        if (n == capacity) resize();
        for (int i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        n++;
    }

    // 3. Insert after specific value
    void insertAfter(int key, int value) {
        if (n == capacity) resize();
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                for (int j = n; j > i + 1; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[i + 1] = value;
                n++;
                return;
            }
        }
        cout << "Value not found!\n";
    }

    // 4. Insert before specific value
    void insertBefore(int key, int value) {
        if (n == capacity) resize();
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                for (int j = n; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[i] = value;
                n++;
                return;
            }
        }
        cout << "Value not found!\n";
    }

    // 5. Display
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

    // 6. Delete from end
    void deleteEnd() {
        if (n > 0) n--;
        else cout << "List is empty!\n";
    }

    // 7. Delete from start
    void deleteStart() {
        if (n > 0) {
            for (int i = 0; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        } else cout << "List is empty!\n";
    }

    // 8. Delete specific value
    void deleteValue(int key) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                for (int j = i; j < n - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                n--;
                return;
            }
        }
        cout << "Value not found!\n";
    }

    // destructor to free memory
    ~ArrayList() {
        delete[] arr;
    }
};


int main() {
    ArrayList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.display();

    list.insertStart(5);
    list.display();

    list.insertAfter(20, 25);
    list.display();

    list.insertBefore(30, 28);
    list.display();

    list.deleteEnd();
    list.display();

    list.deleteStart();
    list.display();

    list.deleteValue(25);
    list.display();

    return 0;
}