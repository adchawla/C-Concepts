#include "MyObject.h"
#include "Node.h"
#include <iostream>
#include <vector>

void printTree(const std::shared_ptr<Node> & rootNode);

int main() {
    /*MyObject myObj1("1");
    MyObject * myObj2 = new MyObject("2");
    std::vector<MyObject *> colletion;
    colletion.push_back(&myObj1);
    colletion.push_back(myObj2);
    delete myObj2;*/
    auto rootNode = Node::makeNode(std::string("root"));
    auto child1 = Node::makeNode(std::string("child1"));
    rootNode->addChild(child1);
    rootNode->addChild(Node::makeNode(std::string("child2")));
    rootNode->addChild(Node::makeNode(std::string("child3")));
    rootNode->addChild(Node::makeNode(std::string("child4")));
    child1->addChild(Node::makeNode(std::string("grandChild1")));
    child1->addChild(Node::makeNode(std::string("grandChild2")));
    child1->addChild(Node::makeNode(std::string("grandChild3")));
    printTree(rootNode);
    printTree(child1);
}

void  printTree(const std::shared_ptr<Node> & node, size_t level) {
    for (size_t i = 0; i < level; ++i) {
        std::cout << "\t";
    }
    std::cout << node->id()<<"\n";
    size_t childCount = node->countOfChildren();
    for (size_t i = 0; i < childCount; ++i) {
        printTree(node->getChild(i), level + 1);
    }
}

void printTree(const std::shared_ptr<Node> & rootNode) {
    printTree(rootNode, 0);
}
