#include "GraphTree.h"

void GraphTree::addNeighborTo(int keyToFind, int keyToAdd)
{
    const auto &existedNode{ m_search->searchByKey(m_startingPoint, keyToFind) };
    if(existedNode)
    {
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
}

void GraphTree::printInfoOfNode(int key)
{
    const auto &temp_node{ m_search->searchByKey(m_startingPoint, key) };
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
    m_startingPoint->clearNodes(m_startingPoint);
}
