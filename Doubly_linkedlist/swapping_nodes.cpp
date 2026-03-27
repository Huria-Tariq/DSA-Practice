 /*void swapNodes(int x, int y) { 
        if (x == y) return; // No need to swap same values 
 
        Node *node1 = NULL, *node2 = NULL, *temp = head; 
 
        // Find both nodes 
        while (temp != NULL) { 
            if (temp->data == x) 
                node1 = temp; 
            else if (temp->data == y) 
                node2 = temp; 
            temp = temp->next; 
        } 
 
        if (node1 == NULL || node2 == NULL) { 
            cout << "One or both values not found!\n"; 
            return; 
        } 

        
    // if node1 has a previous node
    if (node1->prev)
        node1->prev->next = node2;
    else
        head = node2; // if node1 was head

    // if node2 has a previous node
    if (node2->prev)
        node2->prev->next = node1;
    else
        head = node1; // if node2 was head

    // if node1 has a next node
    if (node1->next)
        node1->next->prev = node2;

    // if node2 has a next node
    if (node2->next)
        node2->next->prev = node1;

    // 🧠 swap their next pointers
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    // 🧠 swap their prev pointers
    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;
}
*/