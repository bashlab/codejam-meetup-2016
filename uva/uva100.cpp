// The 3n + 1 problem (Brute force approach)

#include <stdio.h>

int main()
{
    int n,i,j,oi,oj,k,clength,max;
    while(scanf("%d %d", &i, &j) == 2) {
        max = 0;
        oi = i;
        oj = j;
        if(i>j)
        {
            k = i;
            i = j;
            j = k;
        }
        for(int l=i; l<=j; ++l)
        {
            clength = 1;
            n = l; 
            while(n!=1)
            {
                clength++;
                n = n%2 == 0 ? n/2 : 3*n+1;
            }
            if(clength>max)
            {
                max = clength;
            } 
        } 
        printf("%d %d %d\n", oi,oj, max); 
    }
}
