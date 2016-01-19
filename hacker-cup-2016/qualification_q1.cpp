#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int dist[2000][2000];

int main()
{
    int T, N;
    int *X, *Y; 
    long long counter; 
    int k;
    scanf("%d", &T);
    for(int t=1; t<=T; ++t)
    {
        // restore the counter
        counter = 0;
        // start
        scanf("%d", &N);
        X = new int[N];
        Y = new int[N];
        
        // create array to store the 
        int c = 0;
        for(int i=0; i<N; ++i)
        {
            scanf("%d %d", &X[i], &Y[i]); 
        }
/*
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                dist[i][j] = pow(X[i]-X[j],2) + pow(Y[i]-Y[j],2);        
            }
        }
*/
        int prev, rep;
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                dist[i][j] = pow(X[i]-X[j],2) + pow(Y[i]-Y[j],2);        
            }
            sort(dist[i], dist[i] + N);
            rep = 1;
            prev = 0;
            for(int j=1; j<N; ++j)
            {
                if(prev == dist[i][j])
                {
                    rep++;
                }
                else
                {
                    counter += rep * (rep - 1) / 2;
                    rep = 1;
                }
                prev = dist[i][j];
            }
            counter += rep * (rep - 1) / 2;
        }

        delete []X;
        delete []Y;
        cout << "Case #" << t << ": " << counter << endl;
    }
}
