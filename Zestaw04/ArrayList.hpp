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

template<class Type, int SIZE> class List {
private:
    int queued_elements;
    int tail;

    Type array[SIZE];

public:
    List() {
        tail = 0;
        queued_elements = 0;
    }

    ~List() {}

    // dołącza element na początek listy
    void push_front(Type x) {
      if(queued_elements < SIZE) {
        // przesuń wszystkie elemety o 1 w prawo
        for(int i=(queued_elements-1); i >= 0; i--) {
          array[i+1] = array[i];
        }

        array[0] = x;
        queued_elements++;
      } else
        throw std::out_of_range("out of range - overflow");
    }

    // Usuwa i zwraca element z początku listy
    Type pop_front() {
      if(queued_elements >= 1) {
        Type value = array[0];

        for(int i=0; i<(queued_elements-1); i++) {
          array[i] = array[i+1];
        }

        queued_elements--;
        return value;
      } else
          throw std::out_of_range("out of range - underflow");
    }

    // dołącza element na koniec listy
    void push_back(Type x) {
      if(queued_elements < SIZE) {
        array[queued_elements] = x;
        queued_elements++;
      } else
        throw std::out_of_range("out of range - overflow");
    }

    // usuwa i zwraca element z końca listy
    Type pop_back() {
      if(queued_elements >= 1) {
        queued_elements--;
        return array[queued_elements+1];

      } else
        throw std::out_of_range("out of range - underflow");
    }

    // zwraca liczbę elementów w liście
    int size() { return queued_elements; }

    // zwraca true gdy lista jest pusta
    bool empty() {
      if(queued_elements == 0)
        return true;
      else
        return false;
    }

    // czyści listę
    void clear() { queued_elements = 0; }

    // zwraca pozycję pierwszego elementu o wartości x
    int find(Type x) {
      for(int i=0; i<queued_elements; i++) {
        if(array[i] == x)
          return i;
      }
      return -1;
    }

    // usuwa i zwraca element na pozycji i
    Type erase(int i) {
      if(queued_elements > i){
          Type value = array[i];



          queued_elements--;
          return value;
      } else
          throw std::out_of_range("index out of range");
    }

    // wstawia element x przed element i
    void insert(int i, Type x) {
      if((i < queued_elements) && (queued_elements < SIZE)){
        for(int j=(queued_elements-1); j >= i; j--) {
          array[j+1] = array[j];
        }
        array[i] = x;
        queued_elements++;
      } else
          throw std::out_of_range("index out of range");
    }

    // usuwa wystąpienia x i zwraca ich liczbę
    int remove(Type x) {

    }

};

#endif /* LinkedList_hpp */
