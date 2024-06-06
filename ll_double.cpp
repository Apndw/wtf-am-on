#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next, *prev;
};

class LinkedList {
private:
  Node *head, *tail, *current, *newNode;

  bool isEmpty() {
    return head == nullptr;
  }

  void createNode(const int &data) {
    newNode = new Node();
    newNode->data = data;
    newNode->next = newNode->prev = nullptr;
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

    head->prev = newNode;
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
    newNode->prev = tail;

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
    head->prev = nullptr;

    delete current;
  }

  void removeTail() {
    if (isEmpty()) return;

    if (head == tail) {
      head = tail = nullptr;
      return;
    }

    current = tail;

    tail = tail->prev;
    tail->next = nullptr;

    delete current;
  }

  void showData() {
    if (isEmpty()) return;

    current = head;
    int index = 0;

    do {
      cout << "data ke-" << index << " bernilai " << current->data << endl;

      index++;
      current = current->next;
    } while (current != nullptr);
  }
};

int main() {
  LinkedList ll;

  ll.insertHead(32);
  ll.insertTail(19);
  ll.insertTail(72);

  ll.showData();

  cout << "================" << endl;

  ll.updateHead(93);
  ll.updateTail(53);

  ll.showData();

  cout << "================" << endl;

  ll.removeHead();
  ll.removeTail();

  ll.showData();

  cout << "================" << endl;
}