#pragma once

#include <algorithm>
#include <unordered_set>

#include "Node.h"

class SearchStrategy
{
protected:
    std::unordered_set<std::shared_ptr<Node>> m_visited;

    void clearVisited();
    bool isVisitedContains(const std::shared_ptr<Node>&);
    void addNeighborsToQueue(std::shared_ptr<Node>);

    virtual void clearQueue() = 0;
    virtual void addToQueue(std::shared_ptr<Node>) = 0;
    virtual bool isQueueEmpty() = 0;
    virtual std::shared_ptr<Node> getFromQueue() = 0;

public:
    SearchStrategy(){};

    std::shared_ptr<Node> searchByKey(std::shared_ptr<Node>, int);

    virtual ~SearchStrategy(){};
};

void SearchStrategy::clearVisited()
{
    if(!m_visited.empty())
    {
        m_visited.clear();
    }
}

bool SearchStrategy::isVisitedContains(const std::shared_ptr<Node> &node)
{
    for(const auto &it: m_visited)
    {
        if(it == node)
        {
            return true;
        }
    }

    return false;
}

void SearchStrategy::addNeighborsToQueue(std::shared_ptr<Node> node)
{
    std::cout << "His neighbors are: " << std::endl;
    for(const auto &it: node->getNeighbors())
    {
        std::cout << "- " << it->getKey() << std::endl;
        if(!(isVisitedContains(it)))
        {
            addToQueue(it);
        }
    }
}

std::shared_ptr<Node> SearchStrategy::searchByKey(std::shared_ptr<Node> node, int key)
{
    auto clearContainers
    {
        [this]()
        {
            clearVisited();
            clearQueue();
        }
    };

    std::cout<< "Looking for: " << key << " Visited: " << node->getKey() << std::endl;
    if(node->getKey() == key)
    {
        std::cout << key << " Found!\n" << std::endl;

        clearContainers();

        return node;
    }
    else
    {
        m_visited.insert(node);
        addNeighborsToQueue(node);

        if(!isQueueEmpty())
        {
            return searchByKey(getFromQueue(), key);
        }
    }

    std::cout << "Nothing found!\n" << std::endl;

    clearContainers();

    return nullptr;
}
