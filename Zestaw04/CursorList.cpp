
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cassert>
#include <sstream>


#include "CursorList.hpp"

#define LIMIT 1000

int main(int argc, char* argv[])
{
  using namespace std;

  stringstream result;
  const char push_front = 'F', push_back = 'B', delete_first = 'f', delete_last = 'b', check_replace = 'R', size = 'S';

  string buffor;
  getline(cin, buffor);
  const int operations_cnt = stoi(buffor);
  // assert(operations_cnt <= LIMIT);

  List<int, LIMIT> my_list;

  for(int i=0; i<operations_cnt; i++) {
    string var;
    getline(cin, var);
    char command_check = var.at(0);


    switch (command_check) {
      case push_front: {
        // dodaj element na początek listy
        string inserted_value = var.substr(2, (var.size()-1) );
        my_list.push_front(stoi(inserted_value));
        break;
      }
      case push_back: {
        // dodaj element na koniec listy
        string inserted_value = var.substr(2, (var.size()-1) );
        my_list.push_back(stoi(inserted_value));
        break;
      }
      case delete_first: {
        // usuń pierwszy element z listy i go wypisz, jak lista jest pusta wipisz "EMPTY"
        if(my_list.empty())
          cout << "EMPTY\n";
        else {
          int element = my_list.pop_front();
          cout << element << endl;
        }
        break;
      }
      case delete_last: {
        // usuń ostatni element z listy i go wypisz, jak lista jest pusta wipisz "EMPTY"
        if(my_list.empty())
          cout << "EMPTY\n";
        else {
          int element = my_list.pop_back();
          cout << element << endl;
        }
        break;
      }
      case check_replace: {
        // jeżeli x nie jest obecny w liście wypisz FALSE, w przeciwnym razie zastąp jego pierwsze wystąpienie przez
        // y i wypisz true
        stringstream ss(var);
        string array[3];
        string buffer;
        int a = 0;
        while(ss >> buffer) {
          array[a] = buffer;
          a++;
        }

        int x = stoi(array[1]), y = stoi(array[2]);

        int index = my_list.find(x);
        if(index == -1){
          cout << "FALSE\n";
        }else {
          // usunięcie elementu o indeksie "index"
          int erased_num = my_list.erase(index);
          assert(erased_num == x);
          // wstawienei elementu na miejsce elementu index
          my_list.insert(index, y);
          cout << "TRUE\n";
        }
        break;
      }
      case size: {
          cout << my_list.size() << endl;
          break;
      }

    }

  }

  cout << result.str();
  return 0;
}
