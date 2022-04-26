#pragma once

#include <set>
#include <iostream>
#include <memory>

class Node;

bool compareNodes(const std::shared_ptr<Node> &a, const std::shared_ptr<Node> &b);

class Node
{
    int m_key;
    std::set<std::shared_ptr<Node>, decltype(compareNodes)*> m_neighbors;

public:
    Node(int key): m_key{ key }, m_neighbors{ compareNodes } {}
    Node(int, std::shared_ptr<Node>);

    void addNeighbor(std::shared_ptr<Node>);
    void addNeighbor(int, std::shared_ptr<Node>);
    int getKey();
    std::set<std::shared_ptr<Node>, decltype(compareNodes)*>& getNeighbors();
    void printInfo();

    bool operator<(const Node& other) { return m_key < other.m_key; }

    ~Node() = default;
};

bool compareNodes(const std::shared_ptr<Node> &a, const std::shared_ptr<Node> &b)
{
     return *a < *b;
};

Node::Node(int key, std::shared_ptr<Node> otherNode): m_key{ key }, m_neighbors{ compareNodes }
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
    std::cout<<"I'm "<<m_key<<" My neighbors are:\n";
    for(const auto &it: m_neighbors)
    {
        std::cout << it->getKey() << std::endl;
    }
}
