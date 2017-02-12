// Jiaqi Luo
// hw5, main.cpp
// this file contaion the main function

#include "graph.h"
using namespace std;

int main() {
  graph temp;
  temp.display_all();

  temp.load_file();
  temp.display_all();
  char temp1[ARRAY];
  cout << "enter the intersection: ";
  cin.get(temp1, ARRAY, '\n');
  cin.ignore(100, '\n');
  temp.display_vertex(temp1);

  char temp2[ARRAY];
  cout << "enter where you are: ";
  cin.get(temp2, ARRAY, '\n');
  cin.ignore(100, '\n');
  temp.display_route(temp2);
  return 0;
}
