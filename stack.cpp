#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class Stack {
private:
  Node *top, *current, *newNode;

  bool isEmpty() {
    return top == nullptr;
  }

public:
  Stack() {
    top = nullptr;
  }

  void push(const int &data) {
    newNode = new Node();
    newNode->data = data;
    newNode->next = top;

    top = newNode;
  }

  void pop() {
    if (isEmpty()) return;

    current = top;
    top = top->next;

    delete current;
  }

  void peek() {
    if (isEmpty()) return;

    cout << "Data teratas bernilai " << top->data << endl;
  }

  void showData() {
    if (isEmpty()) return;

    current = top;

    int index = 0;

    do {
      cout << "data ke-" << index << " bernilai " << current->data << endl;

      index++;
      current = current->next;
    } while (current != nullptr);
  }
};

int main() {
  Stack s;

  s.push(23);
  s.push(75);
  s.push(42);

  s.peek();

  s.showData();

  cout << "==========" << endl;

  s.pop();

  s.peek();

  s.showData();

  cout << "==========" << endl;

  s.pop();

  s.peek();

  s.showData();

  cout << "==========" << endl;
}