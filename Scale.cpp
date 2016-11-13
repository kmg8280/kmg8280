#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
 
    int arr[1000];
 
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
 
    if (arr[0] != 1)
        printf("1\n");
    else
    {
        int sum = arr[0];
        for (int i = 1; i < n; i++)
            if (sum + 1 >= arr[i])
                sum += arr[i];
        printf("%d\n", sum + 1);
    }
    return 0;
}
