#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class Queue {
private:
  Node *front, *back, *current, *newNode;

  bool isEmpty() {
    return ((front == nullptr) && (back == nullptr));
  }

public:
  Queue() {
    front = back = nullptr;
  }

  void enqueue(const int &data) {
    newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
      front = back = newNode;
      return;
    }

    back->next = newNode;
    back = newNode;
  }

  void dequeue() {
    if (isEmpty()) return;

    current = front;
    front = front->next;

    delete current;
  }

  void peek() {
    if (isEmpty()) return;

    cout << "data teratas bernilai " << front->data << endl;
  }

  void showData() {
    if (isEmpty()) return;

    current = front;

    int index = 0;

    do {
      cout << "data ke-" << index << " bernilai " << current->data << endl;

      index++;
      current = current->next;
    } while (current != nullptr);
  }
};

int main() {
  Queue q;

  q.enqueue(25);
  q.enqueue(63);
  q.enqueue(79);

  q.peek();

  q.showData();

  cout << "===============" << endl;

  q.dequeue();

  q.peek();

  q.showData();

  cout << "===============" << endl;

  q.dequeue();

  q.peek();

  q.showData();

  cout << "===============" << endl;
}