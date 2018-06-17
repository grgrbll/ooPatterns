#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// Simple factories can act like a map
// function from parameters to object
// instances.
//
// It is useful to encapsulate this code
// because in practice it is often 
// reused and added to.
//
// Factorys can also be implemented as
// static classes but doing so will 
// prevent you from subclassing the 
// factory in the future.
//
// In this case the Mul and Add ops 
// are stateless and therefore should
// not be instanciated each time,
// instead a single premade instance
// should be passed. This is however
// a general example.

using namespace std;
class Operator {
    public:
        virtual int apply(int a, int b)=0;
};

class Mul : public Operator {
    public:
        int apply(int a, int b)
        {
            return a * b;
        }
};

class Add : public Operator {
    public:
        int apply(int a, int b)
        {
            return a + b;
        }
};

class OpFactory {
    public:
        Operator * getOp(string s)
        {
            if(s == "add")
            {
                return new Add;
            }
            else if(s=="mul")
            {
                return new Mul;
            }
            else
            {
                return nullptr;
            }
        }
};

int main(int argc, char** argv)
{

    OpFactory factory;

    string in_str;
    int arg;
    string opname;

    int v = 0;

    while(true)
    {
        getline(cin, in_str);
        stringstream(in_str) >> opname >> arg;
        Operator * op;
        if((op = factory.getOp(opname)) == nullptr)
        {
            cout << "unexpected operation" << endl;
        }
        else
        {
            v = op->apply(v, arg);
            cout << v << endl;
        }
        delete op;
        cout << endl;
    }
}
