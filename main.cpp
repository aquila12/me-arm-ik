#include <iostream>
#include "ik.h"
#include "fk.h"

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
            // Check!
            float X, Y, Z;
            unsolve(t0, t1, t2, X, Y, Z);

            if(distance(x, y, z, X, Y, Z) > 0.01)
            {
                cout<<"WARNING: Solution for ("<<x<<","<<y<<","<<z<<")";
                cout<<"resulted in ("<<X<<","<<Y<<","<<Z<<")!"<<endl;
            }

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
