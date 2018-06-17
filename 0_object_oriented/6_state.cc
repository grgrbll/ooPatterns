#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <memory>

// The state pattern allows the a class (Resource)
// to change its entire behaviour depending on
// its current state without filling every
// method with 'if' statements
//
// This is implmented by essentailly making
// the front facing class into an adaptor for
// a family of State classes which can switch 
// between one another without being coupled to 
// the front facing class
//
// The implementation below is simplified 
// and could be improved by using a factory
// to provide the states

using namespace std;

class Resource;

class State {
    protected:
    Resource *ctx; // Context
    public:
        State(Resource *&c){
            ctx = c;
        }
        virtual void use()=0;
};

class Resource {
    private:
        unique_ptr<State> state;

    public:
        void setState(State *s)
        {
            state.reset(s);
        }
        void use(){
            state->use();
        }
};

class State_A : public State { 
    public: 
        State_A(Resource *&c) : State(c) {}
        void use();
};
class State_B : public State { 
    public: 
        State_B(Resource *&c) : State(c) {}
        void use();
};
class State_C : public State { 
    public: 
        State_C(Resource *&c) : State(c) {}
        void use();
};

void State_A::use(){
    cout << "State A" << endl;
    ctx->setState(new State_B(ctx));
}
void State_B::use(){
    cout << "State B" << endl;
    ctx->setState(new State_C(ctx));
}
void State_C::use(){
    cout << "State C" << endl;
    ctx->setState(new State_A(ctx));
}


int main(int argc, char** argv)
{
    Resource *r = new Resource();
    r->setState(new State_A(r));
    string in_str;
    while(true)
    {
        getline(cin, in_str);
        r->use();
    }
}
