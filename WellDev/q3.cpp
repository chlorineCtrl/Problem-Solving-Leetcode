#include <iostream>
#include <stack>
using namespace std;

// Function to delete the middle element of the stack
void deleteMiddleElement(stack<int>& s, int middle) {
    // Base case: if we have reached the middle element
    if (middle == 0) {
        s.pop(); // Remove the middle element
        return;
    }

    // Get the top element and remove it temporarily
    int top = s.top();
    s.pop();

    // Recur for the next element, decrementing middle by 1
    deleteMiddleElement(s, middle - 1);

    // Push the top element back after the middle element is removed
    s.push(top);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int n = s.size();
    int middle = n / 2; // Find the index of the middle element (0-based)

    // Delete the middle element
    deleteMiddleElement(s, middle);

    // Print the stack elements after deleting the middle element
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
