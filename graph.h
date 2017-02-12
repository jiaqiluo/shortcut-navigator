// Jiaqi Luo
// hw5, graph.h
// this file contains the declaration of
// struct vertex, collection, node and the class graph
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>

int const SIZE = 5;   // the size of the array of vertex in graph
int const ARRAY = 50; // the size of array of characters

struct vertex {
  char *intersection;
  int flag;
  struct node *head;
};

struct collection {
  char point1[ARRAY];
  char point2[ARRAY];
  char road[ARRAY];
};

struct node {
  char *street;
  vertex *adjacency;
  node *next;
};

class graph {
public:
  graph();
  ~graph();
  int load_file();
  int display_vertex(char location[]); // display all the locations that can be
                                       // arrived from the argument location
  int display_route(char location[]);  // display all the possible way from the
                                       // arguement to Portlnd
  int display_all();

private:
  int insert(collection &source, int &index);
  int check(char *source, int &size);
  int insert_intersection(char *source, int index);
  int insert_lll(int index1, int index2, char *source);
  int display_lll(node *head);
  int display_rount(node *head);
  int dft(vertex *current);
  int clear_flag();

  vertex **list; // array of pointers to vertex
  int list_size; // the size of the array
};
