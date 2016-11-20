#include<stdio.h>
using namespace std;
long long arr[100001];
int main()
{
    int k, n;
    long long prime[100][2];
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &prime[i][0]);
        prime[i][1] = 0;
    }
 
    int idx = 1;
    arr[0] = 1;
 
    while (1)
    {
        long long min_v = 9999999999;
        int index;
        for (int i = 0; i < k; i++)
            if (min_v > prime[i][0] * arr[prime[i][1]])
            {
                index = i;
                min_v = prime[i][0] * arr[prime[i][1]];
            }
        if (arr[idx - 1] == min_v)
        {
            prime[index][1]++;
            continue;
        }
        arr[idx++] = min_v;
        if (idx == n + 1)
            break;
        prime[index][1]++;
    }
    printf("%lld\n", arr[n]);
    return 0;
}
