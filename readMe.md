#Programming
##Goal and Data Structures
The goal of this program is to create a **directed graph abstraction using an adjacency list** (an array of vertices where each element has a head pointer to a LLL of edges for adjacent vertices).
Have you ever been stuck in traffic and wish you knew a short cut to get around the issues. I am a short cut fan when it comes to the local roads. In fact, my short cuts many times are the long way around, but they are less stressful than being stuck in stop and go traffic. But using short cuts requires reallyknowing an area and spending time investigating alternate routes. 
Your assignment will be to take as input different routes to get into Portland when the freeways are jammed, by building a **directed graph**. The vertices should be the major intersections (e.g. where 217 ends at highway 26 or the 217 flyover I5). The edges will represent the roads that connect these (e.g, Take Barnes instead of highway 26 when it is jammed at 217). The edges connect to other vertices.
The adjacency list will be an array of vertex objects and a head pointer for each linear linked list representing the edge list. Create the code to allocate an “adjacency list” for a graph. Load the major intersections and connecting roads from a pre-created external file (you can create the file using a linux or unix editor). Make sure to turn in the external data file with your assignment.
The adjacency list should contain:

1. Vertex Information2. Head pointer (to an Edge List) 
3. Visit indicator (optional)


