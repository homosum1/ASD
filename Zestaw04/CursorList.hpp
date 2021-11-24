//
//  ArrayStack.hpp
//  stack
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <stdlib.h>
#include <list>
#include <cassert>


template<class Type, int SIZE> class List {
private:
    int listed_elements;
    int head, tail;
    std::list<int> free_indexes;

    typedef struct node {
      Type data;
      int next;
    } LIST_NODE;

    LIST_NODE array[SIZE];

public:
    List() {
        listed_elements = 0;
        head = -1;
        tail = -1;

        for(int i=0; i<SIZE; i++)
          free_indexes.push_back(i);
    }

    ~List() {}

    // dołącza element na początek listy - sprawdzone

    void push_front(Type x) {
      if(listed_elements < SIZE) {

        int free_index = free_indexes.front();
        free_indexes.pop_front();

        array[free_index].data = x;

        if(listed_elements != 0) {
            array[free_index].next = head;
        }
        else
        {
            tail = free_index;
        }

        head = free_index;

        listed_elements++;
      } else
        throw std::out_of_range("out of range - overflow");
    }

    // Usuwa i zwraca element z początku listy - sprawdzone
    Type pop_front() {
      if(listed_elements >= 1) {
        int new_head = array[head].next;
        Type data = array[head].data;

        // uzupełnienie listy wolnych miejsc
        free_indexes.push_front(head);

        head = new_head;
        listed_elements--;

        return data;
      } else
          throw std::out_of_range("out of range - underflow");
    }


    // dołącza element na koniec listy
    void push_back(Type x) {
      if(listed_elements < SIZE) {

        int free_index = free_indexes.front();
        free_indexes.pop_front();

        array[free_index].data = x;

        if(listed_elements != 0) {
          array[tail].next = free_index;
        }
        else
        {
          head = free_index;
        }

        tail = free_index;

        listed_elements++;
      } else
        throw std::out_of_range("out of range - overflow");
    }

    // usuwa i zwraca element z końca listy
    Type pop_back() {
      if(listed_elements >= 1) {
        free_indexes.push_front(tail);
        Type data = array[tail].data;

        if(listed_elements > 1) {
          int index = head;
          for(int i=0; i<(listed_elements-2); i++)
            index = array[index].next;

          tail = index;
        }
        else
        {
          tail = -1;
        }

        listed_elements--;
        return data;
      } else
        throw std::out_of_range("out of range - underflow");
    }

    // zwraca liczbę elementów w liście
    int size() { return listed_elements; }

    // zwraca true gdy lista jest pusta
    bool empty() {
      if(listed_elements == 0)
        return true;
      else
        return false;
    }

    // czyści listę
    void clear() {
      listed_elements = 0;
      head = -1;
      tail = -1;
    }

    // zwraca pozycję pierwszego elementu o wartości x
    int find(Type x) {
      int index = head;
      for(int i=0; i<(listed_elements-1); i++) {
        if(array[index].data == x)
          return i;
        else
          index = array[index].next;
      }
      return -1;
    }

    // usuwa i zwraca element na pozycji i
    Type erase(int i) {
      if(listed_elements > i){

        if(i == 0) {
          return pop_front();
        }
        else if(i == listed_elements-1) {
          return pop_back();
        }
        else {
          int prev_to_searched;
          int index = head;
          for(int j=1; j<=i; j++) {
            prev_to_searched = index;
            index = array[index].next;
          }



          // złączenie poprzedniego elementu z następnym
          array[prev_to_searched].next = array[index].next;

          free_indexes.push_front(index);
          listed_elements--;
          return array[index].data;
        }

      }
      else throw std::out_of_range("index out of range");
    }

    // wstawia element x przed element i
    void insert(int i, Type x) {
      if((i < listed_elements) && (listed_elements < SIZE)){

        if(i == 0) {
          push_front(x);
        }
        else {
          int prev_to_i;
          int i_index = head;
          for(int j=1; j<=i; j++) {
            prev_to_i = i_index;
            i_index = array[i_index].next;
          }

          // znalezienie wolnego miejsca w tablicy
          int free_index = free_indexes.front();
          free_indexes.pop_front();
          // alokacja miejsca w tablicy
          array[free_index].data = x;

          array[prev_to_i].next = free_index;
          array[free_index].next = i_index;

          listed_elements++;
        }
      } else
        throw std::out_of_range("index out of range");
    }

    // usuwa wystąpienia x i zwraca ich liczbę
    int remove(Type x) {
        int index = find(x);
        while(index != -1) {
          erase(index);
          index = find(x);
        }

        return index;
    }

};

#endif /* LinkedList_hpp */
