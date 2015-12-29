// 573 - The Snail
#include <stdio.h>
#include <iostream>

using namespace std;

#define DBL_EPSILON 1e-9

int main()
{
    double H, U, D, F;
    double DC, HAC, HAS;
    while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F)==4)
    {
        // Setup the break condition, H = 0 indicates the end of input
        if(H==0)
        {
            break;
        } 
        else 
        {
            for(int j=1; ; ++j)
            {
                // j is the day
                if(j==1)
                {
                    DC = U;
                    HAC = U; 
                    HAS = U-D;
                } 
                else 
                {
                    DC = DC - U*(double)F/100;
                    if(DC < DBL_EPSILON) DC = 0; 
                    HAC = DC + HAS;
                    HAS = HAC - D;
                }
                //cout << " DC = " << DC << " HAC = " << HAC << " HAS = " << HAS << endl;
                // Trick: HAC must be greater or equal to HAS
                if(HAC > H)
                {
                    cout << "success on day " << j << endl;
                    break;
                }
                if(HAC < 0.0 || HAS < 0.0) {
                    cout << "failure on day " << j << endl;
                    break;
                }
            }
        }
    }
}
