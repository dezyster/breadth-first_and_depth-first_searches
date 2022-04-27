#include "GraphTree.h"
#include "BreadthFirstStrategy.h"
#include "DepthFirstStrategy.h"

//https://dic.academic.ru/pictures/wiki/files/66/Breadth-first-tree.svg

int main()
{
    BreadthFirstStrategy bfs;
    GraphTree testGraph(1, &bfs);

    testGraph.addNeighborTo(1, 2);
    testGraph.addNeighborTo(1, 3);
    testGraph.addNeighborTo(1, 4);
    testGraph.addNeighborTo(2, 5);
    testGraph.addNeighborTo(2, 6);
    testGraph.addNeighborTo(5, 9);
    testGraph.addNeighborTo(5, 10);
    testGraph.addNeighborTo(4, 7);
    testGraph.addNeighborTo(4, 8);
    testGraph.addNeighborTo(7, 11);
    testGraph.addNeighborTo(7, 12);

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "-------------------Breadth-First search---------------" << std::endl;

    testGraph.printInfoOfNode(10); // Searches node 10 and prints its info

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "--------------------Depth-First search----------------" << std::endl;

    DepthFirstStrategy dfs;
    testGraph.setStrategy(&dfs);

    testGraph.printInfoOfNode(10); // Searches node 10 and prints its info

    std::cout << "------------------------------------------------------" << std::endl;

    return 0;
}
