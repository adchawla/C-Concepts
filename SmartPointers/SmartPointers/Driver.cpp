#include "MyObject.h"
#include "Node.h"
#include <iostream>
#include <vector>

void printTree(Node * rootNode);

int main() {
    /*MyObject myObj1("1");
    MyObject * myObj2 = new MyObject("2");
    std::vector<MyObject *> colletion;
    colletion.push_back(&myObj1);
    colletion.push_back(myObj2);
    delete myObj2;*/
    Node * rootNode = new Node("root");
    rootNode->addReference();
    Node * child1 = new Node("child1");
    child1->addReference();
    rootNode->addChild(child1);
    rootNode->addChild(new Node("child2"));
    rootNode->addChild(new Node("child3"));
    rootNode->addChild(new Node("child4"));
    child1->addChild(new Node("grandChild1"));
    child1->addChild(new Node("grandChild2"));
    child1->addChild(new Node("grandChild3"));
    printTree(rootNode);
    rootNode->removeReference();
    printTree(child1);
    child1->removeReference();
}

void  printTree(Node * node, size_t level) {
    for (size_t i = 0; i < level; ++i) {
        std::cout << "\t";
    }
    std::cout << node->id()<<"\n";
    size_t childCount = node->countOfChildren();
    for (size_t i = 0; i < childCount; ++i) {
        printTree(node->getChild(i), level + 1);
    }
}

void printTree(Node * rootNode) {
    printTree(rootNode, 0);
}
