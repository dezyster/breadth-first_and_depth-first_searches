#include "BreadthFirstStrategy.h"

void BreadthFirstStrategy::clearQueue()
{
    m_queue = std::make_unique<std::queue<std::shared_ptr<Node>>>();
}

void BreadthFirstStrategy::addToQueue(std::shared_ptr<Node> node)
{
    m_queue->push(node);
}

bool BreadthFirstStrategy::isQueueEmpty()
{
    return m_queue->empty();
}

std::shared_ptr<Node> BreadthFirstStrategy::getFromQueue()
{
    std::shared_ptr<Node> temp{ m_queue->front() };
    m_queue->pop();
    return temp;
}
