# breadth-first_and_depth-first_searches

Program builds graph like on picture below using breadth-first or depth-first search algorithms. Project uses Strategy pattern so search algorithm can be changed at any time. 

![alt text](https://dic.academic.ru/pictures/wiki/files/66/Breadth-first-tree.svg)

It prints all process of searching nodes on console. Then it shows info of bottom nodes to demonstrate difference in searching algorithms.

Project uses smart pointers and different stl containers such as set, unordered_set, queue and stack.

Nodes use shared_ptr as pointer for neighbors, so program uses special method to ensure that every node is deleted correctly.