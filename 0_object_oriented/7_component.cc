#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <memory>

// The component pattern allows an objects
// behaviour to be defined by a composition
// of components
//
// This is expecially common in game development
// where a single update to an actor may require
// AI, physics and graphical operations. By 
// splitting each kind of operation into a family
// of components we can prevent mixing these multiple
// domains into an unmaintainable mess ( here, they 
// would all be mixed into go() )
//
// We also get the ability to freely compose new 
// actors for free
//
// This is closely related to the Strategy pattern

using namespace std;


// Our two domains, Setting and Multiplying
class Component_Set; 
class Component_Mul;

// Our container for components
class Actor {
    private:
        Component_Set *compS;
        Component_Mul *compM;
    public:
        int x;
        Actor(Component_Set *s, Component_Mul *m);
        void go();
};


class Component_Set {
    public:
        virtual void set(Actor *a)=0;
};

// Within each domain we will want to do slightly 
// different things. Here in the setting domain
// we choose to either set 10 or 3
class Set10 : public Component_Set {
    public:   
        void set(Actor *a) override {
            a->x = 10;   
        };
};

class Set3 : public Component_Set {
    public:   
        void set(Actor *a) override {
            a->x = 3;   
        };
};

class Component_Mul {
    public:
        virtual void mul(Actor *a)=0;
};

class Mul10 : public Component_Mul {
    public:   
        void mul(Actor *a) override {
            a->x *= 10;   
        };
};

class Mul3 : public Component_Mul {
    public:   
        void mul(Actor *a) override {
            a->x *= 3;   
        };
};


Actor::Actor(Component_Set *s, Component_Mul *m)
{
    compS = s;
    compM = m;
}

// This function would be much harder to
// maintain if the set and mul code was directly
// included
void Actor::go()
{
    compS->set(this);
    compM->mul(this);
    std::cout << x << std::endl;
}


int main(int argc, char** argv)
{
    Actor a1(new Set10, new Mul3);
    a1.go();
    
    Actor a2(new Set3, new Mul3);
    a2.go();

    Actor a3(new Set10, new Mul10);
    a3.go();
}
