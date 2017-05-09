#pragma once
#include <string>
#include <vector>

class Node
{
public:
    Node(const std::string & id);
    const std::string & id();
    void addChild(Node * node);
    size_t countOfChildren();
    Node * getChild(size_t index);

    void addReference() const;
    void removeReference() const;

protected:
    virtual ~Node();

private:
    std::string mID;
    std::vector<Node *> mChildren;
    mutable size_t mReferenceCount;
};

