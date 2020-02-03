// 1011.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	unsigned long T = 0, x = 0, y = 0;
	cin >> T;
	for (long i = 0; i < T; ++i)
	{
		cin >> x >> y;
		long num = 1, sum = 0;
		bool second = false;
		while (true)
		{
			sum += num;
			if (sum >= (y - x))
				break;
			if (second)
				++num;
			second = !second;
		}
		cout << (second ? num * 2 : num * 2 - 1) << '\n';
	}
}
