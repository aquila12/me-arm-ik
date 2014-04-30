#include <iostream>
#include "ik.h"

using namespace std;

int main()
{
    {
        float a, b, c;
        solve(10, 105, 70, a, b, c);
        cout<<a<<" "<<b<<" "<<c<<endl;
    }

    // Counters
    int valid=0, invalid=0;

    // Test!
    float x, y, z;
    float t0, t1, t2;
    for(x=-100; x<=100; ++x)  for(y=0; y<=100; ++y) for(z=-50; z<=100; ++z)
    {
        if(solve(x, y, z, t0, t1, t2))
        {
            ++valid;
        }
        else
        {
            ++invalid;
        }
    }

    //Test results
    cout<<"Valid: "<<valid<<"; ";
    cout<<"Invalid: "<<invalid<<"; ";
    cout<<"Total: "<<(valid+invalid)<<endl;

    float pvalid = 100.0 * float(valid) / float(valid + invalid);
    cout<<pvalid<<"% reachable:"<<endl;
}
