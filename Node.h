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

    void clearNodes(std::shared_ptr<Node>);

    ~Node();
};
