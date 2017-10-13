#ifndef LIST_H
#define LIST_H
class List {
   struct Node{
     int data;
     Node* next;
     Node* prev;
   };
   Node* head;
   Node* teil;
   int length;
public:
  List();
  void push(int);
  void pushFront(int);
  void print();
  void printRev();
  List sum(const List& list1,const List& list2);
  List sub(const List& list1,const List& list2);
};
#endif
