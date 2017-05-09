#include "Node.h"
#include <iostream>



Node::Node(const std::string & id)
    : mID(id)
    , mReferenceCount(0)
{

}

Node::~Node()
{
    std::cout << "Destructing Node with id = " << mID<<"\n";
}

const std::string & Node::id()
{
    return mID;
}

void Node::addChild(const std::shared_ptr<Node> & node)
{
    mChildren.push_back(node);
}

std::shared_ptr<Node> Node::getChild(size_t index)
{
    if (index < mChildren.size()) {
        return mChildren[index];
    }
    return std::shared_ptr<Node>();
}

std::shared_ptr<Node> Node::makeNode(std::string & id)
{
    return std::make_shared<Node>(id);
}

size_t Node::countOfChildren()
{
    return mChildren.size();
}