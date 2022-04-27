#pragma once

#include <unordered_set>

#include "Node.h"

class SearchStrategy
{
protected:
    std::unordered_set<std::shared_ptr<Node>> m_visited;

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
