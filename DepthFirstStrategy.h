#pragma once

#include <stack>

#include "SearchStrategy.h"

class DepthFirstStrategy final: public SearchStrategy
{
    std::unique_ptr<std::stack<std::shared_ptr<Node>>> m_stack;

    virtual void clearQueue() override;
    virtual void addToQueue(std::shared_ptr<Node>) override;
    virtual bool isQueueEmpty() override;
    virtual std::shared_ptr<Node> getFromQueue() override;

public:
    DepthFirstStrategy()
        : SearchStrategy{}, m_stack{ std::make_unique<std::stack<std::shared_ptr<Node>>>() }{}

    virtual ~DepthFirstStrategy() override = default;
};
