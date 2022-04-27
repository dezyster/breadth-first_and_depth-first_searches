#pragma once

#include <queue>

#include "SearchStrategy.h"

class BreadthFirstStrategy: public SearchStrategy
{
    std::unique_ptr<std::queue<std::shared_ptr<Node>>> m_queue;

    virtual void clearQueue() override final;
    virtual void addToQueue(std::shared_ptr<Node>) override final;
    virtual bool isQueueEmpty() override final;
    virtual std::shared_ptr<Node> getFromQueue() override final;

public:
    BreadthFirstStrategy()
        : SearchStrategy{}, m_queue{ std::make_unique<std::queue<std::shared_ptr<Node>>>() }{}

    virtual ~BreadthFirstStrategy() override final = default;
};
