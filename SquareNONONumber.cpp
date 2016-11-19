#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
bool check[1000001];
int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
 
    int between = b - a;
    long long max_v = sqrt(b);
    for (long long i = 2; i <= max_v; i++)
    {
        long long y = i*i;
        long long x = a / y;
        if (a % y != 0)
            x++;
        while (x*y <= b)
        {
            check[x*y - a] = true;
            x++;
        }
    }
    int cnt = 0;
    for (int i = 0; i <= between; i++)
        if (!check[i])
            cnt++;
    printf("%d\n", cnt);
    return 0;
}
