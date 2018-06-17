#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <memory>

// The flyweight pattern moves a section of data which
// would overwise be repeated between instances of an
// object and places it into its own object which all 
// the instances can share
//
// This is usually done to minimize space usage but in
// the context of graphics programming (instanced rendering) 
// it is used to avoid sending the repeated data structure 
// to the GPU multiple times, saving time
//
// The example below splits out a traded stocks details from
// each trade
//
// The flyweight InstrumentDetails could be made into a virtual
// parent class for a whole variety of types of instrument types


using namespace std;

class InstrumentDetails;

struct Trade {
    string trader;
    int volume;
    int tickCount;
    InstrumentDetails *inst;
};

struct InstrumentDetails {
    string symbol;
    string isin;
    double tickSize;
    // ...  Any other shared details, eg market/segment
};

int main(int argc, char** argv)
{
    InstrumentDetails inst;
    inst.symbol = "VOD.l";
    inst.isin = "GB00BH4HKS39";
    inst.tickSize = 0.01;
    
    Trade t;
    t.trader = "MGRG1";
    t.volume = 1000;
    t.tickCount = 25000;

    t.inst = &inst;
    
    cout << "Symbol : " << t.inst->symbol << endl;
    cout << "Volume : " << t.volume << endl;
    cout << "Price  : " << t.tickCount * t.inst->tickSize << endl;
}
