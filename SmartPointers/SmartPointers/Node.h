#pragma once
#include <string>
#include <vector>
#include <memory>

class Node : public std::enable_shared_from_this<Node>
{
public:
    const std::string & id();
    std::shared_ptr<Node> addChild(const std::shared_ptr<Node> & node);
    size_t countOfChildren();
    std::shared_ptr<Node> getChild(size_t index);
    static std::shared_ptr<Node> makeNode(std::string & id);

    virtual ~Node();
    Node(const std::string & id);

protected:

private:
    std::string mID;
    std::vector<std::shared_ptr<Node> > mChildren;
    mutable size_t mReferenceCount;
};

