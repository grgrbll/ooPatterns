#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// Decorators make it easy to chain operations together
// by allowing operations to wrap one another

using namespace std;
class Decorator {
    protected:
        Decorator *child = nullptr;
    public:
        void addChild(Decorator *c)
        {
            child = c;
        }
        virtual int run(int n)=0;
};

class Times10 : public Decorator {
    public:
        int run(int n)
        {
            if(child != nullptr)
            {
                return child->run(n) * 10;
            }
            else
            {
                return n * 10;
            }
        }
};

class Add10 : public Decorator {
    public:
        int run(int n)
        {
            if(child != nullptr)
            {
                return child->run(n) + 10;
            }
            else
            {
                return n + 10;
            }
        }
};

int main(int argc, char** argv)
{
    Times10 d1;
    Add10   d2;
    Times10 d3;

    d2.addChild(&d1);
    d3.addChild(&d2);

    int input;
    string in_str;

    while(true)
    {
        getline(cin, in_str);
        stringstream(in_str) >> input;
        cout << d3.run(input) << endl << endl;
    }
}
