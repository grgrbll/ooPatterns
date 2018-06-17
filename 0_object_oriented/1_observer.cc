#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
class Observer {
    public:
        virtual void update(int n)=0;
};

class Times10 : public Observer {
    public:
        void update(int n)
        {
            cout << n * 10 << endl;
        }
};

class Add1 : public Observer {
    public:
        void update(int n)
        {
            cout << n + 1 << endl;
        }
};


class Subject {
    vector<class Observer *> observers;
    public:
        void addObserver(Observer *o){
            observers.push_back(o);
        }
        void update(int n){
            for(Observer *o : observers)
            {
                o->update(n);
            }
        }
};


int main(int argc, char** argv)
{
    Times10 observer1;
    Add1    observer2;

    Subject sub;

    sub.addObserver(&observer1);
    sub.addObserver(&observer2);

    int input;
    string in_str;

    while(true)
    {
        getline(cin, in_str);
        stringstream(in_str) >> input;
        sub.update(input);
        cout << endl;
    }
}
