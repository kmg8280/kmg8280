#include<stdio.h>
#include<memory.h>
using namespace std;
int check[100001];
int main()
{
    int n;
    memset(check, -1, sizeof(check)); // -1로 초기화한다. -1이면 처음 등장하는 수이고 -1이 아니면 중복되는 수 일 것이다.
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
            if (check[arr[i]]>closer) // 클로저 값을 가장 가까운 중복되는 수 index로 설정한다.
                closer = check[arr[i]];
            ans += (long long)(i - closer);
            check[arr[i]] = i; // 해당 수의 가장 최근 index 값을 저장한다.
        }
        else
        {
            ans += (long long)(i - closer);
            check [arr[i]] = i; // 해당 수의 가장 최근 index 값을 저장한다.
        }
    }
    printf("%lld\n", ans);
    return 0;
}
