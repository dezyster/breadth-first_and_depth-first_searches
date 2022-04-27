#pragma once

#include "Node.h"
#include "SearchStrategy.h"

class GraphTree
{
    std::shared_ptr<Node> m_startingPoint;

    SearchStrategy *m_search;

public:
    GraphTree(int key, SearchStrategy *search)
        : m_startingPoint{ std::make_shared<Node>(key) }, m_search{ search }{}

    void addNeighborTo(int, int);
    void printInfoOfNode(int);
    void setStrategy(SearchStrategy*);

    ~GraphTree();
};
