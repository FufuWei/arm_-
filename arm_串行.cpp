#include <iostream>
#include<sys/time.h>
#include <arm_neon.h>
using namespace std;
const int N = 16;
float a[N][N];
void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = float(rand()) / 100;
}

int main()
{


    timeval* start = new timeval();
    timeval* stop = new timeval();
    double durationTime = 0.0;

    init();
    gettimeofday(start, NULL);
    for (int tim = 0; tim < 1000; tim++) {
        for (int k = 0; k < N; k++)
        {
            for (int j = k + 1; j < N; j++)
                a[k][j] /= a[k][k];
            a[k][k] = 1.0;
            for (int i = k + 1; i < N; i++) {

                for (int j = k + 1; j < N; j++)
                    a[i][j] -= a[i][k] * a[k][j];
                a[i][k] = 0;
            }
        }
    }
    gettimeofday(stop, NULL);
    durationTime = stop->tv_sec * 1000 + double(stop->tv_usec) / 1000 - start->tv_sec * 1000 - double(start->tv_usec) / 1000;
    cout << " SequentialAlgorithm time: " << double(durationTime) << " ms" << endl;


    return 0;
}