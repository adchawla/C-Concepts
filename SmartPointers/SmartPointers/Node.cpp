#include "Node.h"
#include <iostream>



Node::Node(const std::string & id)
    : mID(id)
    , mReferenceCount(0)
{

}

Node::~Node()
{
    size_t nCount = mChildren.size();
    for (size_t i = 0; i < nCount; ++i) {
        mChildren[i]->removeReference();
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
    node->addReference();
}

Node * Node::getChild(size_t index)
{
    if (index < mChildren.size()) {
        return mChildren[index];
    }
    return nullptr;
}

void Node::addReference() const
{
    ++mReferenceCount;
}

void Node::removeReference() const
{
    --mReferenceCount;
    if (mReferenceCount == 0) {
        delete this;
    }
}

size_t Node::countOfChildren()
{
    return mChildren.size();
}
