#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// Singletons are used for objects you only
// want one instance of and you want to 
// enforce that rule to avoid misuse.
//
// This works well for caches and database
// connections, but use sparingly and only
// when certain that more instances will
// not be needed in the future.
//
// Singletons can be implemented either 
// like a static factory, as below, or using
// purely static methods where the singletons
// methods are called directly on the class.

using namespace std;

class Singleton{

        Singleton(){}
        string phrase;
        static Singleton *instance;

    public:
        static Singleton* getInstance()
        {
            if( !instance )
            {
                instance = new Singleton();
            }
            return instance;
        }
        
        void setPhrase(string s)
        {
            phrase = s;
        }

        void sayPhrase()
        {
            cout << phrase << endl;
        }

        Singleton(Singleton const&) = delete;
        void operator=(Singleton const&) = delete;
};

Singleton *Singleton::instance = nullptr;


int main(int argc, char** argv)
{

    Singleton *s1 = Singleton::getInstance();
    s1->setPhrase("Hello world");
    
    Singleton *s2 = Singleton::getInstance();
    s2->sayPhrase();
   
    delete s2;

    Singleton *s3 = Singleton::getInstance();
    s3->sayPhrase();
}
