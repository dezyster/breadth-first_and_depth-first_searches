#pragma once

#include <stack>

#include "SearchStrategy.h"

class DepthFirstStrategy: public SearchStrategy
{
    std::unique_ptr<std::stack<std::shared_ptr<Node>>> m_stack;

    virtual void clearQueue() override final;
    virtual void addToQueue(std::shared_ptr<Node>) override final;
    virtual bool isQueueEmpty() override final;
    virtual std::shared_ptr<Node> getFromQueue() override final;

public:
    DepthFirstStrategy()
        : SearchStrategy{}, m_stack{ std::make_unique<std::stack<std::shared_ptr<Node>>>() }{}

    virtual ~DepthFirstStrategy() override final = default;
};
