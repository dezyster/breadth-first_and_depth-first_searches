#include "Node.h"

bool compareNodes(const std::shared_ptr<Node> &a, const std::shared_ptr<Node> &b)
{
     return *a < *b;
};

Node::Node(int key, std::shared_ptr<Node> otherNode)
    : m_key{ key }, m_neighbors{ compareNodes }
{
    m_neighbors.insert(otherNode);
}

void Node::addNeighbor(std::shared_ptr<Node> otherNode)
{
    m_neighbors.insert(otherNode);
}

void Node::addNeighbor(int key, std::shared_ptr<Node> node)
{
    m_neighbors.insert(std::make_shared<Node>(key, node));
}

int Node::getKey()
{
    return m_key;
}

std::set<std::shared_ptr<Node>, decltype(compareNodes)*>& Node::getNeighbors()
{
    return m_neighbors;
}

void Node::printInfo()
{
    std::cout << "I'm " << m_key << " My neighbors are:" << std::endl;
    for(const auto &it: m_neighbors)
    {
        std::cout << it->getKey() << std::endl;
    }
}

void Node::clearNodes(std::shared_ptr<Node> shared_this)
{
    if(!m_neighbors.empty())
    {
        for(const auto &it: m_neighbors)
        {
            it->m_neighbors.erase(shared_this); //deletes pointer for itself from neighbors
        }
        for(const auto &it: m_neighbors)
        {
            it->clearNodes(it);
        }
    }
}

Node::~Node()
{
    std::cout << "Deleted node " << m_key << "!" << std::endl;
}
