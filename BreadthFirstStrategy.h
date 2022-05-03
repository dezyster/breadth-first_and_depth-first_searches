#pragma once

#include <queue>

#include "SearchStrategy.h"

class BreadthFirstStrategy final: public SearchStrategy
{
    std::unique_ptr<std::queue<std::shared_ptr<Node>>> m_queue;

    virtual void clearQueue() override;
    virtual void addToQueue(std::shared_ptr<Node>) override;
    virtual bool isQueueEmpty() override;
    virtual std::shared_ptr<Node> getFromQueue() override;

public:
    BreadthFirstStrategy()
        : SearchStrategy{}, m_queue{ std::make_unique<std::queue<std::shared_ptr<Node>>>() }{}

    virtual ~BreadthFirstStrategy() override = default;
};
