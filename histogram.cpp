#include<stdio.h>
#include<memory.h>
#include<vector>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
int n;
vector<long long> h;
long long solve(int left, int right)
{ // solve(left,right) left~right 범위에서 가장 큰 직사각형을 반환.
	if (left == right) // 가장작은문제에 도달 해당 높이를 리턴.
		return h[left];
	int mid = (left + right) / 2; // 반을 나누자.
	long long ret = MAX(solve(left, mid), solve(mid + 1, right)); // 반을 나눈다.

	int lo = mid, hi = mid + 1; // 중앙선을 기준으로 왼쪽한칸 오른쪽한칸
	long long height = MIN(h[lo], h[hi]); // 높이는 둘 중 낮은 걸로 해야한다.
	ret = MAX(ret, height * 2); // ret 현재 최대 직사각형 크기.

	while (left < lo || hi < right) // left < lo 이거나  hi < right면 아직 전체로 확장한 것이 아님.
	{
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
		{ // hi이 right보다 작고 , lo==left(왼쪽으로 증가하는게 끝까지 도착했거나) , 오른쪽 히스토그램이 왼쪽 히스토그램보다 큰경우
			hi++;
			height = MIN(height, h[hi]); // 높이는 합친 히스토그램의 높이와 현재 높이의 최소
		}
		else // 위에 경우와 반대 되는 경우.
		{
			lo--;
			height = MIN(height, h[lo]); // 높이는 합친 히스토그램의 높이와 현재 높이의 최소
		}
		ret = MAX(ret, height*(hi - lo + 1));
		// 증가할떄마다 최대값을 초기화 시켜줘야 한다.
	}
	return ret;
	// 최종적으로 구해진 최대 직사각형의 넓이 반환
}
void test_case()
{	
	h.clear();
	int x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		h.push_back(x);
	}
	printf("%lld\n", solve(0, n - 1));
}
int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		test_case();
	}
}