// 661 - Blowing Fuses
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct device
{
    bool toggled; // on: true   off: false
    int ampere;
};

int main()
{
    int n,m,c,amp,max,total,td,k;
    bool ifb;
    for(int j=1; ; ++j) {
        if(scanf("%d %d %d", &n, &m, &c)==3) {
            device * d;
            max = 0;
            if(n==0 && m==0 && c==0)
            {
                break; // terminate
            }
            else 
            {
                printf("Sequence %d\n",j);
                total = 0; // init the total ampere before simulation
                ifb = true;
                d = new device[n];
                for(int l=0; l<n; ++l)
                {
                    scanf("%d", &amp);
                    d[l].toggled = false; // init
                    d[l].ampere = amp; // ampere of the device i = k+1
                }
                for(k=0; k<m; ++k)
                {
                    scanf("%d", &td); // toggled device
                    bool isToggled = d[td-1].toggled;
                    isToggled ? total -= d[td-1].ampere : total += d[td-1].ampere;
                    d[td-1].toggled = !isToggled;
                    total>c ? ifb = false : max = total > max ? total : max; // compute max ampere
                }
                ifb ? printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",max) : printf("Fuse was blown.\n");
                delete []d;
            }
            cout << endl;
        }    
    }
}
