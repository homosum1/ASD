
#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>
#include <unistd.h>

#define RANGE 1000
#define T_RANGE 6

// /Users/alexander/Desktop/Aleksander_Kotarski_Zestaw01/Stack.x

int main(int argc, char* argv[])
{
    using namespace std;

    // pozyskanie losowej liczby ze sprzętu
    random_device random_d;
    // seedowanie generatora
    mt19937 gen(random_d());
    // definiowanie zasięgu losowania
    uniform_int_distribution<> distr_num(1, RANGE);
    uniform_int_distribution<> distr_tasks(1, 6);

    int operations_count = distr_num(gen);
    string result = to_string(operations_count) + "\n";

    int command = 0;
    for(int i=0; i<operations_count; i++ ) {
      command = distr_tasks(gen);
      string generated_num = to_string(distr_num(gen));
      switch(command){
        case 1: {
          result.append("F " + generated_num);
          break;
        }
        case 2: {
          result.append("B " + generated_num);
          break;
        }
        case 3: {
          result.append("f");
          break;
        }
        case 4: {
          result.append("b");
          break;
        }
        case 5: {
          result.append("R " + generated_num + " " + to_string(distr_num(gen)) );
          break;
        }
        case 6: {
          result.append("S");
          break;
        }
      }

      result.append("\n");
    }
    cout << result << endl;
    return 0;
}
