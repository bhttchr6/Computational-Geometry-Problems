#include <stdio.h>
#include <memory>
#include <iostream>

// give an example of unique pointer and shared pointer

class counter
{
public:
    int count_;
    counter(int val): count_(val){};
    int getCounter();
};

int counter::getCounter()
{
    return count_;
}

class Object: public counter
{

public:
    int getCount() const;
    void increaseCount();
    Object(std::shared_ptr<counter> &ctr);
private:
    std::shared_ptr<counter> counterInsideObj;
};

Object::Object(std::shared_ptr<counter> &externalPtr): counterInsideObj(externalPtr), counter(externalPtr->getCounter()){};


void Object::increaseCount()
{
     counterInsideObj->count_++;
}
int  Object::getCount() const
{
    return counterInsideObj->getCounter();
}

int main()
{
    std::shared_ptr<counter> iniCounter = std::make_shared<counter>(30);
    std::unique_ptr<Object> obj1 = std::make_unique<Object>(iniCounter);
    obj1->increaseCount();
    std::unique_ptr<Object> obj2 = std::make_unique<Object>(iniCounter);
    obj2->increaseCount();

    std::cout << obj2->getCount() << std::endl;
    return 1;
}