#include <iostream>
#include <vector>
#include <memory>
#include <tuple>


class fibClass
{
public:
    
    fibClass(): val1_(0), val2_(1){};
    std::tuple<int, int> getFibNumbers();
    void setFibNumber(int, int);
private:
    int val1_;
    int val2_;

};

void fibonaci(std::shared_ptr<fibClass> &fibNumber)
{   
    
   
    int valSum = std::get<0>(fibNumber->getFibNumbers()) + std::get<1>(fibNumber->getFibNumbers());
    
    
    fibNumber->setFibNumber(std::get<1>(fibNumber->getFibNumbers()), valSum);
    
}

void fibClass::setFibNumber(int one, int two)
{
    val1_ = one;
    val2_ = two;
}

std::tuple<int, int> fibClass::getFibNumbers()
{
    return {val1_, val2_};
}

int main()
{   
    
    std::shared_ptr<fibClass> fibNumber = std::make_shared<fibClass>();

    int numTerms = 10;
    for(int i = 0; i < numTerms ;i++)
    {
        fibonaci(fibNumber);
    }

    std::cout << std::get<0>(fibNumber->getFibNumbers()) << std::endl;


    return 1;
}