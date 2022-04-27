#include "DepthFirstStrategy.h"

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
