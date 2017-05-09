#pragma once
#include <string>
#include <vector>

class Node
{
public:
    Node(const std::string & id);
    virtual ~Node();
    const std::string & id();
    void addChild(Node * node);
    size_t countOfChildren();
    Node * getChild(size_t index);

private:
    std::string mID;
    std::vector<Node *> mChildren;
};

