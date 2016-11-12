#include<stdio.h>
#include<memory.h>
using namespace std;
int check[100001];
int main()
{
    int n;
    memset(check, -1, sizeof(check));
    scanf("%d", &n);
 
    int arr[100000];
 
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    long long ans = 0;
    long long closer = -1;
    for (int i = 0; i < n; i++)
    {
        if (check[arr[i]] != -1) // 2번 이상.
        {
            if (check[arr[i]]>closer)
                closer = check[arr[i]];
            ans += (long long)(i - closer);
            check[arr[i]] = i;
        }
        else
        {
            ans += (long long)(i - closer);
            check [arr[i]] = i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
