#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class LinkedList {
private:
  Node *head, *tail, *current, *newNode, *temp;

  bool isEmpty() {
    return head == nullptr;
  }

  void createNode(const int &data) {
    newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
  }

  void initNode() {
    head = tail = newNode;
  }

public:
  LinkedList() {
    head = tail = nullptr;
  }

  void insertHead(const int &data) {
    createNode(data);

    if (isEmpty()) {
      initNode();
      return;
    }

    newNode->next = head;
    head = newNode;
  }

  void insertTail(const int &data) {
    createNode(data);

    if (isEmpty()) {
      initNode();
      return;
    }

    tail->next = newNode;
    tail = newNode;
  }

  void updateHead(const int &data) {
    if (isEmpty()) return;

    head->data = data;
  }

  void updateTail(const int &data) {
    if (isEmpty()) return;

    tail->data = data;
  }

  void removeHead() {
    if (isEmpty()) return;

    if (head == tail) {
      head = tail = nullptr;
      return;
    }

    current = head;
    head = head->next;
    delete current;
  }

  void removeTail() {
    if (isEmpty()) return;

    if (head == tail) {
      head = tail = nullptr;
      return;
    }

    current = head;
    temp = tail;

    while (current->next != tail) {
      current = current->next;
    }

    tail = current;
    tail->next = nullptr;

    delete temp;
  }

  void showData() {
    if (isEmpty()) return;

    current = head;

    int index = 0;

    do {
      cout << "Data ke-" << index << " bernilai " << current->data << endl;

      index++;
      current = current->next;
    } while (current != nullptr);
  }
};

int main() {
  LinkedList ll;

  ll.insertHead(12);
  ll.insertTail(32);
  ll.insertTail(45);

  ll.showData();

  cout << "=================" << endl;

  ll.updateHead(75);
  ll.updateTail(93);

  ll.showData();

  cout << "=================" << endl;

  ll.removeHead();
  ll.removeTail();

  ll.showData();

  cout << "=================" << endl;
}