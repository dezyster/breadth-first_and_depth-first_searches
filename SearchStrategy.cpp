#include "SearchStrategy.h"

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
            m_visited.clear();
            clearQueue();
        }
    };

    std::cout<< "Looking for: " << key << " | Visiting: " << node->getKey() << std::endl;

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
