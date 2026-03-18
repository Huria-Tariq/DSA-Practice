#include <iostream>
#include <cstring>  // For strcpy, strcat
using namespace std;

// ----------------- Custom Stack Node -----------------
struct Node {
    char* data;
    Node* next;
    Node(const char* val) {
        data = new char[strlen(val) + 1];
        strcpy(data, val);
        next = nullptr;
    }
    ~Node() {
        delete[] data;
    }
};

// ----------------- Custom Stack -----------------
class Stack {
private:
    Node* topNode;
    int size;
public:
    Stack() : topNode(nullptr), size(0) {}

    void push(const char* val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
            size--;
        }
    }

    char* top() {
        if (topNode) return topNode->data;
        return nullptr;
    }

    bool empty() {
        return topNode == nullptr;
    }

    int getSize() {
        return size;
    }

    void removeBottom() {
        if (!topNode) return;
        if (!topNode->next) {
            delete topNode;
            topNode = nullptr;
            size--;
            return;
        }
        Node* curr = topNode;
        while (curr->next->next) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        size--;
    }
};

// ----------------- TextEditor -----------------
class TextEditor {
private:
    char content[1000];   // Max content size
    Stack undoStack;
    Stack redoStack;
    const int MAX_UNDO = 100;

public:
    TextEditor() { content[0] = '\0'; }

    void write(const char* text) {
        // Limit undo stack size
        if (undoStack.getSize() == MAX_UNDO) undoStack.removeBottom();
        undoStack.push(content);           // save current state

        // Append new text
        strcat(content, text);

        // Clear redo stack
        while (!redoStack.empty()) redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(content);       // save current state
            strcpy(content, undoStack.top());
            undoStack.pop();
        } else {
            cout << "Nothing to undo!\n";
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(content);       // save current state
            strcpy(content, redoStack.top());
            redoStack.pop();
        } else {
            cout << "Nothing to redo!\n";
        }
    }

    void display() {
        cout << "Editor Content: \"" << content << "\"\n";
    }
};

// ----------------- MAIN -----------------
int main() {
    TextEditor editor;

    editor.write("Hello");
    editor.display();

    editor.write(" World");
    editor.display();

    editor.undo();
    editor.display();

    editor.redo();
    editor.display();

    return 0;
}

