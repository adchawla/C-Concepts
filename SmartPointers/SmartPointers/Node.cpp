#include "Node.h"
#include <iostream>



Node::Node(const std::string & id)
    : mID(id)
{

}

Node::~Node()
{
    size_t nCount = mChildren.size();
    for (size_t i = 0; i < nCount; ++i) {
        delete mChildren[i];
    }
    std::cout << "Destructing Node with id = " << mID<<"\n";
}

const std::string & Node::id()
{
    return mID;
}

void Node::addChild(Node * node)
{
    mChildren.push_back(node);
}

Node * Node::getChild(size_t index)
{
    if (index < mChildren.size()) {
        return mChildren[index];
    }
    return nullptr;
}

size_t Node::countOfChildren()
{
    return mChildren.size();
}
