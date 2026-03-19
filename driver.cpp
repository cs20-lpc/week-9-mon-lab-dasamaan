#include "LinkedQueue.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "=== Testing int queue ===\n";

    LinkedQueue<int> q;

    // Here I am testing empty queue behavior
    try {
        q.front();
    } catch (string& e) {
        cout << e << endl;
    }

    try {
        q.back();
    } catch (string& e) {
        cout << e << endl;
    }

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Length: " << q.getLength() << endl;
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    // Dequeue one
    q.dequeue();
    cout << "\nAfter dequeue:\n";
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    // Dequeue all
    q.dequeue();
    q.dequeue();

    cout << "\nAfter removing all:\n";
    cout << "Length: " << q.getLength() << endl;

    // Here I am testing dequeue on empty
    try {
        q.dequeue();
    } catch (string& e) {
        cout << e << endl;
    }

    cout << "\n=== Testing copy constructor ===\n";

    LinkedQueue<int> q2;
    for (int i = 1; i <= 5; i++) {
        q2.enqueue(i * 10);
    }

    LinkedQueue<int> copyQ(q2);

    cout << "Original front: " << q2.front() << endl;
    cout << "Copy front: " << copyQ.front() << endl;

    q2.dequeue();

    cout << "After modifying original:\n";
    cout << "Original front: " << q2.front() << endl;
    cout << "Copy front (should NOT change): " << copyQ.front() << endl;

    cout << "\n=== Testing assignment operator ===\n";

    LinkedQueue<int> q3;
    q3 = q2;

    cout << "Assigned front: " << q3.front() << endl;

    cout << "\n=== Testing clear() ===\n";

    q3.clear();
    cout << "Length after clear: " << q3.getLength() << endl;

    cout << "\n=== Testing string queue ===\n";

    LinkedQueue<string> qs;
    qs.enqueue("apple");
    qs.enqueue("banana");
    qs.enqueue("cherry");

    cout << "Front: " << qs.front() << endl;
    cout << "Back: " << qs.back() << endl;

    qs.dequeue();
    cout << "After dequeue, front: " << qs.front() << endl;

    return 0;
}