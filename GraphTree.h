#pragma once

#include "Node.h"
#include "SearchStrategy.h"

class GraphTree
{
    std::shared_ptr<Node> m_startingPoint;

    SearchStrategy *m_search;

public:
    GraphTree(int, SearchStrategy*);

    void addNeighborTo(int, int);
    void printInfoOfNode(int);
    void setStrategy(SearchStrategy*);

    ~GraphTree();
};

GraphTree::GraphTree(int key, SearchStrategy *search)
    :m_startingPoint{ std::make_shared<Node>(key) }, m_search{ search }
{

}

void GraphTree::addNeighborTo(int keyToFind, int keyToAdd)
{
    const auto &existedNode{ m_search->searchByKey(m_startingPoint, keyToFind) };
    const auto &newNeighborNode{ m_search->searchByKey(m_startingPoint, keyToAdd) };

    if(newNeighborNode)
    {
        existedNode->addNeighbor(newNeighborNode);
    }
    else
    {
        existedNode->addNeighbor(keyToAdd, existedNode);
    }

}

void GraphTree::printInfoOfNode(int key)
{
    const auto& temp_node{ m_search->searchByKey(m_startingPoint, key) };
    if(temp_node)
    {
        temp_node->printInfo();
    }
}

void GraphTree::setStrategy(SearchStrategy *search)
{
    m_search = search;
}

GraphTree::~GraphTree()
{

}
