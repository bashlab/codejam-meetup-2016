// 394 - Mapmaker
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct data 
{
    string name; // id for searching
    int base_addr;
    int dimension; // dimension
    int *coef;
};

int main()
{
    int N, R, B, C_D, D, *l_bound, *u_bound, *coef;
    // Record the N and R first, in the first line of input
    cin >> N >> R;
    data * ref = new data[N];
    for(int i=0; i<N; ++i)
    {
        // Load the setting of each array
        cin >> ref[i].name >> B >> C_D >> D; 
        ref[i].dimension = D; 
        ref[i].base_addr = B;
        // Defind the lower bound and upper bound array
        l_bound = new int[D];
        u_bound = new int[D]; 
        coef = new int[D+1];
        int delta = 0;
        for(int j=0; j<D; ++j)
        {
            cin >> l_bound[j] >> u_bound[j]; 
        }
        coef[D] = C_D;
        if(D>1)
        {
            for(int j=D-1; j>0; --j)
            {
                coef[j] = coef[j+1]*(u_bound[j]-l_bound[j]+1);
                delta += coef[j]*l_bound[j-1];
            }
        }
        coef[0] = B - delta - C_D*l_bound[D-1];
        ref[i].coef = coef;
    }
    // Output part
    int input_i, addr;
    string name, istr;
    for(int i=0; i<R; ++i)
    {
        cin >> name;
        istr = "";
        for(int j=0; j<N; ++j)
        {
            if(name == ref[j].name)
            {
                addr = *(ref[j].coef);
                for(int k=1; k<= ref[j].dimension; ++k) 
                {
                    cin >> input_i;
                    istr += k == 1 ? to_string(input_i) : ", " + to_string(input_i);
                    addr += *(ref[j].coef + k) * input_i;
                }
                break;
            }     
        }     
        cout << name << "[" << istr << "] = " << addr << endl;
    }
    // delete those dynamic allocated stuffs 
    delete []ref;
    delete []l_bound;
    delete []u_bound;
    delete []coef;
}
