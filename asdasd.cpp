#include<iostream>
#include<string>
#define MOD 100000007
using namespace std;
int main()
{
	int a, m;
	string binary;
	cin >> a >> m; // 구할 a^m을 입력.
	while (m > 0)
	{
		if (m % 2 == 1)
			binary = "1" + binary;
		else
			binary = "0" + binary;
		m /= 2;
	}

	long long p[31];
	p[0] = a;
	for (int i = 1; i < binary.length(); i++)
	{
		p[i] = (p[i - 1] * p[i - 1])%MOD; // long long 으로는 표현못하는 경우가 있어서 나머지 연산을 한다.
	} // 2진수로 표현한 m값을 가지고 사용할 배열을 만든다.
	long long solve = 1;
	for (int i = binary.length()-1; i >= 0; i--)
	{
		if (binary[i] == '1') // 1이면 포함하므로 곱한다.
			solve = (solve*p[binary.length() - i-1])%MOD;
	}
	cout << solve << '\n';
	//a^m의 결과가 나온다
	return 0;
}