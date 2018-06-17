#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <stack>

// The Command pattern encapsulates operations as commands
// The Command acts on a Reveiver and is run by the Invoker
//
// The classic use of the command pattern is to allow different
// commands to be assigned to any 'slot' in a controller, for
// example allowing the buttons on a remote to be remapped
//
// This pattern makes it easy to implement Undo by giving 
// each command an undo method and keeping a stack of commands
// so they can be reverted in the correct order

using namespace std;

class Receiver {
    public:
        int val = 0;
};


class Command {
    protected:
    Receiver *r;
    public:
        void setReceiver(Receiver * new_receiver)
        {
            r = new_receiver;
        }

        virtual void execute()=0;
        virtual void undo()=0;
};

class Add5 : public Command {
    public:
        void execute(){
            r->val += 5;
        }
        void undo(){
            r->val -= 5;
        }       
};

class Mul2 : public Command {
    public:
        void execute(){
            r->val *= 2;
        }
        void undo(){
            r->val /= 2;
        }       
};

class Invoker {
    map<char,class Command *> cmdMap;
    stack<char> history; 
    public:

        void setCommand(char k, Command * new_command)
        {
            cmdMap[k] = new_command;
        }

        void invoke(char k)
        {
            history.push(k);
            cmdMap[k]->execute();
        }

        // alternatively undo could be implmented by another
        // concrete command, perhaps taking the invoker
        // as the receiver
        void undo()
        {
            if(history.size() > 0)
            {
                cmdMap[history.top()]->undo();
                history.pop();
            }
        }
};

int main(int argc, char** argv)
{

    Invoker i;
    Receiver r;

    Add5 cmd1;
    Mul2 cmd2;

    cmd1.setReceiver(&r);
    cmd2.setReceiver(&r);

    i.setCommand('a', &cmd1);
    i.setCommand('m', &cmd2);

    char input;
    string in_str;

    while(true)
    {
        getline(cin, in_str);
        stringstream(in_str) >> input;
        if(input == 'u')
        {
            i.undo();
        }
        else
        {
            i.invoke(input);
        }
        cout << r.val << endl << endl;
    }
}
