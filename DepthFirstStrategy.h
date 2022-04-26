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
        :SearchStrategy{}, m_stack{ std::make_unique<std::stack<std::shared_ptr<Node>>>()}
    {
        
    };
    
    virtual ~DepthFirstStrategy() override final
    {
        
    };
};

void DepthFirstStrategy::clearQueue()
{
    m_stack = std::make_unique<std::stack<std::shared_ptr<Node>>>();
}

void DepthFirstStrategy::addToQueue(std::shared_ptr<Node> node)
{
    m_stack->push(node);
}

bool DepthFirstStrategy::isQueueEmpty()
{
    return m_stack->empty();
}

std::shared_ptr<Node> DepthFirstStrategy::getFromQueue()
{
    std::shared_ptr<Node> temp{ m_stack->top() };
    m_stack->pop();
    return temp;
}