// Jiaqi Luo
// hw5, graph.cpp
// there are the functions of the graph class
#include "graph.h"
using namespace std;

// constructor
graph::graph() {
  list_size = 0;
  list = new vertex *[SIZE];
  for (int i = 0; i < SIZE; ++i)
    list[i] = NULL;
}

// distructor
graph::~graph() {
  for (int i = 0; i < SIZE; ++i) {
    node *temp = list[i]->head;
    while (temp) {
      delete temp->street;
      temp->street = NULL;
      delete temp;
      temp = temp->next;
    }
    delete list[i]->intersection;
    list[i]->intersection = NULL;
    delete list[i];
    list[i] = NULL;
  }
}

// load a file into the graph,
// each time to load in a pair of information into an
// temparary struct(ie. collection) and then insert the
// collection into graph,
// return 1 if success,
// otehrwise return 0
int graph::load_file() {
  collection temp;
  ifstream file_in;
  file_in.open("source.txt");
  if (file_in) {
    file_in.get(temp.point1, ARRAY, ',');
    while (!file_in.eof()) {
      file_in.ignore(ARRAY, ',');
      file_in.get(temp.point2, ARRAY, ',');
      file_in.ignore(ARRAY, ',');
      file_in.get(temp.road, ARRAY, '\n');
      file_in.ignore(SIZE, '\n');
      insert(temp, list_size);
      file_in.get(temp.point1, ARRAY, ',');
    }
    file_in.close();
    return 1;
  } else
    return 0;
}

// insert a collection of data into graph,
// firsty, check the array of vetex
// to see if the two intersections exists,
// get the index whatever, and then insert it
// on that position
// finally return 1.
int graph::insert(collection &source, int &index) {
  int index1 = check(source.point1, index);
  int index2 = check(source.point2, index);
  if (index1 == -1) {
    insert_intersection(source.point1, index);
    index1 = index;
    ++index;
  }
  if (index2 == -1) {
    insert_intersection(source.point2, index);
    index2 = index;
    ++index;
  }
  insert_lll(index1, index2, source.road);
  return 1;
}

// check whtehr the intersection exists in the array of vertex
// if it exists, return the index,
// else return -1.
// the size is the size of the array.
int graph::check(char *source, int &size) {
  for (int i = 0; i < size; ++i) {
    if (strcmp(list[i]->intersection, source) == 0)
      return i;
  }
  return -1;
}

// insert the source into the array of vertex with a particular index
// return 1 finally
int graph::insert_intersection(char *source, int index) {
  list[index] = new vertex;
  list[index]->intersection = new char[strlen(source) + 1];
  strcpy(list[index]->intersection, source);
  return 1;
}

// add the intersection whhich index is index2 in the arary of vertex
// in the head of the linear linked list
// in the vertex which index is index1,
// return 1 finally.
int graph::insert_lll(int index1, int index2, char *source) {
  node *temp = new node;
  temp->street = new char[strlen(source) + 1];
  strcpy(temp->street, source);
  temp->adjacency = list[index2];
  temp->next = list[index1]->head;
  list[index1]->head = temp;
  return 1;
}

// display all the vertex in the array of vertex
// return 1 finally.
int graph::display_all() {
  cout << "----- display all --------" << endl;
  for (int i = 0; i < list_size; ++i) {
    cout << list[i]->intersection << endl;
  }
  cout << "----- display all end --------" << endl;
  return 1;
}

// display the information of inside a particular vertex
// by invoking a coresponding function
// reuturn 1 finally
int graph::display_vertex(char intersection[]) {
  for (int i = 0; i < list_size; ++i) {
    if (strcmp(intersection, list[i]->intersection) == 0)
      display_lll(list[i]->head);
  }
  return 1;
}

// display all the information inside a linear linked list
// from head to the end,
// call itself recursively
int graph::display_lll(node *head) {
  if (!head)
    return 0;
  cout << "goes to  '" << head->adjacency->intersection << "' though '"
       << head->street << "'" << endl;
  display_lll(head->next);
}

// display the route from a particlar intersection to Porland
// which is assumpted as intersection1,
// locate the intersection first and display all the intersection reachable
// return 1 finally.
int graph::display_route(char intersection[]) {
  for (int i = 0; i < list_size; ++i) {
    if (strcmp(intersection, list[i]->intersection) == 0)
      dft(list[i]);
  }
  return 1;
}

// display all the intersection which the current can go to,
// everytime arrive a new intersection, mark it as visited,
// and display the information inside,
// and go to the next one recursively
// stop until display all the rount or arrive Portland
int graph::dft(vertex *current) {
  clear_flag();
  if (!current)
    return 0;
  current->flag = 1;
  cout << current->intersection << " -- ";
  if (strcmp(current->intersection, "intersection 1") == 0)
    return 1;
  for (node *temp = current->head; temp != NULL; temp = temp->next) {
    if (temp->adjacency->flag == 0) {
      if (dft(temp->adjacency) == 1)
        return 1;
    }
  }
}

// set all flages to 0, return 1 finally
int graph::clear_flag() {
  for (int i = 0; i < list_size; ++i)
    list[i]->flag = 0;
  return 1;
}
