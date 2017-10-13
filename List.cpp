#include<iostream>
#include"List.h"
List::List(){
   this->head = nullptr;
   this->teil = nullptr;
   this->length = 0;
 }
 void List::push(int element){
   Node* node = new Node();
   if(head == nullptr){
     head = node;
     teil = node;
     head->data = element;
     head->next = nullptr;
     teil->prev = nullptr;
     this->length++;
     return;
   }
   Node* currentNode = head;
   while(currentNode->next != nullptr){
     currentNode->next->prev = currentNode;
     currentNode = currentNode->next;
   }
   currentNode->next = node;
   teil = currentNode->next;
   currentNode->next->prev = currentNode;
   currentNode->next->data = element;
   this->length++;
   return;
 }

 void List::pushFront(int element){
    Node* node = new Node();
    if(head == nullptr){
      head = node;
      teil = node;
      head->data = element;
      head->next = nullptr;
      teil->prev = nullptr;
      this->length++;
      return;
   }
   Node* currentNode = head;
   head = node;
   head->data = element;
   head->prev = nullptr;
   head->next = currentNode;
   head->next->prev = head;
   this->length++;
   return;
 }

 void List::print() {
   try{
     if(head == nullptr) {
       throw "Error";
     }
     Node* currentNode = head;
     while(currentNode != nullptr){
       std::cout<<currentNode->data;
       currentNode = currentNode->next;
     }
   }
   catch(const char* x){
     std::cout<<x<<": invalid linked list";
     exit(EXIT_FAILURE);
   }
 }


 void List::printRev() {
   try{
     if(teil == nullptr) {
       throw "Error";
     }
     Node* currentNode = teil;
     while(currentNode != nullptr){
       std::cout<<currentNode->data;
       currentNode = currentNode->prev;
     }
   }
   catch(const char* x){
     std::cout<<x<<": invalid linked list";
     exit(EXIT_FAILURE);
   }
 }

 ///////////////////  operation sum   //////////////////////

 List List::sum(const List& list1,const List& list2) {
  if(!list1.teil && list2.teil){
     return list2;
  }
  if(list1.teil && !list2.teil){
   return list1;
  }
  try{
    if(!list1.teil && !list2.teil){
      throw "Error";
    }
  }
   catch(const char* x){
    std::cout<<x<<": invalid BigInteger objects";
    exit(EXIT_FAILURE);
   }
   int max_length = 0;
   if(list1.length >= list2.length) {
      max_length = list1.length;
   }
   else {
      max_length = list2.length;
   }
   int transfer = 0;
   int tmp_data1;
   int tmp_data2;
   List list3;
   Node* node1 = list1.teil;
   Node* node2 = list2.teil;
   tmp_data1 = node1->data;
   tmp_data2 = node2->data;
   for(int i = max_length - 1; i >=0  ; --i){
      if(tmp_data1 + tmp_data2 + transfer < 10){
        list3.pushFront(tmp_data1 + tmp_data2 + transfer);
         transfer = 0;
          if(node1->prev){
            node1 = node1->prev ;
            tmp_data1 = node1->data;
          }
         else{
            node1->prev = nullptr;
            tmp_data1 = 0;
          }
         if(node2->prev){
          node2 = node2->prev ;
          tmp_data2 = node2->data;
          }
         else{
            node2->prev = nullptr;
            tmp_data2 = 0;
        }
      }
       else {
         list3.pushFront(tmp_data1 + tmp_data2 + transfer - 10);
         transfer = 0;
         transfer++;
          if(node1->prev){
            node1 = node1->prev ;
            tmp_data1 = node1->data;
           }
          else{
            node1->prev = nullptr;
            tmp_data1 = 0;
           }
          if(node2->prev){
          node2 = node2->prev ;
          tmp_data2 = node2->data;
          }
          else{
            node2->prev = nullptr;
            tmp_data2 = 0;
          }
         if(i == 0 && transfer > 0){
            list3.pushFront(transfer);
         }
       }
     }
   return list3;
}

 ////////////  subtraction's operation    //////////////

 List List::sub(const List& list1,const List& list2) {
   int max_length = 0;
   List nvazeli;//I can't find english version of nvazeli
   List haneli; //I can't find english version of haneli
   bool nshan;
   if(list1.length > list2.length) {
       max_length = list1.length;
       nvazeli = list1;
       haneli = list2;
       nshan = true;
    }
    else if(list1.length < list2.length) {
       max_length = list2.length;
       nvazeli = list2;
       haneli = list1;
       nshan = false;
    }
    else {
      max_length = list1.length;
      Node* node1_head = list1.head;
      Node* node2_head = list2.head;
      for(int i = 0; i < max_length; ++i){
        if(node1_head->data == node2_head->data){
          node1_head = node1_head->next;
          node2_head = node2_head->next;
        }
        else if(node1_head->data > node2_head->data){
         nvazeli = list1;
         haneli = list2;
         nshan = true;
         break;
        }
        else if(node1_head->data < node2_head->data){
         nvazeli = list2;
         haneli = list1;
         nshan = false;
         break;
        }
      }
    }
    List list4;
    if(!nvazeli.head){
        list4.pushFront(0);
        return list4;
    }
    Node* node1 = nvazeli.teil;
    Node* node2 = haneli.teil;
    int tmp_data1;
    int tmp_data2;
    for(int i = max_length-1; i >= 0; --i){
      tmp_data1 = node1->data;
      tmp_data2 = node2->data;
      if(tmp_data1 >= tmp_data2){
         if(i == 0 && nshan == false)
           list4.pushFront((tmp_data1 - tmp_data2)*(-1));
         else
           list4.pushFront(tmp_data1 - tmp_data2);
        if(node2->prev){
           node2 = node2->prev ;
           node1 = node1->prev;
        }
        else{
           node2->prev = nullptr;
           node2->data = 0;
           if(node1->prev)
           node1 = node1->prev;

        }
      }
      else{
        Node* currentNode = node1;
        while(currentNode->prev){
          currentNode = currentNode->prev;
          if(currentNode->data > 0){
            currentNode->data--;
            break;
          }
        }
        while(currentNode->next != node1){
          currentNode = currentNode->next;
          currentNode->data += 9;
        }
         if(i == 0 && nshan == false)
           list4.pushFront((tmp_data1 + 10 - tmp_data2)*(-1));
         else
           list4.pushFront(tmp_data1 + 10 - tmp_data2);
         if(node2->prev){
           node2 = node2->prev ;
           node1 = node1->prev;
        }
        else{
           node2->prev = nullptr;
           if(node1->prev)
           node1 = node1->prev;
           node2->data = 0;
        }
      }
    }
    if(list4.head->data == 0){
      Node* tmp_node;
      while(list4.head->data == 0 && list4.head != list4.teil){
        tmp_node = list4.head;
        list4.head = list4.head->next;
        tmp_node->next = nullptr;
        delete tmp_node;
      }
      if(nshan == false){
        list4.head->data = -1* list4.head->data;
      }
    }
    return list4;
 }
